
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "foldable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public FoldableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete;

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const MappableContainer&) const noexcept = delete;
  virtual bool operator!=(const MappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using MapFunctor = std::function<void (const Data&)>;
  virtual void Map(const MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void Fold(const FoldFunctor, void *) const override;


};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>,
                                  virtual public PreOrderFoldableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator= (const PreOrderMappableContainer&) = delete;

  // Move assignment
  PreOrderMappableContainer& operator= (PreOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator== (const PreOrderMappableContainer&) const noexcept = delete;
  bool operator!= (const PreOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;
  virtual void PreOrderMap(const MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  virtual void Map(const MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void Fold(const FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)
  // type PreOrderFold(arguments) specifiers; // Override PreOrderFoldableContainer member
  virtual void PreOrderFold(const FoldFunctor, void *)const override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>,
                                   virtual public PostOrderFoldableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~PostOrderMappableContainer() = default;
  /* ************************************************************************ */
  // Copy assignment
  PostOrderMappableContainer& operator= (const PostOrderMappableContainer&) = delete;

  // Move assignment
  PostOrderMappableContainer& operator= (PostOrderMappableContainer&&) noexcept = delete;
  
  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const PostOrderMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const PostOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFunctor;
  virtual void PostOrderMap(const MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  virtual void Map(const MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void Fold(const FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)
  virtual void PostOrderFold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>,
                                 virtual public InOrderFoldableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderMappableContainer& operator= (const InOrderMappableContainer&) = delete;

  // Move assignment
  InOrderMappableContainer& operator= (InOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const InOrderMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const InOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;
  virtual void InOrderMap(const MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(const MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  //type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(const FoldFunctor, void *) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)

  // type InOrderFold(arguments) specifiers; // Override InOrderFoldableContainer member
  virtual void InOrderFold(const FoldFunctor, void *) const override;
};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>,
                                 virtual public BreadthFoldableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */


  // Copy assignment
  BreadthMappableContainer& operator= (const BreadthMappableContainer&) = delete;

  // Move assignment
  BreadthMappableContainer& operator= (BreadthMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const BreadthMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const BreadthMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;
  virtual void BreadthMap(const MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(const MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;
  virtual void Fold(const FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  virtual void BreadthFold(const FoldFunctor, void*) const override; // Override BreadthFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableMappableContainer : virtual public MappableContainer<Data>{ 
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~MutableMappableContainer() = default;

  /* ************************************************************************ */

 // Copy assignment
  MutableMappableContainer& operator= (const MutableMappableContainer&) = delete;

  // Move assignment
  MutableMappableContainer& operator= (MutableMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const MutableMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const MutableMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using MutableMapFunctor = std::function<void(Data &)>;
  virtual void Map(const MutableMapFunctor) = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutablePreOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                         virtual public PreOrderMappableContainer<Data>{                                                        
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~MutablePreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutablePreOrderMappableContainer& operator= (const MutablePreOrderMappableContainer&) = delete;

  // Move assignment
  MutablePreOrderMappableContainer& operator= (MutablePreOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const MutablePreOrderMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const MutablePreOrderMappableContainer&) const noexcept = delete;


  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  virtual void PreOrderMap(const MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  virtual void Map(const MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutablePostOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                          virtual public PostOrderMappableContainer<Data>{                                  
private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
  virtual ~MutablePostOrderMappableContainer() = default;

  /* ************************************************************************ */

 // Copy assignment
  MutablePostOrderMappableContainer& operator= (const MutablePostOrderMappableContainer&) = delete;

  // Move assignment
  MutablePostOrderMappableContainer& operator= (MutablePostOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const MutablePostOrderMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const MutablePostOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  virtual void PostOrderMap(const MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  virtual void Map(const MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                        virtual public InOrderMappableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~MutableInOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableInOrderMappableContainer& operator= (const MutableInOrderMappableContainer&) = delete;

  // Move assignment
  MutableInOrderMappableContainer& operator= (MutableInOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const MutableInOrderMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const MutableInOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  virtual void InOrderMap(const MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  virtual void Map(const MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer : virtual public MutableMappableContainer<Data>,
                                        virtual public BreadthMappableContainer<Data>{
private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~MutableBreadthMappableContainer() = default;

  /* ************************************************************************ */

 // Copy assignment
  MutableBreadthMappableContainer& operator= (const MutableBreadthMappableContainer&) = delete;

  // Move assignment
  MutableBreadthMappableContainer& operator= (MutableBreadthMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator== (const MutableBreadthMappableContainer&) const noexcept = delete;
  virtual bool operator!= (const MutableBreadthMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  virtual void BreadthMap(const MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  virtual void Map(const MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
