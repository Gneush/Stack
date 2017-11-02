#include <stdio.h>
#include "stack.h"
#include "stackdbio.h"
#include <iostream>
#include <clocale>                     // ïîäêëþ÷åíèå äëÿ ðóñêîÿçû÷íîé êîíñîëè

using namespace std;

const char *db_file_name = "stack_db_file.bin\0";

int main() 
{
	setlocale(LC_ALL, "Russian");      // ôóíêöèÿ äëÿ ââîäà ðóññêîãî ÿçûêà
	stack Stack;
	inizialization_stack(&Stack);
    DBFile* db = initialize(db_file_name);
	if (db == NULL)
	{
		cout <<"ERROR";
		return 1;
	}
    open_db(db);
	push(&Stack);
    save_node_to_db(db, &Stack); 
	close_db(db);
	open_db(db);
	fseek(db->file_ptr, 0, SEEK_END);						// ïåðåìåùàåì êóðñîð â êîíåö
	long lSize = ftell(db->file_ptr);						//óçíàåì êîëè÷åñòâî áàéò â ôàéëå
	int Size_type = sizeof(int);							// êîëè÷åñòâî áàéò äëÿ îäíîãî ñèìâîëà òèïà int
	int count = lSize / Size_type;							// êîë-âî ñèìâîëîâ = îáùåå êîëâî áàéò / êîëâî áàéò äëÿ 1 ñèìâîëà
	rewind(db->file_ptr);									//êóðñîð âñòàåò â íà÷àëî
	int * buffer = (int*)malloc(sizeof(int)* count);		// âûäåëåíèå ïàìÿòè äëÿ õðàíåíèÿ ñîäåðæèìîãî ôàéëà
	read_from_db(db, buffer, count);
    close_db(db);
    free_db(db);
	system("pause");
    return 0;
}
