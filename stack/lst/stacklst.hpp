
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>,
                 virtual protected List<Data>{
private:
  // ...
protected:

  using List<Data>::size;
public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const MappableContainer<Data>&); // A stack obtained from a MappableContainer
  StackLst(MutableMappableContainer<Data>&&); // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst<Data>&);

  // Move constructor
  StackLst(StackLst<Data>&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst();

  /* ************************************************************************ */

  // Copy assignment
  StackLst<Data>& operator=(const StackLst<Data>&);

  // Move assignment
  StackLst<Data>& operator=(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst<Data>&) const noexcept;
  bool operator!=(const StackLst<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  virtual const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  virtual Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  virtual void Pop() override; // Override Stack member (must throw std::length_error when empty)
  virtual Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  virtual void Push(const Data&) override; // Override Stack member (copy of the value)
  virtual void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
