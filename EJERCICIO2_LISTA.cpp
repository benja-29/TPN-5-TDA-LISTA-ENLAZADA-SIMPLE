#include<bits/stdc++.h>
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
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

void agregar_final(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.contador++; 
}

void agregar_inicio(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		nuevo->siguiente = lista.inicio;
		lista.inicio = nuevo;
	}
	lista.contador++; 
}

pnodo eliminar_inicio(tlista &lista) {
	pnodo borrado;
	if (lista.inicio == NULL) {
		borrado = NULL;
	} else {
		borrado = lista.inicio;
		lista.inicio = lista.inicio->siguiente;
		if (lista.inicio == NULL) { 
			lista.final = NULL;
		}
		borrado->siguiente = NULL;
		lista.contador--; 
	}
	return borrado;
}

void mostrar(tlista lista) {
	pnodo i;
	if (lista.inicio != NULL) {
		for (i = lista.inicio; i != NULL; i = i->siguiente) {
			cout << i->dato << " -> ";
		}
		cout << "NULL" << endl;
	} else {
		cout << "Lista vacía" << endl;
	}
}

int cantidad_elementos(tlista lista) {
	return lista.contador;
}

int main() {
	tlista lista;
	iniciar_lista(lista);
	pnodo nuevo;
	
	crear_nodo(nuevo, 10);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 20);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 5);
	agregar_inicio(lista, nuevo);
	
	cout << "Lista: ";
	mostrar(lista);
	cout << "Cantidad de elementos: " << cantidad_elementos(lista) << endl;
	
	pnodo eliminado = eliminar_inicio(lista);
	if (eliminado != NULL) {
		cout << "Eliminado: " << eliminado->dato << endl;
		delete eliminado; 
	}
	
	cout << "Lista después de eliminar: ";
	mostrar(lista);
	cout << "Cantidad de elementos: " << cantidad_elementos(lista) << endl;
	
	return 0;
}
