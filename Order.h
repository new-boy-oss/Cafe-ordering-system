#pragma once
#include<iostream>
using namespace std;
class Order
{
public:
	Order() 
	{  
		No = '0';
		name = '0';
		prise = 0;
		number = 0;
		totalprice = '0';

	};
	Order(string b, int c, int d, string e)
		: name(b), prise(c), number(d), sizeiceadda(e) {
		No = " 1"; totalprice = '0'; prise = 0; number = 0;
	}
	virtual void print() {};
	virtual int calculation() { return 0; };
	~Order() {};
	string No;//编号
	string name;//咖啡的名字，比如：拿铁，美式等
	int prise;//价格
	int number;//数量
	int totalprice;//一共多少钱
	string sizeiceadda;//性质
};