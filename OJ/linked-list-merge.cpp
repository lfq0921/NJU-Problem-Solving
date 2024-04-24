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
	while(head)//遍历链表，如果写成while(head -> next)则不能撤销尾节点！！
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
	node *po1 = p1,*save1 = p1;
	node *po2 = p2, *save2 = p2;
	po2 = po2->next;
	bool over = true;
	while ((po2->next != &ga[2]) && (over))
	{
		
		if (po1 == &qia[1])
		{
			if (po2->val < po1->next->val)
			{
				node *temp = po2->next;
				po2->next = po1->next;
				po1->next = po2;
				po1 = po1->next;
				po2 = temp;
			}
			else po1 = po1->next;
		}
		if ((po2->val >= po1->val) && (po2->val <= po1->next->val)) 
		{
			node *temp = po2->next;
			po2->next = po1->next;
			po1->next = po2;
			po1 = po1->next;
			po2 = temp;
		}	
		else po1 = po1->next;
		if (po1->next == &ga[1])
		{
			po1->next = po2;
			over = false;
		}	
	}
	while((p1->next != &ga[1]) && (p1->next != &ga[2]))
		{
			p1 = p1->next;
			cout << p1->val << ' ';
		}
	if (over) cout << po2->val;
	DeleteList(save1);
	DeleteList(save2);
	return 0;
 } 
