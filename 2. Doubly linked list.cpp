#include<iostream>
using namespace std;
class node
{
public:
	int val;
	node* next, * prev;

	node(int data)
	{
		val = data;
		next = prev = NULL;
	}
};

class doublylinkedlist
{
public:
	node* head, * tail;

	doublylinkedlist()
	{
		head = tail = NULL;
	}

	bool isempty()
	{
		return head == NULL;
	}

	void insertathead(int data)
	{
		node* new_node = new node(data);
		if (isempty())
		{
			head = tail = new_node;
			return;
		}
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}

	void insertattail(int data)
	{
		node* new_node = new node(data);
		if (isempty())
		{
			head = tail = new_node;
			return;
		}
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}

	void insertatpostion(int data,int pos)
	{
		node* temp = head;;
		node* new_node = new node(data);
		int curr_pos = 0;
		while (curr_pos != pos-1)
		{
			temp = temp->next;
			curr_pos++;
		}
		new_node->next = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
		new_node->next->prev = new_node;
	}

	void deletefromhead()
	{
		if (isempty())
		{
			cout << "Linked list empty" << endl;
			return;
		}
		node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete(temp);
	}

	void deletefromtail()
	{
		if (isempty())
		{
			cout << "Linked list empty" << endl;
			return;
		}
		node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete(temp);
	}

	void deletefromposition(int pos)
	{
		node* temp = head;
		int curr_pos = 0;
		while (curr_pos != pos)
		{
			temp = temp->next;
			curr_pos++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete(temp);
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

int main()
{
	doublylinkedlist l;
	int choice, data, pos;
	cout << "1. To Insert at head" << endl;
	cout << "2. To Insert at tail" << endl;
	cout << "3. To Insert at poition" << endl;
	cout << "4. To delete from head" << endl;
	cout << "5. To delete from tail" << endl;
	cout << "6. To delete from position" << endl;
	cout << "9. To Display" << endl;
	cout << "0. To Exit" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter data you want to insert :";
			cin >> data;
			l.insertathead(data);
			break;
		case 2:
			cout << "Enter data you want to insert :";
			cin >> data;
			l.insertattail(data);
			break;
		case 3:
			cout << "Enter data you want to insert :";
			cin >> data;
			cout << "Enter the postion a which you want to insert :";
			cin >> pos;
			l.insertatpostion(data, pos);
			break;
		case 4:
			l.deletefromhead();
			break;
		case 5:
			l.deletefromtail();
			break;
		case 6:
			cout << "Enter the position you want to delete :";
			cin >> pos;
			l.deletefromposition(pos);
			break;
		case 9:
			cout << "\n\t******Display*****" << endl;
			l.display();
			break;
		case 0:
			cout << "\nProgram End" << endl;
			break;
		default:
			cout << "Error! Enter Correct Choice" << endl;
			break;
		}
	} while (choice!=0);
}
