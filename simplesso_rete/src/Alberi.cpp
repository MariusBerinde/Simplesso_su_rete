#include "../include/Alberi.h"
#include <bits/stdc++.h> 

void add_arco(std::vector<Arco>* lista, Arco a){

    int pos=a.getOrigine()->getNome();

    lista[pos].push_back(a);
}

//funzione di inizializzazione del testerare s
//funzioni per inizializzare l'albero.
//
//funziona solo se si la radice dell'albero è il nodo 0
void set_prev(std::vector<Arco>* albero,const int nr_nodi){
	for(int i=0;i<nr_nodi;i++){
		for(int j=0;j<albero[i].size();j++){
			if(albero[i][j].getDestinazione()->getPred()==-1)
				albero[i][j].getDestinazione()->setPred(i);
		}
		
	}
}

void set_depth_alt(std::vector<Arco>* albero,const int nr_nodi=NR_NODI){
	albero[0][0].getOrigine()->setDetph(0);

	for(int i=0;i<nr_nodi;i++){
		if(albero[i].size()>0){
			for(int j=0;j<albero[i].size();j++){
				Nodo* nodo_attuale=albero[i][j].getDestinazione();

				if(albero[i][j].getDestinazione()->getDetph()==-1){
					int  prev_index=albero[i][j].getDestinazione()->getPred();
					int prev_dept=albero[prev_index][0].getOrigine()->getDetph();
					prev_dept++;
					albero[i][j].getDestinazione()->setDetph(prev_dept);
				}
			}
		}
	}

}
int getIndex(const std::vector<int> v,const int val){
	auto it= find(v.begin(),v.end(),val);
	int index=-1;
	if(it != v.end()){
		index=it-v.begin();
	}
	return index;
}

void DFS(std::vector<Arco>* albero,std::vector<int> *coda,int nodo_attuale){
	if(getIndex(*coda,nodo_attuale)==-1){
		coda->push_back(nodo_attuale);
		for(int i=0;i<albero[nodo_attuale].size();i++){
			int next = albero[nodo_attuale][i].getDestinazione()->getNome();
			if(albero[next].size()==0)
				coda->push_back(next);
			else
				DFS(albero,coda,next);
		}

	}
}


void set_tread_index(std::vector<Arco>* albero,int nodo_partenza=0,const int nr_nodi=NR_NODI){
	std::vector<int> dfs;
	DFS(albero,&dfs,nodo_partenza);
	for(int i=0;i<nr_nodi;i++){
		if(albero[i].size()>0){
			for(int j=0;j<albero[i].size();j++){

				if(i==0 && j==0){
					int ithread=getIndex(dfs,0)+1;
					albero[i][j].getOrigine()->setThreadI(dfs[ithread]);
				}
				if(albero[i][j].getDestinazione()->getThreadI()==-1){
					int nodo_attuale=albero[i][j].getDestinazione()->getNome();
					int ithread=getIndex(dfs,nodo_attuale);
					int val=0;
					if(ithread!=4)
						val=dfs[++ithread];
					albero[i][j].getDestinazione()->setThreadI(val);

				}
			}
		}
	}
	//fare inserimento
}

void set_potenziali(std::vector<Arco>* albero,int nodo_partenza=0,int nr_nodi=NR_NODI){

	int potenzialeO,potenzialeD,deptO,deptD,costo;
	albero[nodo_partenza][0].getOrigine()->setPotenziale(0);
	for(int i=nodo_partenza;i<nr_nodi;i++){
		if(albero[i].size()>0){
			for(int j=0;j<albero[i].size();j++){
				Nodo* nodo_origine=albero[i][j].getOrigine();
				potenzialeO=albero[i][j].getOrigine()->getPotenziale();
				costo=albero[i][j].getCosto();
				deptO=nodo_origine->getDetph();
				deptD=albero[i][j].getDestinazione()->getDetph();
				if(albero[i][j].getDestinazione()->getPotenziale()==-256){
					if(deptO<deptD)
						potenzialeD=potenzialeO-costo;
					else
						potenzialeD=potenzialeO+costo;

					albero[i][j].getDestinazione()->setPotenziale(potenzialeD);

					
				}
			}
		}
	}
	if(nodo_partenza>0){
		for(int i=0;i<nodo_partenza;i++){
		if(albero[i].size()>0){
				for(int j=0;j<albero[i].size();j++){
					Nodo* nodo_origine=albero[i][j].getOrigine();
					potenzialeO=albero[i][j].getOrigine()->getPotenziale();
					costo=albero[i][j].getCosto();
					deptO=nodo_origine->getDetph();
					deptD=albero[i][j].getDestinazione()->getDetph();
					if(albero[i][j].getDestinazione()->getPotenziale()==-256){
						if(deptO<deptD)
							potenzialeD=potenzialeO-costo;
						else
							potenzialeD=potenzialeO+costo;

						albero[i][j].getDestinazione()->setPotenziale(potenzialeD);

					}
				}
			}
		}
	}
}



