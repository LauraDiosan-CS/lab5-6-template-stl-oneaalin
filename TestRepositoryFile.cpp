#include "TestRepositoryFile.h"
#include <assert.h> 



TestRepositoryFile::TestRepositoryFile()
{

	assert(repo.size() == 0);
}

void TestRepositoryFile::testLoadFromFile()
{
	repo.loadFromFile("TestRezervari.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testAddElem()
{
	repo.loadFromFile("TestRezervari.txt");
	repo.addElem(Entity(5,"404", "C" , false));
	assert(repo.size() == 5);
	repo.saveToFile();
}

void TestRepositoryFile::testFindElem()
{
	repo.loadFromFile("TestRezervari.txt");
	assert(repo.findElem(Entity(2 ,"201", "A" , true)) == 1);
	assert(repo.findElem(Entity(10, "100", "B" , false)) == -1);
	repo.saveToFile();
}

void TestRepositoryFile::testDelElem()
{
	repo.loadFromFile("TestRezervari.txt");
	repo.delElem(Entity(5, "404", "C", false));
	assert(repo.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testGetAll()
{
	repo.loadFromFile("TestRezervari.txt");
	vector<Entity> rez = repo.getAll();
	assert(rez.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testUpdateElem()
{
	repo.loadFromFile("TestRezervari.txt");
	repo.updateElem(Entity(2, "201", "A", true), "204", "A", true);
	assert(repo.findElem(Entity(2 ,"204", "A", true)) == 1);
	repo.saveToFile();
}

void TestRepositoryFile::testElemAtPos()
{
	repo.loadFromFile("TestRezervari.txt");
	assert(repo.elemAtPos(2) == Entity(3, "304", "B" ,true));
	repo.saveToFile();
}

void TestRepositoryFile::testSize()
{
	repo.loadFromFile("TestRezervari.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testSaveToFile()
{
	repo.loadFromFile("TestRezervari.txt");
	int n = repo.size();
	repo.addElem(Entity(5, "404", "C", false));
	repo.saveToFile();
	repo.loadFromFile("TestStud.txt");
	assert(repo.getAll().size() == (n + 1));

}


TestRepositoryFile::~TestRepositoryFile()
{
}
