#ifndef LISTEST_HPP
#define LISTEST_HPP

#include "../list/list.hpp"
using namespace lasd;



template <typename Data>
void Empty(const List<Data>& lst, bool ans){
    bool test;
    try{
    std::cout<<"La lista è: ";
    std::cout<<((test = (lst.Empty())) ? "" : "non") << " vuota! ";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}


template <typename Data>
void InsertTest(List<Data>& lst, int val, bool ans){
    bool test;
    try{
    std::cout<<"Inserimento: ";
    std::cout<<((test = (lst.Insert(val))) ? "" : "non") << " effettuato! ";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}
   

template <typename Data>
void InsertAtFrontTest(List<Data>& lst, int val, bool ans){
    bool test;
    try{
    std::cout<<"insert at front of : "<< val << " -->";
    lst.InsertAtFront(val);
    std::cout<<((val == lst.Front()) ? "Corretto" : "Errore" )<< "!"<<std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}

template <typename Data>
void InsertAtBackTest(List<Data>& lst, int val){
    
    try{
    std::cout<<"insert at back of : "<< val << " -->";
    lst.InsertAtBack(val);
    std::cout<<((val == lst.Back()) ? "Corretto" : "Errore" )<< "!"<<std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}

template <typename Data>
void RemoveTest(List<Data>& lst, const int& val, bool ans){
    bool test;
    try{
    std::cout<<"Rimozione: ";
    std::cout<<((test = (lst.Remove(val))) ? "" : "non") << " effettuata! ";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}

template <typename Data>
void RemoveFromFrontTest(List<Data>& lst, const int& val, bool ans){
    bool test;
    try{
    std::cout<<"Rimozione: ";
    std::cout<<((test = (lst.RemoveFromFront(val))) ? "" : "non") << " effettuata! ";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}


template <typename Data>
void FrontNRemoveTest(List<Data>& lst, Data ans){
    Data test;
    try{
    test = lst.FrontNRemove();

    std::cout<<"Rimozione Front: "<< test<< "--Esito: ";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}


template <typename Data, typename Value>
void PostOrderFoldTest(const List<Data>& lst, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  Value val = inival;
  try {
    std::cout <<"Esecuzione fold - ";
    lst.PostOrderFold(fun, &val);
    std::cout << "valore ottenuto \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Corretto" : "Errore") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Corretto" : "Errore") << "!" << std::endl;
  }

}
#endif