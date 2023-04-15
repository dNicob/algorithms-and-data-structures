
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

/*FoldableContainer*/



template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& dato) const noexcept {
    bool exists = false;
    void* v = nullptr;
    FoldFunctor foldFunctor = [&exists, &dato](const Data& value, void* _){

        if(dato == value){
            exists = true;
        }
    };


    Fold(foldFunctor, v); 
    return exists;
};



/*PreOrderFoldableContainer*/
template <typename Data>
void PreOrderFoldableContainer<Data>::Fold(const FoldFunctor f, void * v) const {
    PreOrderFold(f, v); 
};


/*PostOrderFoldableContainer*/
template <typename Data>
void PostOrderFoldableContainer<Data>::Fold(const FoldFunctor f, void * v) const {
    PostOrderFold(f, v); 
};


/*InOrderFoldableContainer*/
template <typename Data>
void InOrderFoldableContainer<Data>::Fold(const FoldFunctor f, void * v) const {
    InOrderFold(f, v); 
};


/*BreadthFoldableContainer*/
template <typename Data>
void BreadthFoldableContainer<Data>::Fold(const FoldFunctor f, void * v) const {
    BreadthFold(f, v); 
};


/* ************************************************************************** */

}
