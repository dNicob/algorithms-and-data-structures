
namespace lasd {

/* ************************************************************************** */


template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(2){}


template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& mapCon){
    size = 2;
    datas = new Data[2];
    mapCon.Map([this](const Data& data){
        Enqueue(data);
    });
}


template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& mutMapCon){
    size = 2;
    datas = new Data[2];
    mutMapCon.Map([this](Data& data){
        Enqueue(std::move(data));
    });
}


//Copy Constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& queVec) : Vector<Data>(queVec) {
    head = queVec.head;
    lenght = queVec.lenght;
}


//Move Constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& queVec) : Vector<Data>(std::move(queVec)) {
    std::swap(head, queVec.head);
    std::swap(lenght, queVec.lenght);
}


//~Destructor
template <typename Data>
QueueVec<Data>::~QueueVec() {};


//Copy Assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queVec){
    Vector<Data>::operator=(queVec);
    head = queVec.head;
    lenght = queVec.lenght;
    return *this;
}


//Move Assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queVec) noexcept{
    Vector<Data>::operator=(std::move(queVec));
    std::swap(head, queVec.head);
    std::swap(lenght, queVec.lenght);

    return *this;

}


//Comparison Operator
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& queVec) const noexcept{
    ulong this_size = lenght;

    if(this_size != queVec.lenght){
        return false;
    }

    ulong temp_head = head;
    ulong temp2_head = queVec.head;
    for(ulong i = 0; i < this_size; i++){
        if(datas[temp_head] != queVec.datas[temp2_head]){
            return false;
        }

        temp_head = (temp_head + 1) % size;
        temp2_head = (temp2_head + 1) % size;
    }
    
    return true;
};



template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& queVec) const noexcept{
    return !operator==(queVec);
};


//Head (mutable)
template <typename Data>
Data& QueueVec<Data>::Head(){
    if(Empty()){
        throw std::length_error("Accesso a coda vuota");
    }

    return datas[head];
};


//Head (not-mutable)
template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(Empty()){
        throw std::length_error("Accesso a coda vuota");
    }

    return datas[head];
};


//Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue() {

    if(Empty()){
        throw std::length_error("Accesso a coda vuota");
    }

    head = (head + 1) % size;
    lenght--;
    if (lenght <= (size / 4))
    {
        Reduce();
    }
};


//HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    Data value = Head();
    Dequeue();
    return value;
};


//Enqueue (copy)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data) {
    ulong tail = Tail();
    if(lenght == size-1){
        Expand();
    }



    datas[tail] = data;
    lenght++;
    
};


//Enqueue (move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data) noexcept {
    ulong tail = Tail();
    if(lenght == size-1){
        Expand();
    }



    std::swap(datas[tail], data);
    lenght++;
    
};


//Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return(lenght == 0);
};


//Size
template <typename Data>
ulong QueueVec<Data>::Size() const noexcept{
    return lenght;
};


//Clear
template <typename Data>
void QueueVec<Data>::Clear() {
    delete[] datas;
    datas = nullptr;
    size = 2;
    head = 0;
    lenght = 0;
    
};


//SwapVectors
template <typename Data>
void QueueVec<Data>::SwapVectors(const ulong newSize) {

    this->size = newSize;
    ulong this_head = head;

    Data* tmpDatas = new Data[newSize];
    for (ulong i = 0; i < lenght; i++)
    {
        tmpDatas[i] = datas[this_head];
        this_head = (this_head + 1) % size;
    }
    head = 0;

    std::swap(datas, tmpDatas);
    delete[] tmpDatas;
    
};


//Expand
template <typename Data>
void QueueVec<Data>::Expand() {
    SwapVectors(this->size*2);
};


//Reduce
template <typename Data>
void QueueVec<Data>::Reduce() {
    SwapVectors(this->size/2);
};


//Tail
template <typename Data>
ulong QueueVec<Data>::Tail() const{
    return (head + lenght) % size;
};
/* ************************************************************************** */

}
