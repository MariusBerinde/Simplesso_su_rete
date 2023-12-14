#include <iostream>
#include <string>
#include "../src/Arco.cpp"
#include <list>
#include<iterator>

using namespace std;
void add_arco(list<Arco> list[],Arco a){
    int pos=a.getOrigine()->getNome();
    list[pos].push_back(a);
}

void print_albero(list<Arco> albero[]){
    for(int i=0;i<4;i++){
        cout<<"archi di "<<i<<":\t";
        list<Arco>::iterator it;
        for(it=albero[i].begin();it!= albero[i].end();++it){
            
            cout<<it->getDestinazione()->getNome()<<"->";
        }
            cout << endl;
            cout<<"\n";

        
    }

}
int main(){
Nodo *n1,*n2,*n3,*n4;
n1=new Nodo(0);
n2=new Nodo(1);
n3=new Nodo(2);
n4=new Nodo(3);
Arco a1(n1,n2,3);
Arco a2(n1,n3,3);
Arco a3(n1,n4,3);
Arco b1(n2,n1,3);
Arco b2(n2,n3,3);
Arco c1(n3,n1,3);

list<Arco> lista[4];
add_arco(lista,a1);
add_arco(lista,a2);
add_arco(lista,a3);
add_arco(lista,b1);
add_arco(lista,b2);
add_arco(lista,c1);

print_albero(lista);
delete n1;
delete n2;
delete n3;
delete n4;

}