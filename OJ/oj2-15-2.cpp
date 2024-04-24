#include<bits/stdc++.h>
using namespace std;
int pre[1000005], in[1000005];
struct node
{
	int data;
	struct node *lchild, *rchild;
};
struct node *create(int ll, int lr, int rl, int rr)
{
	struct node *p = (node*)malloc(sizeof(node));
	p -> data = pre[ll];
	p -> lchild = NULL;
	p -> rchild = NULL;
	int pos;
	for (int i = rl; i <= rr; i++)
	{
		if (pre[ll] == in[i])
		{
			pos = i;
			break;		
		}
	}
	if (pos != rl)
	{
		p -> lchild = create(ll + 1, ll + pos - rl, rl, pos - 1);
	}
	if (pos != rr)
	{
		p -> rchild = create(ll + pos - rl + 1, lr, pos + 1, rr);
	}
	return p;
}
void postorder(struct node *p)
{
	if(p != NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout << p->data << " ";
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	struct node *p = NULL;
	p = create(0, n - 1, 0, n - 1);
	postorder(p);
	cout << endl;
}
