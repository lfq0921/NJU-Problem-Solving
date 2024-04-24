#include<iostream>
using namespace std;
struct node
{
	char col;
	node *next;
}qia, ga;

node *head = &qia, *tail = &ga;
void add(int pos, char color)
{
	for (int i = 1; i <= pos; i++)
		head = head->next;
	node *newnode = new node;
	newnode->col = color;
	newnode->next = head->next;
	head->next = newnode;
	return;
}

void del(int pos)
{
	node *temp;
	for (int i = 1; i <= pos; i++)
		head = head->next;
	temp = head->next;
	head->next = head->next->next;
	delete temp;
}

void swapnode(int x, int y)
{
	node *a, *b;
	for (int i = 1; i <= x + 1; i++)
		head = head->next;
	a = head;
	head = &qia;
	for (int i = 1; i <= y + 1; i++)
		head = head->next;
	b = head;
	swap (a->col, b->col);
	return;
}

void printnode()
{
	while (head->next != &ga)
	{
		head = head->next;
		cout << head->col;
	}
	cout << endl;
	return;
}
int main()
{
	int n;
	cin >> n;
	head->next = tail;
	for (int i = 1; i <= n; i++)
	{
		head = &qia;
		char opt;
		cin >> opt;
		if (opt == 'A')
		{
			int x;
			char c;
			cin >> x >> c;
			add(x, c);
		}
		if (opt == 'D')
		{
			int x;
			cin >> x;
			del(x);
		}
		if (opt == 'S')
		{
			int x, y;
			cin >> x >> y;
			swapnode(x, y);
		}
		if (opt == 'P')
		{
			printnode();
		}
	}
}
