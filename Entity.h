#pragma once
#include <iostream>
#include <string>
using namespace std;
//creates Entity business object
class Entity {
private:
	int id;
	char* numar;
	char* tip;
	bool eliberata;
public:
	/*Entity object constructor
	  Input:-
	  Preconditii:-
	  Output:-
	  Postconditii:-
	*/
	Entity();
	/*
		Input: un pointer constant de tip char si doua de tip intreg
		Preconditii: valorile sa respecte tipul de date
		Output:un obiect de tip Entity
		Postconditii:-
	*/
	Entity(int, const char*, const char*,bool);
	/*
		Input: un obiect de tip Entity
		Preconditii: obiectul trebuie sa fie de tip Entity
		Output:un obiect de tip Entity
		Postconditii: obiectul o sa fie de tip Entity
	*/
	Entity(const Entity&);
	/* Constructor de conversie
	   Input: un string de caractere
	   Preconditii : string-ul sa fie de caractere
	   Output : token-uri ale clasei Entity
	   Postconditii:-
	*/
	Entity(string);
	/* Operatorul de atribuire supraincarcat
	   Input: un obiect constant de tip Entity
	   Preconditii: obiectul sa fie de tip Entity
	   Output : un obiect de tip Entity
	   Postconditii: -
	*/
	Entity& operator=(const Entity&);
	/*	Getter pentru ID
		Input:-
		Preconditii:-
		Ouput : un string de tip char
		Postcodnti : string-ul va fi sir de caractere
	*/
	int getID();
	/*	Getter pentru numar
		Input: -
		Preconditii:-
		Ouput : o variabila de tip int
		Postconditii: valaorea va fi intreaga
	*/
	char* getNumar();
	/*	Getter pentru tip
		Input: -
		Preconditii:-
		Ouput : o variabila de tip int
		Postconditii: valaorea va fi intreaga
	*/
	char* getTip();
	/*	Getter pentru eliberata
		Input: -
		Preconditii:-
		Ouput : o variabila de tip int
		Postconditii: valaorea va fi intreaga
	*/
	bool getEliberata();
	/*	Setter pentru ID
		Input: o variabila de tip int
		Preconditii: valoarea va fi intreaga
		Output: obiectul de tip Entity modificat
		Postconditii: obiectul o sa fie de tip Entity
	*/
	void setID(int);
	/*	Setter pentru numar
		Input: un pointer de tip char
		Preconditii: un string de caractere
		Output: obiectul de tip Entity modificat
		Postconditii: obiectul o sa fie de tip Entity
	*/
	void setNumar(const char*);
	/*	Setter pentru tip
		Input: un pointer de tip char
		Preconditii: un string de caractere
		Output: obiectul de tip Entity modificat
		Postconditii: obiectul o sa fie de tip Entity
	*/
	void setTip(const char*);
	/*	Setter pentru tip
		Input: o variabila de tip boolean
		Preconditii: valoarea va fi de tip boolean
		Output: obiectul de tip Entity modificat
		Postconditii: obiectul o sa fie de tip Entity
	*/
	void setEliberata(bool);
	/*	Operatul == supraincarcat
		Input: un obiect constant de tip Entity
		Preconditii: obiectul o sa fie de tip Entity
		Output: valorile true sau false

	*/
	bool operator==(const Entity&);
	/*	Deconstructor
		Input:-
		Output:-
	*/
	~Entity();
	//operatorul supraincarcat de afisare al unei cheltuieli
	friend ostream& operator<<(ostream& os, Entity s);
	//operatorul supraincarcat de citire al unei cheltuieli
	friend istream& operator>>(istream&, Entity&);
};
