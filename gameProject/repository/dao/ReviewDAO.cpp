#include "ReviewDAO.h"

#include "AccountDAO.h"
#include "GameDAO.h"

int ReviewDAO::createReview(ReviewEntity reviewEntity) {
	sqlite3_stmt *stmt;
	
	const char * sqlInsert = "INSERT INTO review(game_id, account_id, score, summary_text, review_date) VALUES (?,?,?,,?,?,?);";
	int rc = sqlite3_prepare_v2(DAO::getDb(), sqlInsert, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Prepare failed: " << sqlite3_errmsg(DAO::getDb()) << endl;
		sqlite3_close(DAO::getDb());
		return -1;
	}

	// 1 check if the users exist
	AccountDAO accountDAO(DAO::getDataBaseName());
	accountDAO.createAccount(reviewEntity.getAccount());
	// 2 chack if the game exists
	GameDAO gameDAO(DAO::getDataBaseName());
	gameDAO.createGame(reviewEntity.getGame());

	sqlite3_bind_int(stmt, 1, reviewEntity.getGame().getId());
	sqlite3_bind_int(stmt, 2, reviewEntity.getAccount().getId());
    sqlite3_bind_int(stmt, 3, reviewEntity.getScore());
    sqlite3_bind_text(stmt, 4, reviewEntity.getSummaryText().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, reviewEntity.getReviewDate().c_str(), -1, SQLITE_TRANSIENT);


	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		return -2;
	}

	sqlite3_finalize(stmt);

	return 0;
}

/**
   	id INTEGER PRIMARY KEY AUTOINCREMENT,
	game_id INTEGER NOT NULL,
	account_id INTEGER NOT NULL,
	score INTEGER NOT NULL CHECK (score BETWEEN 0 AND 100),
	summary_text TEXT NOT NULL,
	review_date TEXT NOT NULL DEFAULT(DATE('now')),
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE,
	FOREIGN KEY (game_id) REFERENCES games(id) ON DELETE CASCADE
 */