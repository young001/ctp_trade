#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <typeinfo>
#include <algorithm>
#include "myutils.h"

using namespace std;

void print(pair<const string,string> &p)
{
	cout<<p.second<<endl;
}

void read_login_data(char *login_data,map<string,string> &data_map)
{
	ifstream infile;
	string config_line;
	infile.open(login_data);
	if (!infile.is_open())
	{
		cout << "can not open login_data";
		return ;
	
	}
	stringstream sem;
	sem << infile.rdbuf();
	while(true)
	{
		if(sem.eof()) break;
		while(sem >> config_line)
		{
			size_t pos = config_line.find('=');
			if(pos != string::npos)
			{
				string key = config_line.substr(0,pos);
				//cout <<typeid(key).name()<<endl;
				string value = config_line.substr(pos+1);
				//cout <<typeid(value).name()<<endl;
				data_map[key]=value;

			}
			else
			{
				cout <<"bad input pair"<<endl;
			}
			}
	}
	//std::for_each(data_map.begin(),data_map.end(),print);
	

}
