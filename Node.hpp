#pragma once

template <class T>
class Node {
private:
	T data; // Any data.
	Node* next; // Pointer to next node.
	Node* prev; // Pointer to previous node.

public:
	Node() {
		data = 0;
		next = nullptr;
		prev = nullptr;
	}

	~Node() {

	}

	void setData(T newData) {
		this->data = newData;
	}

	T getData() {
		return this->data;
	}

	void setNext(T newNext) {
		this->next = newNext;
	}

	T getNext() {
		return this->next;
	}

	void setPrev(T newPrev) {
		this->prev = newPrev;
	}

	T getPrev() {
		return this->prev;
	}
};
