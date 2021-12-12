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


void Encolar(TpNodo &lista){
	TpNodo p=lista, q = CrearNodo();
	if(lista==NULL)
	   lista=q;
	else{
		while(p->sgte != NULL)
			p=p->sgte;
		p->sgte=q;	
	}   
}


void menu(){
	system("cls");
	cout<<endl;
	cout<<"1.- Encolar Nodo "<<endl;
	cout<<"2.- Desencolar Nodo "<<endl;
	cout<<"3.- Mostrar la COLA "<<endl;
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"\nIngresar Opcion ---> ";
}
 //********************************
 void Desencolar(TpNodo &lista){
 	TpNodo t=lista;
 	lista=lista->sgte;
 	cout<<"\nNodo eliminado Nr. " <<t->dato<<endl<<endl;
 	delete(t);
 	system("pause");
 	
 }
 
 
  
 
 //********************************
int main( ) {
	TpNodo t=NULL, lista=NULL, p=NULL, q=NULL;
	int opc, n, pos, x, busca, reemp;
	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
				// Crear NOdo y asignar un valor al dato
				Encolar(lista);
				system("pause");
				break;
			}
			case 2:{
				Desencolar(lista);
				system("pause");
				break;
	
			
			}
		

			case 3:
			{
				p=lista;
				n=1;
				while(p!=NULL){
					cout<<"El nodo "<<n<<" ingresado es ---> "<<p->dato<<endl;
					p=p->sgte;
					n++;
				}
				system("pause");
				
				break;
			}
	
		}//switch
		
		
	
		
	}while(opc !=0);
	
	return 0;
}
