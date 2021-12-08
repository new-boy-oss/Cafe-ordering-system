//商品类（基类）
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Commodity
{
public:
	void show_product();//显示商品
	int add_product();//添加商品
	void change();//修改商品数量和价格
	Commodity();
	~Commodity();
private:
	string No;//编号
	string name;
	double prise;
	int number;//数量
};

Commodity::Commodity()
{
}

Commodity::~Commodity()
{
}