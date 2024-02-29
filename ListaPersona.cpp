#ifndef LISTAPERSONA_CPP
#define LISTAPERSONA_CPP

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Lista.cpp"
#include "Persona.cpp"

using namespace std;

// L I S T A   D I   C L I E N T I
class ListaPersona : public Lista<Persona>
{
    private:
        Nodo<Persona>* testa; // P U N T A T O R E   A L L ' O G G E T T O   P E R S O N A 
    public:
        ListaPersona() : testa(NULL) {}
        Nodo<Persona> * getTesta() {return testa;}
        void inserisciInCoda() {}
        void inserisciInCoda(Nodo<Persona>* newNodo);
        void printList() const;
        void stampaPerCliente(string cognome , double & tot);
        double getMedia() ;
        void eliminaPerMedia();
        void eliminazione(Nodo<Persona>* );
        double totale(Nodo<Persona> * );

};

// I N S E R I M E N T O   G I A'   R A G G R U P P A T O   P E R   C L I E N T E
void ListaPersona::inserisciInCoda(Nodo<Persona>* newNodo)
{   
    Nodo<Persona>* prec = testa;
    Nodo<Persona>* app = testa;

    if(app == NULL){
        testa = newNodo;
    }
    else{
        while(app != NULL)
        {
            prec = app;

            if(app->getVal()->getCognome() == newNodo->getVal()->getCognome()){
                app->getVal()->getLista()->inserisciInCoda(newNodo->getVal()->getLista()->getTesta());
                return;
            }

            app = app->getSucc();
        }

        prec->setSucc(newNodo);
    }
}

// S T A M P A   D E I   C L I E N T I
void ListaPersona::printList() const
{
    Nodo<Persona>* prev = testa;
    if(prev == NULL) cout<<"non c'e' nulla";
    while(prev != NULL)
    {
        cout<<prev->getVal()->getCognome()<<endl;
        prev = prev->getSucc();
    }
    
}


// C A L C O L O   D E L L A   S P E S A   M E D I A   F A T T A   D A I   C L I E N T I
double ListaPersona::getMedia() 
{
    double media = 0;
    int cont = 0;
    Nodo<Persona>* prev = testa;
    if(prev == nullptr) cout<<"non c'e' nulla";
    while(prev != nullptr)
    {
        ++cont;
        media += this->totale(prev);
        prev = prev->getSucc();
    }
    return media/cont;
    
}

// E L I M I N Z A I O N E   D E I   C L I E N T I   S O T T O   L A   S P E S A   M E D I A 
void ListaPersona::eliminaPerMedia()
{
    double somma = 0;
    double media = this->getMedia();
    Nodo<Persona>* prev = testa;
    Nodo<Persona>* app = testa;
    Nodo<Persona>* successivo = testa;
    if(prev == NULL) cout<<"non c'è nulla";
    while(prev != nullptr)
    {
        somma=this->totale(prev);
        if(somma < media)
        {  
            this->eliminazione(prev);
        }
        somma=0;
        prev = prev->getSucc(); 
    }   
}

// S T A M P A  C O M A N D E 
void ListaPersona::stampaPerCliente(string cognome , double & tot)
{
    Nodo<Persona>* prev = testa;
    while(prev != NULL)
    {
        if(prev->getVal()->getCognome() == cognome)
             prev->getVal()->getLista()->printList(tot);
        prev = prev->getSucc();
    }
}


// E L I M I N A Z I O N E  D I   U N   C L I E N T E  E  S T A M P A   S U   F I L E 
void ListaPersona::eliminazione(Nodo<Persona>* prev)
{   
    ofstream del("cancellati.txt", ios::app);
    Nodo<Persona>* ptr = testa;
    Nodo<Persona>* precedente = testa;
    if(prev == NULL) 
    cout<<"non c'è nulla";
        do
        {
            if(prev->getVal()->getCognome() == ptr->getVal()->getCognome())
            {
                if(ptr==testa)
                {
                    cout<<"eliminato "<<prev->getVal()->getCognome()<<" con totale speso : "<<this->totale(prev)<<endl;
                    del<<prev->getVal()->getCognome()<<endl;
                    Nodo<Ordinazioni> * nodoeliminato = prev->getVal()->getLista()->getTesta();
                    while(nodoeliminato != nullptr)
                    {
                        del<<nodoeliminato->getVal()->getNomePizza()<<","<<nodoeliminato->getVal()->getPrezzo()<<","<<","<<nodoeliminato->getVal()->getQuantita()<<","<<nodoeliminato->getVal()->getQuantita()<<endl;
                        nodoeliminato = nodoeliminato->getSucc();
                    }
                    testa = ptr->getSucc();
                    return; 
                }
                else
                {
                    cout<<"eliminato "<<prev->getVal()->getCognome()<<" con totale speso : "<<this->totale(prev)<<endl;
                    del<<prev->getVal()->getCognome()<<endl;
                    Nodo<Ordinazioni> * nodoeliminato = prev->getVal()->getLista()->getTesta();
                    while(nodoeliminato != nullptr)
                    {
                        del<<nodoeliminato->getVal()->getNomePizza()<<","<<nodoeliminato->getVal()->getPrezzo()<<","<<","<<nodoeliminato->getVal()->getQuantita()<<","<<nodoeliminato->getVal()->getQuantita()<<endl;
                        nodoeliminato = nodoeliminato->getSucc();
                    }
                    precedente->setSucc(ptr->getSucc());
                    return;

                }
             

            }
            precedente = ptr;
            ptr = ptr->getSucc(); 

        }while(ptr->getSucc() != nullptr);

    del.close(); 
}

// C A L C O L O   T O T A L E   S P E S O   D I   U N A   P E R S O N A  
double ListaPersona::totale(Nodo<Persona> * persona )
{
    double somma=0;
    Nodo<Ordinazioni> * ptr = persona->getVal()->getLista()->getTesta();
    while(ptr != nullptr)
    {
        somma += (ptr->getVal()->getPrezzo()) * (ptr->getVal()->getQuantita());
        ptr = ptr->getSucc();
    }
    return somma;
}


#endif
