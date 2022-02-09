#ifndef DOUBLELL_HPP
# define DOUBLELL_HPP

# include <iostream>
# include <string>
# include "SharedPtr.hpp"
# include "WeakPtr.hpp"

using namespace SmartPointer;

template<class T>
class Node {

	public:

		using SNodePtr = SharedPtr<Node<T>>;
		using WNodePtr = WeakPtr<Node<T>>;

		Node() : data(nullptr) {};
		Node(T* data) : data(data) {}
		Node(Node<T> const & src) = default;

		T const *			getData() const { return data; }
		SNodePtr const &	next() const { return next; }
		WNodePtr const &	prev() const { return prev; }
		void				setNext(SNodePtr const & nextNode) {
			next = nextNode;
		}
		void				setPrev(SNodePtr const & prevNode) {
			prev = prevNode;
		}

	private:

		T*			data;
		SNodePtr	next;
		WNodePtr	prev;

};

template<class T>
class DoubleLL
{

	public:

		using SNodePtr = SharedPtr<Node<T>>;
		using WNodePtr = WeakPtr<Node<T>>;

		class Iterator {

			public:

				using iterator_category = std::bidirectional_iterator_tag;
   	 			using difference_type   = std::ptrdiff_t;
    			using value_type        = T;
    			using pointer           = T*;  // or also value_type*
    			using reference         = T&;  // or also value_type&

				Iterator(pointer ptr) : m_ptr(ptr) {};

				reference	operator*() const { return *m_ptr; }
				pointer		operator->() { return m_ptr; }
				//prefix incr
				Iterator &	operator++() { m_ptr++; return *this; }
				//prefix incr
				Iterator	operator++(int) {
					Iterator	tmp = *this;
					++(*this);
					return tmp;
				}
				friend bool operator==(const Iterator& a, const Iterator& b) {
					return (a.m_ptr == b.m_ptr);
				};
    			friend bool operator!=(const Iterator& a, const Iterator& b) {
					return (a.m_ptr != b.m_ptr);
				};
			
			private:

				pointer	m_ptr;

		};

		class ConstIterator {

			public:

				using iterator_category = std::bidirectional_iterator_tag;
   	 			using difference_type   = std::ptrdiff_t;
    			using value_type        = T;
    			using pointer           = T*;  // or also value_type*
    			using reference         = T&;  // or also value_type&

				ConstIterator(pointer ptr) : m_ptr(ptr) {};

				reference const	operator*() const { return *m_ptr; }
				pointer		operator->() { return m_ptr; }
				//prefix incr
				ConstIterator &	operator++() { m_ptr++; return *this; }
				//prefix incr
				ConstIterator	operator++(int) {
					ConstIterator	tmp = *this;
					++(*this);
					return tmp;
				}
				friend bool operator==(const ConstIterator& a, const ConstIterator& b) {
					return (a.m_ptr == b.m_ptr);
				};
    			friend bool operator!=(const ConstIterator& a, const ConstIterator& b) {
					return (a.m_ptr != b.m_ptr);
				};
			
			private:

				pointer	m_ptr;

		};


		DoubleLL() = default;
		DoubleLL(Node const & head) : head(head) {};
		DoubleLL( DoubleLL const & src ) = default;
		~DoubleLL() = default;

		DoubleLL &		operator=( DoubleLL const & rhs ) = default;
		Iterator		begin() { return Iterator(&head); }
		Iterator		end() { return Iterator(&(tail.next())); }
		ConstIterator	cbegin() { return ConstIterator(&head); }
		ConstIterator	cend() { return ConstIterator(&(*tail.next())); }
		void			insertFront(Node<T> const & node) {

		}
		void			insertBack(Node<T> const & node) {

		}
		void			insertBefore(Node<T> const & node) {

		}
		void			insertAfter(Node<T> const & node) {

		}
		void			deleteFirst() {

		}
		void			deleteFirst() {

		}
		void			deleteAt(T const & data) {

		}

	private:

		SNodePtr	head;
		WNodePtr	tail;

		WNodePtr const &	findTail() const {
			if (head == nullptr) return head;
			Node<T>	tmp = head;
			while (tmp.next() != nullptr) {
				tmp = tmp.next();
			}
			return WeakPtr<T>
		}

};

template<class T>
std::ostream &			operator<<( std::ostream & o, DoubleLL<T> const & i );

#endif /* ******************************************************** DOUBLELL_H */