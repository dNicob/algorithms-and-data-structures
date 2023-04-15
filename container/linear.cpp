
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


//Front (non-mutable)
template <typename Data>
const Data& LinearContainer<Data>::Front() const{
    if(this->size != 0){
        return operator[](0);
    }else{
        throw std::length_error("Tentativo di accesso fuori range!");
    }
}


//Front (mutable)
template <typename Data>
Data& LinearContainer<Data>::Front(){
    if(this->size != 0){
        return operator[](0);
    }else{
        throw std::length_error("Tentativo di accesso fuori range!");
    }
}


//Back (non-mutable)
template <typename Data>
const Data& LinearContainer<Data>::Back() const{
    if(this->size != 0){
        return operator[](this->size-1);
    }else{
        throw std::length_error("Tentativo di accesso fuori range!");
    }
}


//Back (mutable)
template <typename Data>
Data& LinearContainer<Data>::Back(){
    if(this->size != 0){
        return operator[](this->size-1);
    }else{
        throw std::length_error("Tentativo di accesso fuori range!");
    }
}


//Fold 
template <typename Data>
void LinearContainer<Data>::Fold(const FoldFunctor ff, void* acc) const{
    PreOrderFold(ff, acc);
}

//PreOrderFold 
template <typename Data>
void LinearContainer<Data>::PreOrderFold(const FoldFunctor ff, void* acc) const{
   for (ulong i = 0; i < this->size; i++)
    {
        ff(operator[](i), acc);
    }
    
}

//PostOrderFold 
template <typename Data>
void LinearContainer<Data>::PostOrderFold(const FoldFunctor ff, void* acc) const{
    for (ulong i = this->size; i > 0; i--)
    {
        ff(operator[](i-1), acc);
    }
}


//Map 
template <typename Data>
void LinearContainer<Data>::Map(const MapFunctor mf) const{
    PreOrderMap(mf);
}


//PreOrderMap 
template <typename Data>
void LinearContainer<Data>::PreOrderMap(const MapFunctor mf) const{
   for (ulong i = 0; i < this->size; i++)
    {
        mf(operator[](i));
    }
}


//PostOrderMap 
template <typename Data>
void LinearContainer<Data>::PostOrderMap(const MapFunctor mf) const{
   for (ulong i = this->size; i > 0; i--)
    {
        mf(operator[](i-1));
    }
}


//Map (MutableMapFunctor) 
template <typename Data>
void LinearContainer<Data>::Map(const MutableMapFunctor mmf){
   PreOrderMap(mmf);
}


//PreOrderMap (MutableMapFunctor) 
template <typename Data>
void LinearContainer<Data>::PreOrderMap(const MutableMapFunctor mmf){
    for (ulong i = 0; i < this->size; i++)
    {
        mmf(operator[](i));
    }
}


//PostOrderMap (MutableMapFunctor) 
template <typename Data>
void LinearContainer<Data>::PostOrderMap(const MutableMapFunctor mmf){
    for (ulong i = this->size; i >0; i--)
    {
        mmf(operator[](i-1));
    }
}


/* ************************************************************************** */

}
