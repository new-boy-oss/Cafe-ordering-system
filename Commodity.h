//商品类（基类）
#pragma once
#include"Raw_material.h"
#include<iostream>
#include<string>
using namespace std;
class Commodity:public Raw_material
{
public:
	bool ColdOrHot();//冷热
	void pay();//支付 (支付宝 微信) 图片收款码
	void show_product();//显示商品
	Commodity();
	~Commodity();
private:
	string No;//编号
	string name;//咖啡的名字，比如：拿铁，美式等
	double prise;
	int number;//数量
};
