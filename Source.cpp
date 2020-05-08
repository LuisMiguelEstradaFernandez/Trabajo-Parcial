//			|-INTEGRANTES-|
//	
//  Luis Miguel Estrada Fernández	U2018D335   2°
//	Antonio Ferrandiz Bendezu		U201918042	1°
//	Julio Gomez Merino				U201721569  3°
// ©2020|Todos los derechos reservados


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <functional>
#include <fstream>

using namespace std;

struct nodo
{
	string dato; int dato1; string dato2; string dato3; string dato4;
	struct nodo* next;
}*last;

template <typename T>
class Paciente {
	T nombre; T edad; T sintomas; T infectado; T esubayecente;
public:
	T getNombre() { return this->nombre; }
	T getEdad() { return this->edad; }
	T getSintomas() { return this->sintomas; }
	T getInfectado() { return this->infectado; }
	T getEsubayecente() { return this->esubayecente; }
};

template <typename T>
class Hospital
{
	vector<Paciente<int>*>* ptrPacientes;
	int cant = 0;
public:
	void agregar_lista(string nombre, int edad, string sintomas, string infectado, string esubayecente);
	void insertar_al_princio(string nombre, int edad, string sintomas, string infectado, string esubayecente);
	void buscar(string nombre);
	void mostrar();
	void modificar();
	void eliminar(string nombre);
	void pacientes_infectados(string infectado);
	void pacientes_sintomas(string sintomas);
	void pacientes_criticos(int edad, string esubayecente);
	Hospital() { last = NULL; }

};

#ifndef __PILA_H__
#define __PILA_H__

class Pila {

	struct Node
	{
		string nombre;
		Node* next;
		Node(string nombre, Node* next = nullptr) : nombre(nombre), next(next) {}
	};

	Node* ptrTop;
	int length;

public:

	Pila() : ptrTop(nullptr), length(0) {}
	~Pila() {

		while (ptrTop != nullptr) {
			auto aux = ptrTop;
			ptrTop = aux->next;
			delete aux;
		}

	}

	void mostrarPila() {

		ofstream nomPacientesDDA;
		nomPacientesDDA.open("Pacientes_dados_de_alta.txt", ios::out);
		if (nomPacientesDDA.is_open()) {
			auto aux = ptrTop;

			if (aux == nullptr)
			{
				cout << "Ningun paciente fue dado de alta" << endl;
				nomPacientesDDA << "Ningun paciente fue dado de alta" << endl;
				return;
			}

			cout << "Pila con pacientes dados de alta" << endl;
			nomPacientesDDA << "Pila con pacientes dados de alta" << endl;

			while (aux != nullptr)
			{
				cout << aux->nombre << endl;
				nomPacientesDDA << aux->nombre << endl;
				aux = aux->next;
			}

			cout << endl;

			nomPacientesDDA.close();
		}

	}

	void agregarPila(string nombre) {

		ptrTop = new Node(nombre, ptrTop);
		++length;
	}


};


#endif // !__PILA_H__




