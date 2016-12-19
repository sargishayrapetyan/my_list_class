#pragma once 

#include <stdexcept>
//#include "iterator.h"
#include "Node.h"
using std::cerr;

template <typename Nodetype>
class List
{
	public:

public:
	  List();
	  ~List();

public:
	  void push_front(const Nodetype&);
	  void push_back(const Nodetype&);

	  Nodetype& pop_back();
	  Nodetype& pop_front();

public:	  
	  bool isEmpty() const;
	  void print() const;
      unsigned size() const;

public:
	  void erase(Node<Nodetype>*);
      Node<Nodetype>* find(const Nodetype&) const;
	  void sort();
	  void merge(List&);
//	  bool reverse(List&);
//	  bool unique(List&);
//	  bool remove(List&);
private:
	  Node<Nodetype> *firstptr;
	  Node<Nodetype> *lastptr;
	  unsigned count;

};

template <typename Nodetype>
List<Nodetype>::List()
	: firstptr(nullptr),
	  lastptr(nullptr),
	  count(0)
{
	
}
template <typename Nodetype>
List<Nodetype>::~List()
{
	Node<Nodetype>* tmp = firstptr;
	while (tmp) {
		Node<Nodetype>* next = tmp->nextptr;
		delete tmp;
		tmp = next;
	}
	firstptr = nullptr;
	lastptr = nullptr;
}

template <typename Nodetype>
void List<Nodetype>::push_front(const Nodetype& value)
{
	if (isEmpty()) {
         Node<Nodetype>* newnode = new Node<Nodetype>(value);
		 firstptr = newnode;
		 lastptr = newnode;
	} else {
		Node<Nodetype>* newnode = new Node<Nodetype>(value);
		newnode->nextptr = firstptr;
		firstptr = newnode;
		newnode->nextptr->prevptr = firstptr;
	}
	++count;
}

template <typename Nodetype>
void List<Nodetype>::push_back(const Nodetype& value)
{
	if (isEmpty()) {
		Node<Nodetype>* newnode = new Node<Nodetype>(value);
		firstptr = newnode;
		lastptr = newnode;
	} else {
		Node<Nodetype>* newnode = new Node<Nodetype>(value);
		lastptr->nextptr = newnode;
		newnode->prevptr = lastptr;
		lastptr = newnode;
	}
	++count;
}

template <typename Nodetype>
bool List<Nodetype>::isEmpty() const
{
	return (count == 0);
}

template <typename Nodetype>
unsigned List<Nodetype>::size() const
{
	return count;
}

template <typename Nodetype>
Nodetype& List<Nodetype>::pop_front()
{
	if( count == 0 )
		std::cout << "list is empty" << std::endl;
	Node<Nodetype> *tempptr = firstptr;
	if( firstptr->nextptr != nullptr)
	{
		firstptr->nextptr->prevptr = nullptr;
	}
	firstptr = firstptr->nextptr;
	--count;
	return *tempptr;

}

template <typename Nodetype>
Nodetype& List<Nodetype>::pop_back()
{
	if( count == 0 )
		std::cout << "List is empty" << std::endl;
	Node<Nodetype> *tempptr = lastptr;
	if( lastptr->prevptr != nullptr )
	{
		lastptr->prevptr->nextptr == nullptr;
	}
	lastptr = lastptr->prevptr;
	--count;
	return *tempptr;
		
}

template <typename Nodetype>
void List<Nodetype>::erase(Node<Nodetype>* del_node)
{
	if( del_node == nullptr)
		std::cout << "list is empty or...." << std::endl;

	if( del_node == lastptr ){
		pop_back();
	}

	if(del_node == firstptr){
		pop_front();
	}

	Node<Nodetype>* p_next = del_node->nextptr;
	Node<Nodetype>* p_prev = del_node->prevptr;
	p_next->prevptr = p_prev;
	p_prev->nextptr = p_next;
	
	delete del_node;
	--count;


}

template <typename Nodetype>
Node<Nodetype>* List<Nodetype>::find(const Nodetype& elem) const
{
	if(count == 0){
		std::cout << "list is empty" << std::endl;
	}
	Node<Nodetype>* tempptr = firstptr;
	while(tempptr->data != elem){
		tempptr = tempptr->nextptr;
	}
	return tempptr;

}

template <typename Nodetype>
void List<Nodetype>::sort()
{
	Node<Nodetype>* tempptr = firstptr;
	while( tempptr->nextptr){
		if(tempptr->data > tempptr->nextptr.data){
			Nodetype temp = tempptr.data;
			tempptr->data = tempptr->nextptr.data;
				tempptr->nextptr.data = temp;
				tempptr = tempptr->nextptr;
				sort();
		} else tempptr = tempptr->nextptr;
			
	}
		
}

template <typename Nodetype>
void List<Nodetype>::print() const
{
	Node<Nodetype>* tempptr = firstptr;
	while(tempptr->nextptr){
		std::cout << tempptr->data << std::endl;
		tempptr = tempptr->nextptr;
	}
}

