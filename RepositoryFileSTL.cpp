#include "RepositoryFileSTL.h"
#include <fstream>
#include <string>
using namespace std;

template <class T> 

RepositoryFile::RepositoryFile()
{

}

RepositoryFile::RepositoryFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* numar = new char[10];
	char* tip = new char[10];
	int id;
	bool eliberata;
	while (!f.eof()) {
		f >> id >> numar >> tip >> eliberata;
		if (numar != "" && tip != "") {
			Entity s(id, numar, tip, eliberata);
			elem.push_back(s);
		}
	}
	delete[] numar;
	delete[] tip;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* numar = new char[10];
	char* tip = new char[10];
	int id;
	bool eliberata;
	while (!f.eof()) {
		f >> id >> numar >> tip >> eliberata;
		if (strcmp(numar, "") != 0 && strcmp(tip, "") != 0) {
			Entity s(id, numar, tip, eliberata);
			elem.push_back(s);
		}
	}
	delete[] numar;
	delete[] tip;
	f.close();
}

void RepositoryFile::addElem(Entity s)
{
	elem.push_back(s);
}

void RepositoryFile::updateElem(Entity s,const char* newNumar, const char* newTip, bool newEliberata)
{
	vector<Entity>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		(*it).setNumar(newNumar);
		(*it).setTip(newTip);
		(*it).setEliberata(newEliberata);
	}

}

//returneaza pozitia la care se gaseste studentul s, sau -1, daca acesta nu apare
int RepositoryFile::findElem(Entity s)
{
	vector<Entity>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

//sterge elementul s din repository, returneaza 0 la succes, -1 altfel
int RepositoryFile::delElem(Entity s)
{
	vector<Entity>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}

Entity RepositoryFile::elemAtPos(int i)
{
	if (i < 0 or i >= elem.size()) return Entity(0,"", "", true);
	return elem[i];
}

vector<Entity> RepositoryFile::getAll()
{
	return elem;
}

int RepositoryFile::size()
{
	return elem.size();
}

void RepositoryFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}


RepositoryFile::~RepositoryFile()
{

}