#include <fstream>
#include <string>
#include <map>
#include "myutils.h"

using namespace std;

void read_login_data(char *login_data,map<string,string> &data_map)
{
	ifstream infile;
	string config_line;
	infile.open(login_data);
	if (!infile.is_open())
	{
		cout << "can not open login_data";
		return false;
	
	}
	stringstream sem;
	sem << infile.rdbuf();
	while(true)
	{
		sem >> config_line;
		while(config_line)
		{
			size_t pos = config_line.find('=');
			if(pos == npos) continue;
			string key = config_line.substr(0,pos);
			string value = config_line.substr(pos+1);
			data_map[key]=value;

		}
	}
	

}
