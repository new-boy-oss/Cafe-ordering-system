#pragma once
#include<iostream>
#include "Order.h"
#include <vector> 
using namespace std;
class OrderOut :virtual public Order//外卖
{
public:
	vector<OrderOut> vOrderOutInfo;
	vector <string>vinfo;
	OrderOut() {};
	OrderOut(string a, string b, double c, int d, string e, string f, string g) :Order(a, b, c, d, e, f, g)
	{
		totalprice = c;
		ExtraTips = 3;
		calculation();
	}
	void add()
	{
		cout << "请输入您送餐地点" << endl;
		cin >> m_OrderPlace;
		cout << "请输入您送餐时间" << endl;
		cin >> m_Ordertime;
		cout << "请输入您的手机号" << endl;
		cin >> m_CustomerPhone;
	}
	void AddOutInfo();//添加订单
	virtual void print();//打印订单在屏幕上
	void printtet();//打印订单在txt
	virtual int calculation();//都已经在构造函数中用过，外卖费用3元
	~OrderOut() {};
	string m_Ordertime;
	string m_OrderPlace;//送餐地点
	string m_CustomerPhone;//客户手机号
	int ExtraTips;//外卖服务费
};