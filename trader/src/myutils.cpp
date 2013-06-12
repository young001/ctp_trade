#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <typeinfo>
#include <algorithm>
#include <typeinfo>
#include <boost/algorithm/string.hpp>
#include "myutils.h"

using namespace std;
using namespace boost::algorithm;

void print(pair<const string,string> &p)
{
	cout<<p.second<<endl;
	cout<<typeid(p.second).name()<<endl;
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
				trim_right(value);
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

//输出map的值
void print_map_string(map<string,string> &data_map){
	map<string,string>::const_iterator map_it = data_map.begin();
	while (map_it != data_map.end()){
		cout << map_it->first << " is " << map_it->second << endl;
		++map_it;

	}
}


//删除一个字符串首部和尾部的空格，删除中间多余的空格，输入"  i love  ",输出"i love"
void remove_space(char* str)
{
    bool no_space_flag = false; //定义是不是空格,利用这个，当碰到空格时,置为false跳过多余的空格,起始置为false是跳过开头的空格.
    int new_str_end = 0; //记录新的字符串长度
 
    for (int i = 0; str[i]; ++i)
    {
        //如果遍历得到的此字符不是空格，则将标志符置为true；在进行else if语句时便可加入一空格；加入空格后标志符为false；这样就达到了缩进空格的目的；
        if (str[i] != ' ')
        {
            str[new_str_end++] = str[i];
            no_space_flag = true;
        }
        //如果遍历得到的此字符是空格，则将标志符置为false；
        else if (no_space_flag)
        {
            str[new_str_end++] = str[i];
            no_space_flag = false;
        }
    }
 
    //在进行最后处理时，判断最后一个字符是否为空格；如果是，则根据题目要求，将其去除；如果不是，则在其后面添加字符串结束符
    if (new_str_end > 0 && str[new_str_end - 1] == ' ')
    {
        str[new_str_end - 1] = '\0';
    }
    else
    {
        str[new_str_end] = '\0';
    }
}
