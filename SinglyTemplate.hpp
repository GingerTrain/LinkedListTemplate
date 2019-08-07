#pragma once
#include "Node.hpp"

template <class T>
class SinglyTemplate {
	T *head; // First node in list.
	T *tail; // Last node in list.

public:
	SinglyTemplate() {
		head = nullptr;
		tail = nullptr;
	}

	~SinglyTemplate() {

	}

	// Inserts node at specified index
	void insert(T index, T data) {
		Node<T> tmp = head;
		Node<T> node = new Node<T>();

		if (index == 0) {
			node.setNext(head);
			head = node;

			return;
		}

		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}

		if (tmp != NULL) {
			node.setNext(tmp->next);
			tmp->next = node;
		}

		delete node;
	}

	// Removes node at specified index
	void remove(T index) {
		Node<T> tmp = head;
		Node<T> prev = NULL;

		if (index == 0) {
			head = head->next;

			return;
		}

		for (int i = 0; i < index - 1; i++) {
			prev = tmp;
			tmp = tmp->next;
		}

		if (tmp != NULL) {
			prev->next = tmp->next;
		}
	}

	// Returns node at specified index
	Node<T> getNode(T index) {	
		
	}

	// Updates node at specified index
	void update(T index, T data) {	
	
	}

	// Reverses linked list
	void reverse() {

	}
};
