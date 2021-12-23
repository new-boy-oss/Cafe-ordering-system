//商品类（基类）
#pragma once
#include<iostream>
#include<string>
using namespace std;

struct product
{
	//string No[20];//编号
	//string Name[20];//名字
	//int prise[20];//价格
	//int number[20];//数量
	string 	No[20] = { "No 1","No 2","No 3","No 4","No 5","No 6","No 7","No 8","No 9","No 10","No 11","No 12" };
	string Name[20] = { "美式咖啡","抹茶拿铁","拿铁咖啡","生椰桂花酿","芋泥波波奶茶","珍珠奶茶","快乐水果桶","草莓清茶","鲜百香果茶","榴莲千层蛋糕","草莓蛋糕","提拉米苏" };
	int prise[20] = { 10,13,15,17,20,12,25,19,21,18,30,16 };
	int number[20] = { 30,40,50,60,35,45,55,65,75,80,25,27 };
};


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
	product s;
private:
};

