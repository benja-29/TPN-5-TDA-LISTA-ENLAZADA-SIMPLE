#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Nodo {
	T dato;
	Nodo<T>* siguiente;
};

template <typename T>
class Lista {
private:
	Nodo<T>* cabeza;
	
public:
	Lista() {
		cabeza = nullptr;
	}
	
	void agregar(T valor) {
		Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->siguiente = nullptr;
		
		if (cabeza == nullptr) {
			cabeza = nuevo;
		} else {
			Nodo<T>* actual = cabeza;
			while (actual->siguiente != nullptr) {
				actual = actual->siguiente;
			}
			actual->siguiente = nuevo;
		}
	}
	
	void mostrar() const {
		Nodo<T>* actual = cabeza;
		while (actual != nullptr) {
			cout << actual->dato << " -> ";
			actual = actual->siguiente;
		}
		cout << "NULL" << endl;
	}
	
	Nodo<T>* getCabeza() const {
		return cabeza;
	}
};

bool esPrimo(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int contarPrimos(Lista<int>& lista) {
	int contador = 0;
	Nodo<int>* actual = lista.getCabeza();
	while (actual != nullptr) {
		if (esPrimo(actual->dato)) {
			contador++;
		}
		actual = actual->siguiente;
	}
	return contador;
}

void contarMayusMinus(Lista<char>& lista, int& mayus, int& minus) {
	mayus = 0;
	minus = 0;
	Nodo<char>* actual = lista.getCabeza();
	while (actual != nullptr) {
		if (isupper(actual->dato)) {
			mayus++;
		} else if (islower(actual->dato)) {
			minus++;
		}
		actual = actual->siguiente;
	}
}

int main() {
	
	Lista<int> listaEnteros;
	listaEnteros.agregar(2);
	listaEnteros.agregar(4);
	listaEnteros.agregar(7);
	listaEnteros.agregar(9);
	listaEnteros.agregar(11);
	
	cout << "Lista de enteros: ";
	listaEnteros.mostrar();
	
	int cantidadPrimos = contarPrimos(listaEnteros);
	cout << "Cantidad de números primos en la lista: " << cantidadPrimos << endl;
	
	Lista<char> listaCaracteres;
	listaCaracteres.agregar('A');
	listaCaracteres.agregar('b');
	listaCaracteres.agregar('C');
	listaCaracteres.agregar('d');
	listaCaracteres.agregar('e');
	
	cout << "\nLista de caracteres: ";
	listaCaracteres.mostrar();
	
	int mayus = 0, minus = 0;
	contarMayusMinus(listaCaracteres, mayus, minus);
	cout << "Mayúsculas: " << mayus << endl;
	cout << "Minúsculas: " << minus << endl;
	
	return 0;
}
