#ifndef DOUBLELL_HPP
# define DOUBLELL_HPP

# include <iostream>
# include <string>
# include "SharedPtr.hpp"
# include "WeakPtr.hpp"

using namespace SmartPointer;

template<class T>
struct Node {

	public:

		using SNodePtr = SharedPtr<Node<T>>;
		using WNodePtr = WeakPtr<Node<T>>;

		Node() = delete;
		Node(T data) : data(data) {
			while (next) {
				prev = next->next;
				next = prev.lock();
			}
		};
		Node(Node<T> const & src) = default;

		T			data;
		SNodePtr	next;
		WNodePtr	prev;

};

template<class T>
std::ostream &			operator<<( std::ostream & o, Node<T> & i ) {
	o << i.data;
	return o;
};

template<class T>
class DoubleLL
{

	public:

		using SNodePtr = SharedPtr<Node<T>>;
		using WNodePtr = WeakPtr<Node<T>>;

		DoubleLL() : size(0) {};
		~DoubleLL() {
			while (head) head = head->next;
		};

		SNodePtr &			begin() { return head; }
		SNodePtr &			end() { return tail.lock(); }
		SNodePtr const &	cbegin() const { return head; }
		SNodePtr const &	cend() const { return tail.lock(); }
		void			insertFront(T const & data) {
			Node<T>*	nPtr = new Node<T>(data);
			auto newNode = SNodePtr(nPtr);
			newNode->next = head;
			if (!head) {
				head = newNode;
				tail = newNode;
			}
			else {
				head->prev = newNode;
				head = newNode;
			}
			size++;
		}
		void			insertBack(T const & data) {
			if (!head) insertFront(data);
			else {
				Node<T>*	nPtr = new Node<T>(data);
				auto newNode = SNodePtr(nPtr);
				auto sPtr = tail.lock();
				sPtr->next = newNode;
				sPtr->prev = tail;
				tail = newNode;
			}
			size++;
		}
		void			insertAfter(SNodePtr prevNode, T const & insert) {
			if (!prevNode) throw std::invalid_argument();
			Node<T>*	nPtr = new Node<T>(insert);
			auto newNode = SNodePtr(nPtr);
			newNode->next = prevNode->next;
			prevNode->next = newNode;
			newNode->prev = prevNode;
			if (newNode->next)
				newNode->next->prev = newNode;
			size++;
		}
		void			deleteFirst() {
			auto sPtr = head;
			head = head->next;
			sPtr = nullptr;
			size--;
		}
		void			deleteLast() {
			auto wPtr = tail;
			tail = tail->prev;
			wPtr.reset();
			size--;
		}
		void			deleteAt(T const & data) {
			auto sPtr = head;
			while (sPtr && *sPtr != data) {
				sPtr = sPtr->next;
			}
			if (!sPtr) throw std::invalid_argument();
			else {
				sPtr->next = sPtr->prev;
				sPtr = nullptr;
				size--;
			}

		}

	private:

		SNodePtr	head;
		WNodePtr	tail;
		int			size;

};

template<class T>
std::ostream &			operator<<( std::ostream & o, DoubleLL<T> const & i ) {
	SharedPtr<Node<T>> it = i.cbegin();
	if (!it) {
		o << "The list is empty.\n";
	}
	else {
		while (it) {
			o << *it;
			o << it;
			it = it->next;
		}
	}
	return o;
};

#endif /* ******************************************************** DOUBLELL_H */