#include<iostream>
using namespace std;
int deep = 0;
struct node
{
	int value;
	struct node *left, *right, *father;
	int dep;
	int lorr;
	int count;
 };
 node *newNode(int val);
 node *root = NULL;
 void deleteIt(node *A)
 {
 	if (A->left == NULL && A->right == NULL)
 		delete A;
 	if (A->left != NULL && A->right != NULL)
 	{
 		A->count = A->right->count;
 		A->value = A->right->value;
		deleteIt(A->right); 
	 }
	 else if (A->left != NULL)
	 {
	 	A->count = A->right->count;
 		A->value = A->right->value;
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
 	cout << "begin to insert" << endl;
 	if (root == NULL) 
 	{
 		newNode(val);
 		return;
	 }
 	if (val == (rooty->value)) 
	 {
	 	rooty->count++;
	 	if (rooty->count == 0) deleteIt(rooty);
		return;
	 }
 	if(val > (rooty->value))
 	{
 		deep++;
 		if (rooty->right == NULL) 
 		{
 			rooty->right = newNode(val);
 			rooty->right->father = rooty;
 			rooty->right->lorr = 1;
		 }
		 	
		else insert (rooty->right, val);
	}
	if(val < rooty->value)
	{
		deep++;
		if (rooty->left == NULL) 
		{
			rooty->left = newNode(val);
			rooty->left->father = rooty;
			rooty->left->lorr = -1;
		}
		 	
		else insert (rooty->left, val);
	}
 }
 
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
 		thenew->dep = 0;
 		thenew->lorr = 0;
 		root = thenew;
	 }
	 else 
	 {
	 	thenew->count = 1;
	 	thenew->value = val;
	 	thenew->left = NULL;
	 	thenew->right = NULL;
	 	thenew->dep = deep;
	 	deep = 0;
	 }
	 return thenew;
 }
 
 void totheroot(node *roothere)
 {
 	cout << roothere->value << endl;
 	if (roothere->father != NULL) totheroot(roothere->father);
 	else return;
 }
 void search(node *rooty, int val)
 {
    if (rooty == NULL) return;
    else
 	if (rooty->value == val) 
	 {
 		cout << "to false delete!" << endl;
 		rooty->count = -1;
 		return;
	 }
	 else if ((rooty->left != NULL) && (rooty->value > val))
	 	search(rooty->left, val);
	else if ((rooty->right != NULL) && (rooty->value < val))
		search(rooty->right, val);
	return;
 }
 void printnode(node *thenode)
 {
 	for (int i = 1; i <= thenode->dep; i++)
 		cout << "  ";
 	switch(thenode->lorr)
 		{
 			case -1:
 				cout << '/';
 				break;
 			case 0:
 				cout << ':';
 				break;
 			case 1:
 				cout << "\\";
 				break;
		 }
		cout << thenode->value << endl;
 }
 void print(node *nownode)
 {
 	if (nownode == NULL) return;
 	//bool left = true;
 	else printf("%d ",nownode->value);
 	if (nownode->left != NULL) 
	 {
	 	print(nownode->left);
	 	//left = false;
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
 	    deep = 0;
 		cin >> opt;
 		switch(opt)
 		{
 		case 1:
 			insert(root, x);
 			break;
 		case 2:
 			search(root, x);
 			break;
 		case 0:
 			print(root);
 			cout << endl;
 			break;
 		}
	 }
	 return 0;
  } 
