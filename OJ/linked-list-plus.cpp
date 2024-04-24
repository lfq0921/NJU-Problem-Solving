#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
	int val;
	node* next;
}qia[3], ga[3];
int count = 0;
node* input(int n)
{
	node *head = &qia[++count], *tail = &ga[count];
	head->next = tail;
	node *p = tail;
	for (int i = 1; i <= n; i++)
	{
		node *newnode = new node;
		int x;
		cin >> x;
		newnode->val = x;
		newnode->next = p;
		head->next = newnode;
		p = newnode;
	}
	return head;
}
node* add(node* p1,node* p2)
{
	node *head = &qia[++count], *tail = &ga[count];
	int flag1 = 1, flag2 = 1;
	
	head->next = tail;
	node *p = tail;
	int m = 0;
	while ((p1->next != &ga[1]) || (p2->next != &ga[2]))
	{
		if (p1->next != &ga[1]) 
			p1 = p1->next;
		else flag1 = 0;
	 	if (p2->next != &ga[2]) 
		 p2 = p2->next;
		 else flag2 = 0;
	 	node *newnode = new node;
	 	int x = p1->val * flag1 + p2->val * flag2 + m;
	 	m = x / 10;
	 	x = x % 10;
	 	newnode->val = x;
	 	head->next = newnode;
	 	newnode->next = p;
	 	p = newnode;
	}
	if (m != 0) 
	{
		node *newnode = new node;
	 	int x = m;
	 	m = x / 10;
	 	x = x % 10;
	 	newnode->val = x;
	 	head->next = newnode;
	 	newnode->next = p;
	 	p = newnode;
	}
	return head;
}
void output(node* head)
{
	while (head->next != &ga[3])
	{
		head = head->next;
		cout << head->val << ' ';
	}
}
int main()
{
	int m,n;

	scanf("%d %d", &m,&n);

	node* p1 = input(m);
	node* p2 = input(n);
	node* sum = add(p1,p2);

	output(sum);

	return 0;
}
