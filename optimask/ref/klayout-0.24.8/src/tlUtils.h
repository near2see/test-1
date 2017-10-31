
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2016 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/


#ifndef HDR_tlUtils
#define HDR_tlUtils

#include "tlAssert.h"

#include <map>

namespace tl
{

/**
 *  @brief A template class mapping a begin .. end iterator pair to the at_end semantics
 */

template <class Iter>
class iterator_pair
{
public:
  typedef typename std::iterator_traits<Iter> it_traits;
  typedef typename it_traits::value_type value_type;
  typedef Iter iter_type;

  /**
   *  @brief Default constructor
   */
  iterator_pair ()
  { }

  /**
   *  @brief Initialisation from a classical "STL-style" iterator pair
   */
  iterator_pair (iter_type from, iter_type to)
    : m_from (from), m_to (to)
  { }

  /**
   *  @brief direct resolution
   */
  const value_type &operator* () const
  {
    return *m_from;
  }

  /**
   *  @brief Indirect resolution
   */
  const value_type *operator-> () const
  {
    return &*m_from;
  }

  /**
   *  @brief Increment
   */
  iterator_pair &operator++() 
  {
    ++m_from;
    return *this;
  }

  /**
   *  @brief Equality
   */
  bool operator== (const iterator_pair &d) const
  {
    return m_from == d.m_from;
  }

  /**
   *  @brief Inequality
   */
  bool operator!= (const iterator_pair &d) const
  {
    return ! operator== (d);
  }

  /**
   *  @brief Return true, if a the end
   */
  bool at_end () const
  {
    return m_from == m_to;
  }

  /** 
   *  @brief Return the basic iterator
   */
  const iter_type &basic_iter () const
  {
    return m_from;
  }

private:
  iter_type m_from, m_to;
};

/**
 *  @brief A mapping function: map one element to the same value
 *
 *  A mapping is in general implemented by the () operator taking one
 *  argument and delivering an argument of the same type.
 *  This implementation of this concept delivers the same value than the input
 */
template <class Value>
class ident_map 
{
public:
  typedef Value value_type;

  ident_map ()
  { }

  const Value &operator() (const Value &v) const 
  {
    return v;
  }
};

/**
 *  @brief A mapping function: map one element to a constant
 *
 *  A mapping is in general implemented by the () operator taking one
 *  argument and delivering an argument of the same type.
 *  This implementation of this concept delivers the same value irregardless of the input.
 */
template <class Value>
class const_map 
{
public:
  typedef Value value_type;

  const_map (const Value &v) 
    : m_value (v)
  { }

  const Value &operator() (const Value &) const 
  {
    return m_value;
  }

private:
  Value m_value;
};

/**
 *  @brief A mapping function: map one element to a value using an associative container
 *
 *  A mapping is in general implemented by the () operator taking one
 *  argument and delivering an argument of the same type.
 *  This implementation of this concept delivers the object mapped by a lookup.
 *  It throws an exception if no association can be found.
 */
template <class Value, class Assoc>
class assoc_map 
{
public:
  typedef Value value_type;

  assoc_map (const Assoc &assoc)
    : m_assoc (assoc)
  { }

  const Value &operator() (const Value &v) const 
  {
    typename Assoc::const_iterator a = m_assoc.find (v);
    tl_assert (a != m_assoc.end ());
    return a->second;
  }

private:
  const Assoc &m_assoc;
};

/**
 *  @brief A specialisation of assoc_map using a std::map as associative container
 */
template <class Value>
struct map_map 
  : public assoc_map<Value, std::map<Value, Value> >
{
  map_map (const std::map<Value, Value> &map) 
    : assoc_map<Value, std::map<Value, Value> > (map) { }
};

/**
 *  @brief A delegation object that wraps some operator into a derived object
 */
template <class Value> 
struct func_delegate_base
{
  virtual ~func_delegate_base () { }
  virtual Value operator () (const Value &v) { return v; }
};

/**
 *  @brief The wrapper
 */
template <class Op, class Value> 
struct func_delegate
  : public func_delegate_base<Value>
{
  func_delegate (Op &op) : m_op (op) { }
  
  virtual Value operator () (const Value &v) 
  { 
    return m_op (v); 
  }

private:
  Op &m_op;
};

/**
 *  @brief A class representing "true" for type expressions
 */
struct True { };

/**
 *  @brief A class representing "false" for type expressions
 */
struct False { };

/**
 *  @brief A type comparison operator
 */
template <class A, class B>
struct is_equal_type
{
  typedef False value;
  operator bool () const { return false; }
};

/**
 *  @brief A type comparison operator (specialisation for equal classes)
 */
template <class A>
struct is_equal_type<A, A>
{
  typedef True value;
  operator bool () const { return true; }
};

/**
 *  @brief Compute the largest common divider of two numbers using the euclidian method
 */
template <class T>
T lcd (T a, T b)
{
  while (true) {
    if (a < b) {
      b %= a;
      if (b == 0) {
        return a;
      }
    } else if (b < a) {
      a %= b;
      if (a == 0) {
        return b;
      }
    } else {
      return a;
    }
  }
}

}

#endif

