#include <iostream>
#pragma once
class Nodo{
private:
	int nome;
	int pred;
	int depth;
	int threadI;
	int potenziale;
public:
	Nodo(int name){
		nome=name;
		pred=-1;
		depth=-1;
		threadI=-1;
		potenziale=-256;
	}
	int getNome(){return nome;}
	int getPred(){return pred;}
	int getThreadI(){return threadI;}
	int getPotenziale(){return potenziale;}
	int getDetph(){return depth;}
	void setPred(int val){
		if(val> -2){
			pred=val;
			} 
		}
	void setDetph(int val){
		if(val> -2){
			depth=val;
			} 
		}

	void setThreadI(int val){
		if(val> -2){
			threadI=val;
			} 
		}

	void setPotenziale(int val){
		potenziale=val;
			 
		}
	bool equals(Nodo d);
	void printNodo(){
		std::cout<<"nome="<<nome<<"\tpred="<<pred<<"\n"<<"depth="<<depth<<"\tthread="<<threadI<<"\tpotenziale="<<potenziale<<"\n";
	}
};

