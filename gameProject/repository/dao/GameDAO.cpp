#include "GameDAO.h"


int GameDAO::createGame(GameEntity gameEntity) {
	sqlite3_stmt *stmt;
	
	const char * sqlInsert = "INSERT INTO games(title, release_year, genre, status, medium_type, file_size_gb, drm_platform, has_box, region) VALUES(?,?,?,?,?,?,?,?,?);";
	int rc = sqlite3_prepare_v2(DAO::getDb(), sqlInsert, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Prepare failed: " << sqlite3_errmsg(DAO::getDb()) << endl;
		sqlite3_close(DAO::getDb());
		return -1;
	}


	sqlite3_bind_text(stmt, 1, gameEntity.getTitle().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 2, gameEntity.getReleaseYear());
    sqlite3_bind_text(stmt, 3, gameEntity.getGenre().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, gameEntity.getStatusString().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, gameEntity.getMediumTypeSting().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, gameEntity.getFileSizeGB());
    sqlite3_bind_text(stmt, 7, gameEntity.getDrmPlataform().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 8, gameEntity.getHasBox());
    sqlite3_bind_text(stmt, 9, gameEntity.getRegion().c_str(), -1, SQLITE_TRANSIENT);

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		return -2;
	}

	sqlite3_finalize(stmt);

	return 0;
}

/*
CREATE TABLE IF NOT EXISTS games(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	title TEXT NOT NULL UNIQUE,
	release_year INTEGER NOT NULL,
	genre TEXT NOT NULL,
	status TEXT NOT NULL CHECK (status in ('backlog', 'inprogress', 'completed')),
	medium_type TEXT NOT NULL CHECK (medium_type in ('digital', 'hardcopy')),
	file_size_gb INTEGER NOT NULL,
	drm_platform TEXT NOT NULL,
	has_box INTEGER NOT NULL CHECK (has_box in (0, 1)),
	region TEXT
);*/ 