
namespace lasd {

/* ************************************************************************** */



template <typename Data>
StackVec<Data>::StackVec() : Vector<Data>(2) { }


template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& mapCon){
    this->size = mapCon.Size();
    this->datas = new Data[this->size];
    mapCon.Map([this](const Data& data){
        Push(data);
    });
}


template <typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&& mutMapCon) noexcept{
    size = mutMapCon.Size();
    datas = new Data[size];
    mutMapCon.Map([this](Data& data){
        Push(std::move(data));
    });
}

//Copy Constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stackvec) : Vector<Data>(stackvec){
    index = stackvec.index;
}


//Move Constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackvec) noexcept : Vector<Data>(stackvec){
    std::swap(index, stackvec.index);
}


//Destructor
template <typename Data>
StackVec<Data>::~StackVec() { };


//Copy Assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackvec) {
    Vector<Data>::operator=(stackvec);
    index = stackvec.index;
    return *this;
}


//Move Assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackvec) noexcept{
    Vector<Data>::operator=(stackvec);
    std::swap(index, stackvec.index);
    return *this;
}


//Comparison Operator
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stackvec) const noexcept{
    if (index != stackvec.index) {
        return false;
    }
    
    for (unsigned long i = 0; i < index; i++) {
        if (datas[i] != stackvec.datas[i]) {
            return false;
        }
    }
    
    return true;
}


template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stackvec) const noexcept{
     return !(*this == stackvec);
}


//Top (not-mutable)
template <typename Data>
const Data& StackVec<Data>::Top() const{
    if (Empty()) {
        throw std::length_error("Accesso ad un vettore vuoto");
    }
    
    return datas[index - 1];
}

//Top (mutable)
template <typename Data>
Data& StackVec<Data>::Top(){
    if (Empty()) {
        throw std::length_error("Accesso ad un vettore vuoto");
    }
    
    return datas[index - 1];
}


//Pop
template <typename Data>
void StackVec<Data>::Pop(){
   if(Empty()){
    throw std::length_error("Accesso a stack vuoto!");
   }

   index--;
   if(index <= this->size/4){
        Reduce();
   }
    
}


//TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop(){

    Data value = Top();
    Pop();
    return value;
}


//Push
template <typename Data>
void StackVec<Data>::Push(const Data& data){
    if(index == this->size - 1){
        Expand();
    }

    datas[index] = data; 
    index++;
}


template <typename Data>
void StackVec<Data>::Push(Data&& data) noexcept {
    if(index == this->size - 1){
        Expand();
    }

    std::swap(datas[index], data);
    index++; 
}


//Empty
template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
    return (Size() == 0);
}


//Size
template <typename Data>
ulong StackVec<Data>::Size() const noexcept{
    return index;
}


//Expand
template <typename Data>
void StackVec<Data>::Expand(){
    Vector<Data>::Resize(this->size * 2);
}


//Reduce
template <typename Data>
void StackVec<Data>::Reduce(){
    Vector<Data>::Resize(this->size / 2);
}


//Clear
template <typename Data>
void StackVec<Data>::Clear() {
    delete[] datas;
    this->size = 2;
    datas = new Data[2];
    index = 0;
}


/* ************************************************************************** */

}
