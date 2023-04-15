

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../container/container.hpp"
#include "../container/linear.hpp"



namespace lasd {

template <typename Data>
class Vector : virtual public ResizableContainer,
               virtual public SortableLinearContainer<Data>{
private:
  // ...
protected:
  using Container::size;
  Data * datas = nullptr;
public:
  // Default constructor
  Vector() = default; 
 
  // Specific constructors
  Vector(const ulong newsize);

  // Vector(argument) specifiers; // A vector obtained from a MappableContainer
  Vector(const MappableContainer<Data>&);

  // Vector(argument) specifiers; // A vector obtained from a MutableMappableContainer
  Vector(MutableMappableContainer<Data>&&);

  // Copy constructor
  Vector(const Vector<Data>&);

  // Move constructor
  Vector(Vector<Data>&&);

  // Destructor
  virtual ~Vector();


  // Copy assignment
  Vector<Data>& operator= (const Vector<Data>&);

  // Move assignment
  Vector<Data>& operator= (Vector<Data>&&) noexcept;

  // Comparison operators
  bool operator==(const Vector<Data>&) const noexcept;
  bool operator!=(const Vector<Data>&) const noexcept;

  // Specific member function (inherited from ClearableContainer)
  virtual void Clear() override;

  // Specific member function (inherited from ResizableContainer)
  virtual void Resize(const ulong) override; 

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  virtual const Data& operator[] (const ulong) const override;
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  virtual Data& operator[] (ulong) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  virtual const Data& Front() const override;
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  virtual Data& Front() override;

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  virtual const Data& Back() const override;
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  virtual Data& Back() override;

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  // type Sort() specifiers; // Override SortableLinearContainer member
  virtual void Sort();

protected:

  // Auxiliary functions, if necessary!

};

}

#include "vector.cpp"

#endif

