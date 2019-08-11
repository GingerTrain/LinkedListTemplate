#include "Node.hpp"
#include "SinglyTemplate.hpp"
#include "DoublyTemplate.hpp"

#include <iostream>
#include <memory>

void nodeTests() {
	std::cout << "--NODE TESTS--" << std::endl;;

	Node<int>* node = new Node<int>();
	Node<int>* node2 = new Node<int>();
	Node<int>* node3 = new Node<int>();
	std::shared_ptr<int> test1 = std::make_shared<int>(2);

	std::cout << "Data: ";
	node->setData(1);
	std::cout << node->getData() << std::endl;

	std::cout << "Next: ";
	node->setNext(std::make_shared<Node<int>>(*node2));
	std::cout << node->getNext() << std::endl;

	std::cout << "Prev: ";
	node->setPrev(std::make_shared<Node<int>>(*node3));
	std::cout << node->getPrev() << std::endl;
	
	std::cout << "Node: ";
	std::cout << node << std::endl;;

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
