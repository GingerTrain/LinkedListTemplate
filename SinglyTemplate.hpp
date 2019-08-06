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

	void add(T index, T data) {	// Inserts node at specified index
		
	}

	void remove(T index) {	// Removes node at specified index

	}

	Node<T> getNode(T index) {	// Returns node at specified index

	}

	void update(T index, T data) {	// Updates node at specified index
	
	}

	void reverse() {	// Reverses linked list

	}
};