Punto esiste_arco(std::vector<Arco>* albero, Arco a,int max_nodi=NR_NODI){
	Punto p;
	if(a.getCosto()==-1){
		p.i=-1;
		p.j=-1;
		p.esito=false;
		return p;
	}
	
	int nodoO,nodoD,costo;
	p.esito=false;
	
	nodoO=a.getOrigine()->getNome();
	nodoD=a.getDestinazione()->getNome();
	costo=a.getCosto();
	
	for(int i=0;i<max_nodi;i++){
		if(albero[i].size()>0){
			for(int j=0;j<albero[i].size();j++){
				 int origine=albero[i][j].getOrigine()->getNome();
				 if(nodoO==origine){
				
					 int dest=albero[i][j].getDestinazione()->getNome();
					 if(nodoD==dest){
						int cap=albero[i][j].getCosto();
						if(costo==cap){
							p.esito=true;
							p.i=i;
							p.j=j;
							return p;
						}
						
					 }
				 }
				
			}
		}
	}
		
	return p;
}


void elimina_arco(std::vector<Arco>* albero,Arco a,int max_nodi){
	Punto p=esiste_arco(albero,a,max_nodi);
	if(p.esito==true){
		albero[p.i].erase(albero[p.i].begin() + p.j);
	}
}

/*
 * dato l'arco entrante restituisce l'arco che che deve uscire
 *
 * */



Arco uscente(std::vector<Arco>* albero,Arco a,const int nr_nodi){
	Punto p=esiste_arco(albero,a,nr_nodi);
	if(!p.esito){
			// dato un arco (k,l) dovrei restituire un arco (pred(l),l)
		int nome_pred=a.getDestinazione()->getPred();
		Nodo* pred_a=albero[nome_pred][0].getOrigine();
		int i=pred_a->getNome();
		for(int j=0;j<albero[i].size();j++){
			int d=albero[i][j].getDestinazione()->getNome();
			if(d==a.getDestinazione()->getNome())
				return albero[i][j];
		}
		Arco ris(pred_a,a.getDestinazione(),a.getCosto());
		return ris;
			}

	return Arco(nullptr,nullptr,-1);		
}
/*funzione di supporto per verificare se e si trova nella lista q*/
bool in_queue(std::queue<int> q,const int e){
	
	while(!q.empty()){
		if(q.front()==e){
			return true;
		}
		else
			q.pop();
	}
	return false;
}

void stampa_soluzione(Problema p){
	std::vector<Arco> *grafo=p.soluzione;

	std::cout<<"Nodo partenza="<<grafo[p.indice_nodo_iniziale][0].getOrigine()->getNome()<<std::endl;
	
	std::queue<int> da_visitare;
	std::queue<int> visitati;

	
	da_visitare.push(grafo[p.indice_nodo_iniziale][0].getOrigine()->getNome());
	while(!da_visitare.empty()){
		int i=da_visitare.front();
		for(int j=0;j<grafo[i].size();j++){
			Arco arco=grafo[i][j];
			int d=arco.getDestinazione()->getNome();
			
			if(!in_queue(visitati,d)&& !in_queue(da_visitare,d)){
				printf("(Nodo=%d\t potenziale=%d)-",arco.getDestinazione()->getNome(),arco.getDestinazione()->getPotenziale());
								da_visitare.push(d);
			}
			if(j==grafo[i].size()-1){
				printf("\n");
				visitati.push(d);
			}
		} 
		da_visitare.pop();
	}

}
/*
 *funzione che tramite un algoritmo greedy crea il grafo iniziale del problema
 * */
