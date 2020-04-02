#pragma once
#include "Entity.h"
#include <vector>
using namespace std;
//Creates repository
template <class T>
class RepositoryFile
{
private:
	vector<T> elem;
	const char* fis;
public:
	//Repository constructor
	RepositoryFile();
	RepositoryFile(const char* fileName);
	//loads data from file
	void loadFromFile(const char* fileName);
	//adauga un obiect de tip Entity
	void addElem(T);
	//actualizeaza un obiect de tip Entity
	void updateElem(T, const char*, const char*, bool);
	//gaseste un obiect de tip Entity
	int findElem(T);
	//sterge un obiect de tip Entity 
	int delElem(T);
	//returneaza un element de tip Entity de la o anumita pozitie
	T elemAtPos(int);
	//returneaza un vector cu toate obiectele de tip Entity
	vector<T> getAll();
	//returneaza dimensiunea 
	int size();
	//saves data to file
	void saveToFile();
	//Repository deconstructor
	~RepositoryFile();
};