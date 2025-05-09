#pragma once

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Objeto
{
protected:
	int id;
	int x;
	int y;
	string tipo;
public:
	Objeto(int id, int x, int y, string tipo);
	Objeto(int id);
	~Objeto();


	int getId();
	int getX();
	int getY();
	string getTipo();

	void setX(int x);
	void setY(int y);

	virtual string toString();
	static string toStatic(Objeto* o);

	bool operator==(Objeto* o);
};

