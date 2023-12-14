#include <iostream>
#include <string>
#include "../src/Arco.cpp"
#include <vector>
#include <queue>
#include <bits/stdc++.h> 
#define TRUE 1
#define NR_NODI 5
using namespace std;
typedef struct Punto{
	int i,j;
	bool esito;
}Punto;
void add_arco(vector<Arco> list[],Arco a){
	int pos=a.getOrigine()->getNome();

	list[pos].push_back(a);
}

void print_albero(vector<Arco> albero[]){
	for(int i=0;i<4;i++){
		cout<<"archi di "<<i<<":\t";
		auto lista_locale=albero[i];
		for(int j=0;j<lista_locale.size();j++){
			cout<<lista_locale[j].getDestinazione()->getNome()<<"->";
		}
		cout<<"\n";
	}

}

void print_albero_alt(vector<Arco> albero[]){
	puts("print alternativa\n");
	for(int i=0;i<4;i++){
		cout<<"archi di "<<i<<":\t";
		for(int j=0;j<albero[i].size();j++){
			cout<<"(d="<<albero[i][j].getDestinazione()->getNome()<<",potenziale(d)=";
			cout<<albero[i][j].getDestinazione()->getPotenziale()<<")->";
		}
		cout<<"\n";
	}

}

void inizializza(vector<Arco> albero[]){
	Nodo *n0,*n1,*n2,*n3,*n4;
	n0=new Nodo(0);
	n1=new Nodo(1);
	n2=new Nodo(2);
	n3=new Nodo(3);
	n4=new Nodo(4);

	Arco a(n0,n1,1);
	Arco b(n0,n2,1);
	Arco c(n1,n4,1);
	Arco d(n3,n2,1);
	Arco e(n2,n3,1);
	Arco f(n2,n3,2);

	add_arco(albero,a);
	add_arco(albero,b);
	add_arco(albero,c);
	add_arco(albero,d);
	add_arco(albero,e);
	add_arco(albero,f);

	//set_prev(albero);
	//set_depth_alt(albero);
	//set_tread_index(albero); 
	//set_potenziali(albero);
	
}
void pulizia(vector<Arco> albero[]){
	for(int i=0;i<4;i++){

		auto lista_locale=albero[i];
		for(int j=0;j<lista_locale.size();j++){
			if(lista_locale[j].getOrigine()->getNome()<NR_NODI)
				delete lista_locale[j].getOrigine();
			if(lista_locale[j].getDestinazione()->getNome()<NR_NODI)
				delete lista_locale[j].getDestinazione();
		}
	}

}

void set_prev(vector<Arco> albero[]){
	for(int i=0;i<4;i++){
		for(int j=0;j<albero[i].size();j++){
			if(albero[i][j].getDestinazione()->getPred()==-1)
				albero[i][j].getDestinazione()->setPred(i);
		}
		cout<<"\n";
	}
}

void setDepth_queue(vector<Arco> adj_list[],queue<int> *dest,int actual_depth){//da fare con
	if (!dest->empty())
	{
		int nodo_attuale = dest->front();
		dest->pop();

		for (int j = 0; j < adj_list[nodo_attuale].size(); j++)
		{
			if (j == 0 ){

				adj_list[nodo_attuale][j].getOrigine()->setDetph(actual_depth);
				actual_depth++;
			}

			int next = adj_list[nodo_attuale][j].getDestinazione()->getNome();
			auto prossimo_nodo = adj_list[nodo_attuale][j].getDestinazione();
			if (adj_list[next].size() == 0)
				adj_list[nodo_attuale][j].getDestinazione()->setDetph(actual_depth--);
			else
			{
				if (prossimo_nodo->getDetph() == -1)
					dest->push(next);
			}
		}
		setDepth_queue(adj_list, dest, actual_depth);
	}
}

void set_depth_alt(vector<Arco> albero[]){
	albero[0][0].getOrigine()->setDetph(0);

	for(int i=0;i<NR_NODI;i++){
		if(albero[i].size()>0){
			for(int j=0;j<albero[i].size();j++){
				auto nodo_attuale=albero[i][j].getDestinazione();

				if(albero[i][j].getDestinazione()->getDetph()==-1){
					auto prev_index=albero[i][j].getDestinazione()->getPred();
					int prev_dept=albero[prev_index][0].getOrigine()->getDetph();
					prev_dept++;
					albero[i][j].getDestinazione()->setDetph(prev_dept);
				}
			}
		}
	}

}

