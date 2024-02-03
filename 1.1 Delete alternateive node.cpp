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

void deleteaternativenodes(node*& head)
{
	node* current = head;
	node* temp = NULL;
	while (current != NULL && current->next != NULL)
	{
		temp = current->next;
		current->next = current->next->next;
		free(temp);
		current = current->next;
	}
}

int main()
{
	linkedlist ll;
	ll.insertattail(10);
	ll.insertattail(20);
	ll.insertattail(30);
	ll.insertattail(40);
	ll.insertattail(50);
    //ll.insertattail(60);
	ll.display();
	deleteaternativenodes(ll.head);
	ll.display();
}







