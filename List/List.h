#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();  //конструктор
	//List(const List& a);  //конструктор
	~List(); //деструктор
	void  copy(List<T>& a);

	void pop_front();						//удалить один элемент из начала списка
	void push_back(T data);					//загрузить в список элемент data типа T в конец списка
	void clear();							//удалить весь список
	int GetSize() { return size; };			//получить длину списка


	List& operator=(List& a);
	T& operator[](const int index);			//получить элемент по номеру "index"


	void push_front(T data);				//загрузить в список элемент data типа T в начало списка
	void insert(T data, int index);			//загрузить элемент data типа T по номеру/метке "index"
	void removeAt(int index);				//удалить элемент по номеру/метке "index"
	void pop_back();						//удалить один элемент из конца списка

	void insert_sort();
	
	Node& operator=(Node& a)
	{
		this->data = a.data;
		this->Next = a.Next;
		return *this;
	}




private:
	

	template<typename T>
	class Node
	{
	public:
		Node* next;
		T data;
		Node(T data=T(), Node *next=nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	int size;
	Node<T> *head;
};

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
inline List<T>::~List()
{
	clear();
}

template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == nullptr)
		head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;
		while (current->next != nullptr)
			current = current->next;

		current->next = new Node<T>(data);
	}
	size++;
}



template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}

		current = current->next;
		counter++;
	}
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T> *tmp = head;
	head = head->next;
	delete tmp;
	size--;

}

template<typename T>
inline void List<T>::clear()
{
	while (size)
		pop_front();
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	size++;
}

template<typename T>
inline void List<T>::insert(T data, int index)
{
	if (index == 0)
		push_front(data);
	else
	{
		Node<T> *prev = this->head;
		for (int i = 0; i < index - 1; i++)
			prev = prev->next;

		Node<T>* newNode = new Node<T>(data, prev->next);
		prev->next = newNode;

		size++;
	}

}

template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T> *prev = this->head;
		for (int i = 0; i < index - 1; i++)
			prev = prev->next;

		Node<T> *toDelete = prev->next;
		prev->next = toDelete->next;
		delete toDelete;
		size--;

	}
}

template<typename T>
inline void List<T>::pop_back()
{
	removeAt(size-1);
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
template<typename T>
inline void List<T>::copy(List<T>& a)
{
	this->clear();
	int leight = a.GetSize();
	for (int i = 0; i < leight; i++)
	{
		T b = a[i];
		this->push_back(b);
	}
}

template<typename T>
inline List<T>& List<T>::operator=(List<T>& a)
{
	this->copy(a);
	return *this;
}

template<typename T>
inline void List<T>::insert_sort()
{
	Node<T>* iter1 = head->next;
	Node<T>* iter2 = head;

	while (iter1->next) 
	{
		if (iter1->data <= iter1->_next->data) 
		{
			iter1 = iter1->next;
			continue;
		}

		iter2 = head;

		if (iter1->_next) 
		{
			while (iter2->_next->_data < iter1->_next->_data) 
				iter2 = iter2->_next;

			Node<T>* aux = iter1->next->next;
			iter1->next->next = iter2->next;
			iter2->next = iter1->next;
			iter1->next = aux;
		}
		else 
		{
			iter1 = iter1->next;
			return;
		}

	}
}