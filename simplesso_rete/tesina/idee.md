# Simplesso su reti
## Sezioni
idee.md
*  Intro
    * motivazioni uso
*  Descrizione generale
    * Algoritmo
    *  problematiche genereali a tutte le implementazioni
* Campi di applicazione
* Implementazione
    * Formulazione teorica
    * strutture dati usati
    * algoritmo
    * risultati
    * grafo iniziale
    * soluzione

## Intro
Il simplesso su reti è un algoritmo che nasce applicare l'algoritmo del simplesso in campi dove usarlo in modo diretto risulta essere poco
performante.Per funzionare usa un grafo e passa da una soluzione ammissibile all'altra fino a quando non trova quella ottimale.
Questo algoritmo viene usato in modo intuitivo in campi dove si presentano problemi di flusso o dove il problema di ottimizzazione può essere visto come un problema di flusso.
## Intro 2
Il simplesso su rete è un'algoritmo che nasce come variante del simplesso per il risolvere in modo efficace problemi di flusso tuttavia vista la sua grande efficacia viene spesso adattato per risolvere problemi non direttamente collegati ai flussi.
Dell'algoritmo abbiamo due versioni :  quella per risolvere il problema del min cost flow e quella usata per risolvere problemi di flusso generale(una sua generalizzazione) 
Entrambi gli algoritmi presentano una struttura di funzionamento identico nella appliacazione dell'algoritmo mentre le parti su cui differiscono sono : il calcolo dei flussi,l'individuazione dell'arco uscente, il calcolo dei potenziali dei nodi e la terminazione.
Queste differenze sono dovute alla natura diversa dei problemi che risolvono perché min cost flow si possono fare delle assunizoni più forti che permettono di scrivere degli algoritmi più efficaci.
è interessante vedere entrambe gli algoriti devono risolvere problematiche simili . Mi limiterò a concentrarmi su una descrizione dell'algoritmo nata per il min cost flow per poi mostrare come questa questa disamina teorica possa essere usata operativamente per risolvere un problema simile ma che ha bisogno di ancora meno premesse per essere implementate:il problema della generazione dello shortest path per da un nodo radice verso tutti i nodi della rete.
Ho deciso di implementare questo algoritmo e non quello per risolvere il min cost flow perché il simplesso su rete per poter lavorare di una soluizione sotto formula di albero , implementazione che mi avrebbe 
richiesto di creare prima un algoritmo che calcoli il flusso e che lo converta in un albero di copertura , mentre per lo shortest path l'algoritmo di creazione dell'albero iniziale inizializza anche i dati necessari per la risoluzione del problema.
Nella mia implementazione della soluzione
## Campi di applicazione
In diversi campi l'agortimo viene usato perché il flusso può essere convertito in un'altra grandezza fisica.
Una breve illustrazione di questo tipo di applicazioni:
* reti finanziarie:i nodi rappresentano diverse tipologie di patrimoni come azioni, obbligazioni, depositi correnti, titoli di Stato e certificati di deposito in determinati momenti, mentre gli 
archi rappresentano diverse alternative di investimento che trasformano un tipo di patrimonio 
in un altro. 
Il moltiplicatore di un arco rappresenta il guadagno associato all'investimento corrispondente.

* reti minerarie:In queste reti, i nodi rappresentano miniere, impianti di purificazione, raffinerie, 
porti e mercati finali. Gli archi rappresentano opportunità di lavorazione o flusso di materiale 
attraverso giunzioni intermedie verso le destinazioni finali. Il moltiplicatore di un arco 
rappresenta la perdita associata al processo corrispondente.

reti energetiche:i nodi rappresentano diversi materiali grezzi e vari tipi di energia.
Gli archi rappresentano la trasformazione dell'energia di a partire dai materiali.

Altre applicazioni possono riguardare la gestione del caricamento delle macchine o gli assegnamenti delle rotte aeere.

## Descrizione generale dell'algoritmo 
//todo: prendila da tesina 1
Lo schema generale di funzionamento del problema è il seguente
* determinare la struttura iniziale del problema.
* inizializza i flussi e i ponteziali dei nodi
* while( esiste almeno un arco che viola le condizioni ottimali)
	seleziona un arco entrante che viola le condizioni 
	inserisci l'arco nella soluzione
	aggiorna gli indici


