#include <iostream>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <cstring>
//#include <>
#include "myutils.h"

using namespace std;

int main()
{
	char login[] = "../../login_data/login.ini";
	//char FRONT_ADDR[];
	//char login[] = "login.ini";
	map <string,string> data_map;

	read_login_data(login,data_map);
	//for_each(data_map.begin(),data_map.end(),print);
	cout<< data_map["BROKER_ID"]<<endl;
	//cout<< typeid(data_map["BROKER_ID"].c_str()).name()<<endl;
	cout<< data_map["BROKER_ID"].c_str()<<endl;
	//cout<< typeid(data_map["BROKER_ID"].c_str()).name()<<endl;
	const char *FRONT_ADDR=data_map["BROKER_ID"].c_str();
	//char FRONT_ADDR[20]={0};
	//strncpy(FRONT_ADDR,data_map["BROKER_ID"].c_str(),sizeof(FRONT_ADDR));
	cout << FRONT_ADDR<<endl;
	


}
