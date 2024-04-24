#include<iostream>
using namespace std;
int deep = 0;
struct node
{
	int value;
	struct node *left, *right, *father;
	int dep;
	int lorr;
 };
 node *newNode(int val);
 node *root = NULL;
 
 void insert(node *rooty, int val)
 {
 	if (root == NULL) 
 	{
 		newNode(val);
 		return;
	 }
 	if (val == (rooty->value)) return;
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
    if (rooty == NULL) cout << "NO" << endl;
    else
 	if (rooty->value == val) 
	 {
 		cout << "YES" << endl;
 		totheroot(rooty);
 		return;
	 }
	 else if ((rooty->left != NULL) && (rooty->value > val))
	 	search(rooty->left, val);
	else if ((rooty->right != NULL) && (rooty->value < val))
		search(rooty->right, val);
	else cout << "NO" << endl;
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
 	bool left = true;
 	if (nownode->left != NULL) 
	 {
	 	print(nownode->left);
	 	left = false;
	 }
 	if ((nownode->left == NULL) || (!left)) printnode(nownode);
 	if (nownode->right != NULL) print(nownode->right);
 	return;
  } 
 int main()
 {
 	int T;
 	char opt;
 	int x;
 	cin >> T;
 	while (T--)
 	deep = 0; 
 	{
 		cin >> opt >> x;
 		switch(opt)
 		{
 		case 'I':
 			insert(root, x);
 			break;
 		case 'S':
 			search(root, x);
 			break;
 		case 'P':
 			cout << "=====" << endl;
 			print(root);
 			cout << "=====" << endl;
 			break;
 		}
	 }
	 return 0;
  } 
