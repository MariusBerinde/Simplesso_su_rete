#include <iostream>
#include <string>
#include "../src/Alberi.cpp"
#include <vector>
#include <queue>
#include <bits/stdc++.h> 
#define Nr_nodi 12
using namespace std;

void crea_grafo(vector<Arco> a[],Nodo *nodi[],bool teorico=false){
//creo i nodi
/*	Nodo *nodi[Nr_nodi];
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}*/
	//creo archi
	Arco a0(nodi[0],nodi[1],11);
	Arco a1(nodi[1],nodi[2],5);
	Arco a2(nodi[1],nodi[3],1);
	Arco a3(nodi[1],nodi[4],4);
	Arco a4(nodi[2],nodi[5],4);
	Arco a5(nodi[4],nodi[6],1);
	Arco a6(nodi[4],nodi[7],2);
	Arco a7(nodi[5],nodi[8],1);
	Arco a8(nodi[5],nodi[9],1);
	Arco a9(nodi[5],nodi[10],1);
	Arco a10(nodi[7],nodi[11],1);
	if(teorico==true){
		a0.setFlusso(11);
		a1.setFlusso(5);
		a2.setFlusso(1);
		a3.setFlusso(4);
		a4.setFlusso(4);
		a5.setFlusso(1);
		a6.setFlusso(2);
		a7.setFlusso(1);
		a8.setFlusso(1);
		a9.setFlusso(1);
		a10.setFlusso(1);

	}
	//inserisco archi
	add_arco(a,a0);
	add_arco(a,a1);
	add_arco(a,a2);
	add_arco(a,a3);
	add_arco(a,a4);
	add_arco(a,a5);
	add_arco(a,a6);
	add_arco(a,a7);
	add_arco(a,a8);
	add_arco(a,a9);
	add_arco(a,a10);
}

void clean(vector<Arco> a[]){
	for(int i=0;i<Nr_nodi;i++){
		if(a[i].size()){
			for (int j = 0; j < a[i].size(); j++){
				if(a[i][j].getDestinazione()!=nullptr)
					a[i][j].eliminaPuntatori();
				}
			}
			
		}
}


void init_flussi(vector<Arco> albero[],Punto indice_arco){
	auto arco=albero[indice_arco.i][indice_arco.j];
	int indice_dest=arco.getDestinazione()->getNome();
	if(albero[indice_dest].size()==0)
		albero[indice_arco.i][indice_arco.j].setFlusso(1);
	else{
		int flussi=1;
		for(int i=0;i<albero[indice_dest].size();i++){
			Punto indice_interno;
			indice_interno.i=indice_dest;
			indice_interno.j=i;
			init_flussi(albero,indice_interno);
			auto arco_interno=albero[indice_dest][i];
			flussi+=arco_interno.getFlusso();
		}
		albero[indice_arco.i][indice_arco.j].setFlusso(flussi);
	}
	
	
}


void test_flussi(vector<Arco> grafo[]){
	Punto arco_iniziale;
	arco_iniziale.i=0;
	arco_iniziale.j=0;
	init_flussi(grafo,arco_iniziale);
	vector<Arco> grafo_teorico[Nr_nodi];
	Nodo* nodi_test[Nr_nodi];
	for(int i=0;i<Nr_nodi;i++){
		nodi_test[i]=new Nodo(i);
	}
	crea_grafo(grafo_teorico,nodi_test,true);
	for(int i=0;i<Nr_nodi;i++){
		for(int j=0;j<grafo_teorico[i].size();j++){
			
			auto arco_reale=grafo[i][j];
			int o=arco_reale.getOrigine()->getNome();
			int d=arco_reale.getDestinazione()->getNome();
			auto cmp=esiste_arco(grafo_teorico,arco_reale,Nr_nodi);
			if(cmp.esito==true){
				auto arco_t=grafo_teorico[cmp.i][cmp.j];
				if(arco_reale.getFlusso()==arco_t.getFlusso())
					printf("Arco %d->%d :OK\n",o,d);
				else{
					printf("Arco %d->%d: flusso teorico=%f \tflusso calcolato=%f\n",o,d,arco_t.getFlusso(),arco_reale.getFlusso());
				}
				
			}
			else
				printf("Arco %d->%d non trovato nel grafo teorico\n",o,d);

		}
	}
	
	for(int i=0;i<Nr_nodi;i++)
		delete(nodi_test[i]);

}
int main(int argc, char const *argv[]){
	Nodo *nodi[Nr_nodi];
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	crea_grafo(grafo,nodi);
	test_flussi(grafo);
	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
