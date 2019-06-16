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

	//append
	int first1 = 192; 
	int second1 = 70;
	int third1 = 0;
	int fourth1 = 1;

	IP.append(IPv4(first1, second1, third1, fourth1));
	IP.append(IPv4(first1, second1, third1, fourth1));
	IP.append(IPv4(first1, second1, third1, fourth1));
	IP.append(IPv4(first1, second1, third1, fourth1));
	IP.append(IPv4(first1, second1, third1, fourth1));

	cout << "IP: " << first1 << "." << second1 << "." << third1 << "." << fourth1<< endl;

	//insert
	int first2 = 193;
	int second2 = 23;
	int third2 = 0;
	int fourth2 = 2;

	int index2 = 0;

	IP.insert(IPv4(first2, second2, third2, fourth2), index2);
	
	cout << "IP: " << first2 << "." << second2 << "." << third2 << "." << fourth2 << endl;

	//remove
	int remove_index = 1;

	IP.remove(remove_index);

	int index3 = 0;
	//get element by index
	cout << "Element index = 0: " << IP[0];

	//get length
	cout << "List lenght: " << IP.lenght() << endl;

	//print list
	cout << "IP list" << endl;
	for (int i = 0; i < IP.lenght(); i++) {
		cout << IP[i] << endl;
	}

	system("pause");
	return 0;
}
