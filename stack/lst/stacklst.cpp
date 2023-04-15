
namespace lasd {

/* ************************************************************************** */


template <typename Data>
StackLst<Data>::StackLst(const MappableContainer<Data>& mapCon) : List<Data>(mapCon){}


template <typename Data>
StackLst<Data>::StackLst(MutableMappableContainer<Data>&& mutMapCon) : List<Data>(mutMapCon) {}


//Copy Constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stack) : List<Data>(stack) {}


//Move Constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stack) : List<Data>(std::move(stack)) {}


//Destructor
template <typename Data>
StackLst<Data>::~StackLst() {}


//Copy Assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stack) {
    List<Data>::operator=(stack);
    return *this;
}


//Move Assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stack) noexcept{
    List<Data>::operator=(std::move(stack));
    return *this;
}


//Comparison Operator
template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept{
    return List<Data>::operator==(stack);
}


template <typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stack) const noexcept{
    return List<Data>::operator!=(stack);
}


//Top
template <typename Data>
const Data& StackLst<Data>::Top() const{
    return List<Data>::Front();
}


template <typename Data>
Data& StackLst<Data>::Top(){
    return List<Data>::Front();
}


//Pop
template <typename Data>
void StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();
}


//TopNPop
template <typename Data>
Data StackLst<Data>::TopNPop(){
    return List<Data>::FrontNRemove();
}


//Push
template <typename Data>
void StackLst<Data>::Push(const Data& data){
    return List<Data>::InsertAtFront(data);
}


template <typename Data>
void StackLst<Data>::Push(Data&& data) noexcept {
    return List<Data>::InsertAtFront(std::move(data));
}



/* ************************************************************************** */

}
