#pragma once
#include <string>

using namespace std;

class Http
{
	public:
		Http(string url);
		Http(string url, int port);
		string post();
		string get();
		string get_config();

	private:
		string url;
		int port;

		int generate_random_number(int min, int max);
		string random_word();
};

