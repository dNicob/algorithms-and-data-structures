
#ifndef FOLDABLE_HPP
#define FOLDABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator= (const FoldableContainer&) = delete;

  // Move assignment
  FoldableContainer& operator= (FoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool virtual operator== (const FoldableContainer&) const noexcept = delete;
  bool virtual operator!= (const FoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using FoldFunctor = std::function <void(const Data &, void *)>;
  virtual void Fold(const FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)
  virtual bool Exists(const Data&) const noexcept override; 

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : virtual public FoldableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator= (const PreOrderFoldableContainer&) = delete;

  // Move assignment
  PreOrderFoldableContainer& operator= (PreOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const PreOrderFoldableContainer&) const noexcept = delete;
  virtual bool operator!= (const PreOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void PreOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  virtual void Fold(const FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : virtual public FoldableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderFoldableContainer& operator= (const PostOrderFoldableContainer&) = delete;

  // Move assignment
  PostOrderFoldableContainer& operator= (PostOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const PostOrderFoldableContainer&) const noexcept = delete;
  virtual bool operator!= (const PostOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void PostOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  virtual void Fold(const FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderFoldableContainer& operator= (const InOrderFoldableContainer&) = delete;

  // Move assignment
  InOrderFoldableContainer& operator= (InOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const InOrderFoldableContainer&) const noexcept = delete;
  bool operator!= (const InOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void InOrderFold(const FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  virtual void Fold(const FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer : virtual public FoldableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthFoldableContainer& operator =(const BreadthFoldableContainer&) = delete;

  // Move assignment
  BreadthFoldableContainer& operator =(BreadthFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const BreadthFoldableContainer&) const noexcept = delete;
  bool operator!= (const BreadthFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void BreadthFold(const FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(const FoldFunctor, void *) const override;
  
};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
