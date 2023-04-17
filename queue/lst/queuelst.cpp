
namespace lasd {

/* ************************************************************************** */


template <typename Data>
QueueLst<Data>::QueueLst(const MappableContainer<Data>& mapCon) : List<Data>(mapCon){}


template <typename Data>
QueueLst<Data>::QueueLst(MutableMappableContainer<Data>&& mutMapCon) : List<Data>(mutMapCon) {}


//Copy Constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& queue) : List<Data>(queue) {}


//Move Constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& queue) : List<Data>(std::move(queue)) {}


//Destructor
template <typename Data>
QueueLst<Data>::~QueueLst() {}


//Copy Assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queue) {
    List<Data>::operator=(queue);
    return *this;
}


//Move Assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queue) noexcept{
    List<Data>::operator=(std::move(queue));
    return *this;
}


//Comparison Operator
template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& queue) const noexcept{
    return List<Data>::operator==(queue);
}


template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst<Data>& queue) const noexcept{
    return List<Data>::operator!=(queue);
}


//Head (not-mutable)
template <typename Data>
const Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}


//Head (mutable)
template <typename Data>
Data& QueueLst<Data>::Head(){
    return List<Data>::Front();
}


//Dequeue
template <typename Data>
void QueueLst<Data>::Dequeue(){
    return List<Data>::RemoveFromFront();
}


//HeadNDequeue
template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    Data value = List<Data>::Front();
    List<Data>::RemoveFromFront();
    return value;
}


//Enqueue (copy)
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& data){
     List<Data>::InsertAtBack(data);
}


//Enqueue (move)
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& data) noexcept {
     List<Data>::InsertAtBack(std::move(data));
}



/* ************************************************************************** */

}
