#pragma once
#include "Node.hpp"

#include <memory>
#include <iostream>

template <class T>
class SinglyTemplate {
private:
	std::shared_ptr<Node<T>> head; // First node in list.
	std::shared_ptr<Node<T>> tail; // Last node in list.
	int length;	// Length of list.

public:
	SinglyTemplate() : head(nullptr), tail(nullptr), length(0) {
	
	}

	// Iterate through list and remove nodes one by one.
	void clean() {
		while (head) {
			head = head->getNext();
		}
	}

	~SinglyTemplate() {
		clean();
	}

	void setHead(std::shared_ptr<Node<T>> newHead) {
		this->head = newHead;
	}

	std::shared_ptr<Node<T>> getHead() {
		return this->head;
	}

	void setTail(std::shared_ptr<Node<T>> newTail) {
		this->tail = newTail;
	}

	std::shared_ptr<Node<T>> getTail() {
		return this->tail;
	}

	int getLength() {
		return this->length;
	}

	// Returns node at specified index.
	Node<T> getNode(T index) {

	}
	
	// Creates node and inserts it at specified index.
	void insert(T data, int index) {
		std::shared_ptr<Node<T>> tmp = head;
		Node<T>* node = new Node<T>();
		node->setData(data);

		this->length++;

		if (index == getLength() || index < 0) {
			std::cout << "Index: ";
			std::cout << index;
			std::cout << " Length: ";
			std::cout << length << std::endl;

			this->length--;

			delete node;
			
			//throw std::out_of_range("Index not in range of list.");
			return;
		}

		if (index == 0) {
			node->setNext(head);
			setHead(std::make_shared<Node<T>>(*node));

			return;
		}
		
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->getNext();
		}

		if (tmp != 0) {
			node->setNext(tmp->getNext());
			tmp->setNext(std::make_shared<Node<T>>(*node));

			setTail(tmp->getNext());
		}

		delete node;
	}

	// Removes node at specified index.
	void remove(T index) {
		Node<T> tmp = head;
		Node<T> prev = 0;

		this->length--;

		if (index == 0) {
			head = head->next;

			return;
		}

		for (int i = 0; i < index - 1; i++) {
			prev = tmp;
			tmp = tmp->next;
		}

		if (tmp != 0) {
			prev->next = tmp->next;
		}
	}

	// Updates node at specified index.
	void update(T data, T index) {

	}

	// Reverses the linked list.
	void reverse() {

	}

	// Traverse linked list and output each node and its data.
	void traverse() {
		std::shared_ptr<Node<T>> tmp = head;

		while (tmp != 0) {
			std::cout << "Node: ";
			std::cout << tmp << std::endl;
			std::cout << "Node Data: ";
			std::cout << tmp->getData() << std::endl;

			tmp = tmp->getNext();
		}
	}
};
