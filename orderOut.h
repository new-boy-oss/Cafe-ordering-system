#pragma once
#include<iostream>
#include "Order.h"
#include <vector> 
using namespace std;
//外卖
class OrderOut :virtual public Order
{
public:
	vector<OrderOut> vOrderOutInfo;
	vector <string> vinfo;
	OrderOut() {};
	OrderOut(string a, string b, double c, int d, string e, string f, string g) :Order(a, b, c, d, e, f, g)
	{
		totalprice = c;
		ExtraTips = 3;//配送费3块
		calculation();
	}
	void AddOutInfo();//添加订单
	virtual void print();//打印订单在屏幕上
	void printtxt();//打印订单在txt
	virtual int calculation();//都已经在构造函数中用过，外卖费用3元
	~OrderOut() {};
private:
	string m_Ordertime;
	string m_OrderPlace;//送餐地点
	string m_CustomerPhone;//客户手机号
	int ExtraTips;//外卖服务费
};