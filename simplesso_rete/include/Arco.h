#include "Nodo.h"
class Arco{
private:
	Nodo* origine; 
	Nodo* destinazione;
	int costo_potenziale;
	int costo;
public:
	Arco(Nodo*  o,Nodo* d,int c){
		if(o->getNome()!=d->getNome()){
			origine=o;
			destinazione=d;
		}
		if(c>=-1)
			costo=c;
	}
	Nodo*  getOrigine(){return origine;}
	Nodo*  getDestinazione(){return destinazione;}
	int getCosto_potenziale(){return costo_potenziale;}
	//int getCosto_potenziale(){return costo-origine->getPotenziale()+destinazione->getPotenziale();}
	int getCosto(){return costo;}

	void setOrigine(Nodo*  o);
	void setDestinazione(Nodo*  d);
	void setCosto_potenziale(int c){
	//	if(f> -1 && f<=costo+1)
			costo_potenziale=c;
	}
	void setCosto(int c);
	void eliminaPuntatori(){
		delete(origine);
	     origine=nullptr;
	     delete(destinazione);
	     destinazione=nullptr;
	}
    bool equals(Arco d);
	void printArco(){
		std::cout<<"Nodo origine="<<origine->getNome()<<"\tnodo destinazione="<<destinazione->getNome()<<"\nflusso="<<costo_potenziale<<"\tcosto="<<costo<<"\n";
		}
	};
