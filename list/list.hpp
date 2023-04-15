
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer,
             virtual public DictionaryContainer<Data>,
             virtual public LinearContainer<Data>{
private:
protected:
    using Container::size;
  typedef struct Node {

    Data value;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    Node(const Data&);
    Node(Data&&);

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node&);

    // Move constructor
     Node(Node&&);

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;

    bool operator!=(const Node& t_Node) const noexcept;

    /* ********************************************************************** */

  }Node;

     Node *head = nullptr;
     Node *tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a MappableContainer
  List(const MappableContainer<Data>& mapCon);
  // List(argument) specifiers; // A list obtained from a MutableMappableContainer
  List(MutableMappableContainer<Data>&& mutMapCon);
  /* ************************************************************************ */

  // Copy constructor
  List(const List& list);

  // Move constructor
  List(List&& list) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  List<Data>& operator= (const List<Data>&);

  // Move assignment
  List<Data>& operator= (List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List<Data>&) const noexcept;
  bool operator!=(const List<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual void InsertAtFront(const Data&); // Copy of the value
  virtual void InsertAtFront(Data&&); // Move of the value
  virtual void RemoveFromFront(); // (must throw std::length_error when empty)
  virtual Data FrontNRemove(); // (must throw std::length_error when empty)

  virtual void InsertAtBack(const Data&); // Copy of the value
  virtual void InsertAtBack(Data&&); // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data&) noexcept override; // Copy of the value
  virtual bool Insert(Data&&) noexcept override; // Move of the value
  virtual bool Remove(const Data&) noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  virtual const Data& operator[](const ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  virtual Data& operator[](const ulong) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  virtual const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  virtual Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  virtual const Data& Back() const override;  // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  virtual Data& Back() override;  // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

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
  virtual void PreOrderMap(const MapFunctor)const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)
  virtual void PostOrderMap(const MapFunctor)const override; // Override PostOrderMappableContainer member

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

protected:

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  virtual void PreOrderFold(const FoldFunctor, void*, Node*) const; // Accessory function executing from one point of the list onwards
  virtual void PostOrderFold(const FoldFunctor, void*, Node*) const; // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  virtual void PreOrderMap(const MapFunctor, Node*) const; // Accessory function executing from one point of the list onwards
  virtual void PostOrderMap(const MapFunctor, Node*) const; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

  // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)

  virtual void PreOrderMap(const MutableMapFunctor, Node*);// Accessory function executing from one point of the list onwards
  virtual void PostOrderMap(const MutableMapFunctor, Node*);/// Accessory function executing from one point of the list onward

  /* ************************************************************************ */
  using FoldableContainer<Data>::Exists;

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
