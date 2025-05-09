#pragma once
#include "Paquete.h"
class PaqueteSMS :public Paquete
{
private:
	int sms;
public:
	PaqueteSMS(int sms);
	~PaqueteSMS();
	int getSMS();
	void setSMS(int sms);
	string toJson();
};

