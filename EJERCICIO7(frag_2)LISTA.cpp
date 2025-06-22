#include <iostream>
using namespace std;

// la clase nodo que representa un nodo de una lista enlazada simple
class Nodo {
private:
	int dato;
	Nodo* siguiente;
public:
	Nodo(int valor) { dato = valor; siguiente = nullptr; }
	int getDato() { return dato; }
	Nodo* getSiguiente() { return siguiente; }
	void setSiguiente(Nodo* sig) { siguiente = sig; }
};

// la función misterio cuenta la cantidad de nodos de la lista enlazada
// su propósito es determinar la longitud (cantidad de nodos) de la lista
int misterio(Nodo* nodo) {
	if (nodo == nullptr)
		return 0; // si la lista terminó (NULL), retorna 0
	else
		return misterio(nodo->getSiguiente()) + 1; // cuenta el nodo actual + recursividad
}

int main() {
	// al crear la lista 6 -> 4 -> 9 -> 5 -> 8 -> NULL
	Nodo* n1 = new Nodo(6);
	Nodo* n2 = new Nodo(4);
	Nodo* n3 = new Nodo(9);
	Nodo* n4 = new Nodo(5);
	Nodo* n5 = new Nodo(8);
	
	n1->setSiguiente(n2);
	n2->setSiguiente(n3);
	n3->setSiguiente(n4);
	n4->setSiguiente(n5);
	
	int cantidad = misterio(n1); // llama a misterio para contar los nodos
	cout << "Cantidad de nodos: " << cantidad << endl;
	
	return 0;
}
