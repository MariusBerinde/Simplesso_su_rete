#include <iostream>
#include <string>
#include <fstream>
#include "../src/Alberi.cpp"
#include <vector>
#include <queue>
#include <bits/stdc++.h> 
#include <utility>
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
	
	//inserisco archi
	add_arco(a,a0);
	add_arco(a,a2);
	add_arco(a,a4);
	add_arco(a,a5);
	add_arco(a,a6);
	add_arco(a,a8);
	
	add_arco(a,a1);
	add_arco(a,a3);
	add_arco(a,a7);
	add_arco(a,a9);
	
}
void crea_grafo_totale(vector<Arco> a[],Nodo *nodi[]){
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
	
	Arco a14(nodi[3],nodi[4],13);
	Arco a15(nodi[4],nodi[3],13);
	
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

//TODO:inserire
Arco restituisci_arco(vector<Arco> grafo[],int nodo_o,int nodo_d){
	int i=0;
	for( i=0;i<grafo[nodo_o].size();i++){
				int d=grafo[nodo_o][i].getDestinazione()->getNome();
				if(d==nodo_d)
					break;
	}

	return grafo[nodo_o][i]; 
}
/*
* versione di restituisci grafo con solo vector
*/
Arco restituisci_arco_vettore(vector<Arco> grafo,int nodo_o,int nodo_d){
	int i=0;	
	for( i=0;i<grafo.size();i++){
		if(grafo[i].getOrigine()->getNome()==nodo_o && grafo[i].getDestinazione()->getNome()==nodo_d)
			break;
	}
	
	return grafo[i];
}
void test_arco_uscente(Problema p){
	auto albero=p.grafo_originale;
	auto arco_1=restituisci_arco(albero,1,2);
	auto arco_1_uscente_teorico=restituisci_arco(albero,0,2);
	auto arco_uscente_pratico=uscente(albero,arco_1,Nr_nodi);
	//test arco 1
	bool test_dest=arco_1_uscente_teorico.getDestinazione()->getNome()==arco_uscente_pratico.getDestinazione()->getNome();
	bool test_origine=arco_1_uscente_teorico.getOrigine()->getNome()==arco_uscente_pratico.getOrigine()->getNome();
	bool test_costo=arco_1_uscente_teorico.getCosto()==arco_uscente_pratico.getCosto();
	if( test_dest && test_origine && test_costo)
		cout<<"arco uscente : ok"<<std::endl;
	else
		cout<<"arco uscente : errore"<<std::endl;
	
	auto arco_2=restituisci_arco(albero,2,1);
	auto arco_2_uscente_teorico=restituisci_arco(albero,0,1);
	auto arco_uscente_pratico2=uscente(albero,arco_2,Nr_nodi);
	
	test_dest=arco_2_uscente_teorico.getDestinazione()->getNome()==arco_uscente_pratico2.getDestinazione()->getNome();
	test_origine=arco_2_uscente_teorico.getOrigine()->getNome()==arco_uscente_pratico2.getOrigine()->getNome();
	test_costo=arco_2_uscente_teorico.getCosto()==arco_uscente_pratico2.getCosto();
	if( test_dest && test_origine && test_costo)
		cout<<"arco uscente 2: ok"<<std::endl;
	else
		cout<<"arco uscente 2: errore"<<std::endl;
}

	void test_aggiorna(Problema p){
	auto arco_entrante=restituisci_arco_vettore(p.L,1,2);//da regola di pivoting
	auto arco_uscente=uscente(p.soluzione,arco_entrante,p.soluzione->size());
	//inserire arco entrante in soluzione e cancellalo da L
	add_arco(p.soluzione,arco_entrante);
	elimina_arco_entrante(p.L,arco_entrante);
	//eliminare arco uscente da soluzione e inserirlo in L
	elimina_arco(p.soluzione,arco_uscente,p.nr_nodi);
	p.L.push_back(arco_uscente);
	//aggiorna inidici in soluzione e L 
    aggiorna_indici(p.soluzione,arco_entrante,p.nr_nodi);
    aggiorna_potenziali_L(p.L);

	cout<<"nuove caratteristiche di nodo 2:"<<endl;
	arco_entrante.getDestinazione()->printNodo();
}

void test_aggiorna_indici(){
	int nr_nodi=4;
	Nodo *nodi[nr_nodi];
	vector<Arco> albero[nr_nodi];
	for(int i=0;i<nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	Arco a0(nodi[0],nodi[1],9);
	a0.setCosto_potenziale(2);
	Arco a1(nodi[1],nodi[2],6);
	Arco a2(nodi[1],nodi[3],1);
	nodi[0]->setPotenziale(0);
	nodi[1]->setPotenziale(-2);
	nodi[2]->setPotenziale(-6);
	nodi[3]->setPotenziale(-8);
	add_arco(albero,a0);
	add_arco(albero,a1);
	add_arco(albero,a2);
	
	aggiorna_indici(albero,a0,nr_nodi);
	//inizio test
	bool potenziale_1=nodi[1]->getPotenziale()==-9;
	bool potenziale_2=nodi[2]->getPotenziale()==-4;
	bool potenziale_3=nodi[3]->getPotenziale()==-6;
	if(potenziale_1)
		cout<<"Pontenziale nodo 1:ok"<<endl;
	else
		cout<<"Potenziale nodo 1:errore"<<endl;
	if(potenziale_2)
		cout<<"Potenziale nodo 2:errore"<<endl;
	else
		cout<<"Potenziale nodo 2:errore"<<endl;
	if(potenziale_3)
		cout<<"Potenziale nodo 3:errore"<<endl;
	else 
		cout<<"Potenziale nodo 3:errore"<<endl;

	for(int i=0;i<nr_nodi;i++){
		delete(nodi[i]);
	}
}

/*
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
*/
string linea_verticale(int d=0,string e=""){
	string bordo="";
	for(int i=0;i<d;i++){
		bordo=bordo+"\t";
	}
	string linea=e+bordo+"|\n"+e+bordo+"|\n";
	return linea;
}
string angolo(int d=0,string e=""){
	string bordo="";
	string linea="";
	for(int i=0;i<d;i++){
		bordo=bordo+"\t";
	}
	if(d>0)
		linea="|"+bordo+"|-";
	else
		linea=bordo+"|-";
	return linea;
}
string linea_orizzontale(int d=0){
	string bordo="";
	for(int i=0;i<d;i++){
		bordo=bordo+"\t";
	}
	string linea=bordo+"--";
	return linea;
}



bool compare_pair( const std::pair<int,int> &pair1, 
                   const std::pair<int,int> &pair2)
{
    int result = 0;
    if(  ((pair2.second == pair1.second) &&
         (pair2.second < pair1.second)) )
    {
        result = 1;
    } 
    return result;
}

void disegna_grafo(Problema p){
	std::queue<int> da_visitare;
	std::queue<int> visitati;
	std::vector<Arco> *grafo=p.soluzione;
	da_visitare.push(grafo[p.indice_nodo_iniziale][0].getOrigine()->getNome());
	while(!da_visitare.empty()){
		
		int i=da_visitare.front();
		// pair<nodo,nr_figli>
		std::pair<int,int> coppie[grafo[i].size()];
		for(int j=0;j<grafo[i].size();j++){
			Arco arco=grafo[i][j];
			int d=arco.getDestinazione()->getNome();
			int nome_dest=d.getDestinazione()->getNome();
			coppie[j]={nome_dest,grafo[nome_dest].size()};
		}
	 size_t len = sizeof(coppie)/sizeof(coppie[0]);
	sort(coppie,coppie+len,&compare_pair);
		
        //todo: creare stringa di stampa
	}

}
int main(int argc, char const *argv[]){
	Nodo *nodi[Nr_nodi];
	Problema p;
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	vector<Arco> T[Nr_nodi];
	crea_grafo_totale(grafo,nodi);
	p=crea_problema(grafo,T,0,Nr_nodi);
	cout<<"albero iniziale"<<endl;
	print_albero(p.soluzione,p.nr_nodi);
	auto nome_soluzione="../out/soluzioni/root_1_alt.txt";
	cout<<"Stato problema iniziale="<<p.indice_nodo_iniziale<<endl;
	//auto nome_grafo="../out/grafo_iniziale_con_partenza0.txt";
	//scrivi_soluzione_file(p,nome_grafo);
	simplessoRete(p);
//	scrivi_soluzione_file(p,nome_soluzione);
	cout<<"Potenziali soluzione:"<<endl;
	stampa_soluzione(p);
	cout<<"albero soluzione:"<<endl;
	print_albero(p.soluzione,p.nr_nodi);
/*	
	cout<<"soluzione:"<<std::endl;
	stampa_soluzione(p);
*/
	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}

