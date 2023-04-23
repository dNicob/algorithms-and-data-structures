

namespace lasd {

/* ************************************************************************** */


//Node Specific Constructors
template <typename Data>
List<Data>::Node::Node(const Data& Value){
    value = Value;     
}


template <typename Data>
List<Data>::Node::Node(Data&& Value){
    value = std::move(Value);     
}


//Node Copy-Constructor
template <typename Data>
List<Data>::Node::Node(const Node& cpNode){
    value = cpNode.value;
}


//Node Move-Constructor
template <typename Data>
List<Data>::Node::Node(Node&& cpNode){
    std::swap(value, cpNode.value);
    std::swap(next, cpNode.next);
}


//Node operator ==
template <typename Data>
bool List<Data>::Node::operator==(const Node& t_Node) const noexcept{
      return(value == t_Node.value && next == t_Node.next);
    };

//Node Copy-Constructor
template <typename Data>
bool List<Data>::Node::operator!=(const Node& t_Node) const noexcept{
      return(!(*this == t_Node));
    };


// A list obtained from a MappableContainer
template <typename Data>
List<Data>::List(const MappableContainer<Data>& mapCon){

     mapCon.Map([this](const Data& data){
        this->InsertAtBack(data);
    });
}


// A list obtained from a MutableMappableContainer
template <typename Data>
List<Data>::List(MutableMappableContainer<Data>&& mutMapCon){

      mutMapCon.Map([this](Data& data){
        this->InsertAtBack(std::move(data));
    });
}


//Copy-Constructor
template <typename Data>
List<Data>::List(const List& list){
   
    if(list.head != nullptr){
        Node* temp = list.head;
        while(temp != nullptr){
            this->InsertAtBack(temp->value);
            temp = temp->next;
        }
    }
    
}


//Move constructor
template <typename Data>
List<Data>::List(List&& list) noexcept {
    std::swap(size, list.size);
    std::swap(head, list.head);
    std::swap(tail, list.tail);
}


//Destructor
template <typename Data>
List<Data>::~List(){
    this->Clear();
    delete head;
    delete tail;
}


//Copy-Assignment
template <typename Data>
List<Data>& List<Data>::operator= (const List<Data>& list){

    if(this != &list){    
        this->Clear();

        if(list.head != nullptr){
            Node* temp = list.head;

            while(temp != nullptr){
                this->InsertAtBack(temp->value);
                temp = temp->next;
            }
        }
    }
    return *this;
}


//Move-Assignment
template <typename Data>
List<Data>& List<Data>::operator= (List<Data>&& list) noexcept{
    std::swap(size, list.size);
    std::swap(head, list.head);
    std::swap(tail, list.tail);

    return *this;
}


//Comparison Operators
template <typename Data>
bool List<Data>::operator== (const List<Data>& list) const noexcept{
    
        if (this->size != list.size){
            return false;
        }


        Node* temp = head;
        Node* temp2 = list.head;

        for(ulong i = 0; i < this->size; i++){

            if(temp->value != temp2->value){
                return false;
            }

            temp = temp->next;
            temp2 = temp2->next;
        }

        return true;
        
}


template <typename Data>
bool List<Data>::operator!= (const List<Data>& list) const noexcept{
   return !(*this == list);
}


//InsertAtFront (copy)
template <typename Data>
void List<Data>::InsertAtFront(const Data& d){

   this->size++;
   Node * newNode = new Node(d);

   if(head == nullptr){
    head = tail = newNode;
    return;
   }


   newNode->next = head;
   head = newNode; 
   
}


//InsertAtFront (move)
template <typename Data>
void List<Data>::InsertAtFront(Data&& d){
    this->size++;


   Node * newNode = new Node(std::move(d));
   if(head==nullptr){
    head = tail = newNode;
    return;
   }


   newNode->next = head;
   head = newNode; 
}


//RemoveFromFront 
template <typename Data>
void List<Data>::RemoveFromFront(){
   if(head == nullptr){
    throw(std::length_error("Tentativo di rimuovere un elemento da una lista vuota!"));
   }

   if(size == 1){
    tail = nullptr;
   }

   Node* temp = head;
   head = head->next;
   temp->next = nullptr;
   delete temp;
   this->size--; 
}


//Front&Remove 
template <typename Data>
Data List<Data>::FrontNRemove(){
   Data front = this->Front();
   this->RemoveFromFront();

   return front;
}


//InsertAtBack (copy)
template <typename Data>
void List<Data>::InsertAtBack(const Data& d){
   
    this->size++;
    Node* newNode = new Node(d);
    
    if (tail == nullptr) {
        tail = head = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = tail->next;
}


//InsertAtBack (move)
template <typename Data>
void List<Data>::InsertAtBack(Data&& d){
   
   this->size++;
   Node* newNode = new Node(std::move(d));
   if (tail == nullptr){
        tail = head = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = tail->next;

}


//Clear
template <typename Data>
void List<Data>::Clear(){
    while(head != nullptr){
        this->RemoveFromFront();
    }

    tail = head;
}


//Insert (copy)
template <typename Data>
bool List<Data>::Insert(const Data& d) noexcept{
    ulong preSize = this->size;
    if(!(this->Exists(d))){
        this->InsertAtBack(d);
    }
    return (this->size > preSize);
}


//Insert (move)
template <typename Data>
bool List<Data>::Insert(Data&& d) noexcept{
    ulong preSize = this->size;
    if(!(this->Exists(d))){
        this->InsertAtBack(std::move(d));
    }
    return (this->size > preSize);
}


//Remove
template <typename Data>
bool List<Data>::Remove(const Data& d) noexcept{  

    if(head!= nullptr){
        if(head->value == d){
            this->RemoveFromFront();
            return true;
        }
            Node* temp = head;
            Node* prev = temp;
            temp = temp->next;
            while(temp != nullptr && temp->value != d){
                prev = temp;
                temp = temp->next;
            }
            if(temp == nullptr){
                return false;
            }
            if(temp == tail){
                prev->next = nullptr;
                tail = prev;
                delete temp;
                this->size--;
                return true;
            }
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
            this->size--;
            return true;
   }
    return false;
}


//Operator[]  (not mutable)
template <typename Data>
const Data& List<Data>::operator[](const ulong index) const{  
    if(index >= this->size){
        throw std::length_error("Tentativo di accesso fuori range.");
    }

    if(index == this->size-1){
        return this->Back();
    }

    if(index == 0){
        return this->Front();
    }


    Node* temp = head;
    for (ulong i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->value;

}


//Operator[]  (mutable)
template <typename Data>
Data& List<Data>::operator[](const ulong index){  
    if(index >= this->size){
        throw std::length_error("Tentativo di accesso fuori range.");
    }

    if(index == this->size-1){
        return this->Back();
    }

    if(index == 0){
        return this->Front();
    }


    Node* temp = head;
    for (ulong i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->value;

}


//Front (not mutable)
template <typename Data>
const Data& List<Data>::Front() const{  
    if(head != nullptr){
        return head->value;
    }

    throw std::length_error("Tentativo di accesso a lista vuota");
    
}


//Front (mutable)
template <typename Data>
Data& List<Data>::Front(){  
      if(head != nullptr){
        return head->value;
    }

    throw std::length_error("Tentativo di accesso a lista vuota");
}


//Back (not mutable)
template <typename Data>
const Data& List<Data>::Back() const{  
    if(tail != nullptr){
        return tail->value;  
    }

    throw std::length_error("Tentativo di accesso a lista vuota");   
}


//Back (mutable)
template <typename Data>
Data& List<Data>::Back(){  
    if(tail != nullptr){
        return tail->value;  
    }

    throw std::length_error("Tentativo di accesso a lista vuota");   
}



//Fold
template <typename Data>
void List<Data>::Fold(const FoldFunctor ff, void* accumulator) const{  

    Node* temp = head;

    while (temp != nullptr)
    {
        ff(temp->value, accumulator);
        temp = temp->next;
    }
}


//PreOrderFold (ausiliare)
template <typename Data>
void List<Data>::PreOrderFold(const FoldFunctor ff, void* acc, Node* start) const{  

    if(start != nullptr){

        ff(start->value, acc);
        this->PreOrderFold(ff, acc, start->next);
        
    }
}


//PreOrderFold
template <typename Data>
void List<Data>::PreOrderFold(const FoldFunctor ff, void* acc) const{  
    this->PreOrderFold(ff, acc, head);
}


//PostOrderFold (ausiliare)
template <typename Data>
void List<Data>::PostOrderFold(const FoldFunctor ff, void* acc, Node* start) const{  

    if(start != nullptr){

        this->PostOrderFold(ff, acc, start->next);
        ff(start->value, acc);
    }
}


//PostOrderFold 
template <typename Data>
void List<Data>::PostOrderFold(const FoldFunctor ff, void* acc) const{  
    this->PostOrderFold(ff, acc, head);
}


//Map
template <typename Data>
void List<Data>::Map(const MapFunctor mf) const{  

    Node* temp = head;
    while(temp != nullptr){
        mf(temp->value);
        temp = temp->next;
    }
    
}


//PreOrderMap (ausiliare)
template <typename Data>
void List<Data>::PreOrderMap(const MapFunctor mf, Node* start) const{  

    if(start != nullptr){
        mf(start->value);
        this->PreOrderMap(mf, start->next);
    }
    
}


//PreOrderMap 
template <typename Data>
void List<Data>::PreOrderMap(const MapFunctor mf) const{  
    this->PreOrderMap(mf, head);
}


//PostOrderMap (ausiliare)
template <typename Data>
void List<Data>::PostOrderMap(const MapFunctor mf, Node* start) const{  
    if(start != nullptr){
        this->PreOrderMap(mf, start->next);
        mf(start->value);
    }
    
}


//PostOrderMap 
template <typename Data>
void List<Data>::PostOrderMap(const MapFunctor mf) const{  
    this->PostOrderMap(mf, head);
}


//Map (mutableMapFunctor)
template <typename Data>
void List<Data>::Map(const MutableMapFunctor mmf){  

    Node* temp = head;
    while (temp != nullptr)
    {
        mmf(temp->value);
        temp = temp->next;
    }
}


//PreOrderMap (ausiliare)
template <typename Data>
void List<Data>::PreOrderMap(const MutableMapFunctor mmf, Node* start){  

    if(start != nullptr){
        mmf(start->value);
        this->PreOrderMap(mmf, start->next);
    }
}


//PreOrderMap 
template <typename Data>
void List<Data>::PreOrderMap(const MutableMapFunctor mmf){  
    
     this->PreOrderMap(mmf, head);
}


//PostOrderMap (ausiliare)
template <typename Data>
void List<Data>::PostOrderMap(const MutableMapFunctor mmf, Node* start){  

    if(start != nullptr){
        this->PostOrderMap(mmf, start->next);
        mmf(start->value);
    }
}


//PostOrderMap 
template <typename Data>
void List<Data>::PostOrderMap(const MutableMapFunctor mmf){  
    
     this->PostOrderMap(mmf, head);
}
/* ************************************************************************** */

}