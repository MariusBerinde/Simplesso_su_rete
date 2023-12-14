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

void crea_grafo_reale(vector<Arco> a[],Nodo *nodi[]){
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
void crea_grafo(vector<Arco> a[],Nodo *nodi[]){
//creo i nodi
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

void crea_grafo_molto_semplice(vector<Arco> a[],Nodo *nodi[]){
	Arco a0(nodi[0],nodi[1],9);
	Arco a2(nodi[0],nodi[2],6);
	Arco a3(nodi[0],nodi[3],1);

		
	//inserisco archi
	add_arco(a,a0);
	add_arco(a,a2);
	add_arco(a,a3);
	
}
void crea_grafo_semplice(vector<Arco> a[],Nodo *nodi[]){
//creo i nodi
	Arco a0(nodi[0],nodi[1],9);
	Arco a2(nodi[0],nodi[2],6);
	Arco a3(nodi[2],nodi[3],7);

	
	
		//inserisco archi
	add_arco(a,a0);
	add_arco(a,a2);
	
	add_arco(a,a3);
		
}
/*
Arco restituisci_arco(vector<Arco> grafo[],int nodo_o,int nodo_d){
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
		linea=e+bordo+"|-";
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

bool esiste_ramo_successivo(std::pair<int,int> vettore[],int max,int pos_attuale){
	bool risultato=false;
	if(pos_attuale<max-1){
		risultato=vettore[pos_attuale+1].second>0;
	}
	return risultato;
}

string disegna_arco(vector<Arco> *s,int nodo_attuale,bool altri_nodi_dopo){
	string ris="";
	if(nodo_attuale<0 || nodo_attuale>Nr_nodi)
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

	ris="("+to_string(a.getDestinazione()->getNome())+",d="+to_string(distanza_nodo)+")\n";
	string e="|";
	
	if(altri_nodi_dopo)
		e="|";
	else
		e="";

	string ramo=linea_verticale(dept,e)+angolo(dept,e)+linea_orizzontale();
	for(int i=0;i<nr_nodi;i++){
		string linea_attuale=ramo;
		if(coppie[i].second>0){
			string linea_figlio="";
			linea_figlio=disegna_arco(s,coppie[i].first,altri_nodi_dopo);
			linea_attuale=linea_attuale+linea_figlio;
			}
		else{
			Arco a=restituisci_arco(s,nodo_attuale,coppie[i].first);
			int distanza_nodo=-1*a.getDestinazione()->getPotenziale();
			linea_attuale+="("+to_string(coppie[i].first)+",d="+to_string(distanza_nodo)+")\n";
			//cout<<"stringa attuale in disegna:\n"<<nodo_figlio<<endl;
		}
		cout<<"disegna: nodo_attuale="<<nodo_attuale<<" linea attuale:\n"<<linea_attuale<<endl;	
		ris=ris+linea_attuale;
	}
	return ris;
}


string disegna(vector<Arco> *s,int nodo_attuale){
	string ris="";
	if(nodo_attuale<0 || nodo_attuale>Nr_nodi)
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
	
	ris=to_string(nodo_attuale)+"\n";

	string ramo=linea_verticale()+angolo()+linea_orizzontale();
	for(int i=0;i<nr_nodi;i++){
		string linea_attuale=ramo;
		if(coppie[i].second>0){
			string linea_figlio="";
			bool ramo_successivo=esiste_ramo_successivo(coppie,nr_nodi,i);
			linea_figlio=disegna_arco(s,coppie[i].first,ramo_successivo);
			linea_attuale=linea_attuale+linea_figlio;
			}
		else{
			Arco a=restituisci_arco(s,nodo_attuale,coppie[i].first);
			int distanza_nodo=-1*a.getDestinazione()->getPotenziale();
			linea_attuale+="("+to_string(coppie[i].first)+",d="+to_string(distanza_nodo)+")\n";
			//cout<<"stringa attuale in disegna:\n"<<nodo_figlio<<endl;
		}
		cout<<"disegna: nodo_attuale="<<nodo_attuale<<" linea attuale:\n"<<linea_attuale<<endl;	
		ris=ris+linea_attuale;
	}
	return ris;
}
void stampa_grafo(Problema p){
	//string out="0\n"+linea_verticale()+angolo()+linea_orizzontale()+"1,d=9\n"+linea_verticale(1,"|")+angolo(1)+linea_orizzontale()+"2,d=6\n"+linea_verticale()+angolo()+linea_orizzontale()+"3,d=5";
	string out=disegna(p.soluzione,p.indice_nodo_iniziale);
	cout<<out<<endl;
}
*/
void test_molto_semplice(){
	int nr_nodi=4;
	Nodo *nodi[Nr_nodi];
	Problema p;
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	vector<Arco> T[Nr_nodi];
	crea_grafo_molto_semplice(grafo,nodi);
	p=crea_problema(grafo,T,0,nr_nodi);
	cout<<"albero molto semplice"<<endl;
	stampa_grafo(p);

	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
void test_semplice(){
	int nr_nodi=4;
	Nodo *nodi[Nr_nodi];
	Problema p;
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	vector<Arco> T[Nr_nodi];
	
	crea_grafo_semplice(grafo,nodi);
	p=crea_problema(grafo,T,0,nr_nodi);
	//print_albero(p.soluzione,p.nr_nodi);
	cout<<"albero  semplice"<<endl;
	stampa_grafo(p);

	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
void test_normale(){
	
	Nodo *nodi[Nr_nodi];
	Problema p;
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	vector<Arco> T[Nr_nodi];
	
	crea_grafo(grafo,nodi);
	p=crea_problema(grafo,T,0,Nr_nodi);
	cout<<"albero "<<endl;

	//print_albero(p.soluzione,p.nr_nodi);
	stampa_grafo(p);

	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
void test_reale(){
	Nodo *nodi[Nr_nodi];
	Problema p;
	for(int i=0;i<Nr_nodi;i++){
		nodi[i]=new Nodo(i);
	}
	vector<Arco> grafo[Nr_nodi];
	vector<Arco> T[Nr_nodi];
	
	crea_grafo_reale(grafo,nodi);
	p=crea_problema(grafo,T,0,Nr_nodi);
	cout<<"albero "<<endl;

	print_albero(p.soluzione,p.nr_nodi);
	
	stampa_grafo(p);

	for(int i=0;i<Nr_nodi;i++){
		delete(nodi[i]);
	}
}
int main(){
	
	test_molto_semplice();

//	test_semplice();

//	test_normale();

//	test_reale();
 	

	
	

}
