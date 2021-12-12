#pragma once
#pragma once
#include<iostream>
#include "Orderin.h"
#include "OrderOut.h"
#include <vector> 
#include<map>
using namespace std;

//管理员
class OrderManage
{
public:
	void DeleteoneOrder();//删除一个订单
	vector<Order> vOrder;
	OrderManage() {}; //构造函数
	void UpdateOrder();//更新订单
	void displayOrder();//显示订单
	void SeekOrder();//查找订单
	void DeleteAllOrder();//删除全部订单
	//存储堂食订单的信息
	map<string, vector<Orderin>> mOI;
	vector<Orderin> vOI;
	//存储外卖订单的信息
	map<string, vector<OrderOut>> mOO;
	vector<OrderOut> vOO;
	//存储临时的从文件中读入的信息
	vector<string> vinfo;
	~OrderManage() {}; //构造函数
};