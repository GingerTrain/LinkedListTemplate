#pragma once

template <class T>
class Node {
	T data; // Any data.
	Node* next; // Pointer to next node.
	Node* prev; // Pointer to previous node.

public:
	Node(T data, Node* next, Node* prev) {
		data = data;
		next = next;
		prev = prev;
	}

	~Node() {

	}

	setData(T newData) {
		this.data = newData;
	}

	getData() {
		return this->data;
	}

	setNext(T newNext) {
		this.next = newNext;
	}

	getNext() {
		return this->next;
	}

	setPrev(T newPrev) {
		this.prev = newPrev;
	}

	getPrev() {
		return this->prev;
	}
};
