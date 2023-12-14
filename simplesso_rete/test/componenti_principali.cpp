#include <iostream>
#include <string>
#include "../src/Alberi.cpp"
#include <vector>
#include <queue>
#include <bits/stdc++.h> 
#define Nr_nodi 4  
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
	add_arco(a,a6);
	add_arco(a,a8);
	/*
	add_arco(a,a1);
	add_arco(a,a3);
	add_arco(a,a5);
	add_arco(a,a9);
	add_arco(a,a7);
	*/
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
				if(arco.getDestinazione()->getNome() != 0)
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
void set_potenziali_per_test(vector<Arco> &U,bool ammissibile=false){
	if(ammissibile){
		for(int i=0;i<U.size();i++){
			U[i].setCosto_potenziale(-1-i);
			
		}
		}else{
	for(int i=0;i<U.size();i++){
			U[i].setCosto_potenziale(1+i);
		}
		
	}
}
bool problema_ottimale(vector<Arco> U){
	bool esito=true;
	
	for(int i=0;i<U.size();i++){
		esito=U[i].getCosto_potenziale()<=0;
		if(!esito)
			break;
	}
	return esito;
}
void test_problemaOttimale(Problema p){
//caso ammissibile
	set_potenziali_per_test(p.U,true);
	bool esito=problema_ottimale(p.U);
	if(esito)
		cout<<"test caso problema ammissibile: ok;"<<endl;
	else
		cout<<"test caso problema ammissibile: errore;"<<endl;

//caso non ammissible
	set_potenziali_per_test(p.U);
	 esito=problema_ottimale(p.U);
	if(!esito)
		cout<<"test caso problema non  ammissibile: ok;"<<endl;
	else
		cout<<"test caso problema non ammissibile: errore;"<<endl;

}
/*
 * ritorna l'arco con il maggior potenziale
 * @param: archi: vector<Arco> lista degli archi
 * @return l'arco di costo potenziale maggiore
 * */
Arco max_costo_potenziale(vector<Arco> archi){
	
	if(archi.size()==1)
		return archi[0];
	int i_max=0;
	for(int i=1;i<archi.size();i++){
		if(archi[i].getCosto_potenziale()>archi[i_max].getCosto_potenziale() && archi[i].getDestinazione()->getNome()!=0 )
			i_max=i;
	}
	return archi[i_max];
}
Arco primo_arco_eligibile(vector<Arco> archi){
	int i_res=-1;
	for(int i=0;i<archi.size();i++){
		if(archi[i].getCosto_potenziale()>0){
			i_res=i;
			break;
		}
	}
	return archi[i_res];
}
Arco regola_pivoting(vector<Arco> archi){
	//return max_costo_potenziale(archi);
	return primo_arco_eligibile(archi);
}
void elimina_arco_entrante(vector<Arco> &U,Arco a){
	int i;
	bool trovato=false;
	for(i=0;i<U.size();i++){
		bool origine=U[i].getOrigine()->getNome()==a.getOrigine()->getNome();
		bool destinazione=U[i].getDestinazione()->getNome()==a.getDestinazione()->getNome();
		bool costo= U[i].getCosto() == a.getCosto();
		if(origine && destinazione && costo){
			trovato=true;
			break;
		}
	}
	if(trovato)
		U.erase(U.begin()+i);
}
void aggiorna_indici(vector<Arco> grafo[],Arco partenza){
	Punto c=esiste_arco(grafo,partenza);
	if(c.esito==false)
		exit(EXIT_FAILURE);
	int costo_potenziale=partenza.getCosto_potenziale();
	int depth=partenza.getOrigine()->getDetph();
	int nodo_origine=partenza.getOrigine()->getNome();
	int pp=partenza.getDestinazione()->getPotenziale();
	partenza.getDestinazione()->setPred(nodo_origine);
	partenza.getDestinazione()->setDetph(depth+1);
	partenza.getDestinazione()->setPotenziale(partenza.getOrigine()->getPotenziale()-partenza.getCosto());//dovrebbe essere potenziale nodo origine - costo arco
	std::queue<int> da_visitare;
	std::queue<int> visitati;

	
	da_visitare.push(partenza.getDestinazione()->getNome());
	while(!da_visitare.empty()){
		int i=da_visitare.front();
		for(int j=0;j<grafo[i].size();j++){
			auto arco=grafo[i][j];
			int d=arco.getDestinazione()->getNome();
			
			if(!in_queue(visitati,d)&& !in_queue(da_visitare,d)){
				int livello=arco.getOrigine()->getDetph()+1;
				pp=arco.getDestinazione()->getPotenziale()+costo_potenziale;
				arco.getDestinazione()->setPotenziale(pp);
				arco.getDestinazione()->setDetph(livello);
				da_visitare.push(d);
			}
			if(j==grafo[i].size()-1)
				visitati.push(d);
		} 
		da_visitare.pop();
	}

}
/*
* aggionrna i costi potenziali
*/
void aggiorna_potenziali_U(vector<Arco> &U){
	//TODO:modificarla per aggiornare solo i potenziali dove compare il nodo de
	for(int i=0;i<U.size();i++){
		int costo_arco=U[i].getCosto();
		int potenziale_i=U[i].getOrigine()->getPotenziale();
		int potenziale_j=U[i].getDestinazione()->getPotenziale();
		U[i].setCosto_potenziale(costo_arco-potenziale_i+potenziale_j);
	}
}

