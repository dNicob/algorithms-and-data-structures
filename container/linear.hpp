
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public MutablePreOrderMappableContainer<Data>,
                        virtual public MutablePostOrderMappableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator= (const LinearContainer&) = delete; 

  // Move assignment
  LinearContainer& operator=(LinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const LinearContainer&) const noexcept = delete;
  bool operator!= (const LinearContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual const Data& operator[](const ulong) const = 0 ;
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](const ulong) = 0;

  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Front() const;
  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Front();

  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Back() const;
  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Back();

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void Fold(const FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)
  virtual void PreOrderFold(const FoldFunctor, void*) const override; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)
  virtual void PostOrderFold(const FoldFunctor, void*) const override; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  using typename MappableContainer<Data>::MapFunctor;
  virtual void Map(const MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)
  virtual void PreOrderMap(const MapFunctor) const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)
  virtual void PostOrderMap(const MapFunctor) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  virtual void Map(const MutableMapFunctor) override; // Override MutableMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)
  virtual void PreOrderMap(const MutableMapFunctor) override; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)
  virtual void PostOrderMap(const MutableMapFunctor) override; // Override MutablePostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data>{
private:
  // ...
protected:
  // ...
public:
  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

   // Copy assignment
  SortableLinearContainer& operator= (const SortableLinearContainer&) = delete; 

  // Move assignment
  SortableLinearContainer& operator=(SortableLinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const SortableLinearContainer&) const noexcept = delete;
  bool operator!= (const SortableLinearContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() = 0;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
