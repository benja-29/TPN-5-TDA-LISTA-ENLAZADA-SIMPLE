#include<bits/stdc++.h>
using namespace std;

typedef struct nodo *pnodo;
typedef struct nodo {
	int dato;
	pnodo siguiente;
};

void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

void crear_nodo(pnodo &nuevo, int valor) {
	nuevo = new nodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pnodo i = lista;
		while (i->siguiente != NULL) {
			i = i->siguiente;
		}
		i->siguiente = nuevo;
	}
}

void mostrar(pnodo lista) {
	pnodo i = lista;
	while (i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}

//ordenacion por seleccion
void orden_seleccion(pnodo lista) {
	pnodo i, j, min;
	int aux;
	for (i = lista; i != NULL && i->siguiente != NULL; i = i->siguiente) {
		min = i;
		for (j = i->siguiente; j != NULL; j = j->siguiente) {
			if (j->dato < min->dato) {
				min = j;
			}
		}
		aux = i->dato;
		i->dato = min->dato;
		min->dato = aux;
	}
}

//combinacion de dos pilas

pnodo combinar_sin_orden(pnodo lista1, pnodo lista2) {
	pnodo nuevaLista = NULL, nuevo;
	
	pnodo i = lista1;
	while (i != NULL) {
		crear_nodo(nuevo, i->dato);
		agregar_final(nuevaLista, nuevo);
		i = i->siguiente;
	}
	
	i = lista2;
	while (i != NULL) {
		crear_nodo(nuevo, i->dato);
		agregar_final(nuevaLista, nuevo);
		i = i->siguiente;
	}
	
	return nuevaLista;
}

pnodo combinar_con_orden(pnodo lista1, pnodo lista2) {
	pnodo nuevaLista = combinar_sin_orden(lista1, lista2);
	orden_seleccion(nuevaLista);
	return nuevaLista;
}

int main() {
	pnodo lista1, lista2, listaCombinada;
	iniciar_lista(lista1);
	iniciar_lista(lista2);
	
	pnodo nuevo;
	
	crear_nodo(nuevo, 5);
	agregar_final(lista1, nuevo);
	crear_nodo(nuevo, 2);
	agregar_final(lista1, nuevo);
	crear_nodo(nuevo, 8);
	agregar_final(lista1, nuevo);
	
	crear_nodo(nuevo, 3);
	agregar_final(lista2, nuevo);
	crear_nodo(nuevo, 7);
	agregar_final(lista2, nuevo);
	
	cout << "Lista 1: ";
	mostrar(lista1);
	cout << "Lista 2: ";
	mostrar(lista2);
	
	orden_seleccion(lista1);
	cout << "Lista 1 ordenada: ";
	mostrar(lista1);
	
	listaCombinada = combinar_sin_orden(lista1, lista2);
	cout << "Listas combinadas sin orden: ";
	mostrar(listaCombinada);
	
	listaCombinada = combinar_con_orden(lista1, lista2);
	cout << "Listas combinadas con orden: ";
	mostrar(listaCombinada);
	
	return 0;
}
