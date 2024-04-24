#include<iostream>
using namespace std;
int n, l, r;
struct node
{
	int val;
	node *next, *prev;
}gaga, haha;

int main()
{
	node *head = &gaga, *tail = &haha;
	head->next = tail;
	tail->prev = head;	
	cin >> n >> l >> r;
	node *p = head;
	for (int i = 1; i <= n; i++)
	{
		node *newnode = new node;
		int x;
		cin >> x;
		newnode->val = x;
		newnode->next = p->next;
		newnode->prev = p;
		p->next->prev = newnode;
		p->next = newnode;
		p = newnode;
	}
	p = head;
	for (int i = 1; i < l; i++)
	{
		p = p->next;
		cout << p->val << ' ';
	}
	for (int i = l; i <= r; i++)
		p = p->next;
	for (int i = r; i >= l; i--)
	{
		cout << p->val << ' ';
		p = p->prev;
	}
	for (int i = l; i <= r; i++)
		p = p->next;
	for (int i = r; i < n; i++)
	{
		p = p->next;
		cout << p->val << ' ';
	}
	return 0;
}
