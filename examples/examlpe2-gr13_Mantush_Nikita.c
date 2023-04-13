#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){  int i;
  for (i = 0; i <argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char* argv[]){
    sqlite3 * db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    rc = sqlite3_open("test.db", &db);
    
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else {
        fprintf(stdout, "Opened database successfully\n");
    }
    sql = "CREATE TABLE Товар ("
    "id INTEGER PRIMARY KEY,"
    "наименование TEXT,"
    "количество INTEGER,"
    "цена REAL,"
    "дата_изготовления TEXT,"
    "изготовитель TEXT,"
    "номер_телефона_изготовителя TEXT,"
    "адрес TEXT);";
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if (rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
   } else{
       fprintf(stdout, "Table created successfully\n");
   }
}
