#pragma once
#include<iostream>
#include<iostream>
#include "Order.h"
#include "OrderOut.h"
#include "Date.h"
#include <vector> 
#include <fstream>
#include <string>
#define DATE_H
#include <iomanip>
#include <string>

using std::setw;
#pragma warning(disable:4996)
//计算（配送费3块）
int OrderOut::calculation()
{
	totalprice = prise * number + ExtraTips;
	return totalprice;
}
//打印外卖订单到txt存入到一个当天的外卖文件里面
void OrderOut::printtxt()
{
	int year, month, day;
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	Date* d;
	d = new Date(t_tm->tm_year + 1900, t_tm->tm_mon + 1, t_tm->tm_mday);
	year = d->get_year();
	month = d->get_month();
	day = d->get_day();
	cout << year << month << day << "日外卖订单如下" << endl;
	ofstream ofs;
	string nameid;
	std::string str1 = std::to_string(year);
	std::string str2 = std::to_string(month);
	std::string str3 = std::to_string(day);
	nameid = str1 + str2 + str3 + "外卖订单" + ".txt";
	if (!ofs.is_open())
	{
		ofstream ofs(nameid);
		//cout << "新文件创建！" << endl;

	}
	ofs.close();
	ofs.open(nameid, ios::app);
	for (vector<OrderOut>::iterator it = vOrderOutInfo.begin(); it != vOrderOutInfo.end(); it++)
	{
		ofs << "订单编号为:" << it->No << " ";
		ofs << "菜品名称为:" << it->name << " ";
		ofs << "菜品价格为:" << it->prise << " ";
		ofs << "菜品份数为:" << it->number << " ";
		ofs << "总费用为:" << it->totalprice << " ";
		ofs << "规格配料:" << it->sizeiceadda << " ";
		ofs << endl;
	}
	ofs.close();
}
// 打印外卖订单到屏幕
void OrderOut::print()
{
	string line;//按行读取
		//输出订单信息
	for (vector<OrderOut>::iterator it = vOrderOutInfo.begin(); it != vOrderOutInfo.end(); it++)
	{
		cout << "订单编号为:" << it->No << endl;
		cout << "菜品名称为：" << it->name << endl;
		cout << "菜品价格为：" << it->prise << endl;
		cout << "菜品份数为：" << it->number << endl;
		cout << "总费用为" << it->totalprice << endl;
		cout << "规格配料::" << it->sizeiceadda << endl;

	}
}
//添加订单
void OrderOut::AddOutInfo()
{
	string n;
	ofstream outfiles;
	OrderOut oo;
	oo.No = No;
	oo.name = name;
	//菜品价格
	oo.prise = prise;
	//菜品份数
	oo.number = number;
	oo.totalprice = totalprice;
	//菜品折扣
	outfiles.open("order.txt", std::ios::app);
	if (!outfiles.is_open())
	{
		cout << "文件夹打开失败" << endl;
		return;
	}
	outfiles << "订单编号为:" << No << "\t" << "菜品名称为:" << "\t" << name << "\t"
		<< "菜品价格为:" << "\t" << prise << "\t" << "菜品份数为:" << "\t" << number
		<< "\t" << "总费用为:" << "\t" << totalprice << "\t" << "规格配料:" << " " << sizeiceadda << std::endl;
	outfiles.close();
	vOrderOutInfo.push_back(oo);

}