#ifndef LISTAORDINAZIONI_CPP
#define LISTAORDINAZIONI_CPP

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Lista.cpp"
#include "Ordinazione.cpp"

using namespace std;

class ListaOrdinazioni : public Lista<Ordinazioni>
{
    private:
        Nodo<Ordinazioni>* testa;
    public:
        ListaOrdinazioni();
        Nodo<Ordinazioni> * getTesta();
        void setTesta(Nodo<Ordinazioni> * x );  
        void inserisciInCoda(Nodo<Ordinazioni>* newNodo);
        void printList(double & tot) const;
        void printList() const;
};

#endif