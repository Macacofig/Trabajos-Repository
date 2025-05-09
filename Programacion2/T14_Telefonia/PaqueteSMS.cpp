#include "PaqueteSMS.h"

PaqueteSMS::PaqueteSMS(int sms)
	:Paquete("sms")
{
	this->sms = sms;
}

PaqueteSMS::~PaqueteSMS()
{
}

int PaqueteSMS::getSMS()
{
	return sms;
}

void PaqueteSMS::setSMS(int sms)
{
	this->sms = sms;

}

string PaqueteSMS::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"sms\",\"saldo sms\":"<<sms<<"}";
	return ss.str();
}
