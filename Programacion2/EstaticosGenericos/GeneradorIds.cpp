#include "GeneradorIds.h"

GeneradorIds::GeneradorIds()
{
	id = 0;
}

GeneradorIds::~GeneradorIds()
{
}

int GeneradorIds::getNextId()
{
	id++;
	return id;
}

GeneradorIds& GeneradorIds::getInst()
{
	static GeneradorIds instancia;
	return instancia;
}
