
#include <iostream>
#include <stdlib.h>
#include <random>

#include "test.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"



using namespace std;

string Scorrect =  "Passato!";
string Serror =  "Fallito!";
string Sresult;

default_random_engine Sgenerator(random_device{}());
uniform_int_distribution<uint> Sdist(1, 999);


// Stack test 1:
void StackTest1(){

    try{

        lasd::StackVec<int> stk;
        for(uint i = 0; i < 100; i++){ stk.Push(Sdist(Sgenerator)); }
        stk.Push(1000);

        lasd::StackVec<int> stk2(std::move(stk));

        for(uint i = 0; i < 100; i++){ stk2.Push(Sdist(Sgenerator)); }
        for(uint i = 0; i < 100; i ++){ stk2.Pop(); }

        if(stk.Size() == 0 && stk.Empty()){

            if(stk2.Size() == 101 && stk2.Top() == 1000){ Sresult = Scorrect; }
            else{ Sresult = Serror; }
        }
        else{ Sresult = Serror; }
    }
    catch(...){ Sresult = Serror; }

    cout << endl << "• Test 1: " << Sresult <<endl;     
}


// Stack test 2:
void StackTest2(){

    Sresult = Scorrect;

    try{

        lasd::StackVec<int> stk1;
        for(uint i = 0; i < 100; i++){ stk1.Push(Sdist(Sgenerator)); }
        for(uint i = 0; i < 100; i++){

            stk1.Push(Sdist(Sgenerator));
            stk1.Pop();
            stk1.Push(Sdist(Sgenerator));
        }

        // expected size 200
        lasd::StackVec<int> stk2(stk1);
        
        lasd::StackVec<int> stk3;
        stk3 = stk1;

        stk1.Clear();

        if(stk1.Size() != 0 || !(stk1.Empty())){ Sresult = Serror; }
        if(stk3.Size() != 200){ Sresult = Serror; }
        if(stk2 != stk3){ Sresult = Serror; }
    }
    catch(...){ Sresult = Serror; }

    cout << endl << "• Test 2: " << Sresult << endl; 
}


// Stack test 3:
void StackTest3(){

    Sresult = Scorrect;

    try{

        lasd::StackLst<int> stk;
        for(uint i = 0; i < 500; i++){ stk.Push(Sdist(Sgenerator)); }
        for(uint i = 0; i < 100; i++){ stk.Pop(); }
        
        lasd::StackLst<int> otherstack(std::move(stk));
        for(uint i = 0; i < 100; i++){ otherstack.Pop(); }
        
        for(uint i = 0; i < 100; i++){ stk.Push(Sdist(Sgenerator)); }

        lasd::StackLst<int> finalstack(stk);

        if(stk.Size() != 100 || stk.Empty()){ Sresult = Serror; }
        if(otherstack.Size() != 300 || finalstack.Size() != 100){ Sresult = Serror; }
        if(finalstack != stk){ Sresult = Serror; }
    }
    catch(...){ Sresult = Serror; }

    cout << endl << "• Test 3: " << Sresult << endl;
}


// Stack test 4:
void StackTest4(){

    Sresult = Scorrect;

    try{

        lasd::StackLst<int> simple;
        simple.Push(Sdist(Sgenerator));
        simple.Pop();

        lasd::StackLst<int> stk;
        for(uint i = 0; i < 500; i++){ stk.Push(Sdist(Sgenerator)); }
        stk.Push(1000);

        lasd::StackLst<int> otherstk;
        otherstk = stk;

        stk.Clear();

        if(!(simple.Empty()) || simple.Size() != 0){ Sresult = Serror; }
        if(!(stk.Empty()) || stk.Size() != 0){ Sresult = Serror; }
        if(otherstk.Top() != 1000 || otherstk.Size() != 501){ Sresult = Serror; }
    }
    catch(...){ Sresult = Serror; }

    cout << endl << "• Test 4: " << Sresult <<endl;
}