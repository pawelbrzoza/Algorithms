#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
}; 

void enqueue(node *&head, node*&tail, int x)
{
	node *p=new node;
	p->val=x;
	p->next=NULL;
	
	if(tail)
		tail->next=p;
	else
		head=p;
	tail=p;
	

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

void ostzpierw(node *&head, node *&tail)
{
	node *p=head;
	
	while(p->next->next)
		p=p->next;

	p->next=NULL;
	
	tail->next=head;
	head=tail;
	tail=p;
}

int main()
{
	node *head=NULL;
	node *tail=NULL;
	
	enqueue(head,tail,2);
	enqueue(head,tail,3);
	enqueue(head,tail,1);
	enqueue(head,tail,5);
	enqueue(head,tail,6);
	enqueue(head,tail,0);
	enqueue(head,tail,9);
	
	show(head);

	ostzpierw(head, tail);

	enqueue(head,tail,9);
	enqueue(head,tail,9);

	show(head);



	system("pause");
}