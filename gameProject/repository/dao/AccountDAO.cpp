#include "AccountDAO.h"


int AccountDAO::createAccount(AccountEntity accountEntity) {
	sqlite3_stmt *stmt;
	
	const char * sqlInsert = "INSERT OR IGNORE INTO account(email, username, account_type, pref_platform) VALUES (?,?,?,?);";
	int rc = sqlite3_prepare_v2(DAO::getDb(), sqlInsert, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Prepare failed: " << sqlite3_errmsg(DAO::getDb()) << endl;
		sqlite3_close(DAO::getDb());
		return -1;
	}



    sqlite3_bind_text(stmt, 1, accountEntity.getEmail().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, accountEntity.getUserName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, accountEntity.getAccountTypeString().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, accountEntity.getPrefPlatform().c_str(), -1, SQLITE_TRANSIENT);


    
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		return -2;
	}

	sqlite3_finalize(stmt);

	return 0;
}

/*
    id INTEGER PRIMARY KEY AUTOINCREMENT,
	email TEXT NOT NULL UNIQUE,
	username TEXT NOT NULL UNIQUE,
	account_type TEXT NOT NULL CHECK (account_type IN ('player', 'reviewer')),
	pref_platform TEXT,
	outlet_name TEXT
*/