#pragma once 
#include "Node.h"

template <typename Nodetype>
class List;

template <typename Nodetype>
class iterator
{
friend class List<Nodetype>;
private:
	   Node<Nodetype>* iter_ptr;
public:
	   iterator(List<Nodetype>*);

public:
	  iterator& operator++();
	  iterator operator++(int); 
	  iterator& operator--();
	  iterator operator--(int);
	  Node<Nodetype>& operator*() const;
	  bool operator==(const iterator&);
	  bool operator!=(const iterator&);

public:
	  iterator begin() const;
	  iterator end() const;
};
	
template <typename Nodetype>
iterator::iterator(Node<Nodetype>* _iter_ptr)
	  : iter_ptr(_iter_ptr)
 {
 }
      
template <typename Nodetype>
iterator& iterator<Nodetype>::operator++()
{   
	if(iter_ptr == 0)
		cerr << "incremented an empty iterator" << std::endl;
     if(iter_ptr->nextptr == 0)
		 cerr <<"this is the end of List" << std::endl;

	return iter_ptr = iter_ptr->nextptr;
	
}

template <typename Nodetype>
List<Nodetype>::iterator iterator<Nodetype>::operator++(int x)
{
	iterator temp = *this;
	if(temp ==  0)
		cerr <<"incremented an empty iterator" << std::endl;
	if(temp->nexptr == 0)
		cerr <<" this is the end of List" << std::endl;

	++(*this)
	return temp;
}

template <typename Nodetype>
iterator& iterator::operator--()
{
	if(iter_ptr == 0)
		cerr<< "decremented an empty iterator" << std::endl;
    if(iter_ptr == prevptr == 0 )
		cerr << "this List is empty" << std::endl;
	      return iter_ptr = iter_ptr->prevptr;

}

template <typename Nodetype>
iterator iterator::operator--(int x)
{
	iterator temp = *this;
	if(temp ==  0)
		cerr <<"incremented an empty iterator" << std::endl;
	if(temp->nexptr == 0)
		cerr <<" this is the end of List" << std::endl;

	--(*this);
	return temp;
}

template <typename Nodetype>
Node<Nodetype>& iterator::operator*() const
{
	return *iter_ptr;
}

template <typename Nodetype>
bool iterator::operator==(const iterator& other)
{
	return iter_ptr == other.iter_ptr;
}

template <typename Nodetype>
bool iterator::operator!=(const iterator& other)
{
	return iter_ptr != other.iter_ptr;
}
