#pragma once
struct Tocka 
{
	int x;
	int y;
	Tocka(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
	double distance() 
	{
		return sqrt(pow(x,2) + pow(y, 2));
	}
};