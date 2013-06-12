// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include "TraderSpi.h"
#include "myutils.h"
#include "datatype.h"
#include <ThostFtdcTraderApi.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

// UserApi对象
CThostFtdcTraderApi* pUserApi;

/*map <string,string> data_map;*/
//char LOGIN_DATA[] = "../../login_data/login.ini";
//read_login_data(LOGIN_DATA,data_map);
//// 配置参数
////char  FRONT_ADDR[] = "tcp://asp-sim2-front1.financial-trading-platform.com:26205";		// 前置地址
////char  FRONT_ADDR[] = "tcp://asp-sim2-front1.financial-trading-platform.com:26205";		// 前置地址
//char  FRONT_ADDR[] = data_map["FRONT_ADDR"];
////char  FRONT_ADDR[] = "tcp://123.124.247.2:41205";
////TThostFtdcBrokerIDType	BROKER_ID = "2030";				// 经纪公司代码
//TThostFtdcBrokerIDType	BROKER_ID = data_map["BROKER_ID"];				// 经纪公司代码
//TThostFtdcInvestorIDType INVESTOR_ID = data_map["INVESTOR_ID"];			// 投资者代码
////TThostFtdcInvestorIDType INVESTOR_ID = "352032";			// 投资者代码
////TThostFtdcPasswordType  PASSWORD = "888888";			// 用户密码
//TThostFtdcPasswordType  PASSWORD = data_map["PASSWORD"];			// 用户密码
//TThostFtdcInstrumentIDType INSTRUMENT_ID = data_map["INSTRUMENT_ID"];	// 合约代码
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 38850;				// 价格
/*
 *char LOGIN_DATA[100] = "../../login_data/login.ini";
 */
char LOGIN_DATA[100] = "../../login_data/";

// 请求编号
int iRequestID = 0;

int main(int argc, char *argv[])
{
	if (argc<2){
		cout <<"USAGE:DATA FILE"<<endl;
		exit(0);
	}

	if (strlen(argv[1]) > 90){
		cout <<"THE FILE NAME IS TOO LONG"<<endl;
		exit(0);
	}
	strcat(LOGIN_DATA,argv[1]);

	extern map <string,string> data_map;
	/*
	 *char LOGIN_DATA[] = "../../login_data/login.ini";
	 */
	read_login_data(LOGIN_DATA,data_map);
	// 配置参数
	//char  FRONT_ADDR[] = "tcp://asp-sim2-front1.financial-trading-platform.com:26205";		// 前置地址
	//char  FRONT_ADDR[] = "tcp://asp-sim2-front1.financial-trading-platform.com:26205";		// 前置地址
	/*
	 *char *FRONT_ADDR = NULL;
	 */
	const char *CONST_FRONT_ADDR = data_map["FRONT_ADDR"].c_str();
	char *FRONT_ADDR = const_cast<char *>(CONST_FRONT_ADDR);
	const char *BROKER_ID = data_map["BROKER_ID"].c_str();				// 经纪公司代码
	const char *INVESTOR_ID = data_map["INVESTOR_ID"].c_str();			// 投资者代码
	const char *PASSWORD = data_map["PASSWORD"].c_str();			// 用户密码
	const char *INSTRUMENT_ID = data_map["INSTRUMENT_ID"].c_str();	// 合约代码

	print_map_string(data_map);


	
	// 初始化UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
	pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);					// 注册公有流
	pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);					// 注册私有流
	std::cout << "FRONT_ADDR=" << FRONT_ADDR << std::endl;
	pUserApi->RegisterFront(FRONT_ADDR);							// connect
	pUserApi->Init();

	pUserApi->Join();
//	pUserApi->Release();
	return 0;
}