void crea_grafo_iniziale(std::vector<Arco> grafo[],std::vector<Arco> soluzione[],std::vector<Arco> &L,int nr_nodi,int nodo_partenza){
	bool nodi_visitati[nr_nodi];
	std::queue<int> da_visitare;
	for(int i=0;i<nr_nodi;i++){
		nodi_visitati[i]=false;
	}
	
	da_visitare.push(nodo_partenza);
	while(!da_visitare.empty()){
		int i=da_visitare.front();
		if(grafo[i].size()==0)
				nodi_visitati[i]=true;
		for(int j=0;j<grafo[i].size();j++){
			Arco arco=grafo[i][j];
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
				
				if(arco.getDestinazione()->getNome() != nodo_partenza)
					L.push_back(arco);
			}
			if(j==grafo[i].size()-1)
				nodi_visitati[i]=true;
		}
		da_visitare.pop();
	}

}
void set_costi_potenziali(std::vector<Arco> &lista){
	int costo,potenziale_i,potenziale_j;
	for(int i=0;i<lista.size();i++){
		costo=lista[i].getCosto();
		potenziale_i=lista[i].getOrigine()->getPotenziale();
		potenziale_j=lista[i].getDestinazione()->getPotenziale();
		lista[i].setCosto_potenziale(costo-potenziale_i+potenziale_j);
	}
}

void set_potenziali_per_test(std::vector<Arco> &L,bool ammissibile=false){
	if(ammissibile){
		for(int i=0;i<L.size();i++){
			L[i].setCosto_potenziale(1+i);
			
		}
		}else{
	for(int i=0;i<L.size();i++){
			L[i].setCosto_potenziale(1-i);
		}
		
	}
}

bool problema_ottimale(std::vector<Arco> &L){
	bool esito=true;
	
	for(int i=0;i<L.size();i++){
		esito=L[i].getCosto_potenziale()>=0;
		if(!esito)
			break;
	}
	return esito;
}

Arco min_costo_potenziale(std::vector<Arco> archi){
	
	if(archi.size()==1)
		return archi[0];
	int i_min=0;
	for(int i=1;i<archi.size();i++){
		if(archi[i].getCosto_potenziale()<archi[i_min].getCosto_potenziale()  )
			i_min=i;
	}
	return archi[i_min];
}

Arco primo_arco_eligibile(std::vector<Arco> archi){
	int i_res=-1;
	for(int i=0;i<archi.size();i++){
		if(archi[i].getCosto_potenziale()>0){
			i_res=i;
			break;
		}
	}
	return archi[i_res];
}
Arco primo_arco_eligibile_v2(std::vector<Arco> archi){
	
	int i_res=-1;
	for(int i=0;i<archi.size();i++){
        int dj=archi[i].getDestinazione()->getPotenziale();
        int di=archi[i].getOrigine()->getPotenziale();
		if(dj>di-archi[i].getCosto()){
			i_res=i;
			break;
		}
	}
	return archi[i_res];
}

Arco regola_pivoting(std::vector<Arco> archi){
	
	//return primo_arco_eligibile(archi);
	return min_costo_potenziale(archi);
}
Arco primo_arco_disponibile(std::vector<Arco> archi,int nodo_partenza){
    int i=0; 
    for(i=0;i<archi.size();i++){
        if(archi[i].getOrigine()->getNome()==nodo_partenza)
		break;
    }
    
            return archi[i];
}

void elimina_arco_entrante(std::vector<Arco> &L,Arco a){
	int i;
	bool trovato=false;
	for(i=0;i<L.size();i++){
		bool origine=L[i].getOrigine()->getNome()==a.getOrigine()->getNome();
		bool destinazione=L[i].getDestinazione()->getNome()==a.getDestinazione()->getNome();
		bool costo= L[i].getCosto() == a.getCosto();
		if(origine && destinazione && costo){
			trovato=true;
			break;
		}
	}
	if(trovato)
		L.erase(L.begin()+i);
}

