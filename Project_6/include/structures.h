#ifndef PROJECT6_INTERFACE_H
#define PROJECT6_INTERFACE_H

enum Menu{
    SELECT = 0,
    INSERT = 1,
    DELETE = 2,
    WHERE 3,
    END_INSERT = 15
};
enum Columns{
    ID = 4,
    наименование = 5,
    количество = 6,
    цена = 7,
    дата_изготовления = 8,
    изготовитель = 9,
    номер_телефона_изготовителя = 10,
    адрес = 11,
    STR_NULL = 12,
    COMMA = 13
};

char *query_parts[] = {"SELECT * Товар", "Insert Into товар(ID, наименование, количество, цена, дата_изготовления, изготовитель, номер_телефона_изготовителя, адрес"}

#endif PROJECT6_INTERFACE_H
