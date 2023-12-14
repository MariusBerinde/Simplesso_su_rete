
#include "../include/Arco.h"
#include "Nodo.cpp"
#include <iostream>
#include <string>

	void Arco::setOrigine(Nodo *o){
		if(destinazione->getNome()!= o->getNome())
			origine=o;
	}
	void Arco::setDestinazione(Nodo *d){
		if(origine->getNome()!=d->getNome())
			destinazione=d;
	}
/*	void Arco::setCosto_potenziale(int  c){
	//	if(f> -1 && f<=costo+1)
			costo_potenziale=c;
	}*/
void Arco::setCosto(int c ){
		if(c<=costo)
			costo=c;
	}
	void Arco::printArco(){
		
		std::cout<<"Nodo origine="<<origine->getNome()<<"\tnodo destinazione="<<destinazione->getNome()<<"\nflusso="<<costo_potenziale<<"\tcosto="<<costo<<"\n";
	}
       
