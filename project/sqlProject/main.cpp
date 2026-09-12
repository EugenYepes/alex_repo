#include <iostream>
#include <cstring>
#include <sqlite3.h>

using namespace std;

void insertValue(sqlite3 *db){
    string title;

    int check;
    string sql_insert = "INSERT OR IGNORE INTO tasks (title, status) VALUES (?, ?);";
	sqlite3_stmt *stmt;

	check = sqlite3_prepare_v2(db, sql_insert.c_str(), -1, &stmt, NULL);
	if (check != SQLITE_OK) {
		cerr << "Prepare failed: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return;
	}

    do {
        cout << "Give values for db title: ";
        getline(cin, title);

        if (!title.empty()) {

			sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_TRANSIENT);
			sqlite3_bind_text(stmt, 2, "PENDING", -1, SQLITE_TRANSIENT);

            
            check = sqlite3_step(stmt);
            if (check != SQLITE_DONE) {
				cerr << check << endl;
                cerr << "SQL error (INSERT): "<< endl;
                sqlite3_free(0);
                sqlite3_close(db);
                return;
            }
			sqlite3_reset(stmt); // Reset the statement for the next iteration
			sqlite3_clear_bindings(stmt); // Clear previous bindings
        }
    } while(!title.empty());
    
    sqlite3_finalize(stmt);
}

int main(){
    sqlite3 *db;
    int check = sqlite3_open("tasks.db", &db);
    if (check != SQLITE_OK){
        printf("Error message: cant open data");
        sqlite3_close(db);
        return 1;
    }
    
    const char *sql_create = 
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "title TEXT NOT NULL, "
        "status TEXT NOT NULL);";

    check = sqlite3_exec(db, sql_create, 0, 0, 0);
    if (check != SQLITE_OK){
        printf("Error message: cant execute data");
        sqlite3_close(db);
        return 1;
    }

   insertValue(db);

   sqlite3_close(db);
return 0;
}