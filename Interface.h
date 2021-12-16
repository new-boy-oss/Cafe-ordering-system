//界面
//查看订单，购买，会员登陆，后台管理员登陆
#pragma once
#include"Commodity.h"
#include <graphics.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include <windows.h>//Sleep()头文件
#include <stdlib.h>
using namespace std;


class Interface :public Commodity 
{
public:
	Interface();
	~Interface();
	void pay_show(int a);//支付 
	void show_product();//显示商品
	void show_product2();//登录vip后的显示商品界面
	string getNo();//返回编号
	string getName();//返回名称
	int getPrise();//返回价格
	string getspecifications();//返回规格
	string getdelivery();//返回配送方式
	void inferface();//主界面
	void inferface2();//商品栏界面
	void VIP_show();//vip选择登陆or注册界面
	void coffee_show();//coffee商品界面
	void milktea_show();//奶茶商品界面
	void fruittea_show();//果茶商品界面
	void cake_show();//蛋糕商品界面
	void choice();//选择跳转页面
	void VIP_register();//vip注册界面
	void VIP_login();//vip登录界面
	void specifications(int a);//选择规格	
	void WeChat_pay();//微信支付
	void Alipay_pay();//支付宝支付
	void order_show(string a, string b, int c, string d, string e);//订单界面


private:
	string no;
	string name;
	int Prise;
	int temp, temp1, temp2, temp3, temp4;
	struct specifications
	{
		string specifications;//配料
		string delivery;//配送方法
	}spe[16] = {
		{"大杯+热+加糖" ,"外卖"},
		{"大杯+热+加糖" ,"自提"},
		{"大杯+热+无糖" ,"外卖"},
		{"大杯+热+无糖" ,"自提"},
		{"大杯+加冰+加糖","外卖"},
		{"大杯+加冰+加糖","自提"},
		{"大杯+加冰+无糖","外卖"},
		{"大杯+加冰+无糖","自提"},
		{"小杯+热+加糖" ,"外卖"},
		{"小杯+热+加糖","自提"},
		{"小杯+热+无糖","外卖"},
		{"小杯+热+无糖","自提"},
		{"小杯+加冰+加糖","外卖"},
		{"小杯+加冰+加糖","自提"},
		{"小杯+加冰+无糖","外卖"},
		{"小杯+加冰+无糖","自提"} };
};
