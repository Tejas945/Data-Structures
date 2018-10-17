#include<iostream>
#ifndef NODE_H_
#define NODE_H_

using namespace std;
struct node
{
	int data;
	node *next;
};
class list
{
		private:
		node *head, *tail;
		public:
		list()  //Constructor
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(int value)
		{
			node *temp=new node;  //pointer temp is pointing to new node
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)   //if node is empty, head=tail
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		void insert_start(int value)
		{
			node *temp=new node;
			temp->data=value;  //initialize data
			temp->next=head;  //the next points to address of head
			head=temp;
		}
		void insert_position(int pos, int value)
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=value;
			pre->next=temp;
			temp->next=cur;
		}
		void delete_first()
		{
			node *temp=new node;
			temp=head;
			head=head->next; //the new head is stored in head
			delete temp;
		}
		void delete_last()  //two pointer approach used
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			while(current->next!=NULL)
			{
				previous=current;
				current=current->next;
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
};

#endif /* NODE_H_ */
