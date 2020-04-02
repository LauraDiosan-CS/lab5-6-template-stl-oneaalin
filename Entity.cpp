#include "Entity.h"
#include <string.h>
#include <sstream>
using namespace std;
Entity::Entity() {
	id = 0;
	numar = NULL;
	tip = NULL;
	eliberata = true;
}

Entity::Entity(int id, const char* numar, const char* tip,bool eliberata) {
	this->id = id;
	this->numar = new char[strlen(numar) + 1];
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->numar, strlen(numar) + 1, numar);
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->eliberata = eliberata;
}

Entity::Entity(const Entity& s) {
	this->id = s.id;
	this->numar = new char[strlen(s.numar) + 1];
	this->tip = new char[strlen(s.tip) + 1];
	strcpy_s(this->numar, strlen(s.numar) + 1, s.numar);
	strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);
	this->eliberata = s.eliberata;
}

Entity::Entity(string linie)
{
	istringstream iss(linie);
	string tok1, tok2, tok3,tok4;
	iss >> tok1 >> tok2 >> tok3 >> tok4;
	id = stoi(tok1);
	numar = new char[tok1.length() + 1];
	tip = new char[tok1.length() + 1];
	strcpy_s(numar, tok1.length() + 1, tok1.c_str());
	strcpy_s(tip, tok1.length() + 1, tok1.c_str());
	eliberata = stoi(tok2);
}

int Entity::getID() {
	return id;
}

void Entity::setID(int v) {
	id = v;
}

char* Entity::getNumar() {
	return numar;
}

void Entity::setNumar(const char* n) {
	if (numar) delete[]numar;
	numar = new char[strlen(n) + 1];
	strcpy_s(numar, strlen(n) + 1, n);
}

char* Entity::getTip() {
	return tip;
}

void Entity::setTip(const char* n) {
	if (tip) delete[]tip;
	tip = new char[strlen(n) + 1];
	strcpy_s(tip, strlen(n) + 1, n);
}

bool Entity::getEliberata() {
	return eliberata;
}

void Entity::setEliberata(bool v) {
	eliberata = v;
}

Entity::~Entity() {
	if (numar) delete[]numar;
	if (tip) delete[]tip;
	numar = NULL;
	tip = NULL;
	eliberata = true;
}

Entity& Entity::operator=(const Entity& s) {
	if (this == &s) return *this;
	if (numar) delete[] numar;
	if (tip) delete[] tip;
	numar = new char[strlen(s.numar) + 1];
	tip = new char[strlen(s.tip) + 1];
	strcpy_s(numar, strlen(s.numar) + 1, s.numar);
	strcpy_s(tip, strlen(s.tip) + 1, s.tip);
	id = s.id;
	eliberata = s.eliberata;
	return *this;
}

bool Entity::operator==(const Entity& s) {
	return (strcmp(numar, s.numar) == 0) and (strcmp(tip, s.tip) == 0) and (id == s.id) and (eliberata == s.eliberata);
}

ostream& operator<<(ostream& os, Entity s) {
	os << s.id << " " << s.numar << " " << s.tip << " " << s.eliberata << endl;
	return os;
}

istream& operator>>(istream& is, Entity& s)
{
	cout << "Dati rezervarea : ";
	int v1;
	cout << "Dati ID-ul : ";
	cin >> v1;
	char* numar = new char[10];
	cout << "Dati numarul : ";
	is >> numar;
	char* tip = new char[10];
	cout << "Dati tipul : ";
	is >> tip;
	cout << "Dati starea de eliberare[false,true] : ";
	bool v2;
	cin >> v2;
	s.setID(v1);
	s.setNumar(numar);
	s.setTip(tip);
	s.setEliberata(v2);
	delete[] numar;
	delete[] tip;
	return is;
}
