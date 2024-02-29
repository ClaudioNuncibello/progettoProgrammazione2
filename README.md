# progettoProgrammazione2
# Programmazione 2 appello del 7 luglio 2021 Claudio Nuncibello

Scelte progettuali:
  ho deciso di gestire gli input da file creando la classe Persona che, oltre al cognome del cliente, ha un
  puntatore alla lista di ordinazioni in modo da svolgere il primo quesito del compito ( Raggruppare le
  ordinazioni per cliente ) direttamente all’inserimento.
  Al termine dell’inserimento quello che si otterrà è una lista di Nodi<Persona>, ognuno dei quali ha come
  valore un oggetto Persona istanziato con il cognome e un puntatore ad una lista di Ordinazioni.
  Funzioni utilizzate in questo punto : ListaPersona::inserisciInCoda(Nodo<Persona> *),
  ListaOrdinazioni:: inserisciInCoda(Nodo<Ordinazioni> *)
  Una volta implementata la parte di cui sopra, si procede con lo sviluppo di quanto richiesto ai punti 3 e 4.

In particolare :
  1. per il punto 3 ho sviluppato un metodo di ListaPersona che prende in input la stringa cognome, e un
  puntatore ad una variabile double( per salvarci il totale speso dal cliente) , il metodo stampa tutte le
  Comande dell’oggetto Persona con quel cognome.
  Funzioni utilizzate in questo punto : ListaPersona::stampaPerCliente(string , double & ) ,
  ListaOrdinazioni::printlist(double & ).

  3. Per il punto 4 ho invece sviluppato un ulteriore metodo di ListaPersona che, calcolata la media,
  confronta quest’ultima al totale speso da ogni cliente (calcolato tramite la funzione totale() ) e
  successivamente, se il totale speso risulta inferiore alla media, elimina dalla lista e salva sul file
  cancellati.txt il Nodo<Persona>, contenente l’oggetto persona.
  Funzioni utilizzate in questo punto : ListaPersona::eliminapermedia() , ListaPersona::totale(Nodo<Persona> *),
  ListaPersona::eliminazione(Nodo<Persona> *) , ListaPersona::getMedia.
