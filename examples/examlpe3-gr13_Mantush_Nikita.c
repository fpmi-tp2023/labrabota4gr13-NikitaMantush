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
char* insert_sql = "INSERT INTO Товар (id, наименование, количество, цена, дата_изготовления, изготовитель, номер_телефона_изготовителя, адрес)\
VALUES (1, 'Книга', 10, 500.99, '2022-01-15', 'Издательство Москва', '+7 (495) 123-45-67', '119991, Россия, Москва, Тверская улица, 1, офис 101');";
char *insert_sql2 = "INSERT INTO Товар (id, наименование, количество, цена, дата_изготовления, изготовитель, номер_телефона_изготовителя, адрес) \
VALUES (2, 'Ноутбук', 5, 40000.00, '2022-06-20', 'Dell', '+1 (800) 624-9896', '90210, США, Калифорния, Лос-Анджелес, Беверли-Хиллз, улица Родео Драйв, 1');";
char *insert_sql3 = "NSERT INTO Товар (id, наименование, количество, цена, дата_изготовления, изготовитель, номер_телефона_изготовителя, адрес) \
VALUES (3, 'Телевизор', 3, 30000.00, '2022-03-10', 'Samsung', '+82-2-2053-3000', '135-090, Южная Корея, Сеул, Сеочо-дон, Сеочо-гу, Шератон-Гранд-Уолкерхилл-Сеул');";
char *insert_sql4 = "INSERT INTO Товар (id, наименование, количество, цена, дата_изготовления, изготовитель, номер_телефона_изготовителя, адрес) \
VALUES (4, 'Монитор', 7, 15000.00, '2022-04-05', 'LG', '+82-2-3777-1114', '03182, Южная Корея, Сеул, Ёндынпо-гу, Синдорим-дон, 8-1');";
char *insert_sql5 = "INSERT INTO Товар (id, наименование, количество, цена, дата_изготовления, изготовитель, номер_телефона_изготовителя, адрес)\
VALUES (5, 'Телефон', 15, 20000.00, '2022-02-28', 'Apple', '+1 (800) 275-2273', '95014, США, Калифорния, Купертино, Инфинити Луп, 1');";
rc = sqlite3_exec(db, insert_sql, callback, 0, &zErrMsg);

if (rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
} else{
    fprintf(stdout, "Data inserted successfully\n");

}  sqlite3_close(db);
    return 0;

}
