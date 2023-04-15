
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data>{

private:
  // ...
protected:
  using Container::size;
public:
  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */
  // Copy assignment
  DictionaryContainer& operator= (const DictionaryContainer&) = delete;

  // Move assignment
  DictionaryContainer& operator= (DictionaryContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool virtual operator== (const DictionaryContainer&) const noexcept = delete;
  bool virtual operator!= (const DictionaryContainer&) const noexcept = delete;

  /* ************************************************************************ */
  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  bool virtual Insert(const Data&) noexcept = 0;  

  // type Insert(argument) specifiers; // Move of the value
  bool virtual Insert(Data&&) noexcept = 0;

  // type Remove(argument) specifiers;
  bool virtual Remove(const Data&) noexcept = 0;

  // type InsertAll(argument) specifiers; // Copy of the value; From MappableContainer; True if all are inserted
  bool virtual InsertAll(const MappableContainer<Data>&) noexcept;

  // type InsertAll(argument) specifiers; // Move of the value; From MutableMappableContainer; True if all are inserted
  bool virtual InsertAll(MutableMappableContainer<Data>&&) noexcept;

  // type RemoveAll(argument) specifiers; // From MappableContainer; True if all are removed
  bool virtual RemoveAll(const MappableContainer<Data>&) noexcept;

  // type InsertSome(argument) specifiers; // Copy of the value; From MappableContainer; True if some is inserted
  bool virtual InsertSome(const MappableContainer<Data>&) noexcept;

  // type InsertSome(argument) specifiers; // Move of the value; From MutableMappableContainer; True if some is inserted
  bool virtual InsertSome(MutableMappableContainer<Data>&&) noexcept;

  // type RemoveSome(argument) specifiers; // From MappableContainer; True if some is removed
  bool virtual RemoveSome(const MappableContainer<Data>&) noexcept;

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
