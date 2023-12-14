#include "../include/Nodo.h"
#include <iostream>
#include <string>

bool Nodo::equals(Nodo d){
	bool test_nome= nome==d.nome;
	bool test_pred= pred==d.pred;
	bool test_dept= depth==d.depth;
	bool test_tread= threadI==d.threadI;
	bool test_potenziale= d.potenziale;
	return test_nome && test_pred && test_dept && test_tread && test_potenziale;
}


