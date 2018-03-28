/* Check if the Linked List is a Palindrome */
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* createNode(int d)
{
	node *new_node=new node;
	new_node->data=d;
	new_node->next=NULL;
	return new_node;
}
void insert_node(node** head,int ele)
{
	node* temp=createNode(ele);
	if((*head)==NULL)
	{
		*head=temp;
	}
	else
	{
		node* rear=(*head);
		while(rear->next)
		{
			rear=rear->next;
		}
		rear->next=temp;
	}
}
bool check_palindrome(int arr[],int len)
{
	for(int i=0;i<len/2;++i)
	{
		if(arr[i]!=arr[len-i-1])
		{
			return false;
		}
	}
	return true;
}
bool isPalindrome(node* head,int len)
{
	if(head->next==NULL)
		return true;
	node *temp=head;
	int arr[len];
	int i=0;
	while(temp)
	{
		arr[i]=temp->data;
		++i;
		temp=temp->next;
	}
	if(check_palindrome(arr,len))
		return true;
	return false;
}

/*TEST CASES*/
bool t1()
{
	//LL contains a single element
	node * head=NULL;
	insert_node(&head,4);
	if(!isPalindrome(head,1))return false;
}
bool t2()
{
	//LL contains even number of elements and is not a palindrome
	node * head=NULL;
	insert_node(&head,4);
	insert_node(&head,44);
	if(isPalindrome(head,2))return false;
}
bool t3()
{
	//LL contains even number of elements and is a palindrome
	node * head=NULL;
	insert_node(&head,4);
	insert_node(&head,2);
	insert_node(&head,2);
	insert_node(&head,4);
	if(!isPalindrome(head,4))return false;
}
bool t4()
{
	//LL contains odd number of elements and is not a palindrome
	node * head=NULL;
	insert_node(&head,4);
	insert_node(&head,4);
	insert_node(&head,5);
	if(isPalindrome(head,3))return false;
}
bool t5()
{
	//LL contains odd number of elements and is a palindrome
	node * head=NULL;
	insert_node(&head,4);
	insert_node(&head,9);
	insert_node(&head,4);
	if(!isPalindrome(head,3))return false;
}
bool test()
{
	if(t1() && t2() && t3() && t4() && t5())
		return true;
	return false;
}
int main()
{
	int ele,len;
	cout<<"Enter the number of elements in the linked list:";
	cin>>len;
	if(len==0)
		cout<<"\nLinked list is empty";
	else
	{
		cout<<"\nEnter the elements in the linked list:";
		node* head=NULL;
		for(int i=0;i<len;++i)
		{
			cin>>ele;
			insert_node(&head,ele);		
		}
		if(isPalindrome(head,len))
			cout<<"\nIt is a palindrome";
		else
			cout<<"\nNot a palindrome";
	}
	
	return 0;
}
