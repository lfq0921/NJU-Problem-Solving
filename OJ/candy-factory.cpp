#include<iostream>
using namespace std;
long long maxsweet = -1;
int point = 1;
struct node
{
	int type;
	int value;
	*node next;
	*node prev;
 }*head, *theprev, *tail;
 
long long sweetest()
{
	int recv0[1000005], recp0[1000005];
	int count0 = 0;
	int count1 = 0;
	int counts = 0;
	node *cur = head;
	long long sum = 0;
	int position = 0;
	while(cur != NULL)
	{
		if (cur->type == 2) sum += cur->value;
		if (cur->type == 0)
		{
			count0 ++;
			recv0[count0] = cur->value;
			recp0[count0] = position;
		}
		else if (cur->type == 1)
		{
			if (count0 > 0) 
			{
				sum += recv0[count0] + cur->value;
				count0--;
			}
			else  maxsweet = max(maxsweet, sum);
		 }
		 cur = cur->next;
	}
}
node *newnode()
{
	node thenew = new node;
	thenew.prev = theprev;
	theprev.next = thenew;
	return thenew;
 } 

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			scanf("%d", head.type);
			theprev = head;
		}
		else 
		{
			node *the_new = newnode();
			scanf("%d", the_new.type);
			theprev = the_new;
			if (i == N) tail = the_new;
		}
	}
	node *cur = head;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", cur.value);
		if (i < N) cur = cur->next;
	}
	printf("%lld\n", sweetest());
	while(M--)
	{
		int pos, ty, va;
		node *the_new = newnode();
		scanf("%d%d%d", &pos, &the_new->type, &the_new->value);
		if (pos == 0)
		{
			head->prev = the_new;
			the_new->next = head;
			head = the_new;
		}
		else if (pos == 1)
		{
			tail->next = the_new;
			the_new->prev = tail;
			tail = the_new;
			tail->next = NULL;
		}
		node *cur = head;
		printf("%lld\n", sweetest());
	}
}
