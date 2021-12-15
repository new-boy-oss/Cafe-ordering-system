#pragma once
#include"VIP.h"
#include"Commodity.h"
#include <graphics.h>
#include<fstream>
#include<conio.h>
using namespace std;

//构造函数，打开文件
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

//析构函数
VIP::~VIP()
{
	
}

//会员注册
void VIP::vip_register()
{
	
	string vip_key2;
	TCHAR s[10];
	InputBox(s, 10, _T("请输入您的姓名"));
	// 将用户输入转换为string
	vip_name = s;

	TCHAR a[10];
	InputBox(a, 10, _T("请输入您的账号"));
	vip_account = a;

	TCHAR b[10];
	InputBox(b, 10, _T("请输入您的电话号码"));
	vip_Phone_number = b;

	/*
	cout << "请输入您的姓名" << endl;
	cin >> vip_name;
	cout << "请输入您的账号" << endl;
	cin >> vip_account;
	cout << "请输入您的电话号码" << endl;
	cin >> vip_Phone_number;
	cout << endl;
	*/
	
	while (1)
	{
		TCHAR d[10];
		InputBox(d, 10, _T("请输入您的密码"));
		vip_key = d;

		TCHAR e[10];
		InputBox(e, 10, _T("请确认您的密码"));
		vip_key2 = e;

		/*
		cout << "请输入您的密码" << endl;
		cin >> vip_key;
		cout << "请确认您的密码" << endl;
		cin >> vip_key2;
		*/
		
		if (vip_key == vip_key2)
		{
			vip_number++;
			//写入文件
			ofstream ofs;
			ofs.open("vip.txt", ios::app);//从文件末尾写
			ofs << "编号: " << vip_number << endl <<"姓名："<<vip_name<<endl<< "会员账号: "
				<< endl << vip_account << endl << "密码: " << endl
				<<vip_key<<endl<<"电话号码： "<<vip_Phone_number<<endl<<"--------------------------"<<endl;
			ofs.close();
			cout << "创建成功" << endl;
			break;
		}
		else {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, _T(""));
			int isok = MessageBox(hnd, _T("两次密码不一致，请重新输入"), _T("提示"), MB_OK);
			//cout << "两次密码不一致，请重新输入" << endl;
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
	int i = 0;
	int login_number = 0;//账号记录标志 等于一存在账号
	int login_key = 0;//密码记录标志 等于一密码正确
	string* vip_login = new string[1000];
	ifstream ifs("vip.txt"); 
	
	//将文件写入临时的数组
	for(int i = 0; i < get_rows_number(); i++)
	{
		getline(ifs, str);//获取文件行数
		vip_login[i] = str;//将行的文件存入数组
	}

flag:
		//判断账户是否存在
		TCHAR g[10];
		InputBox(g, 10, _T("请输入您账号"));
		m_vip_account = g;

	//	cout << "请输入您要登录的账户" << endl;
	//	cin >> m_vip_account;
		for (int j = 0; j < get_rows_number(); j++)
		{
			if (vip_login[j] == m_vip_account)
			{
				login_number = 1;
				break;
			}
		}

		//long_munber默认等于0；如果等于一，则账户存在
		if (login_number == 0)
		{
			HWND hnd = GetHWnd();
			SetWindowText(hnd, _T(""));
			int isok = MessageBox(hnd, _T("账户不存在,请重新登录"), _T("提示"), MB_OK);
			//cout << "账户不存在,请重新登录" << endl;
			goto flag;
		}
		if (login_number == 1)
		{
			HWND hnd = GetHWnd();
			SetWindowText(hnd, _T(""));
			int isok = MessageBox(hnd, _T("账号存在"), _T("提示"), MB_OK);
			//cout << "账号存在" << endl;
		}
	
		//判断密码是否正确

		TCHAR h[10];
		InputBox(h, 10, _T("请输入您的密码"));
		m_vip_key = h;
	//	cout << "请输入您的密码" << endl;
	//	cin >> m_vip_key;
		for (int k = 0; k < get_rows_number(); k++)
		{
			if (vip_login[k] == m_vip_key)
			{
				login_key = 1;
				break;
			}
		}
		//long_key默认等于0；如果等于一，则密码正确
		if (login_key == 0)
		{
			HWND hnd = GetHWnd();
			SetWindowText(hnd, _T(""));
			int isok = MessageBox(hnd, _T("密码错误，请重新登录"), _T("提示"), MB_OK);
			//cout << "密码错误，请重新登录" << endl;
			goto flag;
		}
		if (login_key == 1)
		{
			HWND hnd = GetHWnd();
			SetWindowText(hnd, _T(""));
			int isok = MessageBox(hnd, _T("登陆成功"), _T("提示"), MB_OK);
			//cout << "登陆成功" << endl;
			delete[]vip_login;
		}
}
