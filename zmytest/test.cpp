
#include "test.hpp"
#include "../zlasdtest/test.hpp"
#include "vectorTest.hpp"
#include "listTest.hpp"
#include "queueTest.hpp"
#include "stackTest.hpp"

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/foldable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

using namespace lasd;
#include<iostream>
#include<cstdlib>
#include<stdlib.h> 
#include<time.h>



void menu(){
    int opzione = 0;
    std::cout<<"Selezionare test da eseguire:\n1 - zlasdtest\n2 - zmytest"<<std::endl;
    std::cin>>opzione;
    switch (opzione)
    {
    case 1:
        lasdtest();
        break;
    case 2:
        mytest();
        break;

    default:
        break;
    }
}

void testVettori(){
    srand(time(NULL));

    Vector<int> vec1;
    Vector<int> copvec1(vec1);
    EqualVector(vec1, copvec1, true);


    ulong r = rand() % 1000 + 1;
    Vector<int> vecrand(r);

    
    setAt(vecrand, 0, 1, true);
    setAt(vecrand, 1, 2, true);
    setAt(vecrand, 2, 3, true);
    setAt(vecrand, 3, 4, true);
   
    
    Vector<int> vecrandcopy(vecrand);
    EqualVector(vecrand, vecrandcopy,true);


    Vector<int> vecrandmove(std::move(vecrand));
    EqualVector(vecrand, vecrandmove, false);
    
    vecrandmove.Clear();
    isClear(vecrandmove);
    EqualVector(vecrand, vecrandmove, true);

    vecrand.Resize(100);
    for (ulong i = 0; i < 100; i++)
    {   
        ulong x = rand()%100 + 1;
        vecrand[i] = x;
    }
    setAt(vecrand, 0, 101, false);
    setAt(vecrand, 0, 99, true);


    checkFront(vecrand);
    checkBack(vecrand);
    isSorted(vecrand, false);
    vecrand.Sort();
    isSorted(vecrand, true);
}



void auxFoldSum(const int& dat, void* acc){
    *((int *) acc) += dat;

}


void auxMutMapFunction(int& data){
    data = data * 2;
}


void auxMapFunctionPrint(const int& data){
    std::cout<<data<<" ";
}

void testVettoriDaMappable(){
    List<int> list;
    list.InsertAtBack(1);
    list.InsertAtBack(2);
    list.InsertAtBack(3);

    list.RemoveFromFront();
    list.Remove(3);
    Vector<int> vec(list);
    Fold(vec, true, &auxFoldSum,0 , 2);

    list.RemoveFromFront();
    Vector<int> vecDaListVuota(list);
    Fold(vecDaListVuota, true, &auxFoldSum,0 ,0);
    vecDaListVuota.~Vector();

    list.Clear();
    list.InsertAtBack(3);
    list.InsertAtBack(2);
    list.InsertAtBack(1);
    Vector<int> vec2(list);
    MapPreOrder(vec2, true, &auxMapFunctionPrint);
    MapPreOrder(vec2, true, &auxMutMapFunction);
    MapPreOrder(vec2, true, &auxMapFunctionPrint);

    vec2.Resize(20);

}


void testListe(){
    List<int> lst = List<int>();
    InsertTest(lst, 1 ,true);
    InsertTest(lst, 2 ,true);
    InsertTest(lst, 3 ,true);

    RemoveTest(lst, 3, true);
    RemoveTest(lst, 4, false);


    FrontNRemoveTest(lst, 1);
    InsertTest(lst, 5 ,true);

    PostOrderFoldTest(lst, true, &auxFoldSum, 0 ,7);
    lst.Clear();
    RemoveTest(lst, 4, false);
    InsertTest(lst, 3 ,true);
    RemoveTest(lst, 4, false);
    RemoveTest(lst, 3, true);

    InsertAtBackTest(lst, 3);
    InsertAtBackTest(lst, 4);
    InsertAtBackTest(lst, 5);
    InsertAtFrontTest(lst, 2, true);
    InsertAtFrontTest(lst, 1, true);

}


void mytest(){
    ulong i = system("clear");
    std::cout<<std::endl<<std::endl;
    std::cout<<"~#~#~#~ Test su vettori ~#~#~#~"<<std::endl;
    testVettori();
    testVettoriDaMappable();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~#~#~#~ Test su Liste ~#~#~#~"<<std::endl;
    testListe();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~#~#~#~ Test su stack ~#~#~#~"<<std::endl;
    StackTest1();
    StackTest2();
    StackTest3();
    StackTest4();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~#~#~#~ Test su Queue ~#~#~#~"<<std::endl;
    QueueTest1();
    QueueTest2();
    QueueTest3();
    QueueTest4();

}
