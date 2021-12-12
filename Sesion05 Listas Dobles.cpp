#include <iostream>

using namespace std;

struct nodo{
	int dato;
	struct nodo *sgte;
	struct nodo *ant;
};
 int nrnodos=0;
typedef struct nodo *TpNodo;// Definiendo un tipo de dato tipo struct nodo 

TpNodo CrearNodo(){
		TpNodo nuevo = new(struct nodo);
		cout<<"Ingresar valor del nodo---> ";cin>>nuevo->dato;
		cout<<endl;
		nuevo->sgte=NULL;
		nuevo->ant=NULL;
		return nuevo;
}

void InsertarInicio(TpNodo &lista){
	TpNodo  q = CrearNodo();
	if(lista!=NULL){
		q->sgte=lista;
		lista->ant = q;
	}
	lista=q;
}

void InsertarFinal(TpNodo &lista){
	TpNodo p=lista, q = CrearNodo();
	if(lista==NULL)
	   lista=q;
	else{
		while(p->sgte != NULL)
			p=p->sgte;
		p->sgte=q;
		q->ant=p;	
	}   
}

void InsertarPosicion(TpNodo &lista, int pos){
	TpNodo p=lista, q=NULL;
	int x=1;
	bool flag = false;
	if(pos==1){
		InsertarInicio(lista);
		return;
	}
	
	q=CrearNodo();
	while(p->sgte != NULL && x!= pos){
		p=p->sgte;
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag ==true){

			q->sgte =p;
			p->ant->sgte=q;
			q->ant=p->ant;
			p->ant=q;	
		}
	else{
		cout<<"ERROR: Posicion "<<pos<< " ingresada No Existe "<<endl;
		system("pause");
	}
}

void menu(){
	system("cls");
	cout<<endl;
	cout<<"\tLISTAS DOBLEMENTE ENLAZADAS "<<endl<<endl;
	cout<<"1.- Insertar Nodo al Inicio "<<endl;
	cout<<"2.- Insertar Nodo al Final "<<endl;
	cout<<"3.- Insertar por Posicion "<<endl;
	cout<<"4.- Mostrar elementos de Ida y Vuelta "<<endl;
	cout<<"5.- Eliminar Primer Nodo "<<endl;
	cout<<"6.- Eliminar ultimo Nodo "<<endl;
	cout<<"7.- Eliminar por Posicion "<<endl;
	cout<<"8.- Buscar y Reemplazar valores "<<endl;
	
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"\nIngresar Opcion ---> ";
}
 //********************************
 void EliminarInicio(TpNodo &lista){
 	TpNodo t=lista;
 	if(lista->sgte ==NULL){
		lista=NULL;
		delete(t);
		return;
	}
 	
 	lista=lista->sgte;
 	lista->ant=NULL;
 	cout<<"\nNodo eliminado Nr. " <<t->dato<<endl<<endl;
 	delete(t);
 	system("pause");
 	
 }
 
 void EliminarFinal(TpNodo &lista){
 	TpNodo p=lista;
 	if(lista == NULL){
 		cout<<"ERROR: Lista vacia, no permite esta opcion"<<endl;
 		system("pause");
		 return;
	 }
	 if(lista->sgte ==NULL){
	 	lista=NULL;
		cout<<"\nNodo eliminado Nr "<<p->dato<<endl;
		delete(p);
 		system("pause");
	 	return;
	 }
	 	 
	 while(p->sgte != NULL){
	  	p=p->sgte;
	 }
	p->ant->sgte = NULL;
	cout<<"\nNodo eliminado Nr. " <<p->dato<<endl<<endl;
 	delete(p);
 	system("pause");
	 	
 }
 void EliminarPosicion(TpNodo &lista, int pos){
 	TpNodo p=lista;
 	int x=1;
 	bool flag=false;
 	// Si es la primera posicion
 	if(pos==1){
	 	EliminarInicio(lista);
	 	return;
	 }
	 
 	while(p->sgte != NULL && x != pos){
 		p=p->sgte;
 		x++;
 		if(x==pos)
 			flag=true;
 	 }
 	if(flag = true){
		// Si es el ultimo nodo 	
		if(p->sgte ==NULL){
	 		EliminarFinal(lista);
	 		return;
	 	}
 		p->ant->sgte = p->sgte;
		p->sgte->ant= p->ant;
 		cout<<"\nNodo eliminado Nr. " <<p->dato<<endl<<endl;
 		delete(p);
 		system("pause");
 	}
 	else{
 		cout<<"ERROR Posicion ingresada No Existe..."<<endl;
 		system("pause");
	 }
 	
 }
  void BuscaReemplaza(TpNodo lista, int b, int r){
  	TpNodo p=lista;
  	bool flag = false;
  	while(p!=NULL){
  		if(p->dato ==b){
  			p->dato=r;	
  			flag=true;
		  }
  			
  		p=p->sgte;	
	  }
  	if(flag==false){
  		cout<<"Valor "<<b<< " no encontrado en la lista"<<endl;
  		system("pause");
	  }
  	
  }
 
 void MostrarLista(TpNodo lista){
 	TpNodo p=lista, t=NULL;
	int	n=1;
	cout<<"LISTA DE IDA"<<endl;
	while(p!=NULL){
		cout<<"El nodo "<<n<<" ingresado es ---> "<<p->dato<<endl;
		t=p;
		p=p->sgte;
		n++;
	}
	
	p=t;
	n=n-1;
	cout<<"LISTA DE VUELTA"<<endl;
	while(p!=NULL){
		cout<<"El nodo "<<n<<" ingresado es ---> "<<p->dato<<endl;
		p=p->ant;
		n--;
	}
	
	
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
				InsertarInicio(lista);
				system("pause");
				break;
			}
			case 2:{
				InsertarFinal(lista);
				system("pause");
				break;
	
			
			}
		
			case 3:
				{
				if(lista ==NULL){
					cout<<"\nERROR: La lista esta vacia.. no permite esta opcion "<<endl;
					system("pause");
				}
				else{
					cout<<"Ingresar la posicion---->";cin>>pos;
					if(pos>0)
						InsertarPosicion(lista, pos);
					else{
						cout<<"\nERROR: Solo permite valores mayores que cero"<<endl;
						system("pause");
					}
							
				}	
				
				
			
			break;
			}
		
			case 4:
			{
				MostrarLista(lista);
				
				break;
			}
			case 5:
				{
				EliminarInicio(lista);
				break;	
				}
			case 6:
				{
				EliminarFinal(lista);	
				break;
				}
			case 7:
			{
				if(lista==NULL){
					cout<<" Error: Lista Vacia..no permite esat opcion "<<endl;
					system("pause");
				}
				else{
					cout<<"Insertar Posicion---> ";cin>>pos;
					EliminarPosicion(lista, pos);
					
				}
				
				break;
			}	
			case 8:
			{
				if(lista==NULL){
					cout<<" Error: Lista Vacia..no permite esat opcion "<<endl;
					system("pause");
				}
				else{
					cout<<"Insertar el valor a Buscar-------> ";cin>>busca;
					cout<<"Insertar el valor a Reemplazar---> ";cin>>reemp;
					if(busca > 0 && reemp > 0)
						BuscaReemplaza(lista, busca, reemp);
					else{
						cout<<"ERROR: Solo permite valores > cero "<<endl;
						system("pause");
					}
				}
				
				break;
			}	
		}//switch
		
		
	
		
	}while(opc !=0);
	
	return 0;
}
