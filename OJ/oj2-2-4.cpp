#include<iostream>
using namespace std;
struct node
{
	int value;
	struct node *left, *right, *father;
	int count;
 };
node *root = NULL;
void print(node *nownode);
node *newNode(int val)
 {
 	node *thenew = new node;
 	if (root == NULL)
 	{
 		thenew->count = 1;
 		thenew->father = NULL;
 		thenew->left = NULL;
 		thenew->right = NULL;
 		thenew->value = val;
 		root = thenew;
	 }
	 else 
	 {
	 	thenew->count = 1;
	 	thenew->value = val;
	 	thenew->left = NULL;
	 	thenew->right = NULL;
	 }
	 return thenew;
 }
 void deleteIt(node* A)
 {
 	if (A->left == NULL && A->right == NULL)
 	{
 		if (A->father != NULL)
 		{
 			if (A->father->left != NULL)
 			{
	 			if (A->father->left->value == A->value) A->father->left = NULL;
				else A->father->right = NULL;
			}
 			else A->father->right = NULL;
		}
		else root = NULL;
		delete A;
		return;	
	}
 		else if (A->left != NULL && A->right != NULL)
 	{
 		node *curr = A->right;
 		node *successor = curr;
 		node *sucparent = NULL;
 		while(curr != NULL)
 		{
 			sucparent = successor;
 			successor = curr;
 			curr = curr->left;
 		}
			A->value = successor->value;
			A->count = successor->count;
			deleteIt (successor);
	}
	 else if (A->left != NULL)
	 {
	 	A->count = A->left->count;
 		A->value = A->left->value;
 		deleteIt(A->left);
	 }
	 else 
	 {
 		A->count = A->right->count;
 		A->value = A->right->value;
		deleteIt (A->right); 
	 } 
	 return;
 }
 void insert(node *rooty, int val)
 {
 	if (root == NULL) 
 	{
 		newNode(val);
 		return;
	 }
 	if (val == (rooty->value)) 
	 {
	 	rooty->count++;
		return;
	 }
 	if(val > (rooty->value))
 	{
 		if (rooty->right == NULL) 
 		{
 			rooty->right = newNode(val);
 			rooty->right->father = rooty;
		 }
		else insert (rooty->right, val);
	}
	if(val < rooty->value)
	{
		if (rooty->left == NULL) 
		{
			rooty->left = newNode(val);
			rooty->left->father = rooty;
		}
		else insert (rooty->left, val);
	}
	return;
 }
void search(node *rooty, int val)
 {
    if (rooty == NULL) return;
    else
 	if (rooty->value == val) 
	 {
 		rooty->count --;
 		if (rooty->count == 0) deleteIt(rooty);
 		return;
	 }
	 else if ((rooty->left != NULL) && (rooty->value > val))
	 	search(rooty->left, val);
	else if ((rooty->right != NULL) && (rooty->value < val))
		search(rooty->right, val);
	return;
 }
void print(node *nownode)
 {
 	if (nownode == NULL) return;
 	else printf("%d ",nownode->value);
 	if (nownode->left != NULL) 
	 {
	 	print(nownode->left);
	 }
 	if (nownode->right != NULL) print(nownode->right);
 	return;
  } 
int main()
 {
 	int M, opt, x;
 	cin >> M;
 	while (M--)
 	{
 		cin >> opt;
 		if (opt == 1)
 		{
 			cin >> x;
 			insert(root, x);
		 }
 			
 		if (opt == 2)
 		{
 			cin >> x;
 			search(root, x);
		 }
 			
 		if (opt == 0)
 		{
 			print(root);
 			cout << endl;
		 }
	 }
	 return 0;
  } 
