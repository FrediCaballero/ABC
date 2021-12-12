#include <iostream>

using namespace std;

struct nodo{
	int dato;
	struct nodo *sgte;
};
 int nrnodos=0;
typedef struct nodo *TpNodo;// Definiendo un tipo de dato tipo struct nodo 

TpNodo CrearNodo(){
		TpNodo nuevo = new(struct nodo);
		cout<<"Ingresar valor del nodo---> ";cin>>nuevo->dato;
		cout<<endl;
		nuevo->sgte=NULL;
		return nuevo;
}

void Push(TpNodo &lista){
	TpNodo  q = CrearNodo();
	if(lista!=NULL)
		q->sgte=lista;
	lista=q;
}

void PushAdd(TpNodo &lista, TpNodo q){
	if(lista!=NULL)
		q->sgte=lista;
	lista=q;
}

void mostrar(TpNodo lista){
	TpNodo p=lista;
	int n=1;
	while(p!=NULL){
		cout<<"El nodo "<<n<<" ingresado es ---> "<<p->dato<<endl;
		p=p->sgte;
		n++;
				}	
}

void menu(){
	system("cls");
	cout<<endl;
	cout<<"1.- Aplicar PUSH a la pila "<<endl;// Insertar al Inicio
	cout<<"2.- Trasladar un nodo de Pila A a la Pila C "<<endl;// Eliminar del inicio
	cout<<"3.- Trasladar un nodo de Pila A a la Pila B "<<endl;// Eliminar del inicio
	cout<<"4.- Trasladar un nodo de Pila C a la Pila B "<<endl;// Eliminar del inicio
	cout<<"5.- Trasladar un nodo de Pila B a la Pila A "<<endl;// Eliminar del inicio
	cout<<"6.- Trasladar un nodo de Pila B a la Pila C "<<endl;// Eliminar del inicio
	cout<<"8.- Mostrar Elementos "<<endl;
	cout<<"0.- Salir "<<endl;
		
	cout<<"\n0.- Salir"<<endl;
	cout<<"\nIngresar Opcion ---> ";
}
 //********************************
 TpNodo Pop(TpNodo &lista){
 	TpNodo t=lista;
 	lista=lista->sgte;
 	t->sgte = NULL;
 	cout<<"\nNodo extraido Nr. " <<t->dato<<endl<<endl;
 	system("pause");
 	return t;
 }
 
 
 //********************************
int main( ) {
	TpNodo t=NULL, pilaA=NULL,pilaB=NULL, pilaC=NULL, p=NULL, q=NULL;
	int opc, n, pos, x, busca, reemp;
	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
				// Crear NOdo y asignar un valor al dato
				Push(pilaA);
				system("pause");
				break;
			}
			case 2:{
				q=Pop(pilaA);
				PushAdd(pilaC, q);
				system("pause");
				break;
			}
			case 3:{
				q=Pop(pilaA);
				PushAdd(pilaB, q);
				system("pause");
				break;
			}
			case 4:{
				q=Pop(pilaC);
				PushAdd(pilaB, q);
				system("pause");
				break;
			}
			case 5:{
				q=Pop(pilaB);
				PushAdd(pilaA, q);
				system("pause");
				break;
			}
			case 6:{
				q=Pop(pilaB);
				PushAdd(pilaC, q);
				system("pause");
				break;
			}

			case 8:
			{
				cout<<"Elementos de PILA A"<<endl<<endl;
				mostrar(pilaA);
				cout<<"\nElementos de PILA B"<<endl<<endl;
				if(pilaB !=NULL)
					mostrar(pilaB);
				else
					cout<<"PIla B esta vacia... "<<endl;	
					
				cout<<"\nElementos de PILA C"<<endl<<endl;
					if(pilaC !=NULL)
					mostrar(pilaC);
				else
					cout<<"PIla C esta vacia... "<<endl;	
					
				system("pause");
				
				break;
			}

		}//switch

	}while(opc !=0);
	
	return 0;
}
