#include <iostream>
using namespace std;

// clase nodo que representa un nodo de una lista enlazada simple
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

// la unción desconocido retorna la dirección del último nodo de la lista
// su proposito es obtener un puntero al nodo final de la lista (tail)
Nodo* desconocido(Nodo* nodo) {
	if (nodo == nullptr || nodo->getSiguiente() == nullptr)
		return nodo; // si es el último nodo o la lista está vacía, retorna el nodo actual
	else
		return desconocido(nodo->getSiguiente()); // sigue recorriendo hasta llegar al final
}

int main() {
	// clea la lista: 6 -> 4 -> 9 -> 5 -> 8 -> NULL
	Nodo* n1 = new Nodo(6);
	Nodo* n2 = new Nodo(4);
	Nodo* n3 = new Nodo(9);
	Nodo* n4 = new Nodo(5);
	Nodo* n5 = new Nodo(8);
	
	n1->setSiguiente(n2);
	n2->setSiguiente(n3);
	n3->setSiguiente(n4);
	n4->setSiguiente(n5);
	
	Nodo* ultimo = desconocido(n1); // llama a desconocido para obtener el último nodo
	cout << "Dato del último nodo: " << ultimo->getDato() << endl;
	
	return 0;
}
