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

class stack
{
public:
	node* top;

	stack()
	{
		top = NULL;
	}

	bool isempty()
	{
		return top == NULL;
	}

	//insert at top of stack
	void push(int data)
	{
		node* new_node = new node(data);
		if (isempty())
		{
			top = new_node;
			return;
		}
		new_node->next = top;
		top = new_node;
	}

	//delete from top of the stack
	void pop()
	{
		if (isempty())
		{
			cout << "Stack underflow" << endl;
			return;
		}
		node* temp = top;
		top = top->next;
		free(temp);
	}

	//display the top of stack
	void peek()
	{
		if (isempty())
		{
			cout << "Stack underflow" << endl;
			return;
		}
		cout << "Top :" << top->val << endl;
	}

	//dislay the whole stack
	void display()
	{
		node* temp = top;
		if (isempty())
		{
			cout << "Stack underflow" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	
};

int main()
{
	stack s;
	int choice, data;
	cout << "1. To Push" << endl;
	cout << "2. To Pop" << endl;
	cout << "3. To Peek" << endl;
	cout << "4. To Display" << endl;
	cout << "0. To exit" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter Data to push :";
			cin >> data;
			s.push(data);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.peek();
			break;
		case 4:
			s.display();
			break;
		case 0:
			cout << "Program Exit" << endl;
			break;
		default:
			cout << "Error! Enter Correct Choice" << endl;
		}
	} while (choice != 0);
}