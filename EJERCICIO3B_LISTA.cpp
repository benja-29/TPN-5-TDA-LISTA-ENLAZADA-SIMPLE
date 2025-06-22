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

pnodo buscar_por_indice(tlista lista, int indice) {
	if (indice < 0 || indice >= lista.contador) {
		return NULL; 
	}
	pnodo i = lista.inicio;
	int actual = 0;
	while (i != NULL && actual < indice) {
		i = i->siguiente;
		actual++;
	}
	return i; 
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
	
	int indice_buscar = 1;
	pnodo encontrado = buscar_por_indice(lista, indice_buscar);
	if(encontrado != NULL)
		cout << "Elemento en la posición " << indice_buscar << ": " << encontrado->dato << endl;
	else
		cout << "No existe elemento en esa posición." << endl;
	
	return 0;
}
