
#ifndef VECTEST_HPP
#define VECTEST_HPP


using namespace lasd;

/* ************************************************************************** */

template <typename Data>
void EqualVector(const Vector<Data>& vec1, const Vector<Data>& vec2 , bool ans){
    bool test;
    try{
    std::cout<<"I due vettori sono ";
    std::cout<<((test = (vec1 == vec2)) ? "uguali" : "diversi") << " :";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}


template <typename Data>
void Empty(const Vector<Data> vec1, bool ans){
    bool test;
    try{
    std::cout<<"Il Vettore è: ";
    std::cout<<((test = (vec1.Empty())) ? "" : "non") << " vuoto!";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "\" " << exc.what() << " \""; 
    } 
}


template <typename Data>
void setAt(Vector<Data>& vec, const Data& val, const ulong& index, bool ans){
    bool test;
    try{
    std::cout<<"Set valore :"<<val<<" at index: "<<index<<"  :";
    vec[index] = val;
    std::cout<<((test = (vec[index] == val)) ? "" : "Non") << "effettuato! : ";
    std::cout<<((test == ans) ? "Corretto" : "Errore") << "!"<< std::endl;
    }catch(std::exception exc){
        std::cout<< "Exception " << exc.what() <<std::endl; 
    } 
}


template <typename Data>
void printVector(Vector<Data>& vec){
    std::cout<<"-----------------------]]]Stampa Vettore[[[------------------------"<<std::endl;
    for (ulong i = 0; i < vec.Size(); i++)
    {
        std::cout<<vec[i]<< " - ";
    }
    std::cout<<std::endl;
}


template <typename Data>
void isClear(const Vector<Data>& vec){
    try
    {
        std::cout<<"Size "<<((vec.Size() == 0) ? "" : "Non") << " azzerata"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


template <typename Data>
void checkFront(const Vector<Data>& vec){
    try
    {
        std::cout<<"Front: "<< vec.Front() <<" ";
        std::cout<<((vec.Front() == vec[0]) ? "Corretto" : "Errore") << "!"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


template <typename Data>
void checkBack(const Vector<Data>& vec){
    try
    {
        std::cout<<"Back: "<< vec.Back()<< " ";
        std::cout<<((vec.Back() == vec[vec.Size()-1])? "Corretto" : "Errore") << "!"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


template <typename Data>
void isSorted(const Vector<Data>& vec, bool ans){
    bool test = true;
    try
    {
        for (ulong i = 0; i < vec.Size() - 1; i++)
        {
            if(vec[i] > vec[i + 1]){
                test = false;
            }
        }
        
        std::cout<<(test ? "Array ordinato" : "Array non ordinato")<< " "<< ((test == ans) ? "Corretto" : "Errore") << "!"<<std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}



template <typename Data, typename Value>
void Fold(const lasd::FoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Value& inival, const Value& finval) {
  bool tst;
  Value val = inival;
  try {
    std::cout <<"Esecuzione fold - ";
    con.Fold(fun, &val);
    std::cout << "valore ottenuto \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Corretto" : "Errore") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Corretto" : "Errore") << "!" << std::endl;
  }
}


template <typename Data>
void MapPreOrder(lasd::MutablePreOrderMappableContainer<Data>& con, bool chk, typename lasd::MutableMappableContainer<Data>::MutableMapFunctor fun) {
  bool tst = true;
  try {
    std::cout << "Esecuzione map in pre order - ";
    con.PreOrderMap(fun);
    std::cout << ": " << ((tst = chk) ? "Corretto" : "Errore") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Corretto" : "Errore") << "!" << std::endl;
  }
}


/* ************************************************************************** */

#endif
