#include <iostream>
#include <cstring>
#include <sqlite3.h>

using namespace std;

void get_all_users(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT id, name, email FROM users;";

    // 1. Prepare statement
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        cerr << "Prepare failed: " << sqlite3_errmsg(db) << endl;
        return;
    }

    cout << "--- Query Results ---" << endl;

    // 2. Iterate through results row by row
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // Read columns by 0-based index
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        const unsigned char *email = sqlite3_column_text(stmt, 2);

        cout << "ID: " << id << " | Name: " << name << " | Email: " << email << endl;
    }

    // 3. Free resources
    sqlite3_finalize(stmt);
}

int main(void) {

    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // 1. Open (or create) the database file
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK) {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    // 2. Create a table
    const char *sql_create = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "email TEXT UNIQUE NOT NULL);";

    rc = sqlite3_exec(db, sql_create, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error (CREATE): " << err_msg << endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // 3. Insert data
    
    string name, email;

	string sql_insert = "INSERT OR IGNORE INTO users (name, email) VALUES (?, ?);";
	sqlite3_stmt *stmt;
	rc = sqlite3_prepare_v2(db, sql_insert.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Prepare failed: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return 1;
	}

    // Use getline so the user can submit an empty line (press Enter) to exit
    do {
        cout << "Give values for db name: ";
        getline(cin, name);

        cout << "Give values for db email: ";
        getline(cin, email);

        if (!name.empty()) {

			sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
			sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_TRANSIENT);

            
            rc = sqlite3_step(stmt);
            if (rc != SQLITE_DONE) {
				cerr << rc << endl;
                cerr << "SQL error (INSERT): " << err_msg << endl;
                sqlite3_free(err_msg);
                sqlite3_close(db);
                return 1;
            }
			sqlite3_reset(stmt); // Reset the statement for the next iteration
			sqlite3_clear_bindings(stmt); // Clear previous bindings
        }
    } while(!name.empty());
    
    sqlite3_finalize(stmt); // Finalize the statement after the loop



    
    cout << "--- Query Results ---" << endl;
    get_all_users(db);

    // 5. Close database connection
    sqlite3_close(db);
    return 0;
}
