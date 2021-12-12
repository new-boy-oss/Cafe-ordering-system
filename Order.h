#pragma once
#include<iostream>
using namespace std;
class Order
{
public:
	Order() {};
	Order(string a, string b, double c, int d,string e,string f,string g) 
		:No(a), name(b), prise(c), number(d),size(e), ice(f), adda(g) { totalprice = 0; }
	virtual void print() = 0;
	virtual int calculation() = 0;
	~Order() {};
	string No;//编号
	string name;//咖啡的名字，比如：拿铁，美式等
	double prise;//价格
	double number;//数量
	double totalprice;//一共多少钱
	string size;//大杯小杯
	string ice;//冰
	string adda;//加料
};
