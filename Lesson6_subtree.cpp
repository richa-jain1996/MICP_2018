/*
Subtree of Another Tree
Given two non-empty binary trees s and t,
check whether tree t has exactly the same structure and node values with a subtree of s.
A subtree of s is a tree that consists of a node in s and all of that node's descendants.

*/
#include<iostream>
using namespace std;
struct tree
{
	char data;
	tree* left,*right;
	tree* createNode(char d)
	{
		tree* p=new tree;
		p->data=d;
		p->left=NULL;
		p->right=NULL;
	}
	int compareTree(tree* S,tree* T)
	{
		if((S==NULL)&&(T==NULL)) return 1;
		if((S==NULL) || (T==NULL))return 0;
		if((S->data==T->data) && compareTree(S->left,T->left) && compareTree(S->right,T->right))
			return 1;
	}
	int checkIfSubtree(tree* S,tree* T)
	{
		if(S==NULL) return 0;
		if(T==NULL) return 1;
		if( compareTree(S,T)==1) return 1;
		return (checkIfSubtree(S->left,T) || checkIfSubtree(S->right,T));
	}
	void inorder(tree* root)
	{
		if(root)
		{
			inorder(root->left);
			cout<<root->data<<"--";
			inorder(root->right);
		}
	}
}obj;

/*TEST CASES*/
bool t1()
{
	// T is empty and S is empty
	tree* S=obj.createNode('');
	tree* T=obj.createNode('');
	if(obj.checkIfSubtree(S,T)!=-1) return false;
}
bool t2()
{
	//T is exactly same as S
	tree* S=obj.createNode('A');
	S->left=obj.createNode('B');
	S->right=obj.createNode('C');
	tree* T=obj.createNode('A');
	T->left=obj.createNode('B');
	T->right=obj.createNode('C');
	if(obj.checkIfSubtree(S,T)!=1) return false;
}
bool t3()
{
	//T is subtree of S
	tree* S=obj.createNode('A');
	S->left=obj.createNode('B');
	S->right=obj.createNode('C');
	S->left->left=obj.createNode('E');
	S->right->right=obj.createNode('F');
	S->right->left=obj.createNode('G');
	tree* T=obj.createNode('C');
	T->right=obj.createNode('F');
	T->left=obj.createNode('G');
	if(obj.checkIfSubtree(S,T)!=1) return false;	
}
bool t4()
{
	//T is not a subtree of S
	tree *S	 = obj.createNode('H');
	S->right		= obj.createNode('3');
	S->right->right	 = obj.createNode('3');
	S->left			 = obj.createNode('1');
	S->left->left	= obj.createNode('4');
	S->left->left->right = obj.createNode('G');
	S->left->right	 = obj.createNode('6');

	tree *T = obj.createNode('1');
	T->right	= obj.createNode('6');
	T->left		 = obj.createNode('4');
	if(obj.checkIfSubtree(S,T)!=0) return false;
}
bool test()
{
	if(t2() && t3() && t4()) return true;
	return false;
}
int main()
{	
	tree* S=obj.createNode('A');
	S->left=obj.createNode('B');
	S->right=obj.createNode('C');
	tree* T=obj.createNode('A');
	T->left=obj.createNode('B');
	T->right=obj.createNode('C');
	cout<<"inorder traversal of tree S is:";
	obj.inorder(S);
	cout<<endl<<"inorder traversal of tree T is:";
	obj.inorder(T);
	cout<<endl;
	int ans=obj.checkIfSubtree(S,T);
	if(ans==-1)
		cout<<"invalid case";
	else
	if(ans==1)
		cout<<"T is a subtree of S";
	else
		cout<<"T is not a subtree of S";
	
	
	return 0;
}
