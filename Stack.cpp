
#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <stdio.h>
using namespace std;
struct Note {
	int data;
	struct Note *next;
};
void push(Note* &NEXT, int DATA)
{
	Note *head = new Note;
    head->data = DATA;
	head->next = NEXT;
	NEXT = head;
}
int pop (Note* &NEXT)
{
	int temp = NEXT->data;
	Note *head = NEXT;
	NEXT = NEXT->next;
	delete head;
	cout << temp<<endl;
	return temp;
}
int main()
{
	Note *p = 0;
		push(p,78);
		push(p, 87);
		push(p, -52);
		push(p, 0);
		push(p, 7777899);

		pop(p);
		pop(p);
		pop(p);
		pop(p);
		pop(p);
		system("pause");
		return 0;
}
