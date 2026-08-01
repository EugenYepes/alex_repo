#include <stdio.h>
#include <sqlite3.h>

// Callback function to handle rows returned by SELECT
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(void) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // 1. Open (or create) the database file
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
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
        fprintf(stderr, "SQL error (CREATE): %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // 3. Insert data
    const char *sql_insert = 
        "INSERT OR IGNORE INTO users (name, email) "
        "VALUES ('Alice', 'alice@example.com');";

    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (INSERT): %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // 4. Query data
    const char *sql_select = "SELECT * FROM users;";
    
    printf("--- Query Results ---\n");
    rc = sqlite3_exec(db, sql_select, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error (SELECT): %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // 5. Close database connection
    sqlite3_close(db);
    return 0;
}