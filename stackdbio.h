#include <stdio.h>
#define FILE_NAME_MAX_LEN 60

struct DBFile {
    FILE *file_ptr;
    char file_name[FILE_NAME_MAX_LEN];
};

DBFile* initialize(const char *db_file_name);

void open_db(DBFile *db);

void close_db(DBFile *db);

void save_node_to_db(DBFile *db, stack *Stack);	//  ïðîòîòèï  çàïèñè â ôàéë

void read_from_db(DBFile *db, int* buffer, int count);	//ïðîòîòèï  ñ÷èòûâàíèÿ ôàéëà 

void free_db(DBFile *db);
