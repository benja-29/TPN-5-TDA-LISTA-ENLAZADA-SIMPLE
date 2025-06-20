#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

void iniciar_lista(pnodo &lista) {
	lista = NULL;
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

void agregar_inicio(pnodo &lista, pnodo nuevo) {
	nuevo->siguiente = lista;
	lista = nuevo;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
	pnodo i;
	if (lista == NULL) {
		lista = nuevo;
	} else {
		for (i = lista; i->siguiente != NULL; i = i->siguiente);
		i->siguiente = nuevo;
	}
}

void mostrar(pnodo lista) {
	pnodo i;
	if (lista != NULL) {
		for (i = lista; i != NULL; i = i->siguiente) {
			cout << i->dato << " -> ";
		}
		cout << "NULL" << endl;
	} else {
		cout << "Lista vacía" << endl;
	}
}

int minimo(pnodo lista) {
	if (lista == NULL) {
		cout << "Lista vacía." << endl;
		return -1; 
	}
	int minValor = lista->dato;
	pnodo i = lista->siguiente;
	while (i != NULL) {
		if (i->dato < minValor) {
			minValor = i->dato;
		}
		i = i->siguiente;
	}
	return minValor;
}

int main() {
	pnodo lista;
	iniciar_lista(lista);
	
	pnodo nuevo;
	
	crear_nodo(nuevo, 15);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 8);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 22);
	agregar_final(lista, nuevo);
	
	crear_nodo(nuevo, 5);
	agregar_final(lista, nuevo);
	
	cout << "Lista: ";
	mostrar(lista);
	
	cout << "El valor minimo es: " << minimo(lista) << endl;
	
	return 0;
}
