#pragma once
#include"VIP.h"
#include"Commodity.h"
#include<fstream>
using namespace std;
VIP::VIP()
{
	
	vip_account = "0";//账号
	vip_key = "0";//密码
	vip_name = "0";//会员姓名
	vip_Phone_number = "0";//电话号
	vip_number = 0;//编号

	ifstream ifs;
	ifs.open("vip.txt", ios::in);//只读
	if (!ifs.is_open())
	{
		cout << "文件夹打开失败" << endl;
		return;
	}
}
VIP::~VIP()
{
	
}

//会员注册
void VIP::vip_register()
{
	string vip_key2;
	cout << "*********会员注册*********" << endl;
	cout << "请输入您的姓名" << endl;
	cin >> vip_name;
	cout << "请输入您的账号" << endl;
	cin >> vip_account;
	cout << "请输入您的电话号码" << endl;
	cin >> vip_Phone_number;
	cout << endl;
	while (1)
	{
		cout << "请输入您的密码" << endl;
		cin >> vip_key;
		cout << "请确认您的密码" << endl;
		cin >> vip_key2;
		if (vip_key == vip_key2)
		{
			vip_number++;
			//写入文件
			ofstream ofs;
			ofs.open("vip.txt", ios::app);//从文件末尾写
			ofs << "编号: " << vip_number << endl << "会员账号: " << endl << vip_account << endl << "密码: " << endl
				<<vip_key<<endl<<"电话号码： "<<vip_Phone_number<<endl<<"--------------------------"<<endl;
			ofs.close();
			cout << "创建成功" << endl;
			break;
		}
		else {
			cout << "两次密码不一致，请重新输入" << endl;
		}

	}
}

//获取行数
int VIP::get_rows_number()
{
	int rows_number=0;//行数
	string str;
	ifstream ifs("vip.txt");
	while (getline(ifs, str))
	{
		rows_number++;	
	}
	return rows_number;
}

//会员登陆
void VIP::vip_login()
{	
	string m_vip_account,m_vip_key;
	
	string str;

	string* vip_login = new string[1000];
	
		cout << "请输入您要登录的账户" << endl;
		cin >> m_vip_account;
		cout << "请输入您的密码" << endl;
		cin >> m_vip_key;
		ifstream ifs("vip.txt");
		int i = 0;
		while (getline(ifs, str))
		{
			vip_login[i] = str;
		}
		for (int j = 0; j < get_rows_number(); j++)
		{
			if (vip_login[j] == m_vip_account)
			{

				for (int k = 0; k < get_rows_number(); k++)
				{
					if (vip_login[k] == m_vip_key)
					{
						cout << "登录成功" << endl;
						delete[]vip_login;
						break;
					}
					else
					{
						cout << "登陆失败" << endl;
						break;
					}
				}
			}
		}
}
