#pragma once

template <typename Nodetype>
class List;

template <typename Nodetype>
class Node
{
	friend class List<Nodetype>;
public:
	Node(const Nodetype& data);
	Node(const Node&);

	Nodetype getdata() const;

public:
	Nodetype data;
	Node<Nodetype> *nextptr;
	Node<Nodetype> *prevptr;

};

template <typename Nodetype>
Node<Nodetype>::Node(const Nodetype& d)
	: data(d)
	, nextptr(nullptr)
	, prevptr(nullptr)
{
}

template <typename Nodetype>
Node<Nodetype>::Node(const Node& otherNode)
{
	data = otherNode.data;
	if (otherNode.nextptr) {
		nextptr = new Node<Nodetype>(*otherNode.nextptr);
	}
	if (otherNode.prevptr) {
		prevptr = new Node<Nodetype>(*otherNode.prevptr);
	}
}

template <typename Nodetype>
Nodetype Node<Nodetype>::getdata() const
{
	return data;
}


