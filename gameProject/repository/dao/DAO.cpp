#include "DAO.h"

DAO::DAO(char *databaseName) {
	int rc = sqlite3_open(databaseName, &db);
    if (rc != SQLITE_OK) {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
    }
}

DAO::~DAO() {
	sqlite3_close(db);
}