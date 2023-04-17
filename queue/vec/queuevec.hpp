
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>,
                 virtual protected Vector<Data>{
private:
  // ...
protected:
  using Vector<Data>::size;
  using Vector<Data>::datas;
  ulong head = 0;
  ulong lenght = 0;
public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const MappableContainer<Data>&); // A queue obtained from a MappableContainer
  QueueVec(MutableMappableContainer<Data>&&); // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec<Data>&);

  // Move constructor
  QueueVec(QueueVec<Data>&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec();

  /* ************************************************************************ */

  // Copy assignment
  QueueVec<Data>& operator=(const QueueVec<Data>&);

  // Move assignment
  QueueVec<Data>& operator=(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec<Data>&) const noexcept;
  bool operator!=(const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  virtual Data& Head() override; // (mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Head() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual void Dequeue() override; // (concrete function must throw std::length_error when empty)
  virtual Data HeadNDequeue(); // (concrete function must throw std::length_error when empty)
  virtual void Enqueue(const Data&)  override; // Copy of the value
  virtual void Enqueue(Data&&) noexcept override; // Move of the value

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
  virtual void SwapVectors(const ulong);
  virtual ulong Tail() const;
};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
