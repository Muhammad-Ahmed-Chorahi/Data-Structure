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

void insertathead(node*& head, int val)
{
	node* newnode = new node(val);
	newnode->next = head;
	head = newnode;
}

void insertattail(node*& head, int val)
{
	node* new_node = new node(val);
	node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

void insertatposition(node*& head, int val, int pos)
{
	if (pos == 0)
	{
		insertathead(head, val);
		return;
	}
	node* new_node = new node(val);
	node* temp = head;
	int current_pos = 0;
	while (current_pos != pos - 1)
	{
		temp = temp->next;
		current_pos++;
	}
	new_node->next = temp->next;
	temp->next = new_node;
}

void display(node* head)
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void updateatpostion(node*& head, int val, int pos)
{
	node* temp = head;
	int current_pos = 0;
	while (current_pos != pos)
	{
		temp = temp->next;
		current_pos++;
	}
	temp->val = val;
}

void deletefromhead(node*& head)
{
	node* temp = head;
	head = head->next;
	free(temp);
}

void deletefromtail(node*& head)
{
	node* second_last = head;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	node* temp = second_last->next;
	second_last->next = NULL;
	free(temp);
}

void deletefromposition(node*& head, int pos)
{
	if (pos == 0)
	{
		deletefromhead(head);
		return;
	}
	int current_pos = 0;
	node* prev = head;
	while (current_pos != pos - 1)
	{
		prev = prev->next;
		current_pos++;
	}
	node* temp = prev->next;
	prev->next = prev->next->next;
	free(temp);
}

int main()
{
	node* head = NULL;
	int data, choice, position;
	do
	{
		cout << "Press 1 to Insert at head" << endl;
		cout << "Press 2 to Insert at tail" << endl;
		cout << "Press 3 to Insert at position" << endl;
		cout << "Press 4 to Update at position" << endl;
		cout << "Press 5 to Diplay" << endl;
		cout << "Press 6 to Delete from head" << endl;
		cout << "Press 7 to Delete from tail" << endl;
		cout << "Press 8 to Delete from position" << endl;
		cout << "Press 0 to exit" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			cout << "Enter the data you want to inset : ";
			cin >> data;
			insertathead(head, data);
			break;
		case 2:
			cout << "Enter the data you want to inset : ";
			cin >> data;
			insertattail(head, data);
			break;
		case 3:
			cout << "Enter the data you want to insert : ";
			cin >> data;
			cout << "Enter the position at you want to insert :";
			cin >> position;
			insertatposition(head, data, position);
			break;
		case 4:
			cout << "Enter the data you want to insert : ";
			cin >> data;
			cout << "Enter the position at you want to update :";
			cin >> position;
			updateatpostion(head, data, position);
			break;
		case 5:
			display(head);
			break;
		case 6:
			deletefromhead(head);
			break;
		case 7:
			deletefromtail(head);
			break;
		case 8:
			cout << "Enter the position at you want to delete :";
			cin >> position;
			deletefromposition(head, position);
		case 0:
			cout << "Program Exit" << endl;
			break;
		default:
			cout << "Error! Wrong choice" << endl;
			break;
		}
	} while (choice!=0);
}