void test_dept(vector<Arco> albero[]){
	bool r0,r1,r2,r3,r4;   

	r0= 0 == albero[0][0].getOrigine()->getDetph();
	r1= 1 == albero[0][0].getDestinazione()->getDetph();
	r2= 1 == albero[0][1].getDestinazione()->getDetph();
	r3= 2 == albero[2][0].getDestinazione()->getDetph();  //nodo 3
	r4= 2 == albero[1][0].getDestinazione()->getDetph();  //nodo 4

	if(r0)
		cout<<"nodo 0: depth ok\n";
	else
		cout<<"nodo 0: depth sbagliato\n";

	if(r1)
		cout<<"nodo 1: depth ok\n";
	else
		cout<<"nodo 1: depth sbagliato\n";

	if(r2)
		cout<<"nodo 2: depth ok\n";
	else
		cout<<"nodo 2: depth sbagliato\n";
	if(r3)
		cout<<"nodo 3: depth ok\n";
	else
		cout<<"nodo 3: depth sbagliato\n";

	if(r4)
		cout<<"nodo 4: depth ok\n";
	else
		cout<<"nodo 4: depth sbagliato\n";
}
void print_pop_queue(queue<int> *q){
	if (q->empty())
		puts("coda vuota\n");

	if(!q->empty()){
		cout<<q->front()<<"->";
		q->pop();
		print_pop_queue(q);
	}
}

bool test_indice(int nodo,int val){
	switch(nodo){
		case 0: return val==1;
			break;
		case 1: return val==4;
			break;
		case 2: return val==3;
			break;
		case 3: return val==0;
			break;
		case 4: return val==2;
			break;
		default: return false;
	}
}
int getIndex(vector<int> v,int val){
	auto it= find(v.begin(),v.end(),val);
	int index=-1;
	if(it != v.end()){
		index=it-v.begin();
	}
	return index;
}

void DFS(vector<Arco> albero[],vector<int> *coda,int nodo_attuale){
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
void set_tread_index(vector<Arco> albero[]){
	vector<int> dfs;
	DFS(albero,&dfs,0);
	for(int i=0;i<NR_NODI;i++){
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
void test_tread_index(vector<Arco> albero[]){
	bool r0,r1,r2,r3,r4;   
	r0=test_indice( 0,albero[0][0].getOrigine()->getThreadI());
	r1=test_indice(1,albero[0][0].getDestinazione()->getThreadI());
	r2=test_indice(2,albero[0][1].getDestinazione()->getThreadI());
	r3=test_indice(3,albero[2][0].getDestinazione()->getThreadI());
	r4=test_indice(4,albero[1][0].getDestinazione()->getThreadI());

	if(r0)
		cout<<"nodo 0: indice thread ok\n";
	else
		cout<<"nodo 0: indice thread sbagliato\n";

	if(r1)
		cout<<"nodo 1: indice thread ok\n";
	else
		cout<<"nodo 1: indice thread sbagliato\n";

	if(r2)
		cout<<"nodo 2: indice thread ok\n";
	else
		cout<<"nodo 2: indice thread sbagliato\n";
	if(r3)
		cout<<"nodo 3: indice thread ok\n";
	else
		cout<<"nodo 3: indice thread sbagliato\n";

	if(r4)
		cout<<"nodo 4: indice thread ok\n";
	else
		cout<<"nodo 4: indice thread sbagliato\n";
}
bool test_potenziale(int nodo,int val){
	switch(nodo){
		case 0: return val==0;
			break;
		case 1: return val==-1;
			break;
		case 2: return val==-1;
			break;
		case 3: return val==-2;
			break;
		case 4: return val==-2;
			break;
		default: return false;
	}

}
void set_potenziali(vector<Arco> albero[]){

	int potenzialeO,potenzialeD,deptO,deptD,costo;
	albero[0][0].getOrigine()->setPotenziale(0);
	for(int i=0;i<NR_NODI;i++){
		if(albero[i].size()>0){
			for(int j=0;j<albero[i].size();j++){
				auto nodo_origine=albero[i][j].getOrigine();
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

					/*if(albero[i][j].getDestinazione()->getNome()==4){
					  cout<<"potenzialeD="<<potenzialeD<<"\n";
					  cout<<"nodo 4 potenziale="<<albero[i][j].getDestinazione()->getPotenziale()<<"\n";
					  }*/
				}
			}
		}
	}
}
void test_potenziali(vector<Arco> albero[]){

	bool r0,r1,r2,r3,r4; 
	r0=test_potenziale( 0,albero[0][0].getOrigine()->getPotenziale());
	r1=test_potenziale(1,albero[0][0].getDestinazione()->getPotenziale());
	r2=test_potenziale(2,albero[0][1].getDestinazione()->getPotenziale());
	r3=test_potenziale(3,albero[2][0].getDestinazione()->getPotenziale());
	r4=test_potenziale(4,albero[1][0].getDestinazione()->getPotenziale());

	if(r0)
		cout<<"nodo 0: potenziale ok\n";
	else
		cout<<"nodo 0: potenziale sbagliato\n";

	if(r1)
		cout<<"nodo 1: potenziale ok\n";
	else
		cout<<"nodo 1: potenziale sbagliato\n";

	if(r2)
		cout<<"nodo 2: potenziale ok\n";
	else
		cout<<"nodo 2: potenziale sbagliato\n";
	if(r3)
		cout<<"nodo 3: potenziale ok\n";
	else
		cout<<"nodo 3: potenziale sbagliato\n";

	if(r4)
		cout<<"nodo 4: potenziale ok\n";
	else
		cout<<"nodo 4: potenziale sbagliato\n";
}
/**
 *La classe punto ha eisto false se il punto non è trovato altrimenti esito è true e ij contengono le coordnate nella matrice di adiacenza
 * */
Punto esiste_arco(vector<Arco> albero[], Arco a){
	int nodoO,nodoD,costo;
	Punto p;
	p.esito=false;
	
	nodoO=a.getOrigine()->getNome();
	nodoD=a.getDestinazione()->getNome();
	costo=a.getCosto();
	
	for(int i=0;i<NR_NODI;i++){
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
							break;	
						}
						
					 }
				 }
				
			}
		}
	}
		
	return p;
}

