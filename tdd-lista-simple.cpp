#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//Nodo que representara nuestra lista
typedef struct nodo{
	int codigoCliente;
	char nombre[30];
	char apellido[30];
	struct nodo *ptrSig;
} stcNodo;


stcNodo *ptrInicio, *ptrRecorrido, *ptrNuevo, *ptrAnterior;



//Solicita información en pantalla y 
//crea un nodo para que sea agregado a la lista
bool CrearNodo(){
	bool seCreoNodo=false;
	system("cls");
	
	//Se busca un espacio en memoria
	ptrNuevo = (stcNodo *)malloc( sizeof(stcNodo) );
	
	//Si el puntero es nulo, envia error
	if(ptrNuevo == NULL){
		printf("%s","No hay espacio en memoria disponible para crear");
	}else{
		//Paso 1, pedimos avlor a inicializamos punteros
		printf("%s","***** INGRESO DE DATOS *****\n");
		printf("%s","\nIngrese codigo de cliente:\n");
		scanf("%d", &ptrNuevo->codigoCliente);
		printf("%s","\nIngrese nombre:\n");
		scanf("%s", &ptrNuevo->nombre);
		printf("%s","\nIngrese apellido:\n");
		scanf("%s", &ptrNuevo->apellido);
		ptrNuevo->ptrSig = NULL;
		
		if(ptrInicio == NULL){
			ptrInicio = ptrNuevo;
		}else{
			seCreoNodo=true;
		}
	}
	
	return seCreoNodo ;
}



//Agrega al final de la lista al nodo
void CrearNodoFinal(){
		
	if( CrearNodo() ){
		ptrRecorrido = ptrInicio;
		while(ptrRecorrido->ptrSig != NULL){
			ptrRecorrido = ptrRecorrido->ptrSig;			
		}
		
		ptrRecorrido->ptrSig = ptrNuevo;
	}

}



//Agrega el nodo al principio de la lista
void CrearNodoInicio(){

	if( CrearNodo() ){
		ptrNuevo->ptrSig = ptrInicio;
		ptrInicio = ptrNuevo;
	}

}



//Agrega el nodo en orden descendente según el código del cliente ingresado.
void CrearNodoEnOrden(){
//	bool encontro=false;

	if( CrearNodo() ){

		ptrAnterior = ptrInicio;
		ptrRecorrido = ptrInicio;
		while(ptrRecorrido->ptrSig != NULL){

			if(ptrNuevo->codigoCliente > ptrRecorrido->codigoCliente){
				break;
			}

			ptrAnterior = ptrRecorrido;
			ptrRecorrido = ptrRecorrido->ptrSig;
		}
		
		if(ptrNuevo->codigoCliente > ptrRecorrido->codigoCliente){
			ptrNuevo->ptrSig = ptrRecorrido ;
			
			if(ptrInicio == ptrRecorrido){
				ptrInicio = ptrNuevo;
			}else{
				ptrAnterior->ptrSig = ptrNuevo;
			}			
		}else{
			ptrRecorrido->ptrSig = ptrNuevo;
		}
	}

}



//Elimina un nodo de la lista
void EliminarNodoEnOrden(){
	bool nodoEncontrado=false;
	int numBusqueda, numEncontrado;
	
	numBusqueda=0;
	numEncontrado=0;

	system("cls");
	printf("%s\n","***** ELIMINAR NODO *****");
	printf("%s","* INGRESE NODO A ELIMINAR: ");
	scanf("%d",&numBusqueda);
	
	ptrAnterior = ptrInicio;
	ptrRecorrido = ptrInicio;
	while(ptrRecorrido != NULL){
		if(ptrRecorrido->codigoCliente == numBusqueda){
			ptrAnterior->ptrSig = ptrRecorrido->ptrSig;

			nodoEncontrado=true;
			printf("%s%d%s\n","* ",numBusqueda, "--> [Eliminado exitosamente !!!]");
			break;
		}
		ptrAnterior = ptrRecorrido;
		ptrRecorrido = ptrRecorrido->ptrSig;
	}
	
	printf("%s\n","*       *");
	printf("%s\n","**************************");
	getch();
}




//Recorre la lista
void Recorrido(){
	system("cls");
	
	printf("%s\n","*****");
	printf("%s\n","***** RECORRIDO DE LISTA SIMPLE *****");
	printf("%s\n","*****");
	printf("%s","*   ");

	ptrRecorrido = ptrInicio;
	while(ptrRecorrido != NULL){
		printf("(%d-%s %s)-->", 
				ptrRecorrido->codigoCliente,
				ptrRecorrido->nombre, 
				ptrRecorrido->apellido);
		ptrRecorrido = ptrRecorrido->ptrSig;	
	}
	
	printf("%s\n","NIL");
	printf("%s\n","*            *");
	printf("%s\n","*****");
	getch();
}




//Busca un código de cliente
void Busqueda(){
	int numBusqueda, numEncontrado;
	
	numBusqueda=0;
	numEncontrado=0;

	system("cls");
	printf("%s\n","***** BUSQUEDA DE UN VALOR *****");
	printf("%s","* INGRESE VALOR A BUSCAR:   ");
	scanf("%d",&numBusqueda);
	
	ptrRecorrido = ptrInicio;
	while(ptrRecorrido != NULL){
		if(ptrRecorrido->codigoCliente == numBusqueda){
			printf("* (%d-%s %s)--> [Valor encontrado]\n", 
					ptrRecorrido->codigoCliente,
					ptrRecorrido->nombre, 
					ptrRecorrido->apellido);
			//printf("%s%d%s\n","* ",ptrRecorrido->codigoCliente, "-->");
			numEncontrado++;
		}
		ptrRecorrido = ptrRecorrido->ptrSig;
	}	
	
	if(numEncontrado == 0){
		printf("%s%d%s\n","* ",numBusqueda, "--> [Lo lamento, el valor no fue encontrado !!!]");
	}
	
	printf("%s\n","*       *");
	printf("%s\n","**************************");
	getch();
}




int main (){
	
	int opcion=0;
	while(opcion != 7){
		system("cls");
		printf("%s\n","1.Ingresar (final de la lista)");
		printf("%s\n","2.Ingresar (inicio de la lista)");
		printf("%s\n","3.Mostrar");
		printf("%s\n","4.Buscar");
		printf("%s\n","5.Ingresar en orden DESCENDENTE");
		printf("%s\n","6.Eliminar");
		printf("%s\n","7.Salir");
		printf("%s\n","Seleccione una opcion");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				CrearNodoFinal();
				break;
			case 2:
				CrearNodoInicio();
				break;
			case 3:
				Recorrido();
				break;
			case 4:
				Busqueda();
				break;
			case 5:
				CrearNodoEnOrden();
				break;				
			case 6:
				EliminarNodoEnOrden();
				break;								
			case 7:
				break;								

			default:
				printf("%s\n","5.Salir");	
				getch();
				opcion=0;
				break;													
		}
		
	}
	
	return 0;
}

