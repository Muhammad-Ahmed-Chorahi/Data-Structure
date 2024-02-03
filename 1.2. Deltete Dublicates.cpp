#include<iostream>
using namespace std;
class node
{
public:
	int val;
	node* next;

	node(int data)
	{
		val = data;
		next = NULL;
	}
};

class linkedlist
{
public:
	node* head;
	
	linkedlist()
	{
		head = NULL;
	}

	void insertattail(int data)
	{
		node* new_node = new node(data);
		if (head == NULL)
		{
			head = new_node;
			return;
		}
		node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}

	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

void deletedublication(node*&head)
{
	node* current = head;
	node* temp = NULL;
	while (current != NULL)
	{
		while (current->next != NULL && current->val == current->next->val)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
		}
		current = current->next;
	}
}

int main()
{
	linkedlist ll;
	ll.insertattail(1);
	ll.insertattail(1);
	ll.insertattail(2);
	ll.insertattail(3);
	ll.insertattail(3);
	ll.insertattail(3);
	ll.insertattail(4);
	ll.insertattail(5);
	ll.insertattail(5);
	ll.insertattail(6);
	ll.insertattail(7);
	ll.insertattail(7);
	ll.display();
	deletedublication(ll.head);
	ll.display();
}
