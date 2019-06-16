#include<iostream>

using namespace std;

class List {
public:
	List();
	~List();

	void pop_front();
	
	void push_back(int data);

	void clear();
	
	int GetSize() { return Size; }

	int& operator[](const int index);

	void remove(int index);

	void remove_multi(List lst2);


	class Node
	{
	public:
		Node * pNext;
		int data;

		Node(int data = int(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;

	int getData(int x) const
	{
		Node *current;
		for (current = head; x > 0; x--)
			current = current->pNext;
		return current->data;
	}
};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List()
{
}


void List::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}



int & List::operator[](const int index)
{
	int counter = 0;

	Node *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


void List::remove(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

void List::remove_multi(List lst2) {
	for (int i = 0; i < GetSize(); i++)
	{
		for (int k = 0; k < lst2.GetSize(); k++)
		if (getData(i) == lst2.getData(k)){
			remove(i);
		}
	}
}
int main()
{
	List list1;

	//fill array

	for (int i = 0; i < 20; i++) {
		list1.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		list1.push_back(i);
	}
	for (int i = 0; i < 11; i++) {
		list1.push_back(i);
	}

	cout << "Show list" << endl;

	for (int i = 0; i < list1.GetSize(); i++) {
		cout << list1[i] << endl;
	}


	List mlst;
	for (int i = 0; i <= 5; i++) {
		mlst.push_back(i);
	}

	list1.remove_multi(mlst);

	cout << "Show list after deletion" << endl;
	
	for (int i = 0; i < list1.GetSize(); i++) {
		cout << list1[i] << endl;
	}

	system("pause");
	return 0;
}
