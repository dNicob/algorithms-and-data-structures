
#include <iostream>

namespace lasd {

/* ************************************************************************** */




//costruttore con dimensione iniziale data
template <typename Data>
Vector<Data>::Vector(ulong newsize){
    try{
        datas = new Data[newsize] {};
        this->size = newsize;
    }catch(std::bad_alloc){
        std::cout<<"Allocazione della memoria non riuscita!"<<std::endl;
    }
};



//Costruttore a partira da MappableContainer
template <typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& con){
    this->Resize(con.Size());
    ulong index = 0;
    con.Map([this, &index](const Data& d){
        operator[](index) = d;
        index++;
        });
}


//Costruttore a partira da MutableMappableContainer
template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& con){
    
    this->Resize(con.Size());
    ulong index = 0;
    con.Map([this, &index](Data& data){operator[](index) = std::move(data); index++;});
}


//copy-constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& v){
    this->size = v.size;
    datas = new Data[this->size];
    for (int i = 0; i < size; i++)
    {
       datas[i] = v.datas[i];
    }
};


//move-constructor
template <typename Data>
Vector<Data>::Vector(Vector<Data>&& v){
    //il prof scambia le size e i puntatori con la funzione std::swap
    std::swap(size, v.size);
    std::swap(datas, v.datas);
};

//Destructor
template <typename Data>
Vector<Data>::~Vector(){
    delete[] datas;
};


//Copy Assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator= (const Vector<Data>& v){
    this->Resize(v.size);
    for (int i = 0; i < size; i++)
    {
       datas[i] = v.datas[i];
    }
    return *this;
};


//Move Assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator= (Vector<Data>&& v) noexcept{

    std::swap(size, v.size);
    std::swap(datas, v.datas);

    return *this;
};


// Comparison operator ==
template <typename Data>
bool Vector<Data>::operator== (const Vector<Data>& v) const noexcept{
   
   if(this->size == v.size){
        for (ulong i = 0; i < this->size; i++)
        {
            if(datas[i] != v.datas[i]){
                return false;
            }
        }
        return true;
   }else{
        return false;
   }
};


// Comparison operator  !=
template <typename Data>
bool Vector<Data>::operator!= (const Vector<Data>& v) const noexcept{
   return !(*this == v);
};


//Clear Function
template <typename Data>
void Vector<Data>::Clear(){
    Resize(0);
};


//Resize Function
template <typename Data>
void Vector<Data>::Resize(const ulong newsize){
    if(newsize == 0){
        delete[] datas;
        datas = nullptr;
        this->size = 0;
    }else if(newsize == this->size){
        return;
    }else{
        ulong limit = (this->size < newsize) ? this->size : newsize;
        this->size = newsize;
        Data* tmpDatas = new Data[newsize];
        for (ulong i = 0; i < limit; i++)
        {
            tmpDatas[i] = datas[i];
        }
        std::swap(datas, tmpDatas);
        delete[] tmpDatas;
        
    }

};


//Operator [] (NotMutable)
template <typename Data>
const Data& Vector<Data>::operator[](const ulong index) const{
    if(index < size){
        return datas[index];
    }else{
        throw std::out_of_range("Tentativo di accesso fuori range!");
    }

};


//Operator [] (Mutable)
template <typename Data>
Data& Vector<Data>::operator[](ulong index) {
    if(index < size){
        return datas[index];
    }else{
        throw std::out_of_range("Tentativo di accesso fuori range!");
    }
};


//Front() (NotMutable)
template <typename Data>
const Data& Vector<Data>::Front() const {
    if(!(Empty())){
        return datas[0];
    }else{
        throw std::length_error("Tentativo di accesso ad un vettore vuoto!!");
    }
};


//Front() (Mutable)
template <typename Data>
Data& Vector<Data>::Front(){
    if(!(Empty())){
        return datas[0];
    }else{
        throw std::length_error("Tentativo di accesso ad un vettore vuoto!!");
    }

};


//Back() (NotMutable)
template <typename Data>
const Data& Vector<Data>::Back() const {
    if(!(Empty())){
        return datas[size-1];
    }else{
        throw std::length_error("Tentativo di accesso ad un vettore vuoto!!");
    }
};


//Back() (Mutable)
template <typename Data>
Data& Vector<Data>::Back() {
    if(!(Empty())){
        return datas[size-1];
    }else{
        throw std::length_error("Tentativo di accesso ad un vettore vuoto!!");
    }
};


//Sort
template <typename Data>
void Vector<Data>::Sort(){
    for (ulong i = 0; i < size - 1; i++)
    {
        ulong indice = i;
        for (ulong j = i + 1; j < size; j++)
        {
            if(datas[j] < datas[indice]){
                indice = j;
            }
        }
        if (indice!=i)
            std::swap(datas[indice], datas[i]);
    }
    
}


/* ************************************************************************** */

}
