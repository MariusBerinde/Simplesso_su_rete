#include <iostream>
#include <string>
#include "../src/Arco.cpp"
#include <vector>
using namespace std;
typedef struct P{
	vector<Arco> U;
	vector<Arco> L;
}P;
void add_arco(vector<Arco> list[], Arco a){
    int pos=a.getOrigine()->getNome();
    list[pos].push_back(a);
}

void print_albero(const vector<Arco> albero[]){
    for(int i=0;i<4;i++){
        cout<<"archi di "<<i<<":\t";
        auto lista_locale=albero[i];
        for(int j=0;j<lista_locale.size();j++){
            cout<<lista_locale[j].getDestinazione()->getNome()<<"->";
        }
        cout<<"\n";
    }

}

void init(P *problema,vector<Arco> albero[]){
	problema->L.push_back(albero[0][0]);
	problema->L.push_back(albero[0][1]);

}

void print_lista(vector<Arco>& l){
	for(int i=0;i<l.size();i++){
		printf("L[%d]:%d->%d\n",i,l[i].getOrigine()->getNome(),l[i].getDestinazione()->getNome());
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

vector<Arco> lista[4];
add_arco(lista,a1);
add_arco(lista,a2);
add_arco(lista,a3);
add_arco(lista,b1);
add_arco(lista,b2);
add_arco(lista,c1);

print_albero(lista);
vector<Arco> L;
L.push_back(a1);
L.push_back(a2);
L.push_back(a3);
cout<<"provo a stampare L\n";
if(L.size()>0){
	cout<<"numero di elementi di L:"<<L.size()<<"\n";
	print_lista(L);
}

P pr;
init(&pr,lista);
print_lista(pr.L);
n2->setPred(0);
cout<<"Test puntatori="<<L[0].getDestinazione()->getPred()<<"\n";

delete n1;
delete n2;
delete n3;
delete n4;

}