void test_esiste_arco(vector<Arco> albero[]){
        Nodo *n0,*n1,*n2,*n3,*n4;
	Punto t1,t2,t3,t4;
	
	n0=new Nodo(0);
	n1=new Nodo(1);
	n2=new Nodo(2);
	n3=new Nodo(3);
	
	Arco a(n0,n1,1);
	Arco b(n0,n1,2);
	Arco c(n3,n2,1);
	Arco d(n3,n2,4);
	t1=esiste_arco(albero,a);	
	t2=esiste_arco(albero,b);	
	t3=esiste_arco(albero,c);	
	t4=esiste_arco(albero,d);	
	cout<<"inizio testi esiste arco\n";
	if(t1.esito==true)
		cout<<"t1:ok\n";
	else
		cout<<"t1:errato\n";
	if(t2.esito==false)
		cout<<"t2:ok\n";
	else
		cout<<"t2:errato\n";
	if(t3.esito==true)
		cout<<"t3:ok\n";
	else
		cout<<"t3:errato\n";
	if(t4.esito==false)
		cout<<"t4:ok\n";
	else
		cout<<"t4:errato\n";

	free(n0);
	free(n1);
	free(n2);
	free(n3);
}
void elimina_arco(vector<Arco> albero[],Arco a){
	Punto p=esiste_arco(albero,a);
	if(p.esito==true){
		albero[p.i].erase(albero[p.i].begin() + p.j);
	}
}
void test_cancellazione(vector<Arco> albero[]){
	Nodo *origine,*dest;
	origine=albero[0][0].getOrigine();
	dest=albero[0][0].getDestinazione();
	Arco a(origine,dest,2);
	add_arco(albero,a);
	Punto esistenza=esiste_arco(albero,a);
	cout<<"arco prima di cancellazione="<<esistenza.esito<<"\n";
	elimina_arco(albero,a);
	esistenza=esiste_arco(albero,a);
	cout<<"arco dopop  cancellazione="<<esistenza.esito<<"\n";
}
int main(){
	queue<int> coda;
	vector<Arco> a[NR_NODI];
	inizializza(a);
	/*set_prev(a);
	set_depth_alt(a);
	test_dept(a);
	set_tread_index(a); 
	test_tread_index(a);
	set_potenziali(a);
	print_albero_alt(a);
	test_potenziali(a);*/
	test_esiste_arco(a);
	test_cancellazione(a);
	pulizia(a);  
}




