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

	void insert(int data)
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
		if (head == NULL)
		{
			cout << "List empty" << endl;
			return;
		}
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

void printReverse(node* head)
{
	if (head == NULL)
	{
		return;
	}
	printReverse(head->next);
	cout << head->val << " ";
}

int main()
{
	linkedlist l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.display();
	printReverse(l.head);
}