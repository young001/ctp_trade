#include <map>
#include "myutils.h"

extern char LOGIN_DATA[];
map <string,string> data_map; //信息容器
read_login_data(LOGIN_DATA,data_map);

char *FRONT_ADDR = NULL;
const char *CONST_FRONT_ADDR = data_map["FRONT_ADDR"].c_str();
char *FRONT_ADDR = const_cast<char *>(CONST_FRONT_ADDR);
const char *BROKER_ID = data_map["BROKER_ID"].c_str();				// 经纪公司代码
const char *INVESTOR_ID = data_map["INVESTOR_ID"].c_str();			// 投资者代码
const char *PASSWORD = data_map["PASSWORD"].c_str();			// 用户密码
const char *INSTRUMENT_ID = data_map["INSTRUMENT_ID"].c_str();	// 合约代码




