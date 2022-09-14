#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#pragma once

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Category = std::random_access_iterator_tag,
		class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class vector_iterator
	{
		public:
			//	MEMBER TYPES
			typedef Category iterator_category;
			typedef T value_type;
			typedef Distance difference_type;
			typedef Pointer pointer;
			typedef Reference reference;

			//	MEMBER FUNCTIONS
			vector_iterator() : _iptr() {}
			vector_iterator(pointer ptr) : _iptr(ptr) {}
			vector_iterator(const reference ref) {_iptr = ref.get_pointer();}
			~vector_iterator() {}

			operator vector_iterator<const T>(void) const
			{
				return (vector_iterator<const T>(this->_iptr));
			}

			reference			operator*() const {return (*_iptr);}
			vector_iterator		operator+ (difference_type n) const {return vector_iterator(_iptr + n);}
			//vector_iterator		operator+ (difference_type n) const
			//{
			//	vector_iterator tmp(*this);
			//	tmp += n;
			//	return (tmp);
			//}

			//friend vector_iterator	operator+ (std::ptrdiff_t n, vector_iterator it)
			//{
			//	vector_iterator temp(it.get_pointer());
			//	temp += n;
			//	return (temp);
			//}

			vector_iterator&	operator++()
			{
				_iptr++;
				return (*this);
			}

			vector_iterator		operator++(int)
			{
				vector_iterator	temp(*this);
				operator++();
				return (temp);
			}

			vector_iterator&	operator+= (difference_type n)
			{
				_iptr += n;
				return (*this);
			}

			vector_iterator		operator- (difference_type n) const {return vector_iterator(_iptr - n);}
			//vector_iterator operator - (int n) const
			//{
			//	vector_iterator tmp(*this);
			//	tmp -= n;
			//	return (tmp);
			//}

			vector_iterator&	operator--()
			{
				_iptr--;
				return (*this);
			}

			vector_iterator		operator--(int)
			{
				vector_iterator	temp(*this);
				operator--();
				return (temp);
			}

			vector_iterator		operator-= (difference_type n)
			{
				_iptr -= n;
				return (*this);
			}

			pointer				operator->() const {return (_iptr);}
			reference			operator[] (difference_type n) const {return (_iptr[n]);}

			vector_iterator&	operator=(const vector_iterator<const T> &x)
			{
				if (this != &x)
					_iptr = x.get_pointer();
				return (*this);
			}

			pointer				get_pointer() const {return (_iptr);}

		//	COMPARISON
			bool operator== (const vector_iterator<const T> &x) const
			{
				return (_iptr == x.get_pointer());
			}

			bool operator!= (const vector_iterator<const T> &x) const
			{
				return (_iptr != x.get_pointer());
			}

			bool operator> (const vector_iterator<const T> &x) const
			{
				return (_iptr > x.get_pointer());
			}

			bool operator>= (const vector_iterator<const T> &x) const
			{
				return (_iptr >= x.get_pointer());
			}

			bool operator< (const vector_iterator<const T> &x) const
			{
				return (_iptr < x.get_pointer());
			}

			bool operator<= (const vector_iterator<const T> &x) const
			{
				return (_iptr <= x.get_pointer());
			}

		protected:
			pointer	_iptr;
	};
}

	//	https://legacy.cplusplus.com/reference/iterator/iterator/

#endif