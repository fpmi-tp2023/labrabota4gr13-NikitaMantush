#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(void){
    sqlite3 * db;
    char *err_msg = 0;
    int  rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

   char *sql ="DROP TABLE IF EXISTS Phone;"
              "BEGIN TRANSACTION;"
              "CREATE TABLE Phone(ID INTEGER PRIMARY KEY, Name TEXT);"
              "INSERT INTO Phone(NAME) VALUES('Samsung');"
              "INSERT INTO Phone(NAME) VALUES('iPhone');"
              "INSERT INTO Phone(NAME) VALUES('Xiaomi');"
              "INSERT INTO Phone(NAME) VALUES('Realme');"
              "COMMIT;";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK ){
         fprintf(stderr, "Failed to execute statement: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    sqlite3_close(db);

    return 0;
}
