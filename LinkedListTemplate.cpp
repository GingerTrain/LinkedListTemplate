#include "Node.hpp"
#include "SinglyTemplate.hpp"
#include "DoublyTemplate.hpp"

#include <iostream>
#include <memory>

void nodeTests() {
	std::cout << "--NODE TESTS--" << std::endl;

	Node<int>* node = new Node<int>();
	Node<int>* node2 = new Node<int>();
	Node<int>* node3 = new Node<int>();
	Node<std::shared_ptr<int>>* node4 = new Node<std::shared_ptr<int>>();
	Node<char>* node5 = new Node<char>();
	//Node<std::unique_ptr<int>>* node6 = new Node<std::unique_ptr<int>>();

	std::cout << "Node Data: ";
	node->setData(1);
	node2->setData(2);
	node3->setData(3);
	node4->setData(std::make_shared<int>(42));
	node5->setData('T');
	//node6->setData(std::make_unique<int>(42));
	std::cout << node->getData() << std::endl;

	std::cout << "Next: ";
	node->setNext(std::make_shared<Node<int>>(*node2));
	std::cout << node->getNext() << std::endl;

	std::cout << "Next Data: ";
	node2->setData(4);	// Should it output 4 or 2?
	std::cout << node->getNext()->getData() << std::endl;

	std::cout << "Prev: ";
	node->setPrev(std::make_shared<Node<int>>(*node3));
	std::cout << node->getPrev() << std::endl;

	std::cout << "Prev Data: ";
	std::cout << node->getPrev()->getData() << std::endl;
	
	std::cout << "Node: ";
	std::cout << node << std::endl;

	delete node;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
}

void singlyTests() {
	std::cout << std::endl << "--SINGLY TESTS--" << std::endl;

	SinglyTemplate<int>* llist = new SinglyTemplate<int>();

	llist->insert(1, 0);
	llist->insert(2, 1);
	llist->insert(3, 2);
	llist->insert(4, 0);
	llist->insert(5, 5);	// Should fail
	llist->insert(5, -1);	// Should fail

	llist->traverse();

	llist->remove(0);
	llist->remove(3);	// Should fail
	llist->remove(-1);	// Should fail
	llist->remove(2);

	llist->traverse();

	llist->getNode(0)->getData();
	llist->getNode(2); // Should fail
	//llist->getNode(2)->getData();
	llist->getNode(-1); // Should fail
	llist->getNode(1)->getData();

	llist->update(4, 0);
	llist->update(2, 2); // Should fail
	llist->update(2, -1); // Should fail
	llist->update(5, 1);

	llist->traverse();

	std::cout << "Head: ";
	std::cout << llist->getHead() << std::endl;

	std::cout << "Tail: ";
	std::cout << llist->getTail() << std::endl;

	std::cout << "Length: ";
	std::cout << llist->getLength() << std::endl;

	std::cout << "LList: ";
	std::cout << llist << std::endl;

	delete llist;
}

void doublyTests() {

}

int main() {
	nodeTests();
	singlyTests();
	doublyTests();

	return 0;
}
