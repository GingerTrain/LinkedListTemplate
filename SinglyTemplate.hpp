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
	std::shared_ptr<Node<T>> getNode(T index) {
		std::shared_ptr<Node<T>> tmp = getHead();

		if (index == getLength() || index < 0) {
			std::cout << "Can't get node at non-existant index." << std::endl;

			//throw std::out_of_range("Index not in range of list.");
			return nullptr;
		}

		for (int i = 0; i < index; i++) {
			tmp = tmp->getNext();
		}

		return tmp;
	}
	
	// Creates node and inserts it at specified index.
	void insert(T data, int index) {
		std::shared_ptr<Node<T>> tmp = getHead();
		Node<T>* node = new Node<T>();
		node->setData(data);

		this->length++;

		if (index == getLength() || index < 0) {
			std::cout << "Can't insert to non-existant index." <<std::endl;

			this->length--;

			delete node;
			
			//throw std::out_of_range("Index not in range of list.");
			return;
		}

		if (index == 0) {
			node->setNext(getHead());
			setHead(std::make_shared<Node<T>>(*node));

			return;
		}
		
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->getNext();
		}

		if (tmp) {
			node->setNext(tmp->getNext());
			tmp->setNext(std::make_shared<Node<T>>(*node));

			setTail(tmp->getNext());
		}

		delete node;
	}

	// Removes node at specified index.
	void remove(T index) {
		std::shared_ptr<Node<T>> tmp = getHead();
		std::shared_ptr<Node<T>> prev = 0;

		if (index == getLength() || index < 0 || getLength() <= 0) {
			std::cout << "Can't remove non-existant index." << std::endl;

			//throw std::out_of_range("Index not in range of list.");
			return;
		}

		this->length--;

		if (index == 0) {
			setHead(head->getNext());

			return;
		}

		for (int i = 0; i < index; i++) {
			prev = tmp;
			tmp = tmp->getNext();
		}

		if (tmp) {
			prev->setNext(tmp->getNext());
		}
	}

	// Updates node at specified index.
	void update(T data, T index) {
		std::shared_ptr<Node<T>> tmp = getHead();

		if (index == getLength() || index < 0) {
			std::cout << "Can't update node at non-existant index." << std::endl;

			//throw std::out_of_range("Index not in range of list.");
			return;
		}

		for (int i = 0; i < index; i++) {
			tmp = tmp->getNext();
		}

		tmp->setData(data);
	}

	// Reverses the linked list.
	void reverse() {

	}

	// Traverse linked list and output each node and its data.
	void traverse() {
		std::shared_ptr<Node<T>> tmp = head;

		while (tmp) {
			std::cout << "Node: ";
			std::cout << tmp << std::endl;
			std::cout << "Node Data: ";
			std::cout << tmp->getData() << std::endl;

			tmp = tmp->getNext();
		}
	}
};
