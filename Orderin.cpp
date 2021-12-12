#pragma once
#define DATE_H

#include<iostream>
#include "Order.h"
#include "Orderin.h"
#include <vector> 
#include <fstream>
#include <string>
#include "Date.h"
#include <iomanip>
#include <sstream>
#pragma warning(disable:4996)
using std::setw;
//计算总钱数
int Orderin::calculation()
{
	totalprice = prise * number;
	return totalprice;
}

//打印堂食订单到屏幕
void Orderin::print()
{
	
	string line;//按行读取
	//输出订单信息
	for (vector<Orderin>::iterator it = vOrderInInfo.begin(); it != vOrderInInfo.end(); it++)
	{
		cout << "菜品编号为:" << it->No << endl;
		cout << "菜品名称为：" << it->name << endl;
		cout << "菜品价格为：" << it->prise << endl;
		cout << "菜品份数为：" << it->number << endl;
	    cout << "总费用为：" << it->totalprice << endl;
		cout << "大杯或小杯:" << it->size << " ";
		cout << "是否加冰:" << it->ice << " ";
		cout << "是否加料" << it->adda << " ";

	}
	
}

//打印堂食每日订单并存入到一个当天的外卖文件里面
void Orderin::printtxt()
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
	ofstream ofs;
	string nameid;
	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream ss3;
	std::string str1;
	std::string str2;
	std::string str3;
	ss1 << year;
	ss1 >> str1;
	ss2 << month;
	ss2 >> str2;
	ss3 << day;
	ss3 >> str3;
	string str = str1 + str2 + str3;
	str = str + "堂食订单" + "txt";
	nameid = str;
	if (!ofs.is_open())
	{
		ofstream ofs(nameid);
		//cout << "新文件创建！" << endl;

	}
	ofs.close();
	ofs.open(nameid, ios::app);
	for (vector<Orderin>::iterator it = vOrderInInfo.begin(); it != vOrderInInfo.end(); it++)
	{
		ofs << "菜品编号为:" << it->No << " ";
		ofs << "菜品名称为:" << it->name << " ";
		ofs << "菜品价格为:" << it->prise << " ";
		ofs << "菜品份数为:" << it->number << " ";
		ofs << "菜品总价为:" << it->totalprice << " ";
		ofs << "大杯或小杯:" << it->size << " ";
		ofs << "是否加冰:" << it->ice << " ";
		ofs << "是否加料" << it->adda << " ";

		ofs << endl;
	}
	ofs.close();
}

//添加订单
void Orderin::AddOutInfo()
{
	string n;
	ofstream outfiles;
	Orderin oi;
	oi.No = No;
	oi.name = name;
	//菜品价格
	oi.prise = prise;
	//菜品份数
	oi.number = number;
	oi.totalprice =totalprice;
	//菜品折扣
	vOrderInInfo.clear();
	outfiles.open("test.txt", std::ios::app);
	if (!outfiles.is_open())
	{
		cout << "文件夹打开失败" << endl;
		return;
	}
	outfiles << "菜品编号为:"  << No << "\t" << "菜品名称为:" << "\t"<< name << "\t" << "菜品价格为:" << "\t" << prise << "\t" << "菜品份数为:" << "\t" << number << "\t" << "总费用为:" << "\t" << totalprice << "\t" << "大杯或小杯:" << size << " "<< "是否加冰:" << ice << " "<< "是否加料" << adda << " " << std::endl;
	outfiles.close();
	vOrderInInfo.push_back(oi);
}