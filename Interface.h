//界面
//查看订单，购买，会员登陆，后台管理员登陆
#pragma once
#include <graphics.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include <windows.h>//Sleep()头文件
#include <stdlib.h>
using namespace std;


class Interface
{
public:
	void pay_show(int temp);//支付 (支付宝 微信) 图片收款码
	void show_product();//显示商品
	Interface();
	~Interface();
	void admin_login_OR_guest_choice();//用户点餐或管理员登录
	void inferface();//主界面
	void inferface_product();//商品栏界面
	void VIP_show();//vip选择登陆or注册界面
	void coffee_show();//coffee商品界面
	void milktea_show();//奶茶商品界面
	void fruittea_show();//果茶商品界面
	void cake_show();//蛋糕商品界面
	void choice();//选择跳转页面
	void VIP_register();//vip注册界面
	void VIP_login();//vip登录界面
	void specifications(int temp);//选择规格
	void WeChat_pay();
	void Alipay_pay();
	void order_show();

private:
	char* No[12];//编号
	char* name[12];//咖啡的名字，比如：拿铁，美式等
	int prise[12];//价格
	int number[12];//数量
	char NO[20];
	string Name[12];
	string Prise[12];
	char weight[20];
	char temperature[20];
	char suger[20];
	char delivery[20];
};

