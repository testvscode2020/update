#include "MojRed.h"

void MojRed::push(int val)
{
	if (vrh < sizeof(values) / sizeof(int)) 
	{
		values[vrh++] = val;
	}
}

bool MojRed::empty()
{
	return vrh == 0;
}

int MojRed::front()
{
	//tu paziti->nemamo sto vratiti ako smo prazni!
	return values[0];
}

void MojRed::pop()
{
	if (!empty()) 
	{
		for (unsigned i = 0; i < vrh - 1; i++)
		{
			values[i] = values[i + 1];
		}
		vrh--;
	}
}
