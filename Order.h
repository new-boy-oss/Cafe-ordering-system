//订单
#include "Commodity.h"
#pragma once
using namespace std;
class Order:public  Commodity
{
public:
	void show_order();//显示订单
	void delete_order();//删除订单
	void refer();//查询订单
	void delivery_method();//自提or配送
	Order();
	~Order();
private:
	double delivery_time;//配送时间
};

