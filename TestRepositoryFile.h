#pragma once
#include "RepositoryFileSTL.h"
//creates Tests for RepositoryFile
class TestRepositoryFile
{
private:
	RepositoryFile repo;
public:
	//Tests constructor
	TestRepositoryFile();
	//tests loadFromFile function
	void testLoadFromFile();
	//tests addEelem function
	void testAddElem();
	//tests findElem function
	void testFindElem();
	//tests delElem function
	void testDelElem();
	//tests getAll
	void testGetAll();
	//tests getAll function
	void testUpdateElem();
	//tests updateElem
	void testElemAtPos();
	//tests elemAtPos function
	void testSize();
	//test savetToFile function
	void testSaveToFile();
	//tests deconstructor
	~TestRepositoryFile();
};

