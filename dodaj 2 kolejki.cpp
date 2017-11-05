#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
}; 


void enqueue(node *&head, node *&tail, int x)
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

void dodaj(node *&tail, node *&head2)
{
	if(tail && head2)
		tail->next=head2;

}
void dequeue(node *&head, node *&tail)
{
  if(head)
  {
    node *p = head;
    head = head->next;
	if(head==0)
		tail=NULL;
	delete p;
  }  
} 

int main()
{
	node *head=NULL;
	node *tail=NULL;
	node *head2=NULL;
	node *tail2=NULL;
	
	
	enqueue(head, tail, 4);
	enqueue(head, tail, 1);
	enqueue(head, tail, 2);
	enqueue(head, tail, 1);

	/*enqueue(head2, tail2, 5);
	enqueue(head2, tail2, 4);
	enqueue(head2, tail2, 9);
	enqueue(head2, tail2, 12);*/
	
	show(head);
	show(head2);

	dodaj(tail,head2);
	show(head);
	
	dequeue(head, tail);
	show(head);
	

	system("pause");
}