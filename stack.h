struct node	
{ 
    int data;
	node *prev;
};

struct stack                           // ñòðóêòóðà, â êîòîðîé õðàíèòñÿ óêàçàòåëü íà ñòðóêòóðû
{
	node *top;					       // óêàçàòåëü íà âåðøèíó (å¸ àäðåñ)
	int size;
};

void inizialization_stack(stack* S);

void push(stack *S);

int pop(stack *S);

void output(stack *S);
