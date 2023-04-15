
#include "vector.hpp"
#include "/home/nicola/Documenti/Università/Esami - II Anno - II Semestre/LASD/Esercizi/exercise1Copia/container/mappable.hpp"
#include "/home/nicola/Documenti/Università/Esami - II Anno - II Semestre/LASD/Esercizi/exercise1Copia/container/testable.hpp"
#include "/home/nicola/Documenti/Università/Esami - II Anno - II Semestre/LASD/Esercizi/exercise1Copia/container/linear.hpp"
#include "/home/nicola/Documenti/Università/Esami - II Anno - II Semestre/LASD/Esercizi/exercise1Copia/container/foldable.hpp"
#include "/home/nicola/Documenti/Università/Esami - II Anno - II Semestre/LASD/Esercizi/exercise1Copia/container/dictionary.hpp"
#include "/home/nicola/Documenti/Università/Esami - II Anno - II Semestre/LASD/Esercizi/exercise1Copia/container/container.hpp"
#include <stdio.h>
#include <iostream>

int main(){

    lasd::Vector<int> v1 = lasd::Vector<int>(6);
    lasd::Vector<int> v2 = lasd::Vector<int>(10);
    lasd::Vector<int> v4 = lasd::Vector<int>(2);

    std::cout<<"Size v1 "<<v1.Size()<<std::endl;
    std::cout<<"Size v2 "<<v2.Size()<<std::endl;

    lasd::Vector<int> v3 = lasd::Vector<int>(5);
    v3[0] = 1;
    v3[1] = 3;
    v3[2] = 5;
    v3[3] = 2;
    v3[4] = 4;


    std::cout<<v3[0]<<v3[1]<<v3[2]<<v3[3]<<v3[4]<<std::endl;

    v3.Sort();
    std::cout<<"sorted!\n"<<std::endl;

    std::cout<<v3[0]<<v3[1]<<v3[2]<<v3[3]<<v3[4]<<std::endl;


    lasd::Vector<int> v10 = lasd::Vector<int>(v3);

    std::cout<<"v10 from v3!\n"<<std::endl;

    std::cout<<v10[0]<<v10[1]<<v10[2]<<v10[3]<<v10[4]<<std::endl;


    if(v10 == v3){
            std::cout<<"v10 e v3 sono uguali!\n"<<std::endl;

    };


    

    
    

    

}