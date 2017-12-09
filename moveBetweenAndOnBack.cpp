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

void moveBetweenAndOnBack(node *&head, int x, int y)
{
	node *p=head;
	
	int tab[5];
	int i=0;
	while(p->val!=x)
		p=p->next;

	node *p1=p;
	p=p->next;

	while(p->val!=y)
	{
		tab[i]=p->val;
		p1=p->next;
		delete p;
		p=p1;
		i++;
	}
	p=head;

	while(p->val!=x)
		p=p->next;

	p->next=p1;
	
	while(p1->next!=NULL)
		p1=p1->next;

	for(int a=0; a<i; a++)
	{
		node *p2=new node;
		p1->next=p2;
		p2->val=tab[a];
		p2->next=NULL;
		p1=p2;
	}
}

int main()
{
	node *head=NULL;

	push(head, 4);
	push(head, 1);
	push(head, 4);
	push(head, 3);
	push(head, 7);
	push(head, 9);
	push(head, 5);
	push(head, 8);
	push(head, 5);
	
	show(head);
	moveBetweenAndOnBack(head, 5, 4);
	show(head);

	system("pause");
}
