#include<iostream>
using namespace std;
class stack
{
	int size, * array, top;
public:
	stack(int c)
	{
		size = c;
		array = new int[c];
		top = -1;
	}

	bool isEmpty()
	{
		return top == -1;
	}


	bool isFull()
	{
		return top == size - 1;
	}

	void push(int data)
	{
		if (isFull())
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			top++;
			array[top] = data;
		}
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow" << endl;
		}
		else
		{
			top--;
		}
	}

	void peek()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow" << endl;
		}
		else
		{
			cout << "Top is :" << array[top];
		}
	}
	
	~stack()
	{
		delete [] array;
	}
};


int main()
{
	int s, n, choice;
	cout << "Enter size of Stack :";
	cin >> s;
	stack s1(s);
	do
	{
		cout << "\n\nPress 1 to push." << endl;
		cout << "Press 2 to pop." << endl;
		cout << "Press 3 to peek." << endl;
		cout << "Press 4 to exit." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter data to push :";
			cin >> n;
			s1.push(s);
			break;

		case 2:
			s1.pop();
			break;

		case 3:
			s1.peek();
			break;

		case 4:
			cout << "Program Exit" << endl;
			break;
		default:
			cout << "Error! enter correct choice." << endl;
			break;
		}
	} while (choice!=4);
	s1.~stack();
}
