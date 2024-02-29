#include "ListaOrdinazioni.h"

ListaOrdinazioni::ListaOrdinazioni()
{
    testa = NULL;
}

// I N S E R I M E N T O   D E L L E   C O M A N D E   D I   U N   C L I E N T E
void ListaOrdinazioni::inserisciInCoda(Nodo<Ordinazioni>* newNodo)
{
    Nodo<Ordinazioni>* prec;
    Nodo<Ordinazioni>* app = testa;

    if(app == NULL){
        testa = newNodo;
    }
    else{
        while(app != NULL)
        {
            prec = app;
            app = app->getSucc();
        }

        prec->setSucc(newNodo);
    }
}


void ListaOrdinazioni::setTesta(Nodo<Ordinazioni> * x ) 
{
    testa = x;
}

Nodo<Ordinazioni> * ListaOrdinazioni::getTesta()
{
    return testa;
}


// S T A M P A    D E L L E   P I Z Z E   P E R   C L I E N T E 
void ListaOrdinazioni:: printList(double & tot) const
{
    Nodo<Ordinazioni>* prev = testa;
    while(prev != NULL)
    {
        cout<<prev->getVal()->getNomePizza()<<" "<<prev->getVal()->getPrezzo()<<" "<<prev->getVal()->getQuantita()<<endl;
        tot += prev->getVal()->getPrezzo() * prev->getVal()->getQuantita();
        prev = prev->getSucc();
    } 
}


void ListaOrdinazioni::printList() const
{
    
}
