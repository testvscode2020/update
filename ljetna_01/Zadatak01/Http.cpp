#include "Http.h"
#include <sstream>
#include <ctime>

Http::Http(string url) : Http(url, port)
{
}

Http::Http(string url, int port) 
{
	srand(time(nullptr));
	set_port(port);
	set_url(url);
}

string Http::get_url()
{
	return url;
}

void Http::set_url(string url)
{
	this->url = url;
}

int Http::get_port()
{
	return port;
}

void Http::set_port(int port)
{
	this->port = port;
}

string Http::to_string()
{
	stringstream ss;
	ss << "http://" << url << ":" << port;
	return ss.str();
}

string Http::get()
{
	return generate_random_letters();
}

string Http::post()
{
	return generate_random_letters();
}

int Http::generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

string Http::generate_random_letters()
{
	stringstream ss;
	for (int i = 0; i < 10; i++)
	{
		ss << (char)generate_random(97, 122);
	}
	return ss.str();
}
