#pragma once
#include "Order.h"
#include <vector>
#include <string>
using namespace std;
//外卖
class OrderOut :virtual public Order
{
public:
	vector<OrderOut> vOrderOutInfo;
	vector <string> vinfo;
	OrderOut() 
	{
		ExtraTips = 0;
	};
	OrderOut(string b, int c, int d, string e) :Order(b, c, d, e)
	{
		srand((int)(time(NULL)));
		int n = rand() % 9999 + 1000;
		std::string str = std::to_string(n);
		totalprice = c;
		No = str + "o";
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
	int ExtraTips;//外卖服务费
	static int count;
};