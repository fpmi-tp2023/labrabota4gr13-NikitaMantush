#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

int main(void){
    sqlite3 * db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    int rc = sqlite3_open("test.db", &db);
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    char *sql = "Select id, name from Товар where id = 7;";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    if (rc  != SQLITE_OK) {
    sqlite3_bind_int(res, 1, 3);
    } else{
        fprintf(stderr, "Failed to execitr statment: %s\n", sqlite3_errmsg(db));
    }
    int step = sqlite3_step(res);
    if(step == SQLITE_ROW){
        printf("%s: ", sqlite3_column_text(res,0));
        printf("%s\n", sqlite3_column_text(res,1));
    }

   sqlite3_finalize(res);
   sqlite3_close(db);
   return 0;
}
