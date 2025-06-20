#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct {
	pnodo inicio;
	pnodo final;
	int contador;
} tlista;

void iniciar_lista(tlista &lista) {
	lista.inicio = NULL;
	lista.final = NULL;
	lista.contador = 0;
}

void crear_nodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
}

void agregar_final(tlista &lista, pnodo nuevo) {
	if(lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.contador++;
}

void mostrar(tlista lista) {
	pnodo i = lista.inicio;
	while(i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}

int buscar_indice(tlista lista, int valor) {
	pnodo i = lista.inicio;
	int indice = 0;
	while (i != NULL) {
		if (i->dato == valor) {
			return indice;
		}
		i = i->siguiente;
		indice++;
	}
	return -1; 
}

int main() {
	tlista lista;
	pnodo nuevo;
	iniciar_lista(lista);
	
	crear_nodo(nuevo, 10);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 20);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 30);
	agregar_final(lista, nuevo);
	
	mostrar(lista);
	
	int indice = buscar_indice(lista, 20);
	cout << "El valor 20 está en la posición: " << indice << endl;
	
	return 0;
}
