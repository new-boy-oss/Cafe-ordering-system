//商品类（基类）
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Commodity
{
public:
	Commodity();
	~Commodity();
	string No;//编号
	string name;//咖啡的名字，比如：拿铁，美式等
	string prise;//价格
	string number;//数量
	int raw_coffee, suger, ice, milk, cup;//原材料的数量
private:	
};

