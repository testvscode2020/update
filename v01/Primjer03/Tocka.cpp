#include <sstream>
#include "Tocka.h"

Tocka::Tocka(int x, int y) 
{
	set_x(x);
	set_y(y);
}
int Tocka::get_x() {
	return x;
}
void Tocka::set_x(int x) 
{
	this->x = x;
}
int Tocka::get_y() {
	return y;
}
void Tocka::set_y(int y)
{
	this->y = y;
}
Tocka::Tocka() {
	set_x(0);
	set_y(0);
}
string Tocka::to_string() {
	stringstream ss;
	ss << "t(" << x << ", " << y << ")";
	return ss.str();
}
double Tocka::distance() {
	return sqrt(pow(x, 2) + pow(y, 2));
}