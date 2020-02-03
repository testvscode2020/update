#include "Http.h"
#include <sstream>
#include <ctime>

Http::Http(string url)
{
	srand(time(nullptr));
	
	this->url = url;
	this->port = 80;
}

Http::Http(string url, int port)
{
	srand(time(nullptr));

	this->url = url;
	this->port = port;
}

string Http::post()
{
	return this->random_word();
}

string Http::get()
{
	return this->random_word();
}

string Http::get_config()
{
	stringstream ss;

	ss << "Port: " << this->port << endl;
	ss << "Url: " << this->url << endl;

	return ss.str();
}

int Http::generate_random_number(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

string Http::random_word()
{
	stringstream ss;

	for (int i = 0; i < 10; i++)
	{
		ss << (char)generate_random_number(97, 122);
	}
	
	return ss.str();
}
