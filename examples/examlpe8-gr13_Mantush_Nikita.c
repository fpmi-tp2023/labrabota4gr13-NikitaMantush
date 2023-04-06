
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    sqlite3 *db;
    sqlite3_open("test.db", &db);

    FILE *file = fopen("g.jpg", "rb");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *data = malloc(size + 1);
    fread(data, size, 1, file);
    fclose(file);
    data[size] = '\0';

    char *sql = "INSERT INTO Images (id, data) VALUES (?, ?)";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, 1);
    sqlite3_bind_blob(stmt, 2, data, size, SQLITE_STATIC);
    sqlite3_step(stmt);

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}

