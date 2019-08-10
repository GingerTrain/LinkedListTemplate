#include "Node.hpp"
#include "SinglyTemplate.hpp"
#include "DoublyTemplate.hpp"

#include <iostream>
#include <memory>

void nodeTests() {
	Node<int>* node = new Node<int>();
	Node<int>* node2 = new Node<int>();
	Node<int>* node3 = new Node<int>();
	std::unique_ptr<int> test1 = std::make_unique<int>(2);

	node->setData(1);
	std::cout << node->getData();

	node->setNext(std::make_unique<Node<int>>(node2));
	std::cout << node->getNext();

	node->setPrev(std::make_unique<Node<int>>(node3));
	std::cout << node->getPrev();

	std::cout << node;

	delete node;
	delete node2;
	delete node3;
}

void singlyTests() {

}

void doublyTests() {

}

int main() {
	nodeTests();
	singlyTests();
	doublyTests();

	return 0;
}
