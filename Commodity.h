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
	double prise;//价格
	int raw_coffee, suger, ice, milk, cup;//原材料的数量
private:	
};

