#pragma once
#include <string>

using namespace std;

class Http
{
public:
	Http(string url);
	Http(string url, int port);
	string get_url();
	void set_url(string url);
	int get_port();
	void set_port(int port);
	string to_string();
	string get();
	string post();
private:
	int generate_random(int min, int max);
	string generate_random_letters();
	string url;
	int port;
};

