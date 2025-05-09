#include "SMS.h"

SMS::SMS(int id, long fecha)
	:Accion("sms", id, fecha)
{
}

SMS::~SMS()
{
}

string SMS::toJson()
{
	stringstream ss;
	ss << "{\"id\":" << id << ",\"fecha\":" << fecha << ",\"tipo\":\"sms\"}";
	return ss.str();
}
