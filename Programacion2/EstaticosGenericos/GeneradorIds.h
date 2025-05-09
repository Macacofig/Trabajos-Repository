#pragma once
#include "iostream"
#include "string"
#include "sstream"
using namespace std;
class GeneradorIds
{
private:
	int id;
public:
	~GeneradorIds();
	int getNextId();
	static GeneradorIds& getInst();
private:
	GeneradorIds();
};

