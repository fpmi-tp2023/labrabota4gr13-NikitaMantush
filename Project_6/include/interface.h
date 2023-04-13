#include <sqlite3.h>

#ifndef PROJECT6_INTERFACE_H
#define PROJECT6_INTERFACE_H

int open_database(char* path, sqlite3* db);
int process_menu_actions(sqlite3* db);

#endif PROJECT6_INTERFACE_H
