
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


/*InsertAll copy*/
template <typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& mapCon) noexcept{

    

    bool flag = true;
    mapCon.Map([this, &flag](const Data& d){     //se almeno una volta diventa falso ritorna falso
       
        if(!(this->Insert(d))){
            flag = false;
        }
    });


    return flag;

}


/*InsertAll move*/
template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MutableMappableContainer<Data>&& mutMapCon) noexcept {

    bool flag = true;
    mutMapCon.Map([this, &flag](const Data& d){     //se almeno una volta diventa falso ritorna falso
       
        if(!(this->Insert(std::move(d)))){
            flag = false;
        }
    });


    return flag;

}


template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& mapCon) noexcept{

    bool flag = true;
    mapCon.Map([this, &flag](const Data& d){
        if(!(this->Remove(d))){
            flag = false;
        }
    });

    return flag;
}

/*InsertSome Copy*/
template <typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& mapCon) noexcept{

    bool flag = false; 
    mapCon.Map([this, &flag](const Data& d){ //se almeno una volta flag diventa vero la funzione ritorna vero
       if(this->Insert(d)){
            flag = true;
       }
    });

    return flag;

}


/*InsertSome Move*/
template <typename Data>
bool DictionaryContainer<Data>::InsertSome(MutableMappableContainer<Data>&& mutMapCon) noexcept{

    bool flag = false; 
    mutMapCon.Map([this, &flag](const Data& d){ //se almeno una volta flag diventa vero la funzione ritorna vero
       if(this->Insert(std::move(d))){
            flag = true;
       }
    });

    return flag;

}


template <typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& mapCon) noexcept{

    bool flag = false; 
    mapCon.Map([this, &flag](const Data& d){ //se almeno una volta flag diventa vero la funzione ritorna vero
       if(this->Remove(d)){
            flag = true;
       }
    });

    return flag;

}


/* ************************************************************************** */

}
