#include<iostream>
using namespace std;

class node
{
public:
	node* next;
	int val;

	node(int data)
	{
		val = data;
		next = NULL;
	}
};

class queue
{
public:
	node* front, * back;

	queue()
	{
		front = back = NULL;
	}

	bool isempty()
	{
		return front == NULL;
	}

	//insert in the end of the queue
	void enqueue(int data)
	{
		node* new_node = new node(data);
		if (isempty())
		{
			front = back = new_node;
			return;
		}
		back->next = new_node;
		back = new_node;
	}

	//delete from the front of the queue
	void dequeue()
	{
		if (isempty())
		{
			cout << "Queue under flow" << endl;
			return;
		}
		node* temp = front;
		front = front->next;
		free(temp);
	}

	void display()
	{
		if (isempty())
		{
			cout << "Queue under flow" << endl;
			return;
		}
		node* temp = front;
		while (temp != NULL)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	queue q;
	int choice, data;
	cout << "1. Enqueue" << endl;
	cout << "2. Dequeue" << endl;
	cout << "3. Display" << endl;
	cout << "0. Exit" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the data you want to enqueue :";
			cin >> data;
			q.enqueue(data);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.display();
			break;
		case 0:
			cout << "Program Exit" << endl;
			break;
		default:
			cout << "Error! Enter Correct Choice" << endl;
			break;
		}
	} while (choice != 0);
}