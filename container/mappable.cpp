
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

/*MappableContainer*/
template <typename Data>   
void MappableContainer<Data>::Fold(const FoldFunctor f, void * acc) const{
    
    Map([f, &acc](const Data& data){
        f(data, acc);
    }
    );

}


/*PreOrderMappableContainer*/
template <typename Data>
void PreOrderMappableContainer<Data>::Map(const MapFunctor mapFunctor) const{
    PreOrderMap(mapFunctor);
}


template <typename Data>
void PreOrderMappableContainer<Data>::PreOrderFold(const FoldFunctor f, void * acc) const{

    Map([f, &acc](const Data& data){
            f(data, acc);
            }   
        );
}


template <typename Data>
void PreOrderMappableContainer<Data>::Fold(const FoldFunctor f, void * v) const{
    PreOrderFold(f, v);
}


/*PostOrderMappableContainer*/
template <typename Data>
void PostOrderMappableContainer<Data>::Map(const MapFunctor mapFunctor) const{
    PostOrderMap(mapFunctor);
}


template <typename Data>
void PostOrderMappableContainer<Data>::PostOrderFold(const FoldFunctor f, void * acc) const{

    PostOrderMap([f, &acc](const Data& data){
            f(data, acc);
        }
        );
}


template <typename Data>
void PostOrderMappableContainer<Data>::Fold(const FoldFunctor f, void * v) const{
    PostOrderFold(f,v);
}


/*InOrderMappableContainer*/
template <typename Data>
void InOrderMappableContainer<Data>::Map(const MapFunctor mapFunctor) const{
    InOrderMap(mapFunctor);
}


template <typename Data>
void InOrderMappableContainer<Data>::InOrderFold(const FoldFunctor f, void * acc) const{
     InOrderMap([f, &acc](const Data& data){
            f(data, acc);
        }
        );
}

template <typename Data>
void InOrderMappableContainer<Data>::Fold(const FoldFunctor f, void * v) const{
    InOrderFold(f,v);
}


/*BreadthMappableContainer*/
template <typename Data>
void BreadthMappableContainer<Data>::Map(const MapFunctor mapFunctor) const{
    BreadthMap(mapFunctor);
}


template <typename Data>
void BreadthMappableContainer<Data>::BreadthFold(const FoldFunctor f, void * acc) const {
    BreadthMap([f, &acc](const Data& data){
            f(data, acc);
        }
        );
}


template <typename Data>
void BreadthMappableContainer<Data>::Fold(const FoldFunctor f, void * v) const {
    BreadthFold(f,v);
}


/*MutablePreOrderMappableContainer*/
template <typename Data>
void MutablePreOrderMappableContainer<Data>::Map(const MutableMapFunctor mutMapFunctor){
    PreOrderMap(mutMapFunctor);
}


/*MutablePostOrderMappableContainer*/
template <typename Data>
void MutablePostOrderMappableContainer<Data>::Map(const MutableMapFunctor mutMapFunctor){
    PostOrderMap(mutMapFunctor);
}


/*MutableInOrderMappableContainer*/
template <typename Data>
void MutableInOrderMappableContainer<Data>::Map(const MutableMapFunctor mutMapFunctor){
    InOrderMap(mutMapFunctor);
}


/*MutableBreadthMappableContainer*/
template <typename Data>
void MutableBreadthMappableContainer<Data>::Map(const MutableMapFunctor mutMapFunctor){
    BreadthMap(mutMapFunctor);
}



/* ************************************************************************** */

}
