#ifndef DAO_H
#define DAO_H

#include "../../lib/sqlite3.h"
#include <iostream>

using namespace std;

class DAO {
private:
	sqlite3 *db;
	char *dataBaseName;
public:
	DAO(char *databaseName);

	sqlite3* getDb() {
		return db;
	}

	char* getDataBaseName() { return dataBaseName; }

	~DAO();
};
#endif