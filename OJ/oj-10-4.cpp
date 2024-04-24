#include<iostream>
using namespace std;
struct node
{
	int value;
	struct node *left, *right, *father;
 };
 node *newNode(int val);
 node *root = NULL;
 
 void insert(node *rooty, int val)
 {
 	if (root == NULL) 
 	{
 		/*cout << "the root is null" << endl;*/
 		newNode(val);
 		return;
	 }
	 /*cout << "the value of rooty is " << rooty->value << endl;*/
 	if (val == (rooty->value)) return;
 	if(val > (rooty->value))
 		if (rooty->right == NULL) 
 		{
 			rooty->right = newNode(val);
 			rooty->right->father = rooty;
		 }
		 	
		else insert (rooty->right, val);
	if(val < rooty->value)
		if (rooty->left == NULL) 
		{
			rooty->left = newNode(val);
			rooty->left->father = rooty;
		}
		 	
		else insert (rooty->left, val);
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
 		root = thenew;
	 }
	 else 
	 {
	 	thenew->value = val;
	 	thenew->left = NULL;
	 	thenew->right = NULL;
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
 int main()
 {
 	int T;
 	char opt;
 	int x;
 	cin >> T;
 	while (T--)
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
 		}
	 }
	 return 0;
  } 