int main()
{

	int opcion = 20, posicion;
	string nombre, sintomas, infectado, esubayecente; int edad;
	Hospital<int> lista;
	Paciente<int>* ptrPacientes = new Paciente<int>;
	Pila* pilaPacientes = new Pila();

	//Nota: No tengo la menor idea porque funcion con <int> pero funciona 

	while (opcion != 0)
	{
		system("cls");
		cout << endl << "HOSPITAL AYED" << endl;
		cout << "________________________" << endl;
		cout << "1) Agregar paciente" << endl;
		cout << "2) Insertar paciente al frente de la lista" << endl;
		cout << "3) Buscar paciente" << endl;
		cout << "4) Mostrar pacientes" << endl;
		cout << "5) Modificar datos" << endl;
		cout << "6) Pacientes dados de alta" << endl;
		cout << "7) Mostrar todos los pacientes infectados" << endl;
		cout << "8) Mostrar todos los pacientes con sintomas" << endl;
		cout << "9) Mostrar todos los pacientes en riesgo" << endl;
		cout << "0) Cerrar lista" << endl;
		cout << endl << "Selecciona una opcion: "; cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 0:
			break;
		case 1:
			cout << "Ingrese nombre del paciente: "; cin.ignore(); getline(cin, nombre); cout << endl;
			cout << "Ingrese edad del paciente: "; cin >> edad; cout << endl;
			cout << "Ingrese si el paciente el presenta sintomas(S/N): "; cin >> sintomas; cout << endl;
			cout << "Ingrese si el paciente esta infectado(S/N): "; cin >> infectado; cout << endl;
			cout << "Ingrese si el paciente posee alguna enfermedad subayecente(S/N): "; cin >> esubayecente; cout << endl;
			lista.agregar_lista(nombre, edad, sintomas, infectado, esubayecente);
			cout << endl;
			_getch();
			break;
		case 2:
			cout << "Ingrese nombre del paciente: "; cin.ignore(); getline(cin, nombre); cout << endl;
			cout << "Ingrese edad del paciente: "; cin >> edad; cout << endl;
			cout << "Ingrese si el paciente el presenta sintomas(S/N): "; cin >> sintomas; cout << endl;
			cout << "Ingrese si el paciente esta infectado(S/N): "; cin >> infectado; cout << endl;
			cout << "Ingrese si el paciente posee alguna enfermedad subayecente(S/N): "; cin >> esubayecente; cout << endl;
			lista.agregar_lista(nombre, edad, sintomas, infectado, esubayecente);
			cout << endl;
			_getch();
			break;
		case 3:
			if (last == NULL) { cout << "La lista de pacientes esta vacia" << endl; break; }
			cout << "Ingrese el paciente que se va a buscar: "; cin.ignore(); getline(cin, nombre);
			lista.buscar(nombre);
			cout << endl;
			_getch();
			break;
		case 4:

			lista.mostrar();

			_getch();
			break;
		case 5:
			lista.modificar();
			_getch();
			break;
		case 6:
			cout << "Ingrese el paciente que ha sido dado de alta: "; cin.ignore();  getline(cin, nombre);
			pilaPacientes->agregarPila(nombre);
			lista.eliminar(nombre);
			_getch();
			break;
		case 7:
			cout << "Lista de pacientes infectados:  " << endl;
			cout << "****************************************************************" << endl;
			cout << "Nombres            " << "\t" << "Edad   " << "\t" << "Presenta sintomas" << "\t" << "Esta infecttado" << "\t" << "Presenta alguna enfermedad subyacente" << endl;
			lista.pacientes_infectados("S");
			_getch();
			break;
		case 8:
			cout << "Lista de Pacientes con sintomas: " << endl;
			cout << "************************************************************************" << endl;
			cout << "Nombres            " << "\t" << "Edad   " << "\t" << "Presenta sintomas" << "\t" << "Esta infecttado" << "\t" << "Presenta alguna enfermedad subyacente" << endl;
			lista.pacientes_sintomas("S");
			_getch();
			break;
		case 9:

			cout << "Lista de Pacientes criticos: " << endl;
			cout << "************************************************************************" << endl;
			cout << "Nombres            " << "\t" << "Edad   " << "\t" << "Presenta sintomas" << "\t" << "Esta infecttado" << "\t" << "Presenta alguna enfermedad subyacente" << endl;
			lista.pacientes_criticos(65, "S");
			_getch();
		default:
			cout << "La opcion seleccionada no existe " << endl;
		}
	}

	pilaPacientes->mostrarPila();

	system("pause>>null");
	return 0;
}

//FUNCION PARA AGREGAR MAS PACIENTES A LA LISTA

template <typename T>
void Hospital<T>::agregar_lista(string nombre, int edad, string sintomas, string infectado, string esubayecente)
{
	cant++;
	struct nodo* aux;
	aux = new(struct nodo);


	//Lamda para comparar si la edad es positiva. Es decir, si la edad existe
	auto lamda_edad = [&]() {

		if (edad >= 0 && edad <= 110)
			return true;
		else
			return false;
	};

	aux->dato = nombre;


	if (lamda_edad())
		aux->dato1 = edad;
	else {
		cout << "Edad no valida, cerrando programa" << endl;
		exit(0);
	}




	aux->dato1 = edad;
	aux->dato2 = sintomas;
	aux->dato3 = infectado;
	aux->dato4 = esubayecente;
	if (last == NULL) {
		last = aux;
		aux->next = last;
	}
	else
	{
		aux->next = last->next;
		last->next = aux;
		last = aux;

	}
}

