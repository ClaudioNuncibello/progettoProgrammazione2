#ifndef LISTA_CPP
#define LISTA_CPP

#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Nodo
{
    T* val;
    Nodo<T>* succ;
    public:
    
        Nodo(T* val) {this->val = val; succ=NULL;}
        Nodo<T>* getSucc() const {return succ;}
        void setSucc(Nodo<T>* nuovo){succ = nuovo;}
        T* getVal() const {return val;}
};

template <class T>
class Lista
{
    public:
        Lista(){} 
        virtual void inserisciInCoda(Nodo<T>* newNodo) = 0;
        virtual void printList() const =0;
};

#endif