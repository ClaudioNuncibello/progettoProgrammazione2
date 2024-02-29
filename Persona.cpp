#ifndef PERSONA_CPP
#define PERSONA_CPP

#include <string>
#include <iostream>
#include "ListaOrdinazioni.cpp"


using namespace std;

class Persona
{
    string cognome;
    ListaOrdinazioni* Listacliente;

    public:
     
    Persona(string x ) : cognome(x), Listacliente(new ListaOrdinazioni()) {}
    string getCognome() const;
    void setCognome(string);
    ListaOrdinazioni * getLista() const;
    void setHead(Nodo<Ordinazioni> * x );
};


// G E T T E R S
string Persona::getCognome() const
{
    return this->cognome;
}
ListaOrdinazioni * Persona::getLista() const
{
    return Listacliente;
}

// S E T T E R S
void Persona::setCognome(string x)
{
    cognome = x;
}

void Persona::setHead(Nodo<Ordinazioni> * x )
{
    Listacliente->setTesta(x);
}

#endif


