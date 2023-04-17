
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>,
                 virtual protected List<Data>{

private:
  // ...
protected:
  using List<Data>::size;
  // ...
public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const MappableContainer<Data>&); // A queue obtained from a MappableContainer
  QueueLst(MutableMappableContainer<Data>&&); // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst<Data>&);

  // Move constructor
  QueueLst(QueueLst<Data>&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst();

  /* ************************************************************************ */

  // Copy assignment
  QueueLst<Data>& operator=(const QueueLst<Data>&);

  // Move assignment
  QueueLst<Data>& operator=(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst<Data>&) const noexcept;
  bool operator!=(const QueueLst<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  virtual Data& Head() override; // (mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Head() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual void Dequeue() override; // (concrete function must throw std::length_error when empty)
  virtual Data HeadNDequeue() override; // (concrete function must throw std::length_error when empty)
  virtual void Enqueue(const Data&)  override; // Copy of the value
  virtual void Enqueue(Data&&) noexcept override; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