void simplessoRete(Problema p){
	bool ammissibile=problema_ottimale(p.U);
	while(!ammissibile){
		auto arco_entrante=regola_pivoting(p.U);//da regola di pivoting
		auto arco_uscente=uscente(p.soluzione,arco_entrante,p.soluzione->size());
		//inserire arco entrante in soluzione e cancellalo da U
		add_arco(p.soluzione,arco_entrante);
		elimina_arco_entrante(p.U,arco_entrante);
		//eliminare arco uscente da soluzione e inserirlo in U
		elimina_arco(p.soluzione,arco_uscente);
		p.U.push_back(arco_uscente);
		//aggiorna inidici in soluzione e U 
		aggiorna_indici(p.soluzione,arco_entrante);
		aggiorna_potenziali_U(p.U);
		ammissibile=problema_ottimale(p.U);
	//	cout<<"stato soluzione"<<std::endl;
	//	print_albero(p.soluzione);
	}
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
Arco restituisci_arco(vector<Arco> grafo[],int nodo_o,int nodo_d){
	for(int i=0;i<grafo[nodo_o].size();i++){
				int d=grafo[nodo_o][i].getDestinazione()->getNome();
				if(d==nodo_d)
					return grafo[nodo_o][i]; 
	}
}
/*
* versione di restituisci grafo con solo vector
*/
Arco restituisci_arco_vettore(vector<Arco> grafo,int nodo_o,int nodo_d){
	
	for(int i=0;i<grafo.size();i++){
		if(grafo[i].getOrigine()->getNome()==nodo_o && grafo[i].getDestinazione()->getNome()==nodo_d)
			return grafo[i];
	}
	
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
	auto arco_entrante=restituisci_arco_vettore(p.U,1,2);//da regola di pivoting
	auto arco_uscente=uscente(p.soluzione,arco_entrante,p.soluzione->size());
	//inserire arco entrante in soluzione e cancellalo da U
	add_arco(p.soluzione,arco_entrante);
	elimina_arco_entrante(p.U,arco_entrante);
	//eliminare arco uscente da soluzione e inserirlo in U
	elimina_arco(p.soluzione,arco_uscente);
	p.U.push_back(arco_uscente);
	//aggiorna inidici in soluzione e U 
    aggiorna_indici(p.soluzione,arco_entrante);
    aggiorna_potenziali_U(p.U);

	cout<<"nuove caratteristiche di nodo 2:"<<endl;
	arco_entrante.getDestinazione()->printNodo();
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
	p=crea_problema(grafo,T,0,Nr_nodi);
	cout<<"Nodo partenza problema="<<p.indice_nodo_iniziale<<endl;
	int nodi_grafo_iniziale=p.grafo_originale->size();
	int nodi_soluzione=p.soluzione->size();
	cout<<"Nodi grafo iniziale:"<<nodi_grafo_iniziale<<std::endl;
	cout<<"Nodi grafo soluzione:"<<nodi_soluzione<<std::endl;
//    test_problemaOttimale(p);
//	print_albero(p.grafo_originale);	
	//test_arco_uscente(p);
//	test_aggiorna(p);
	simplessoRete(p);
	cout<<"prima soluzione:"<<std::endl;
	print_albero(p.soluzione);
	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
