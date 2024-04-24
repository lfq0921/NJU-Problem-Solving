#include<iostream>
using namespace std;
int N, l, r;
struct node
{
	int val;
	node *next;
	node *prev;
};
node *lnode = NULL, *rnode = NULL, *llnode = NULL, *rlnode = NULL;
node *creatList()
{
	node *head = NULL, *tail = NULL, p;
	for (int i = 0; i < N; i++)
	{
		node *newnode = new node;
		cin >> newnode->val;
		if (head == NULL) head = value;
		else tail->next = p;
		tail = p; 
		if (i == (l - 1)) lnode = p;
		if (i == (r - 1)) rnode = p;
		if ((l >= 2) && (i == (l - 2))) llnode = p;
		if ((r >= 2) && (i == (r - 2))) rlnode = p;
	}
	return head;
}

int main()
{
	cin >> N >> l >> r;
	/*node *here = creatList();
	node *temp = rnode->next;
	rnode->next = lnode->next;
	lnode->next = temp;
	if (llnode != NULL) llnode->next = rnode;
	else here = rnode;*/
	
	node *temp = NULL;
	node *freshnext = lnode;//把倒序链表另外构建：找到左点 
	node *freshprev = lnode->next;
	for (int i = 0; i <= l - r - 2; i++) 
	temp = freshprev->next;//存储原本右边的下一个 
	freshprev->next = freshnext;
	freshprev = temp;
	freshnext
	
	
	for (int i = 0; i < N; i++)
	{
		cout << here->val << " ";
		here = here->next;
	}
	return 0;
}
