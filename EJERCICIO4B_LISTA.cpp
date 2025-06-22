#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct {
	pnodo frente;
	pnodo final;
	int contador;
} tcola;

void iniciar_cola(tcola &cola) {
	cola.frente = NULL;
	cola.final = NULL;
	cola.contador = 0;
}

bool es_vacia(tcola cola) {
	return cola.frente == NULL;
}

void encolar(tcola &cola, int valor) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
	
	if(es_vacia(cola)) {
		cola.frente = nuevo;
		cola.final = nuevo;
	} else {
		cola.final->siguiente = nuevo;
		cola.final = nuevo;
	}
	cola.contador++;
}

int desencolar(tcola &cola) {
	if(es_vacia(cola)) {
		cout << "Cola vacía." << endl;
		return -1;
	} else {
		pnodo borrado = cola.frente;
		int valor = borrado->dato;
		cola.frente = borrado->siguiente;
		if(cola.frente == NULL) { 
			cola.final = NULL;
		}
		delete borrado;
		cola.contador--;
		return valor;
	}
}

void mostrar(tcola cola) {
	pnodo i = cola.frente;
	while(i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}

int cantidad(tcola cola) {
	return cola.contador;
}

int main() {
	tcola cola;
	iniciar_cola(cola);
	
	encolar(cola, 5);
	encolar(cola, 15);
	encolar(cola, 25);
	
	cout << "Contenido de la cola:" << endl;
	mostrar(cola);
	
	cout << "Desencolando: " << desencolar(cola) << endl;
	
	cout << "Contenido de la cola luego de desencolar:" << endl;
	mostrar(cola);
	
	cout << "Cantidad de elementos en cola: " << cantidad(cola) << endl;
	
	return 0;
}
