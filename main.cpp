#include <string>
#include <iostream>
#include <fstream>
#include "ListaPersona.cpp"

using namespace std;

ListaPersona* list = new ListaPersona();
double  tot = 0;
void leggifile(string nomefile );

int main()
{

    leggifile("Comande.txt");

    // S T A M P A   D E I   C O G N O M I   D E I   C L I E N T I
    list->printList();

    // S T A M P A   D I   T U T T E   L E   P I Z Z E   O R D I N A T E   D A   U N   C L I E N T E 
    // E D   I L   S U O   T O T A L E
    string nome = "Moltisanti";
    cout<<endl<<endl<<"le comande di "<<nome<<" sono : "<<endl;
    list->stampaPerCliente(nome, tot); 
    cout<<"il totale di "<<nome<< " speso e' : "<<tot<<endl<<endl<<endl;

    // E L I M I N A Z I O N E   D E I   C L I E N T I   
    // C H E   H A N N O   S P E S O   U N   T O T A L E   I N F E R I O R E   A L L A   M E D I A 
    cout<<"la media di quanto ha speso ogni cliente e' : "<<list->getMedia()<<endl;
    list->eliminaPerMedia();
    cout<<endl;
    // S T A M P A   D E I   C L I E N T I   R I M A S T I
    list->printList();

    return 0;
}

// F U N Z I O N E   P E R   I NS E R I R E   D A   F I L E   N E L L E   R I S P E T T I V E   L I S T E  
void leggifile(string nomefile )
{
    ifstream f(nomefile);
    char a;
    while (!f.eof())
    {
    string riga = "";
    string cognome = "";
    string pizza = "";
    string prezzoStr = "";
    double prezzo = 0;
    string quantitaStr = "";
    int quantita = 0;
        f >> riga;
        int i = 0;
        while (riga[i] != ',')
        {
            cognome += riga[i];
            ++i;
        }
        ++i;
        while (riga[i] != ',')
        {
            pizza += riga[i];
            ++i;
        }
        ++i;
        while (riga[i] != ',')
        {
            quantitaStr += riga[i];
            ++i;
        }
        ++i;
        quantita = stoi(quantitaStr);
        while (riga[i])
        {
            prezzoStr += riga[i];
            ++i;
        }
        prezzo = stod(prezzoStr);

        Nodo<Persona>* newPersona = new Nodo<Persona>(new Persona(cognome));
        Nodo<Ordinazioni>* newOrdinazione = new Nodo<Ordinazioni>(new Ordinazioni(pizza, prezzo, quantita));
        newPersona->getVal()->getLista()->inserisciInCoda(newOrdinazione);

        list->inserisciInCoda(newPersona);
    }

    f.close();
}
