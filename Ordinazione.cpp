#ifndef ORDINAZIONE_CPP
#define ORDINAZIONE_CPP

#include <string>
#include <iostream>

using namespace std;


class Ordinazioni
{
    string nomePizza;
    double prezzo;
    int quantita;
    
    public:
        Ordinazioni(string a , double b , int c) : nomePizza(a) , prezzo(b) , quantita(c) {}
        string getNomePizza() const;
        double getPrezzo() const;
        int getQuantita() const;
        void setNomePizza(string );
        void setPrezzo(double );
        void setQuantita( int );
};


// G E T T E R S
string Ordinazioni::getNomePizza() const
{
    return nomePizza;
}
double Ordinazioni::getPrezzo() const
{
    return prezzo;
}
int Ordinazioni::getQuantita() const
{
    return quantita; 
}


// S E T T E R S
void Ordinazioni::setNomePizza(string pizza)
{
    nomePizza = pizza;
}
void Ordinazioni::setPrezzo(double x )
{
    prezzo = x;
}
void Ordinazioni::setQuantita( int numero )
{
    quantita = numero;
}

#endif
