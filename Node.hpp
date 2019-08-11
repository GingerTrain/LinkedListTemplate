#pragma once
#include <memory>

template <class T>
class Node {
private:
	T data; // Any data.
	std::shared_ptr<Node> next; // Pointer to next node.
	std::shared_ptr<Node> prev; // Pointer to previous node.

public:
	Node() : data(0), next(nullptr), prev(nullptr) {
	
	}

	~Node() {

	}

	void setData(T newData) {
		this->data = newData;
	}

	T getData() {
		return this->data;
	}

	void setNext(std::shared_ptr<Node> newNext) {
		this->next = newNext;
	}

	std::shared_ptr<Node> getNext() {
		return this->next;
	}

	void setPrev(std::shared_ptr<Node> newPrev) {
		this->prev = newPrev;
	}

	std::shared_ptr<Node> getPrev() {
		return this->prev;
	}
};
