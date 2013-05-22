// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include "TraderSpi.h"
#include <ThostFtdcTraderApi.h>
#include <iostream>
#include <sstream>
#include <fstream>

// UserApi对象
CThostFtdcTraderApi* pUserApi;

// 配置参数
//char  FRONT_ADDR[] = "tcp://asp-sim2-front1.financial-trading-platform.com:26205";		// 前置地址
//char  FRONT_ADDR[] = "tcp://asp-sim2-front1.financial-trading-platform.com:26205";		// 前置地址
char  FRONT_ADDR[] = "tcp://ctpfz1-front1.citicsf.com:51205";		// 前置地址
//char  FRONT_ADDR[] = "tcp://123.124.247.2:41205";
//TThostFtdcBrokerIDType	BROKER_ID = "2030";				// 经纪公司代码
TThostFtdcBrokerIDType	BROKER_ID = "66666";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "00017001033";			// 投资者代码
//TThostFtdcInvestorIDType INVESTOR_ID = "352032";			// 投资者代码
//TThostFtdcPasswordType  PASSWORD = "888888";			// 用户密码
TThostFtdcPasswordType  PASSWORD = "123456";			// 用户密码
TThostFtdcInstrumentIDType INSTRUMENT_ID = "cu1309";	// 合约代码
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 38850;				// 价格
char LOGIN_DATA[] = "../../login_data/login.ini";
void read_login_data(LOGIN_DATA);

// 请求编号
int iRequestID = 0;

int main()
{
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
