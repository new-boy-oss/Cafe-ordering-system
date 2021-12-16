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
	//string No;//编号
	//string name;//咖啡的名字，比如：拿铁，美式等
	//string prise;//价格
	//string number;//数量
	int raw_coffee, suger, ice, milk, cup;//原材料的数量
	struct product
	{
		string No;//编号
		string Name;//名字
		int prise;//价格
		int number;//数量
	}pro[20] = {
		{"No 1","美式咖啡",10,30},
		{"No 2","拿铁咖啡",13,30},
		{"No 3","抹茶拿铁",15,30} ,
		{"No 4","生椰桂花酿",17,40},
		{"No 5","芋泥波波奶茶",20,40},
		{"No 6","珍珠奶茶",15,40},
		{"No 7","快乐水果桶",25,45},
		{"No 8","草莓清茶",19,45},
		{"No 9","鲜百香果茶",19,45},
		{"No 10","榴莲千层蛋糕",10,30},
		{"No 11","草莓蛋糕",30,30},
		{"No 12","提拉米苏",16,30}
	};


	
	
private:	
};

