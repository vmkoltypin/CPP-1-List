#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();  //�����������
	~List(); //����������

	void pop_front();						//������� ���� ������� �� ������ ������
	void push_back(T data);					//��������� � ������ ������� data ���� T � ����� ������
	void clear();							//������� ���� ������
	int GetSize() { return size; };			//�������� ����� ������
	T& operator[](const int index);			//�������� ������� �� ������ "index"
	void push_front(T data);				//��������� � ������ ������� data ���� T � ������ ������
	void insert(T data, int index);			//��������� ������� data ���� T �� ������/����� "index"
	void removeAt(int index);				//������� ������� �� ������/����� "index"
	void pop_back();						//������� ���� ������� �� ����� ������



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
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	//cout<<"Clear\n";
	clear();
}

template<typename T>
void List<T>::push_back(T data)
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
T& List<T>::operator[](const int index)
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
void List<T>::pop_front()
{
	Node<T> *tmp = head;
	head = head->next;
	delete tmp;
	size--;

}

template<typename T>
void List<T>::clear()
{
	while (size)
		pop_front();
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
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
void List<T>::removeAt(int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* prev = this->head;
		for (int i = 0; i < index - 1; i++)
			prev = prev->next;

		Node<T> *toDelete = prev->next;
		prev->next = toDelete->next;
		delete toDelete;
		size--;

	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size-1);
}