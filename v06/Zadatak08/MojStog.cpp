#include "MojStog.h"

void MojStog::push(int val)
{
	if (vrh < sizeof(values) / sizeof(int)) 
	{
		values[vrh++] = val;
	}
}

bool MojStog::empty()
{
	return vrh == 0;
}

int MojStog::top()
{
	//tu paziti -> nemamo sto vratiti ako smo prazni!
	return values[vrh - 1];
}

void MojStog::pop()
{	
	if (!empty()) 
	{
		vrh--;
	}
}