Nell'implementazione dell'algoritmo vengono affrontati i seguenti problemi :
- determinare la struttura iniziale del problema
- determinare l'ottimalità del problema 
- determinare la scelta dell'arco entrante nella soluzione  
- determinare la scelta dell'arco usente
- determinare l'aggiornamento degli archi
- determinare la computazione dei flussi
- determinare le condizioni di terminazione del problema
- determinare la terminazione

Tuttavia esiste un'altra cosa da tenere a mente mentre lo si usa: se l'albero iniziale non è creato in modo opportuno l'algoritmo potrebbe non terminare per questo bisogna fare a monte uno studio dell'albero che viene dato .Questo problema viene risolto nel min cost flow creando un albero strettamente ammissibile.

### Determinare struttura generale
Solitamente il grafo iniziale viene scomposto in 3 grafi:
*Soluzione: grafo contenete la soluzione
*L:lista archi con costi potenziali positivi.
*U: lista archi con costi potenziale negativi.
La cosa interessante di questo algoritmo è di passare da una soluzione ammissible all'altra fino a quando non trova quella ottimale 
### Determinare soluzione ottimale del problema
La soluzione è ottimale se:
* ogni arco in L deve evere costo potenziale negativo.
* ogni arco in U deve evere costo potenziale positivo.

