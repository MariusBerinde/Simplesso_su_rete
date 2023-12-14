#include "Arco.h"
#include <vector>
#include <string>
#define NR_NODI 5
typedef struct Punto{
	int i,j;
	bool esito;
}Punto;

typedef struct Problema {
	std::vector<Arco>* grafo_originale;//non mi serve
	std::vector<Arco>* soluzione;
	std::vector<Arco> L;
	int indice_nodo_iniziale;
	int nr_nodi;
}Problema;


void add_arco(std::vector<Arco>* lista, Arco a);

int getIndex(std::vector<int> v,int val);
void DFS(std::vector<Arco>* albero,std::vector<int> *coda,int nodo_attuale);

void set_prev(std::vector<Arco>* albero);

void set_depth_alt(std::vector<Arco>* albero);

void set_tread_index(std::vector<Arco>* albero);

void set_potenziali(std::vector<Arco>* albero);


//bool esiste_arco(std::vector<Arco>* albero, Arco a);
Punto esiste_arco(std::vector<Arco> albero, Arco a,int max_nodi=NR_NODI);
void elimina_arco(std::vector<Arco> albero,Arco a);

/*
 * dato l'arco entrante restituisce l'arco che che deve uscire
 *
 * */
Arco uscente(std::vector<Arco>& albero,Arco a,int nr_nodi);

void stampa_soluzione(Problema p);


//funzioni principali
/*funzione che crea il grafo di partenza*/
void crea_grafo_iniziale(std::vector<Arco> grafo[],std::vector<Arco> soluzione[],std::vector<Arco> &L,int nr_nodi,int nodo_partenza);

//crea i costi potenziali nel grafo
void set_costi_potenziali(std::vector<Arco> &lista);
	

//condizioni di ottimalità del problema
bool problema_ottimale(std::vector<Arco> &L);

//regola di pivoting
Arco min_costo_potenziale(std::vector<Arco> archi);

//altra regola di pivoting
Arco primo_arco_eligibile_v2(std::vector<Arco> archi);

//metodo per cambiare con facilità le regole di pivoting
Arco regola_pivoting(std::vector<Arco> archi);

//funzione usata nel caso in cui il nodo radice diventa isolato
Arco arco_necessario(std::vector<Arco> archi,int nodo_partenza);

void elimina_arco_entrante(std::vector<Arco> &L,Arco a);
