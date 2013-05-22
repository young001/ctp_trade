#include <iostream>
#include <map>
#include "myutils.h"

using namespace std;

int main()
{
	char login[] = "../../login_data/login.ini";
	map <string,string> data_map;

	read_login_data(login,data_map);
	cout<< data_map["BROKER_ID"]<<endl;

}
