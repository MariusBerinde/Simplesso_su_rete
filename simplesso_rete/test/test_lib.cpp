#include <iostream>
#include <string>
#include "../src/Alberi.cpp"
#include <vector>
#include <queue>
#include <bits/stdc++.h> 
#define FALSE 0
#define TRUE 1
#define NR_NODI 5
using namespace std;

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

	add_arco(albero,a);
	add_arco(albero,b);
	add_arco(albero,c);
	add_arco(albero,d);
	add_arco(albero,e);
	
	set_prev(albero);
	set_depth_alt(albero);
	set_tread_index(albero); 
	set_potenziali(albero);
	
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
/*
 * verifica che l'albero a sia uguale all'albero 
	righe_a=indica indici di a sono effettivamente usati
	righe_b=indica indici di a sono effettivamente usati
 b*/
bool alberi_uguali(vector<Arco> a[],int righe_a,vector<Arco> b[],int righe_b){
	
	if(righe_a!=righe_b)
		return false;
	for(int i=0;i<righe_a;i++){
		for(int j=0;j<a[i].size();j++){
			auto arco_attuale=a[i][j];
			Punto esito_ricerca=esiste_arco(b,arco_attuale);
			if(esito_ricerca.esito==false)
				return false;
		}
	}
	return true;
}
void test_alberi_uguali(){
	vector<Arco> albero1[5];
	vector<Arco> albero2[5];
	vector<Arco> albero3[5];
	Nodo *n0,*n1,*n2,*n3,*n4;
	bool c1,c2;
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

	add_arco(albero1,a);
	add_arco(albero1,b);
	add_arco(albero1,c);
	add_arco(albero1,d);
	add_arco(albero1,e);
	
	add_arco(albero2,a);
	add_arco(albero2,b);
	add_arco(albero2,c);
	add_arco(albero2,d);
	add_arco(albero2,e);
	
	add_arco(albero3,a);
	add_arco(albero3,b);
	c1=alberi_uguali(albero1,5,albero2,5);
	c2=alberi_uguali(albero1,5,albero3,3);
	if(c1==true)
		cout<<"confronto tra alberi uguali:ok\n";
	else
		cout<<"confronto tra alberi uguali:errore\n";

	if(c2==false)
		cout<<"confronto tra alberi diversi:ok\n";
	else
		cout<<"confronto tra alberi diversi:errore\n";
			

}
int main(){

	vector<Arco> a[NR_NODI];
	inizializza(a);
	int nr_nodi=sizeof(a)/sizeof(a[0]);
	cout<<"test_nr_righe="<<nr_nodi<<"\n";
	test_alberi_uguali();

/*	inizializza(a);
	test_dept(a);
	test_tread_index(a);
	//print_albero_alt(a);
	test_potenziali(a);
	test_esiste_arco(a);
	test_cancellazione(a);
	pulizia(a);  */
}




