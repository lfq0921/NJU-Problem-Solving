#include<iostream>
using namespace std;
const int N = 500 + 5;

struct node
{
	int x, y;
	node *left, *right, *up, *down;
};
node c[N][N];
int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		c[i][j].x = i;
		c[i][j].y = j;
		if (i != 1) c[i][j].left = &c[i - 1][j];
		else c[i][j].left = NULL;
		if (j != 1) c[i][j].down = &c[i][j - 1];
		else c[i][j].down = NULL;
		if (i != n) c[i][j].right = &c[i + 1][j];
		else c[i][j].right = NULL;
		if (j != n) c[i][j].up = &c[i][j + 1];
		else c[i][j].up = NULL;
	}
	int T;
	scanf("%d", &T);
	int xnow = 1, ynow = 1;
	int x0, y0;
	char opt;
	for (int i = 1; i <= T; i++)
	{
		scanf("\n%c", &opt);
		x0 = xnow;
		y0 = ynow;
		if ((opt == 'W') && (c[x0][y0].up != NULL)) {xnow = c[x0][y0].up->x; ynow = c[x0][y0].up->y;}
		if ((opt == 'S') && (c[x0][y0].down != NULL)) {xnow = c[x0][y0].down->x; ynow = c[x0][y0].down->y;}
		if ((opt == 'A') && (c[x0][y0].left != NULL)) {xnow = c[x0][y0].left->x; ynow = c[x0][y0].left->y;}
		if ((opt == 'D') && (c[x0][y0].right != NULL)) {xnow = c[x0][y0].right->x; ynow = c[x0][y0].right->y;}
		if (opt == 'B')
		{
			if(c[xnow][ynow].left != NULL) c[xnow][ynow].left->right = c[xnow][ynow].right;
			if(c[xnow][ynow].right != NULL) c[xnow][ynow].right->left = c[xnow][ynow].left;
			if(c[xnow][ynow].down != NULL) c[xnow][ynow].down->up = c[xnow][ynow].up;
			if(c[xnow][ynow].up != NULL) c[xnow][ynow].up->down = c[xnow][ynow].down;
		}
		if(opt == 'P') printf("(%d, %d)\n", xnow, ynow);
	}
	return 0;
 } 
