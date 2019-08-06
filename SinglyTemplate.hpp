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
		Node<T> node = new Node<T>(data, NULL);

		if (index == 0) {
			node->next = head;
			head = node;

			return;
		}

		for (int i = 0; i <= index - 1; i++) {
			tmp = tmp->next;
		}

		if (tmp != NULL) {
			node->next = tmp->next;
			tmp->next = node;
		}

		//delete tmp;
		//delete node;
	}

	// Removes node at specified index
	void remove(T index) {
		
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
