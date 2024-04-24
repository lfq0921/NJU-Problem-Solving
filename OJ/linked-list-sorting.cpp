#include<stdio.h>
#include<iostream>
using namespace std;
int n;
struct node
{
	int value;
	node* next;
}qia, ga;
node* input(int n)
{
	//Todo: 输入数据并建立链表
	node *head = &qia, *tail = &ga;
	head->next = tail;
	node *p = head;
	for (int i = 1; i <= n; i++)
	{
		node *newnode = new node;
		int x;
		cin >> x;
		newnode->value = x;
		p->next = newnode;
		newnode->next = tail;
		p = newnode;
	}
	return head;
}
void sort(node* head)
{
	//Todo: 对链表排序
	for (int i = 1; i <= n; i++)
	{
		node *p1 = head->next;
		/*cout <<"the val of p1 = " << p1->value << endl;*/
		for (int j = 1; j <= n - 1; j++)
		{
			if (p1->value < p1->next->value) 
			{
				swap(p1->value, p1->next->value);
				/*cout << "swap succeed!" << endl;*/
			}
				
			p1 = p1->next;	
		}
	}
	return;
}
void output(node* head)
{
	//Todo: 输出链表数据
	node *p = head->next;
	while (p != &ga)
	{
		cout << p->value << ' ';
		p = p->next;
	}
		
	return;
}
int main()
{

	scanf("%d", &n);

	node* pHead = input(n);
	/*cout << "the queue is ";
	pHead = pHead -> next;
	while (pHead != &ga)
	{
		cout << pHead->value << ' ';
		pHead= pHead->next;
	}
	cout <<endl;*/

	sort(pHead);

	output(pHead);

	return 0;
}
