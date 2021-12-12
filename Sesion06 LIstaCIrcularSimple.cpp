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

void InsertarInicio(TpNodo &lista){
	TpNodo  q = CrearNodo(), p=lista;
	if(lista==NULL){
		lista=q;
		q->sgte=lista;
	}
	else{
		while(p->sgte!= lista)
			p=p->sgte;
		q->sgte=lista;
		p->sgte=q;
		lista=q;	
	}
	cout<<"\nIngresado al Inicio ---> "<<q->dato<<endl<<endl;
}

void InsertarFinal(TpNodo &lista){
	TpNodo p=lista, q = CrearNodo();
	if(lista==NULL){
		lista=q;	
		q->sgte=lista;
	}
	   
	   
	else{
		while(p->sgte != lista)
			p=p->sgte;
		p->sgte=q;
		q->sgte=lista;	
	}   
		cout<<"\nIngresado al Final ---> "<<q->dato<<endl<<endl;
}

void InsertarPosicion(TpNodo &lista, int pos){
	TpNodo p=lista, t=NULL, q=NULL;
	int x=1;
	bool flag = false;
	if(pos==1){
		InsertarInicio(lista);
		return;
	}
	
	q=CrearNodo();
	while(p->sgte != NULL && x!= pos){
		t=p;
		p=p->sgte;
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag ==true){
			t->sgte = q;
			q->sgte = p;	
		}
	else{
		cout<<"ERROR: Posicion "<<pos<< " ingresada No Existe "<<endl;
		system("pause");
	}
}

void menu(){
	system("cls");
	cout<<endl;
	cout<<"\nLISTA CIRCULAR SIMPLE"<<endl;
	cout<<"1.- Insertar Nodo al Inicio "<<endl;
	cout<<"2.- Insertar Nodo al Final "<<endl;
	cout<<"3.- Insertar por Posicion "<<endl;
	cout<<"4.- Mostrar elementos de la lista "<<endl;
	cout<<"5.- Eliminar Primer Nodo "<<endl;
	cout<<"6.- Eliminar ultimo Nodo "<<endl;
	cout<<"7.- Eliminar por Posicion "<<endl;
	cout<<"8.- Buscar y Reemplazar valores "<<endl;
	
	
	cout<<"\n0.- Salir"<<endl;
	cout<<"\nIngresar Opcion ---> ";
}
 //********************************
 void EliminarInicio(TpNodo &lista){
 	TpNodo t=lista, p=lista;
 	if(lista==NULL){
 		cout<<"\nERROR: Lista Vacia, no permite esta opcion "<<endl;
 		system("pause");
 		return;
 	 }
 	 if(lista->sgte != lista){
 	 	
 	 	while(p->sgte != lista)
 	 		p=p->sgte;
 	 	p->sgte=lista->sgte;
	 	lista=lista->sgte;	
 	  }
 	  else
 	  	lista=NULL;
 	 
 	 cout<<"\nNodo eliminado Nr. " <<t->dato<<endl<<endl;
 	delete(t);
 	system("pause");
 	
 }
 
 void EliminarFinal(TpNodo &lista){
 	TpNodo p=lista, t=NULL;
 	if(lista == NULL){
 		cout<<"ERROR: Lista vacia, no permite esta opcion"<<endl;
 		system("pause");
		 return;
	 }
	 if(lista->sgte != lista){
	 	while(p->sgte !=lista){
	 		t=p;
	 		p=p->sgte;
		 }
		 t->sgte=lista;
		}	
		else
			lista=NULL;
		
		cout<<"\nNodo eliminado Nr "<<p->dato<<endl;
		delete(p);
 		system("pause");
	 	return;
	 }
	 

 //*******************************************
 void EliminarPosicion(TpNodo &lista, int pos){
 	TpNodo p=lista, t=NULL;
 	int x=1;
 	bool flag=false;
 	if(pos==1){
	 	EliminarInicio(lista);
	 	return;
	 }
	 
 	while(p->sgte != NULL && x != pos){
 		t=p;
 		p=p->sgte;
 		x++;
 		if(x==pos)
 			flag=true;
 	 }
 	if(flag = true){
 		t->sgte = p->sgte;
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
  	while(p->sgte!=lista){
  		if(p->dato ==b){
  			p->dato=r;	
  			flag=true;
		  }
  			
  		p=p->sgte;	
	  }
	  	if(p->dato ==b){
  			p->dato=r;	
  			flag=true;
		  }
  	if(flag==false){
  		cout<<"Valor "<<b<< " no encontrado en la lista"<<endl;
  		system("pause");
	  }
  	
  }
 
 void MostrarLista(TpNodo lista){
 	TpNodo p=lista;
	int	n=1;
	if(lista==NULL)
		cout<<"\nLISTA VACIA....."<<endl;
	else{
		while(p->sgte!=lista){
			cout<<"El nodo "<<n<<" ingresado es ---> "<<p->dato<<endl;
			p=p->sgte;
			n++;
		}
		cout<<"El nodo "<<n<<" ingresado es ---> "<<p->dato<<endl;
		
	}
		
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
				system("pause");
				
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
