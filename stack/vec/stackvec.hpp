
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>,
                 virtual protected Vector<Data>{

private:
  // ...
protected:
  using Vector<Data>::size;
  using Vector<Data>::datas;
  ulong index = 0;

public:

  // Default constructor
  StackVec();

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer<Data>&); // A stack obtained from a  MappableContainer
  StackVec(MutableMappableContainer<Data>&&) noexcept; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec<Data>&);

  // Move constructor
  StackVec(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec();

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec<Data>&);

  // Move assignment
  StackVec<Data>& operator=(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec<Data>&) const noexcept;
  bool operator!=(const StackVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  virtual const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  virtual Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  virtual void Pop() override; // Override Stack member (must throw std::length_error when empty)
  virtual Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  virtual void Push(const Data&) override; // Override Stack member (copy of the value)
  virtual void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual bool Empty() const noexcept override; // Override Container member
  virtual ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  virtual void Expand();
  virtual void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