//FUNCION PARA AGREGAR PACIENTES AL PRINCIPIO DE LA LISTA

template <typename T>
void Hospital<T>::insertar_al_princio(string nombre, int edad, string sintomas, string infectado, string esubayecente)
{
	if (last == NULL)
	{
		cout << "Debes crear la lista para poder insertar un paciente." << endl;
		return;
	}
	cant++;
	struct nodo* aux;
	aux = new(struct nodo);
	aux->dato = nombre;
	aux->dato1 = edad;
	aux->dato2 = sintomas;
	aux->dato3 = infectado;
	aux->dato4 = esubayecente;
	aux->next = last->next;
	last->next = aux;
}

//FUNCION PARA BUSCAR UN PACIENTE POR SU NOMBRE EN LA LISTA

template <typename T>
void Hospital<T>::buscar(string nombre)
{
	struct nodo* s;
	int c = 0;
	int iguales = 0;
	s = last->next;
	if (last == NULL)
	{
		cout << "La lista de pacientes esta vacia" << endl;
		return;
	}
	while (c != cant)
	{
		c++;
		if (s->dato == nombre)
		{
			cout << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
			iguales++;
		}
		else {
			cout << "El paciente " << nombre << "no se encuentra en la lista " << endl;
		}
		s = s->next;
	}


}

//FUNCION PARA MOSTRAR TODOS LOS PACIENTES DE LA LISTA Y A LA VEZ CREAR LA VARIABLE DEL ARCHIVO PARA ALMACENARLOS

template <typename T>
void Hospital<T>::mostrar()
{
	ofstream nomPacientes;
	nomPacientes.open("Pacientes.txt", ios::out);
	if (nomPacientes.is_open()) {
		struct nodo* s;
		if (last == NULL)
		{
			cout << "No se ha creado la lista o esta vacia" << endl;
			return;
		}
		s = last->next;

		cout << "Lista: " << endl;
		cout << "****************************************************************" << endl;
		cout << "Nombres            " << "\t\t" << "Edad   " << "\t" << "Presenta sintomas" << "\t" << "Esta infecttado" << "\t\t" << "Presenta alguna enfermedad subyacente" << endl;
		nomPacientes << "Lista: " << endl;
		nomPacientes << "***************************************************************************************" << endl;
		nomPacientes << "Nombres            " << "\t\t" << "Edad   " << "\t" << "Presenta sintomas" << "\t" << "Esta infecttado" << "\t\t" << "Presenta alguna enfermedad subyacente" << endl;
		while (s != last)
		{
			cout << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
			nomPacientes << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
			s = s->next;
		}
		nomPacientes << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
		cout << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
		nomPacientes.close();
	}
}

//FUNCION PARA MODIFICAR LOS DATOS DEL PACIENTE

template <typename T>
void Hospital<T>::modificar()
{
	int numero, pos, i;
	string Nnombre; string Nsintomas; string Ninfectado; string Nsubayecente;  int Nedad;
	string nombre; char respuesta;
	if (last == NULL)
	{
		cout << "No se puede sustituir porque la lista no se ha creado o esta vacia" << endl;
		return;
	}
	cout << "Ingresa la posicion del paciente xd: ";
	cin >> pos;
	cout << "Ingresa el nuevo nombre: "; cin.ignore(); getline(cin, Nnombre); cout << endl;
	cout << "Ingresa la nueva edad: "; cin >> Nedad; cout << endl;
	cout << "Ingresa si el paciente posee sintomas: "; cin >> Nsintomas; cout << endl;
	cout << "Ingresa si el pacienta esta infectado(S/N): "; cin >> Ninfectado; cout << endl;
	cout << "Ingresa si el paciente posee una enfermedad subayecente(S/N): "; cin >> Nsubayecente; cout << endl;
	//	else if (respuesta == 'N') { cout << "Desea modificar la edad? (S/N) "; cin >> respuesta; }

	struct nodo* s;
	s = last->next;
	for (i = 0; i < pos - 1; i++)
	{
		if (s == last)
		{
			cout << "Hay menos de " << pos << " pacientes.";
			cout << endl;
			return;
		}
		s = s->next;
	}
	s->dato = Nnombre;
	s->dato1 = Nedad;
	s->dato2 = Nsintomas;
	s->dato3 = Ninfectado;
	s->dato4 = Nsubayecente;
	cout << "Datos de paciente actualizados" << endl;
}