### Determinare arco entrante o regola di pivoting
Dato un arco il suo costo potenziale è chiamato anche violazione.
Esistono 3 strategie molto comuni per determinare l'arco entrante
#### Primo arco eligibile
Per implementare questa regola, scansioniamo la lista degli archi in modo sequenziale e selezioniamo il primo arco idoneo per entrare nell'albero. In una versione popolare di questa regola, esaminiamo la lista degli archi in 
modo circolare. Ad esempio, in un'iterazione se scopriamo che il quinto arco nella lista degli archi \`e il primo arco idoneo, allora nella successiva iterazione iniziamo a scansionare la lista degli archi dal sesto arco in 
poi. Se raggiungiamo la fine della lista degli archi mentre stiamo eseguendo un'iterazione, continuiamo esaminando la lista degli archi dall'inizio. Un bel vantaggio di questa regola di pivot \`e che identifica rapidamente 
l'arco in ingresso. La regola di pivot ha per\`o un inconveniente compensatorio: con essa, l'algoritmo in genere esegue pi\`u iterazioni rispetto a quanto farebbe con altre regole di pivot perch\'e ogni operazione di pivot produce 
una diminuzione relativamente piccola nel valore della funzione obiettivo. L'effetto complessivo di questa regola di pivot sul tempo di esecuzione dell'algoritmo non \`e molto attraente, anche se la regola produce 
un'implementazione pi\`u efficiente rispetto alla regola di pivot di Dantzig.
#### Regola di Danzing
Questa regola \`e stata suggerita da George B. Dantzig,(padre della programmazione lineare). Ad ogni iterazione,  seleziona l'arco con la massima violazione per entrare nell'albero. 
Il motivo  \`e che l'arco con la massima violazione causa la massima diminuzione nella funzione obiettivo per unit\`a di cambiamento nel valore del flusso sull'arco selezionato, e quindi l'introduzione di 
questo arco nell'albero di copertura causerebbe la massima diminuzione per passo se l'incremento medio nel 
valore dell'arco selezionato fosse lo stesso per tutti gli archi. 

I risultati computazionali confermano che questa scelta dell'arco in ingresso tende a produrre diminuzioni relativamente grandi nella funzione obiettivo per 
iterazione e, di conseguenza, l'algoritmo esegue meno iterazioni rispetto ad altre scelte per la regola di pivot. 

Questa regola ha grosso svantaggio: l'algoritmo deve considerare ogni arco al di fuori dell'albero  per identificare l'arco con la massima violazione e farlo \`e molto dispendioso in termini di tempo. 
Pertanto, anche se questo algoritmo in genere esegue meno iterazioni rispetto ad altre implementazioni, il tempo di esecuzione  dell'algoritmo non \`e attraente.

#### Candidate list pivot rule
L'algoritmo seleziona l'arco in ingresso utilizzando una procedura a due fasi composta da iterazioni principali e iterazioni minori. In una iterazione principale, costruiamo una lista dei candidati di archi idonei. Una volta 
costruita questa lista, eseguiamo un certo numero di iterazioni minori; in ognuna di queste iterazioni, selezioniamo un arco idoneo dalla lista dei cand
idati con la massima violazione. In una iterazione principale costruiamo la lista dei candidati nel seguente modo. Iniziamo esaminando gli archi che si originano dal nodo 1 e aggiungiamo gli archi idonei alla lista dei 
candidati. Ripetiamo questo processo per i nodi 2, 3, ... , fino a quando la lista raggiunge la sua dimensione massima consentita o abbiamo esaminato tutti i nodi. La successiva iterazione principale inizia con il nodo in cui 
si \`e conclusa la precedente iterazione principale e esamina i nodi in modo circolare. Una volta che l'algoritmo ha formato la lista dei candidati in una iterazione principale, esegue un certo numero di iterazioni minori. In 
una iterazione minore, l'algoritmo scansiona tutti gli archi nella lista dei candidati e seleziona un arco idoneo con la massima violazione per entrare nell'albero. Mentre scansioniamo gli archi, aggiorniamo la lista dei 
candidati rimuovendo quegli archi che non sono pi\`u idonei (a causa di modifiche nei potenziali dei nodi). Una volta che la lista dei candidati diventa vuota o abbiamo raggiunto un limite specificato sul numero di iterazioni 
minori da eseguire all'interno di ciascuna iterazione principale, ricostruiamo la lista dei candidati eseguendo un'altra iterazione principale. Nota che l'approccio della lista dei candidati offre notevole flessibilit\`a per 
adattarsi a classi di problemi speciali. Regolando opportunamente la dimensione massima consentita della lista dei candidati e specificando il numero di iterazioni minori da eseguire all'interno di una iterazione principale, 
possiamo ottenere numerose regole di pivot diverse.


## Implementazione problema shortest path 
Per capire le problematiche descritte sopra ho implementato in C++ il simplsso su reti che risolve
il shortest path da un nodo radice verso tutti gli altri.
### Formulazione
descrizione problema con formula matematica .
//todo : prendere formulazione da latex
### Albero in input
Il primo albero che inizializza i dati necessari al funzionamento del problema viene creato con un
algoritmo di copertura greedy che oltre a creare la prima soluzione ammissibile del problema calcola anche i costi dei vari nodi e i costi potenziali degli archi.
In questa versione del simplesso l'insieme dei nodi U non viene usata perché non esistono archi all'indietro .
### Strutture dati usate
Questo algoritmo utilizza i seguenti tipi per funzionare:
//todo: copiare da codice
Per rappresentare la soluzione ho deciso di usare lista di adiacenze di vector<Arco> invece che un
una matrice (come avviene di solito in letteratura) mentre L è memorizzato come un semplice vector
di archi.
Piccola nota sul rappresentazione di L : in linea teorica sarebbe bastata una seplice coda come struttura dati tuttavia in c++ questa tecnica diventa meno efficace qunado i numeri di nodi è maggiore di 50 matrice (come avviene di solito in letteratura) mentre L è memorizzato come un semplice vector
di archi.
Piccola nota sul rappresentazione di L : in linea teorica sarebbe bastata una seplice coda come struttura dati tuttavia in c++ questa tecnica diventa meno efficace qunado i numeri di nodi è maggiore di 50..
### computazione flusso + codice
### regola di pivoting + codice
La regola di pivoting che ho implementato è regola di Danzing che declinata a questa versione 
del simplesso sceglie l'arco con minor costo potenziale.

### Arco uscente 
Se l'arco (k,l) è l'arco entrante l'arco uscente è (pred(l),l), questo algoritmo è stao particolarmente 
facile implementare visto che i nodi memorizzano l'indice del nodo precedessore mediante un 
un indice apposito. 
### considerazioni.


