#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "stackdbio.h"
#include <iostream>

DBFile* initialize(const char *db_file_name) 
{
    DBFile *db_file = (DBFile *) malloc(sizeof(DBFile));
    db_file->file_ptr = NULL;
    strncpy(db_file->file_name, db_file_name, FILE_NAME_MAX_LEN);
    return db_file;
}

void open_db(DBFile *db) 
{
    db->file_ptr = fopen(db->file_name, "ab+");
}

void close_db(DBFile *db) 
{
    fclose(db->file_ptr);
}

void save_node_to_db(DBFile *db, stack *Stack) 
{
	fclose(db->file_ptr);
	db->file_ptr = fopen(db->file_name, "wb+");
	fwrite(&(Stack->size), sizeof(int), 1, db->file_ptr);
	node* top = Stack->top;
	int size = Stack->size;
	while (size)
	{
		fwrite(&(top->data), sizeof(int), 1, db->file_ptr);
		top = top->prev;
		size--;
	}
}

void read_from_db(DBFile *db, int* buffer,  int count) 
{
	std::cout << "Äàííûå èç ôàéëà: \n";
	bool check_size = true;
	while (count)
	{
		fread(buffer, sizeof(int), 1, db->file_ptr);
		if (!check_size)
		{
			std::cout << *buffer << " ";
			
		}
		else
		{
			std::cout << "Êîëè÷åñòâî ýëåìåíòîâ: " << *buffer << "\n";
			std::cout << "Äàííûå: ";
			check_size = false;
		}
		count--;
	}
}

void free_db(DBFile *db)
{
    free(db);
}
