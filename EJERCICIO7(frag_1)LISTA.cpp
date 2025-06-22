#include<bits/stdc++.h>
using namespace std;

// clase nodo que representa un nodo de una lista enlazada simple
class Nodo {
private:
	int dato;           // valor almacenado en el nodo
	Nodo* siguiente;    // puntero al siguiente nodo
public:
	Nodo(int valor) { dato = valor; siguiente = nullptr; }
	int getDato() { return dato; }
	Nodo* getSiguiente() { return siguiente; }
	void setSiguiente(Nodo* sig) { siguiente = sig; }
};

// función enigma la cual imprime los datos de la lista en orden inverso usando recursividad
// su propósito Mostrar los elementos desde el último hasta el primero
void enigma(Nodo* nodo) {
	if (nodo != nullptr) {
		if (nodo->getSiguiente() == nullptr)
			cout << nodo->getDato() << " "; // caso base el cual imprime el último nodo
		else {
			enigma(nodo->getSiguiente());   // llamada recursiva para avanzar al siguiente nodo
			cout << nodo->getDato() << " "; // imprime al retornar (orden inverso)
		}
	}
}

int main() {
	// crear la lista: 6 -> 4 -> 9 -> 5 -> 8 -> NULL
	Nodo* n1 = new Nodo(6);
	Nodo* n2 = new Nodo(4);
	Nodo* n3 = new Nodo(9);
	Nodo* n4 = new Nodo(5);
	Nodo* n5 = new Nodo(8);
	
	n1->setSiguiente(n2);
	n2->setSiguiente(n3);
	n3->setSiguiente(n4);
	n4->setSiguiente(n5);
	
	cout << "Salida de enigma (inverso): ";
	enigma(n1); // llama a la función enigma para imprimir la lista al revés
	cout << endl;
	
	return 0;
}
