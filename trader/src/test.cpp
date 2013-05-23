#include <iostream>
#include <map>
#include <algorithm>
//#include <>
#include "myutils.h"

using namespace std;

int main()
{
	char login[] = "../../login_data/login.ini";
	//char login[] = "login.ini";
	map <string,string> data_map;

	read_login_data(login,data_map);
	for_each(data_map.begin(),data_map.end(),print);
	//cout<< data_map["BROKER_ID"]<<endl;

}
