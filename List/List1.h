#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
private:

	template<typename T>
	class Node
	{
	public:
		Node* next;
		T data;
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	int size;
	Node<T>* head;

public:
	List();				  //�����������


	List(const List& a);  //�����������


	~List(); //����������



	//void pop_front();	

	template<typename T>
	inline void pop_front()		//������� ���� ������� �� ������ ������
	{
		Node<T>* tmp = head;
		head = head->next;
		delete tmp;
		size--;

	}


	//void push_back(T data);		

	template<typename T>
	inline void push_back(T data)			//��������� � ������ ������� data ���� T � ����� ������
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

	//void clear();	
	template<typename T>
	inline void clear()						//������� ���� ������
	{
		while (size)
			pop_front();
	}

	int GetSize() { return size; };			//�������� ����� ������



	//List& operator=(const List& a);
	T& operator[](const int index);			//�������� ������� �� ������ "index"


	void push_front(T data);				//��������� � ������ ������� data ���� T � ������ ������


	void insert(T data, int index);			//��������� ������� data ���� T �� ������/����� "index"


	void removeAt(int index);				//������� ������� �� ������/����� "index"


	void pop_back();						//������� ���� ������� �� ����� ������






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
	//cout<<"Clear\n";
	clear();
}
//
//template<typename T>
//inline void List<T>::push_back(T data)
//{
//	if (head == nullptr)
//		head = new Node<T>(data);
//	else
//	{
//		Node<T>* current = this->head;
//		while (current->next != nullptr)
//			current = current->next;
//
//		current->next = new Node<T>(data);
//	}
//	size++;
//}


//template<typename T>
//List<T>& List<T>::operator=(const List& a)
//{
//	this->size = a.size;
//	this->head = a.head;
//	return *this;
//}

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

//template<typename T>
//inline void List<T>::pop_front()
//{
//	Node<T> *tmp = head;
//	head = head->next;
//	delete tmp;
//	size--;
//
//}

//template<typename T>
//inline void List<T>::clear()
//{
//	while (size)
//		pop_front();
//}

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

template<typename T>
inline List<T>::List(const List& a)
{
	size = a.size;
	head = a.head;
}