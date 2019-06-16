#include<iostream>

using namespace std;

class IPv4 {
public:

	int firstoctet;
	int secondoctet;
	int thirdoctet;
	int fourthoctet;

	IPv4() {
	}
	
	IPv4(int firstoctet,int secondoctet,int thirdoctet,int fourthoctet) {
		this->firstoctet = firstoctet;
		this->secondoctet = secondoctet;
		this->thirdoctet = thirdoctet;
		this->fourthoctet = fourthoctet;
	}
};

template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front(); //Âèäàëåííÿ ïåðøîãî åëåìåíòó

	void append(T data); //äîäàâàííÿ åëåìåíòó â êiíåöü ñïèñêó

	int lenght() { return Size;} //äîâæèíà ñïèñêó

	T& operator[](const int index); //äîñòóï äî åëåìåíòó çà iíäåêñîì

	void push_front(T data); //äîäàâàííÿ åëåìåíòó íà ïî÷àòîê ñïèñêó

	void insert(T data, int index); //äîäàâàííÿ åëåìåíòó çà iíäåêñîì

	void remove(int index); //âèäàëåííÿ åëåìåíòó çà iíäåêñîì

private:

	template<typename T>
	class Node {
	public:
		Node * pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};


template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List() {
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
void List<T>::pop_front() {
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::append(T data) {
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
T & List<T>::operator[](const int index) {
	int counter = 0;

	Node<T> *current = this->head;

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

template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index) {

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::remove(int index) {
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

ostream& operator<<(ostream& os, const IPv4& item) {

	os << item.firstoctet
		<< "." << item.secondoctet
		<< "." << item.thirdoctet
		<< "." << item.fourthoctet << endl;

return os;
}
int main() {
	List<IPv4> IP;
	bool back = false;
	while (!back) {
		cout << "Choose operation" << endl
			<< "Press 1 to add element" << endl
			<< "Press 2 to insert element by index" << endl
			<< "Press 3 to remove element by index" << endl
			<< "Press 4 to get element by index" << endl
			<< "Press 5 to get list lenght" << endl
			<< "Press 6 to show list" << endl;

		int choose;
		cin >> choose;

		switch (choose) {
		case 1:
			cout << "Please enter IP address" << endl;
			cout << "First octet: ";
			int first1;
			cin >> first1;
			cout << "Second octet: ";
			int second1;
			cin >> second1;
			cout << "Third octet: ";
			int third1;
			cin >> third1;
			cout << "Fouth octet: ";
			int fourth1;
			cin >> fourth1;
			
			IP.append(IPv4(first1, second1, third1, fourth1));

			cout << "Done! IP: " << first1 << "." << second1 << "." << third1 << "." << fourth1<< endl;
			break;
		case 2:
			cout << "Please enter IP address" << endl;
			cout << "First octet: ";
			int first2;
			cin >> first2;
			cout << "Second octet: ";
			int second2;
			cin >> second2;
			cout << "Third octet: ";
			int third2;
			cin >> third2;
			cout << "Fouth octet: ";
			int fourth2;
			cin >> fourth2;
			
			cout << "Enter index" << endl;
			int index2;
			cin >> index2;

			IP.insert(IPv4(first2, second2, third2, fourth2), index2);

			cout << "Done! IP: " << first2 << "." << second2 << "." << third2 << "." << fourth2 << endl;
			break;
		case 3:
			cout << "To remove element enter element index: ";
			int remove_index;
			cin >> remove_index;

			IP.remove(remove_index);

			cout << "Done!" << endl;
			break;
		case 4:
			cout << "To get element from list enter element index" << endl;
			int index3;

			cin >> index3;
			cout << IP[index3];
			break;
		case 5:
			cout << "List lenght: " << IP.lenght() << endl;
			break;
		case 6:
			cout << "IP list" << endl;
			for (int i = 0; i < IP.lenght(); i++) {
				cout << IP[i] << endl;
			}
			break;
		default:
			cout << "Try again" << endl;
			break;
		}

		cout << "Press any key to exit or 0 to back to menu" << endl;

		char choose_exit;
		cin >> choose_exit;

		if (choose_exit == '0') {
			back = false;
		}
		else {
			back = true;
		}
	}
	system("pause");
	return 0;
}
