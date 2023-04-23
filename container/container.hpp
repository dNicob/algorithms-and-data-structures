
#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <iostream>
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:
  // ...
protected:
  ulong size = 0;
public:
  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator= (const Container&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Container& operator= (Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!= (const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Empty() const noexcept {return size == 0;}; // (concrete function should not throw exceptions)
  virtual ulong Size()  const noexcept {return size;}; // (concrete function should not throw exceptions)
};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  ClearableContainer& operator= (const ClearableContainer&) = delete; 

  // Move assignment
  ClearableContainer& operator= (ClearableContainer&&) noexcept = delete;

  /* ************************************************************************ */
  // Comparison operators
  bool operator== (const ClearableContainer&) const noexcept = delete;
  bool operator!= (const ClearableContainer&) const noexcept = delete;

  /* ************************************************************************ */
  // Specific member function
   virtual void Clear() = 0;
};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer{
private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
   virtual ~ResizableContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  ResizableContainer& operator= (const ResizableContainer&) = delete;

  // Move assignment
  ResizableContainer& operator= (ResizableContainer&&) noexcept = delete;

  /* ************************************************************************ */
  // Comparison operators
  virtual bool operator== (const ResizableContainer&) const noexcept = delete;
  virtual bool operator!= (const ResizableContainer&) const noexcept = delete;

  /* ************************************************************************ */
  // Specific member function

  // type Resize(argument) specifiers;
  virtual void Resize(const ulong) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
    void Clear() override {
      Resize(0);
    };

};

/* ************************************************************************** */

};


#endif