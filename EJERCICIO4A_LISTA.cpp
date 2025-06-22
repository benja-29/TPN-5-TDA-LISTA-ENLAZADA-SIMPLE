#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct {
	pnodo tope;
} tpila;

void iniciar_pila(tpila &pila) {
	pila.tope = NULL;
}

bool es_vacia(tpila pila) {
	return pila.tope == NULL;
}

void push(tpila &pila, int valor) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = pila.tope;
	pila.tope = nuevo;
}

int pop(tpila &pila) {
	if(es_vacia(pila)) {
		cout << "Pila vacía." << endl;
		return -1;
	} else {
		pnodo borrado = pila.tope;
		int valor = borrado->dato;
		pila.tope = borrado->siguiente;
		delete borrado;
		return valor;
	}
}

void mostrar(tpila pila) {
	pnodo i = pila.tope;
	while(i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}

int main() {
	tpila pila;
	iniciar_pila(pila);
	
	push(pila, 10);
	push(pila, 20);
	push(pila, 30);
	
	cout << "Contenido de la pila:" << endl;
	mostrar(pila);
	
	cout << "Desapilando: " << pop(pila) << endl;
	
	cout << "Contenido de la pila luego de desapilar:" << endl;
	mostrar(pila);
	
	return 0;
}
