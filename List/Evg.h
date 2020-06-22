#pragma once

#include <iostream>
#include <stdio.h>
#include "Train.h"

template<typename K>

struct Node {

	K _data;

	Node<K>* _next;

	Node(K data, Node<K>* next) 
	{
		_data = data;
		_next = next; 
	};

	Node() {

		_next = NULL;

	}

};

template<typename T>

class List {

private:

	Node<T>* head;

public:

	List() 
	{

		head = new Node<T>();

	}

	~List() {

		while (head->_next) {

			del(head->_next);

		}

		delete head;

	}

	void del(Node<T>* ptr) {

		if (ptr) {

			Node<T>* iter = head;

			while (iter->_next && iter->_next != ptr) {

				iter = iter->_next;

			}

			if (iter->_next) {

				iter->_next = ptr->_next;

				delete ptr;

			}

		}

	}

	bool isEmpty() {

		return head->_next == NULL;

	}

	List(T* t, int n) {

		head = new Node<T>();

		Node<T>* temp = nullptr;

		Node<T>* ptr = nullptr;

		for (int i = 0; i < n; i++)

		{

			temp = new Node<T>(t[i], NULL);

			if (head->_next == NULL) {

				head->_next = temp;

				ptr = temp;

			}

			else {

				if (ptr) {

					ptr->_next = temp;

				}

			}

			ptr = temp;

		}

	}

	List(const List& list) {

		head = new Node<T>();

		Node<T>* temp = nullptr;

		Node<T>* ptr = nullptr;

		for (Node<T>* i = list.head->_next; i; i = i->_next)

		{

			temp = new Node<T>(i->_data, NULL);

			if (head->_next == NULL) {

				head->_next = temp;

				ptr = temp;

			}

			else {

				if (ptr) {

					ptr->_next = temp;

				}

			}

			ptr = temp;

		}

	}

	void addElementBegin(T& t) {

		Node<T>* newNode = new Node<T>(t, NULL);

		if (head->_next == NULL) {

			head->_next = newNode;

		}

		else {

			Node<T>* aux = head->_next;

			head->_next = newNode;

			newNode->_next = aux;

		}

	}

	void addElementEnd(T& t) {

		Node<T>* newNode = new Node<T>(t, NULL);

		if (head->_next == NULL) {

			head->_next = newNode;

		}

		else {

			Node<T>* iter = head->_next;

			while (iter->_next != NULL) {

				iter = iter->_next;

			}

			iter->_next = newNode;

		}

	}

	Node<T>* findElem(T& t) {

		Node<T>* iter = head->_next;

		while (iter != NULL && iter->_data != t) {

			iter = iter->_next;

		}

		return iter;

	}

	void delElem(T& t) {

		Node<T>* iter = head;

		while (iter->_next != NULL && iter->_next->_data != t) {

			iter = iter->_next;

		}

		if (iter->_next) {

			iter->_next = iter->_next->_next;

		}

	}

	void addElemInSortedList(T& t) {

		Node<T>* iter = head;

		Node<T>* newNode = new Node<T>(t, NULL);

		while (iter->_next != NULL && iter->_next->_data < t) {

			iter = iter->_next;

		}

		if (iter->_next) {

			Node<T>* aux = iter->_next;

			iter->_next = newNode;

			newNode->_next = aux;

		}

	}

	void insertSort() {

		Node<T>* iter1 = head->_next;

		Node<T>* iter2 = head;

		while (iter1->_next) {

			if (iter1->_data <= iter1->_next->_data) {

				iter1 = iter1->_next;

				continue;

			}

			iter2 = head;

			if (iter1->_next) {

				while (iter2->_next->_data < iter1->_next->_data) {

					iter2 = iter2->_next;

				}

				Node<T>* aux = iter1->_next->_next;

				iter1->_next->_next = iter2->_next;

				iter2->_next = iter1->_next;

				iter1->_next = aux;

			}

			else {

				iter1 = iter1->_next;

				return;

			}

		}

	}

	void deleteSequence() {

		Node<T>* iter = head;

		Node<T>* save = nullptr;

		while (iter->_next != NULL) {

			if (iter->_data == iter->_next->_data) {

				save = iter;

				iter = iter->_next;

				while (iter->_next != NULL && iter->_data == iter->_next->_data) {

					iter = iter->_next;

				}

				if (iter->_next != NULL) {

					save->_next = iter->_next;

				}

				else {

					save->_next = NULL;

					break;

				}

			}

			iter = iter->_next;

		}

	}

	friend std::ostream& operator<<(std::ostream& os, List& list) {

		if (list.head->_next != NULL) {

			Node<T>* iter = list.head->_next;

			while (iter != NULL) {

				os << iter->_data << std::endl;

				iter = iter->_next;

			}

		}

		return os;

	}

};