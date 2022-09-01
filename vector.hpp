#pragma once

#include <iostream>

namespace ft
{
	template <class Type, class Allocator = std::allocator<Type>>
	class vector
	{
		//	MEMBER TYPES
	public:
		typedef Type value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		// need to include the iterators that i need to do
		typedef iterator;
		typedef const_iterator;
		typedef reverse_iterator;
		typedef const_reverse_iterator;

		//	MEMBER FUNCTIONS
		//	default constructor
		explicit vector(const allocator_type &alloc = allocator_type()) : _data(NULL),
																		  _capacity(0), _size(0), _alloc(alloc) {}

		//	fill constructor
		explicit vector(size_type n, const_reference val = value_type(),
						const allocator_type &alloc = allocator_type()) {}

		//	range constructor
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type()) {}

		//	copy constructor
		vector(const vector &x) {}

		//	destructor
		~vector() {}

		//	copy
		vector &operator=(const vector &x) {}

		//	ITERATORS
		iterator begin() {}
		const_iterator begin() const {}
		iterator end() {}
		const_iterator end() const {}
		reverse_iterator rbegin() {}
		const_reverse_iterator rbegin() const {}
		reverse_iterator rend() {}
		const_reverse_iterator rend() const {}

		//	CAPACITY
		size_type size() const {}
		size_type max_size() const {}
		void resize(size_type n, value_type val = value_type()) {}
		size_type capacity() const {}
		bool empty() const {}
		void reserve(size_type n) {}

		//	ELEMENT ACCESS
		reference operator[](size_type n) {}
		const_reference operator[](size_type n) const {}
		reference at(size_type n) {}
		const_reference at(size_type n) const {}
		reference front() {}
		const_reference front() const {}
		reference back() {}
		const_reference back() const {}

		//	MODIFIERS
		template <class InputIterator>
		//	range assign
		void assign(InputIterator first, InputIterator last)
		{
		}
		//	fill assign
		void assign(size_type n, const_reference val) {}

		void push_back(const_reference val) {}
		void pop_back() {}

		//	single element insert
		iterator insert(iterator position, const_reference val) {}
		//	fill insert
		void insert(iterator position, size_type n, const_reference val) {}
		//	range insert
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {}

		iterator erase(iterator position) {}
		iterator erase(iterator first, iterator last) {}
		void swap(vector &x) {}
		void clear() {}

		//	ALLOCATOR
		allocator_type get_allocator() const {}

	private:
		pointer _content;
		Allocator _alloc;
		size_type _capacity;
		size_type _size;
	};

	//	NON-MEMBER FUNCTIONS
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {}
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs) {}
}
//	https://legacy.cplusplus.com/reference/vector/vector/
