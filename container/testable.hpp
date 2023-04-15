
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{
  
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  TestableContainer& operator= (const TestableContainer&) = delete;

  // Move assignment
  TestableContainer& operator= (TestableContainer&&) noexcept = delete;
  
  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const TestableContainer&) const noexcept = delete;
  virtual bool operator!= (const TestableContainer&) const noexcept = delete;

  /* ************************************************************************ */
  // Specific member function

  // type Exists(argument) specifiers; // (concrete function should not throw exceptions)
  virtual bool Exists(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

}

#endif
