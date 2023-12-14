#include <iostream>
#include <string>
#include "../src/Alberi.cpp"
#include <vector>
#include <queue>
#include <bits/stdc++.h> 
#define Nr_nodi 7  
using namespace std;
void crea_grafo(vector<Arco> a[],Nodo *nodi[]){
//creo i nodi
/*	Nodo *nodi[Nr_nodi];
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}*/
	//creo archi
	Arco a0(nodi[0],nodi[1],9);
	Arco a1(nodi[1],nodi[0],9);
	
	Arco a2(nodi[0],nodi[2],6);
	Arco a3(nodi[2],nodi[0],6);

	Arco a4(nodi[1],nodi[2],11);
	Arco a5(nodi[2],nodi[1],11);

	Arco a6(nodi[1],nodi[3],1);
	Arco a7(nodi[3],nodi[1],1);
	
	Arco a8(nodi[2],nodi[3],2);
	Arco a9(nodi[3],nodi[2],2);
	
	Arco a10(nodi[1],nodi[4],20);
	Arco a11(nodi[4],nodi[1],20);
	
	Arco a12(nodi[2],nodi[5],18);
	Arco a13(nodi[5],nodi[2],18);
	
	Arco a14(nodi[3],nodi[4],14);
	Arco a15(nodi[4],nodi[3],14);
	
	Arco a16(nodi[3],nodi[6],15);
	Arco a17(nodi[6],nodi[3],15);

	Arco a18(nodi[3],nodi[5],28);
	Arco a19(nodi[5],nodi[3],28);

	Arco a20(nodi[4],nodi[6],3);
	Arco a21(nodi[6],nodi[4],3);

	Arco a22(nodi[5],nodi[6],25);
	Arco a23(nodi[6],nodi[5],25);
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
	add_arco(a,a11);
	add_arco(a,a12);
	add_arco(a,a13);
	add_arco(a,a14);
	add_arco(a,a15);
	add_arco(a,a16);
	add_arco(a,a17);
	add_arco(a,a18);
	add_arco(a,a19);
	add_arco(a,a20);
	add_arco(a,a21);
	add_arco(a,a22);
	add_arco(a,a23);
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
bool in_queue(queue<int> q,int e){
	
	while(!q.empty()){
		if(q.front()==e){
			return true;
		}
		else
			q.pop();
	}
	return false;
}

/*funzione che crea il grafo di partenza settando anche gli indici di pred e di depth*/
//todo Mettere 
void crea_grafo_iniziale(vector<Arco> grafo[],vector<Arco> soluzione[],vector<Arco> &U,int nr_nodi,int nodo_partenza){
	bool nodi_visitati[nr_nodi];
	std::queue<int> da_visitare;
	for(int i=0;i<nr_nodi;i++){
		nodi_visitati[i]=false;
	}
	
	da_visitare.push(nodo_partenza);
	while(!da_visitare.empty()){
		int i=da_visitare.front();
		for(int j=0;j<grafo[i].size();j++){
			auto arco=grafo[i][j];
			int d=arco.getDestinazione()->getNome();
			
			if(nodi_visitati[d]==false && !in_queue(da_visitare,d)){
				if(nodo_partenza==i)
					arco.getOrigine()->setDetph(0);
				int livello=arco.getOrigine()->getDetph()+1;
				da_visitare.push(d);
				arco.getDestinazione()->setPred(i);
				arco.getDestinazione()->setDetph(livello);
				add_arco(soluzione,arco);
			}
			else{
				U.push_back(arco);
			}
			if(j==grafo[i].size()-1)
				nodi_visitati[i]=true;
		}
		da_visitare.pop();
	}

}
void print_albero(vector<Arco> albero[]){
	for(int i=0;i<Nr_nodi;i++){
		cout<<"archi di "<<i<<":\t";
		auto lista_locale=albero[i];
		for(int j=0;j<lista_locale.size();j++){
			cout<<lista_locale[j].getDestinazione()->getNome()<<"->";
		}
		cout<<"\n";
	}

}

void set_costi_potenziali(vector<Arco> &lista){
	int costo,potenziale_i,potenziale_j;
	for(int i=0;i<lista.size();i++){
		costo=lista[i].getCosto();
		potenziale_i=lista[i].getOrigine()->getPotenziale();
		potenziale_j=lista[i].getDestinazione()->getPotenziale();
		lista[i].setCosto_potenziale(costo-potenziale_i+potenziale_j);
	}
}

Arco max_costo_potenziale(vector<Arco> archi){
	
	if(archi.size()==1)
		return archi[0];
	int i_max=0;
	for(int i=1;i<archi.size();i++){
		if(archi[i].getCosto_potenziale()>archi[i_max].getCosto_potenziale())
			i_max=i;
	}
	return archi[i_max];
}
void usoU(vector<Arco> &a){
	cout<<"Test dim U="<<a.size()<<endl;
	a[0].setCosto_potenziale(42);
}
/*
 * Dato grafo questa funzione inizializza il problema:
 * - crea l'albero di copertura T
 * - inizializza gli indici dei nodi
 * - inizializza i flussi degli archi*/
Problema crea_problema(vector<Arco> grafo[],vector<Arco> sol[],int nodo_partenza,int nr_nodi){
	if(nodo_partenza<0 || nodo_partenza>nr_nodi){
		std::cout<<"Il nodo di partenza non appartiene al grafo\n"<<std::endl;
		exit(EXIT_FAILURE);
	}
	Problema p;
	p.indice_nodo_iniziale=nodo_partenza;
	p.grafo_originale=grafo;
	vector<Arco> T[nr_nodi];
	crea_grafo_iniziale(grafo,sol,p.U,nr_nodi,nodo_partenza);
	set_tread_index(sol,nodo_partenza,nr_nodi);
	set_potenziali(sol,nodo_partenza,nr_nodi);
	
	
	for(int i=0;i<nr_nodi;i++){
		if(sol[i].size()>0)
			set_costi_potenziali(sol[i]);
	}
	set_costi_potenziali(p.U);
	p.soluzione=sol;
	return p;
}

int main(int argc, char const *argv[]){
	Nodo *nodi[Nr_nodi];
	Problema p;
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	vector<Arco> T[Nr_nodi];
	crea_grafo(grafo,nodi);
	p=crea_problema(grafo,T,1,Nr_nodi);
	cout<<"Nodo partenza problema="<<p.indice_nodo_iniziale<<endl;
	int nodi_grafo_iniziale=p.grafo_originale->size();
	int nodi_soluzione=p.soluzione->size();
	cout<<"Nodi grafo iniziale:"<<nodi_grafo_iniziale<<std::endl;
	cout<<"Nodi grafo soluzione:"<<nodi_soluzione<<std::endl;

	cout<<"Test stampa grafo iniziale:"<<std::endl;
	print_albero(p.soluzione);	
	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
