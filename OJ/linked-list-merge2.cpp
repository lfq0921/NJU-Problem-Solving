#include<iostream>
using namespace std;
int m, n;
struct node
{
	int val;
	node *next;
}qia[3], ga[3];
int count = 0;
node *input (int N)
{
	node *head = &qia[++count], *tail = &ga[count];
	head->next = tail;
	node *p = head;
	for (int i = 1; i <= N; i++)
	{
		node *newnode = new node;
		int x;
		cin >> x;
		newnode->val = x;
		p->next = newnode;
		newnode->next = tail;
		p = newnode;
	}
	return head;
}


void DeleteList(node * head)
{  
	head = head -> next; 
	while((head -> next != &ga[1]) && (head -> next != &ga[2]))//遍历链表，如果写成while(head -> next)则不能撤销尾节点！！
	{
		node *current = head;
		head = head -> next;
		delete current;
   }
}

int main()
{
	cin >> m >> n;
	node *p1 = input(m);
	node *p2 = input(n);
	node *po1 = p1, *save1 = p1;
	node *po2 = p2, *save2 = p2;
	po1 = po1->next;
	po2 = po2->next;
	bool flag1 = true, flag2 = true;
	while (flag1 || flag2)
	{
		if (flag1 == false)
		{
			cout << po2->val << ' ';
			if (po2->next!= &ga[2]) po2 = po2->next;
			else {flag2 = false; 
			}
		}
		else if (flag2 == false)
		{
			cout << po1->val << ' ';
			if (po1->next != &ga[1]) po1 = po1->next;
			else {flag1 = false; 
			}
		}
		else
		{
			if (po1->val <= po2->val)
			{
				cout << po1->val << ' ';
				if (po1->next != &ga[1]) po1 = po1->next;
				else {flag1 = false; 
				}
			}
			else 
			{
				cout << po2->val << ' ';
				if (po2->next!= &ga[2]) po2 = po2->next;
				else {flag2 = false; 
				}
			}
		}
	}
	DeleteList(save1);
	DeleteList(save2);
	return 0;
}