void aggiorna_indici(std::vector<Arco> grafo[],Arco partenza,int max_nodi){
	Punto c=esiste_arco(grafo,partenza,max_nodi);
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
			Arco arco=grafo[i][j];
			int d=arco.getDestinazione()->getNome();
			if(arco.getDestinazione()->getNome()==partenza.getDestinazione()->getNome())
				std::cout<<"aggiorna indici:POSSIBILE CICLO!!"<<std::endl;
			if(!in_queue(visitati,d)&& !in_queue(da_visitare,d)){
				//if(!in_queue(visitati,d)){
				int livello=arco.getOrigine()->getDetph()+1;
				//pp=arco.getDestinazione()->getPotenziale()+costo_potenziale;
			/*	if(arco.getOrigine()->getDetph()<arco.getDestinazione()->getDetph())
						pp=arco.getOrigine()->getPotenziale()-arco.getCosto();
					else
						pp=arco.getOrigine()->getPotenziale()+arco.getCosto(); */ 
				
					pp=arco.getDestinazione()->getPotenziale()-costo_potenziale;
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
* aggiorna i costi potenziali in L
*/
void aggiorna_potenziali_L(std::vector<Arco> &L){
	for(int i=0;i<L.size();i++){
		int costo_arco=L[i].getCosto();
		int potenziale_i=L[i].getOrigine()->getPotenziale();
		int potenziale_j=L[i].getDestinazione()->getPotenziale();
		L[i].setCosto_potenziale(costo_arco-potenziale_i+potenziale_j);
	}
}
void print_albero(std::vector<Arco> *albero,int nr_nodi){
	for(int i=0;i<nr_nodi;i++){
		std::cout<<"archi di "<<i<<":\t";
		std::vector<Arco>  lista_locale=albero[i];
		for(int j=0;j<lista_locale.size();j++){
			std::cout<<lista_locale[j].getDestinazione()->getNome()<<"->";
		}
		std::cout<<"\n";
	}

}

Arco restituisci_arco(std::vector<Arco> *grafo,int nodo_o,int nodo_d){
	int i=0;
	for( i=0;i<grafo[nodo_o].size();i++){
				int d=grafo[nodo_o][i].getDestinazione()->getNome();
				if(d==nodo_d)
					break;
	}

	return grafo[nodo_o][i]; 
}

bool compare_pair( const std::pair<int,int> &pair1, 
                   const std::pair<int,int> &pair2)
{
    int result = 0;
	if(  (pair2.second > pair1.second) ){
        result = 1;
    } 
    return result;
}
std::string linea_verticale(int d=0,std::string e=""){
	std::string bordo="";
	for(int i=0;i<d;i++){
		bordo=bordo+"\t";
	}
	std::string linea=e+bordo+"|\n"+e+bordo+"|\n";
	return linea;
}
std::string angolo(int d=0,std::string e=""){
	std::string bordo="";
	std::string linea="";
	for(int i=0;i<d;i++){
		bordo=bordo+"\t";
	}
	if(d>0)
		linea=e+bordo+"|-";
	else
		linea=bordo+"|-";
	return linea;
}
std::string linea_orizzontale(int d=0){
	std::string bordo="";
	for(int i=0;i<d;i++){
		bordo=bordo+"\t";
	}
	std::string linea=bordo+"--";
	return linea;
}

bool esiste_ramo_successivo(std::pair<int,int> vettore[],int max,int pos_attuale){
	bool risultato=false;
	if(pos_attuale<max-1){
		risultato=vettore[pos_attuale+1].second>0;
	}
	return risultato;
}

std::string disegna_arco(std::vector<Arco> *s,int nodo_attuale,bool altri_nodi_dopo){
	std::string ris="";
	if(nodo_attuale<0)
		return ris;
	int nr_nodi=s[nodo_attuale].size();
	// pair<nodo,nr_figli>
	std::pair<int,int> coppie[nr_nodi];
	for(int i=0;i<nr_nodi;i++){
		Arco arco=s[nodo_attuale][i];
		int d=arco.getDestinazione()->getNome();
		int nr_figli_dest=s[d].size();
		coppie[i]={d,nr_figli_dest};
	}

	size_t len = sizeof(coppie)/sizeof(coppie[0]);
	sort(coppie,coppie+len,&compare_pair);
	
	int dept=s[nodo_attuale][0].getOrigine()->getDetph();
	Arco a=restituisci_arco(s,s[nodo_attuale][0].getOrigine()->getPred(),nodo_attuale);
	int distanza_nodo=-1*a.getDestinazione()->getPotenziale();

	ris="("+std::__cxx11::to_string(a.getDestinazione()->getNome())+",d="+std::__cxx11::to_string(distanza_nodo)+")\n";
	std::string e="|";
	
	if(altri_nodi_dopo)
		e="|";
	else
		e="";

	std::string ramo=linea_verticale(dept,e)+angolo(dept,e)+linea_orizzontale();
	for(int i=0;i<nr_nodi;i++){
		std::string linea_attuale=ramo;
		if(coppie[i].second>0){
			std::string linea_figlio="";
			linea_figlio=disegna_arco(s,coppie[i].first,altri_nodi_dopo);
			linea_attuale=linea_attuale+linea_figlio;
			}
		else{
			Arco a=restituisci_arco(s,nodo_attuale,coppie[i].first);
			int distanza_nodo=-1*a.getDestinazione()->getPotenziale();
			linea_attuale+="("+std::__cxx11::to_string(coppie[i].first)+",d="+std::__cxx11::to_string(distanza_nodo)+")\n";
			//cout<<"stringa attuale in disegna:\n"<<nodo_figlio<<endl;
		}
//		cout<<"disegna: nodo_attuale="<<nodo_attuale<<" linea attuale:\n"<<linea_attuale<<endl;	
		ris=ris+linea_attuale;
	}
	return ris;
}


std::string disegna(std::vector<Arco> *s,int nodo_attuale){
	std::string ris="";
	if(nodo_attuale<0)
		return ris;
	int nr_nodi=s[nodo_attuale].size();
	// pair<nodo,nr_figli>
	std::pair<int,int> coppie[nr_nodi];
	for(int i=0;i<nr_nodi;i++){
		Arco arco=s[nodo_attuale][i];
		int d=arco.getDestinazione()->getNome();
		int nr_figli_dest=s[d].size();
		coppie[i]={d,nr_figli_dest};
	}

	size_t len = sizeof(coppie)/sizeof(coppie[0]);
	sort(coppie,coppie+len,&compare_pair);
	
	ris=std::__cxx11::to_string(nodo_attuale)+"\n";

	std::string ramo=linea_verticale()+angolo()+linea_orizzontale();
	for(int i=0;i<nr_nodi;i++){
		std::string linea_attuale=ramo;
		if(coppie[i].second>0){
			std::string linea_figlio="";
			bool ramo_successivo=esiste_ramo_successivo(coppie,nr_nodi,i);
			linea_figlio=disegna_arco(s,coppie[i].first,ramo_successivo);
			linea_attuale=linea_attuale+linea_figlio;
			}
		else{
			Arco a=restituisci_arco(s,nodo_attuale,coppie[i].first);
			int distanza_nodo=-1*a.getDestinazione()->getPotenziale();
			linea_attuale+="("+std::__cxx11::to_string(coppie[i].first)+",d="+std::__cxx11::to_string(distanza_nodo)+")\n";
			//cout<<"stringa attuale in disegna:\n"<<nodo_figlio<<endl;
		}
//		cout<<"disegna: nodo_attuale="<<nodo_attuale<<" linea attuale:\n"<<linea_attuale<<endl;	
		ris=ris+linea_attuale;
	}
	return ris;
}
void stampa_grafo(Problema p){
	//string out="0\n"+linea_verticale()+angolo()+linea_orizzontale()+"1,d=9\n"+linea_verticale(1,"|")+angolo(1)+linea_orizzontale()+"2,d=6\n"+linea_verticale()+angolo()+linea_orizzontale()+"3,d=5";
	std::string out=disegna(p.soluzione,p.indice_nodo_iniziale);
	std::cout<<out<<std::endl;
}

void simplessoRete(Problema p){
	bool ammissibile=problema_ottimale(p.L);
	while(!ammissibile){
		Arco arco_entrante=regola_pivoting(p.L);//da regola di pivoting
		Arco  arco_uscente=uscente(p.soluzione,arco_entrante,p.soluzione->size());
		//inserire arco entrante in soluzione e cancellalo da L
		add_arco(p.soluzione,arco_entrante);
		elimina_arco_entrante(p.L,arco_entrante);
		
		
		//eliminare arco uscente da soluzione e inserirlo in L
		if(arco_entrante.getDestinazione()->getPred()!=-1){
			elimina_arco(p.soluzione,arco_uscente,p.nr_nodi);
			p.L.push_back(arco_uscente);

		}
		//aggiorna indici in soluzione e L 
		aggiorna_indici(p.soluzione,arco_entrante,p.nr_nodi);
		aggiorna_potenziali_L(p.L);


		if(p.soluzione[p.indice_nodo_iniziale].size()==0){ //albero degenere forzo l'introduzione di un arco dal nodo di partenza
		    Arco arco_entrante=primo_arco_disponibile(p.L,p.indice_nodo_iniziale);//da regola di pivoting
		    Arco arco_uscente=uscente(p.soluzione,arco_entrante,p.soluzione->size());
		    //inserire arco entrante in soluzione e cancellalo da L
            add_arco(p.soluzione,arco_entrante);
            elimina_arco_entrante(p.L,arco_entrante);
            //eliminare arco uscente da soluzione e inserirlo in L
            elimina_arco(p.soluzione,arco_uscente,p.nr_nodi);
            p.L.push_back(arco_uscente);
            //aggiorna inidici in soluzione e L 
            aggiorna_indici(p.soluzione,arco_entrante,p.nr_nodi);
            aggiorna_potenziali_L(p.L); 
        }
/*		
	std::cout<<"grafo soluzione"<<std::endl;
	stampa_grafo(p);
    std::cout<<"Arco entrante="<<std::endl;
	arco_entrante.printArco();
	std::cout<<"Arco uscente:"<<std::endl;
	arco_uscente.printArco();  */ 
        ammissibile=problema_ottimale(p.L);
		
	}
}

/*
 * Dato grafo questa funzione inizializza il problema:
 * - crea l'albero di copertura T
 * - inizializza gli indici dei nodi
 * - inizializza i flussi degli archi*/
Problema crea_problema(std::vector<Arco>* grafo,std::vector<Arco>* sol,int nodo_partenza,int nr_nodi){
	if(nodo_partenza<0 || nodo_partenza>nr_nodi){
		std::cout<<"Il nodo di partenza non appartiene al grafo\n"<<std::endl;
		exit(EXIT_FAILURE);
	}
	if(nr_nodi<0){

		std::cout<<"nr nodi errati"<<std::endl;
		exit(EXIT_FAILURE);
	}
	Problema p;
	p.nr_nodi=nr_nodi;
	p.indice_nodo_iniziale=nodo_partenza;
	p.grafo_originale=grafo;
	crea_grafo_iniziale(grafo,sol,p.L,nr_nodi,nodo_partenza);
	set_tread_index(sol,nodo_partenza,nr_nodi);
	set_potenziali(sol,nodo_partenza,nr_nodi);
	
	
	for(int i=0;i<nr_nodi;i++){
		if(sol[i].size()>0)
			set_costi_potenziali(sol[i]);
	}
	set_costi_potenziali(p.L);
	p.soluzione=sol;
	return p;
}
//fino a qui testato
void scrivi_soluzione_file(Problema p,std::string nome_file="../out/soluzione.txt"){
		
	std::ofstream myfile(nome_file);
	if(myfile.is_open()){
		//add here printing of arcs
		

		std::vector<Arco> *grafo=p.soluzione;

		myfile<<"Nodo origine:"<<"Nodo partenza="<<grafo[p.indice_nodo_iniziale][0].getOrigine()->getNome()<<"\n";
		
		std::queue<int> da_visitare;
		std::queue<int> visitati;

		
		da_visitare.push(grafo[p.indice_nodo_iniziale][0].getOrigine()->getNome());
		while(!da_visitare.empty()){
			int i=da_visitare.front();
			for(int j=0;j<grafo[i].size();j++){
				Arco arco=grafo[i][j];
				int d=arco.getDestinazione()->getNome();
				
				if(!in_queue(visitati,d)&& !in_queue(da_visitare,d)){
					int distanza=arco.getDestinazione()->getPotenziale()*(-1);
					myfile<<"(Nodo="<<arco.getDestinazione()->getNome()<<",potenziale="<<distanza<<")-";
					da_visitare.push(d);
				}
				if(j==grafo[i].size()-1){
					myfile<<"\n";
					visitati.push(d);
				}
			} 
			da_visitare.pop();
		}
		
	}else{
		std::cout<<"non posso aprire il file\n";
	}

}