//FUNCION PARA "ELIMINAR PACIENTES DE LA LISTA"  (PARA DARLOS DE ALTA)

template <typename T>
void Hospital<T>::eliminar(string nombre)
{
	struct nodo* aux, *s;
	s = last->next;
	//Si la lista solo tiene un numero//
	if (last->next == last && last->dato == nombre)
	{
		aux = last;
		last = NULL;
		free(aux);
		return;
	}
	if (s->dato == nombre)  /*Elimina el primer elemento*/
	{
		aux = s;
		last->next = s->next;
		free(aux);
		return;
	}
	while (s->next != last)
	{
		if (s->next->dato == nombre)
		{
			aux = s->next;
			s->next = aux->next;
			free(aux);
			cout << "El paciente " << nombre;
			cout << " fue dado de alta" << endl;
			return;
		}
		s = s->next;
	}
	if (s->next->dato == nombre)
	{
		aux = s->next;
		s->next = last->next;
		free(aux);
		last = s;
		return;
	}
	cout << "El paciente " << nombre << " no fue encontrada en la lista" << endl;
}

//MOSTRAR PACIENTES INFECTADOS

template <typename T>
void Hospital<T>::pacientes_infectados(string infectados)
{
	struct nodo* s;
	int c = 0;
	int iguales = 0;
	s = last->next;
	if (last == NULL)
	{
		cout << "La lista de pacientes esta vacia" << endl;
		return;
	}
	while (c != cant)
	{
		c++;
		if (s->dato3 == infectados) // ESTE IF ES LO QUE HACE PARA MOSTRAR LOS PACIENTES QUE CUMPLEN CIERTA CONDICION 
		{
			cout << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
			iguales++;
		}
		s = s->next;
	}
	if (iguales == 0) { cout << "No hay pacientes infectados" << endl; }

}

//MOSTRAR PACIENTES CON SINTOMAS

template <typename T>
void Hospital<T>::pacientes_sintomas(string sintomas)
{
	struct nodo* s;
	int c = 0;
	int iguales = 0;
	s = last->next;
	if (last == NULL)
	{
		cout << "La lista de pacientes esta vacia" << endl;
		return;
	}
	while (c != cant)
	{
		c++;
		if (s->dato2 == sintomas)
		{
			cout << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
			iguales++;
		}
		
		s = s->next;
	}
	if (iguales == 0) { cout << "No hay pacientes que presenten sintomas" << endl; }
}

//MOSTRAR PACIENTES EN ESTADO CRITICO EDAD >= 65 && POSEEN UNA ENFERMEDAD SUBAYECENTE

template <typename T>
void Hospital<T>::pacientes_criticos(int edad, string esubayecente)
{
	struct nodo* s;
	int c = 0;
	int iguales = 0;
	s = last->next;
	if (last == NULL)
	{
		cout << "La lista de pacientes esta vacia" << endl;
		return;
	}
	while (c != cant)
	{
		c++;
		if (s->dato1 >= edad && s->dato4 == esubayecente)
		{
			cout << s->dato << "\t\t" << s->dato1 << "\t\t" << s->dato2 << "\t\t\t" << s->dato3 << "\t\t\t\t" << s->dato4 << endl;
			iguales++;
		}
		s = s->next;
	}
	if (iguales == 0) { cout << "No hay pacientes en estado critico" << endl; }
	
}
