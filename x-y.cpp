#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
}; 

void push(node *&head, int x)
{
	node *p=new node;
	p->val=x;
	p->next=head;
	head=p;

}
void show(node *&head)
{
	node *p=head;
	
	cout<<"Head->";

	while(p)
	{
		cout<<p->val;
		p=p->next;
		cout<<"->";
	}

	cout<<"NULL"<<endl;
}

void funkcja(node *&head, int x, int y)
{
	node *p=head;
	node *p3=head;
	
	//znajdowanie wart. x
	while(p->val!=x)
		p=p->next;

	p=p->next;

	while(p3->next!=NULL)
		p3=p3->next;

	while(p->val!=y)
	{
		p3->next=p;
		p->next=NULL;
		p3=p;
		delete p;
		p=p3;
		
	}



}

int main()
{
	node *head=NULL;

	push(head, 1);
	push(head, 4);
	push(head, 3);
	push(head, 7);
	push(head, 9);
	push(head, 5);
	push(head, 8);
	
	show(head);
	funkcja(head, 5, 4);
	show(head);

	system("pause");
}