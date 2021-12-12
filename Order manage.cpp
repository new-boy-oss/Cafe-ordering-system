#pragma once
#include<iostream>
#include "Orderin.h"
#include "OrderOut.h"
#include "Order manage.h"
#include <vector> 
#include<map>
#include <fstream>
#include <string>
#include <windows.h>
#pragma warning(disable:4996)
using namespace std;
void OrderManage::displayOrder()//显示当天的所有订单
{
	FILE* fp = fopen("test.txt", "r+");
	ofstream outfiles;
	vector<string> vs;//生成string类型的变量vs
	char buf[1024];
	while (fgets(buf, 1024, fp) != NULL)//一行一行的读取信息
	{
		vs.push_back(buf);//将读取到的信息添加到buf的信息结尾处
		cout << buf << endl;
	}


}
void  OrderManage::SeekOrder()
{ 

	string temp = "0";
	UpdateOrder();
	cout << "欢迎您使用查找订单功能！注意:只可查找当日订单" << endl;
	cout << "请输入您要查找的方式！1、按照订单编号查找  2.退出" << endl;
	int op;
	string seekid;
	string seeknumber;
	cin >> temp;
	if (temp == "1" || temp == "2")
	{
		op = int(temp[0] - '0');
	}
	else
	{
		cout << "输入错误！" << endl;
		return;
	}
	//使用外卖单号查找
	if (op == 1)
	{
		cout << "请输入您要查找的订单编号！" << endl;
		cin >> seekid;
		if(seekid[4] == 'o'|| seekid[4] == 'i')
		{
			if (seekid[4] == 'o')
			{
				cout << "此订单是外卖订单,具体信息如下" << endl;
					for (map<string, vector<OrderOut>>::iterator it = mOO.begin(); it != mOO.end(); it++)
					{
						//cout << it->first << "it->firstin"; int count = 0;
						string y = it->first;
							if (y == seekid)
							{
								cout << "订单编号：" << it->first << endl;
								int count = 0;

								for (vector<OrderOut>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
								{
									count++;
									cout << "菜品名称为：" << mit->name << " 菜品价格：" << mit->prise << " 菜品份数：" << mit->number << " 总费用：" << mit->totalprice << mit->adda << endl;
								}
								return;
							}

					}
			}
			else 
			{
				cout << "此订单是堂食订单,具体信息如下" << endl;
				for (map<string, vector<Orderin>>::iterator it = mOI.begin(); it != mOI.end(); it++)
				{
					//cout << it->first << "it->firstin";int count = 0;
					string y = it->first;
					if (y == seekid)
					{
						cout << "订单编号：" << it->first << endl;
						int count = 0;

						for (vector<Orderin>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
						{
							count++;
							cout << "菜品名称为：" << mit->name << " 菜品价格：" << mit->prise << " 菜品份数：" << mit->number << "总费用：" << mit->totalprice << mit->adda << endl;
						}
						return;
					}

				}
			}
		}
	   else
	   {
			cout << "输入错误！" << endl;
			return;
	   }
	}
}
void OrderManage::UpdateOrder()
{
	Orderin oi;
	OrderOut oo;
	ifstream ifs;
	mOI.clear();
	vOI.clear();
	mOO.clear();
	vOO.clear();
	vinfo.clear();
	ifs.open("test.txt", ios::in);
	//打开文件失败，创建文件
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//cout << "----------------------------------------------------" << endl;
	//打开成功
	string line;//按行读取
	if (ifs)
	{
		while (getline(ifs, line))
		{

			vinfo.push_back(line);
		}
	}
	//cout << "----------------------------------------------------" << endl;
	//找到每一个订单的起始行
	int temp[100];
	int count = 0;
	int c = 1;
	for (vector<string>::iterator it = vinfo.begin(); it != vinfo.end(); it++)
	{
		line = *it;
		count++;

		if (line.size() > 15)
		{
			if (line.at(15) == 'o' || line.at(15) == 'i')
			{

				temp[c] = count;
				c++;
			}
		}

	}
	//cout << "----------------------------------------------------" << endl;
	temp[c] = vinfo.size() + 1;
	/*for (int i = 1; i <= c; i++)
	{
		cout << temp[i] << " ";
	}*/

	string orderid, foodname,adda;//外卖订单编号
	int foodprice, foodnum, totalprice;//菜品价格、菜品数量
	int pos1, pos2;

	//cout << "---卡死在这-------------------------------------------------" << endl;
	//遍历
	int i = 0;
	int o = 0;
	for (vector<string>::iterator it = vinfo.begin(); it != vinfo.end(); it++)
	{
		line = *it;
		//cout << line;
		//cout << "smdd" << endl;
		if (line.at(15) == 'o' || line.at(15) == 'i') 
		{
			if (line.at(15) == 'o')
			{

				vOO.clear();
				i++;
				for (int k = temp[i]; k < temp[i + 1]; k++)
				{
					//读入数据，存储到vector容器
					//cout << vinfo[k-1] << endl;
					//存储在外卖vector容qi
					if (k == temp[i])//订单编号
					{
						count = 6;
						while (count--)
						{
							if (count == 5)
							{
								pos1 = vinfo[k - 1].find(":") + 1;
								orderid = vinfo[k - 1].substr(pos1, 5);

								//cout << orderid << "编号" ;
							}
							if (count == 4)
							{
								pos1 = vinfo[k - 1].find("称");
								pos2 = pos1 + 5;

								foodname = vinfo[k - 1].substr(pos2, 6);
								//cout << foodname << "mingz ";

								oo.name = foodname;
							}
							else if (count == 3)
							{
								pos1 = vinfo[k - 1].find("格");
								pos2 = pos1 + 5;
								foodprice = atoi(vinfo[k - 1].substr(pos2, 4).c_str());

								//cout << foodprice << " foodprice";
								oo.prise = foodprice;
							}
							else if (count == 2)
							{
								pos1 = vinfo[k - 1].find("数");
								pos2 = pos1 + 5;

								foodnum = atoi(vinfo[k - 1].substr(pos2, 2).c_str());

								//cout << foodnum << " num";

								oo.number = foodnum;
							}
							else if (count == 1)
							{
								pos1 = vinfo[k - 1].find("用");
								pos2 = pos1 + 5;

								totalprice = atoi(vinfo[k - 1].substr(pos2, 4).c_str());

								//cout << totalprice << "totalprice";
								oo.totalprice = totalprice;
							}
							else if (count == 0)
							{
								pos1 = vinfo[k - 1].find("用");
								pos2 = pos1 + 9;
								adda = vinfo[k - 1].substr(pos2);
								oo.adda = adda;
							}
						}vOO.push_back(oo);
					}
	            
				}	
				//cout << "----------------------" << endl;
				//插入到vector容器
				for (vector<OrderOut>::iterator it = vOO.begin(); it != vOO.end(); it++)
				{
					it->No = orderid;
				}

				//插入到map容器中

				mOO.insert(make_pair(orderid, vOO));

			}
			else if (line.at(15) == 'i')
			{
				//cout << "堂食订单！" << endl;
				vOI.clear();
				i++;

				for (int k = temp[i]; k < temp[i + 1]; k++)
				{
					//读入数据，存储到vector容器
					//cout << vinfo[k-1] << endl;
					//存储在外卖vector容qi
					if (k == temp[i])//订单编号
					{
						count = 6;
						while (count--)
						{
							if (count == 5)
							{
								pos1 = vinfo[k - 1].find(":") + 1;
								orderid = vinfo[k - 1].substr(pos1, 5);

								//cout << orderid << "编号" ;
							}
							if (count == 4)
							{
								pos1 = vinfo[k - 1].find("称");
								pos2 = pos1 + 5;

								foodname = vinfo[k - 1].substr(pos2, 6);
								//cout << foodname << "mingz ";

								oi.name = foodname;
							}
							else if (count == 3)
							{
								pos1 = vinfo[k - 1].find("格");
								pos2 = pos1 + 5;
								foodprice = atoi(vinfo[k - 1].substr(pos2, 4).c_str());

								//cout << foodprice << " foodprice";
								oi.prise = foodprice;
							}
							else if (count == 2)
							{
								pos1 = vinfo[k - 1].find("数");
								pos2 = pos1 + 5;

								foodnum = atoi(vinfo[k - 1].substr(pos2, 2).c_str());

								//cout << foodnum << " num";

								oi.number = foodnum;
							}
							else if (count == 1)
							{
								pos1 = vinfo[k - 1].find("用");
								pos2 = pos1 + 5;

								totalprice = atoi(vinfo[k - 1].substr(pos2, 4).c_str());

								//cout << totalprice << "totalprice";
								oi.totalprice = totalprice;
							}
							else if (count == 0)
							{
								pos1 = vinfo[k - 1].find("用");
								pos2 = pos1 + 9;
								adda = vinfo[k - 1].substr(pos2);
								oi.adda = adda;
							}

						}
						vOI.push_back(oi);
					}
				}


				//cout << "----------------------" << endl;
				//插入到vector容器
				for (vector<Orderin>::iterator it = vOI.begin(); it != vOI.end(); it++)
				{

					it->No = orderid;
					//cout << "tableid=" << tableid << " " << "boxprice=" << boxprice << endl;
				}

				//插入到map容器中

				mOI.insert(make_pair(orderid, vOI));


			}

		}
	}
	/*int l = 0;测试程序
	for (map<string, vector<OrderOut>>::iterator it = mOO.begin(); it != mOO.end(); it++)
	{	
	
		cout << "订单编号：" << it->first << endl;
		int count = 0;
		for (vector<OrderOut>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{	
			l++;cout << l << "woyaokk1jic";
			count++;
			cout << "菜品名称为：" << mit->name << " 菜品价格：" << mit->prise << " 菜品份数：" << mit->number << " 总费用：" << mit->totalprice << endl;
		}
	}*/
}
void  OrderManage::DeleteAllOrder()//删除订单
{
	cout << endl;
	cout << "     正在删除所有的文本信息......"<<endl;
	Sleep(3000);
	try
	{
		fstream fout("test.txt", ios::out | ios::trunc);

		fout.close();

	}
	catch (exception& e)
	{
		cout << "error happened:" << e.what() << endl;
	}
	cout << "          已完成              " << endl;
}
void OrderManage::DeleteoneOrder()
{
	cout << "欢迎删除订单" << endl;

    string temp = "0";
	//删除的订单编号
	string deleteid;

	cout << "请输入您要删除的订单编号！" << endl;
	cin >> deleteid;

	if (deleteid[4] == 'i')
	{
		mOI.erase(deleteid);
	}
	else if (deleteid[4] == 'o')
	{
		mOO.erase(deleteid);
	}

	//写入文件

	ofstream ofs;
	ofs.open("test.txt", ios::trunc);
	//打开文件失败，创建文件
	if (!ofs.is_open())
	{
		cout << "无订单信息！" << endl;
		return;

	}
	
//插入到文件
	vector<string> vtemp;
	for (map<string, vector<Orderin>>::iterator it = mOI.begin(); it != mOI.end(); it++)
	{
		vtemp.push_back(it->first);
	}
	for (map<string, vector<OrderOut>>::iterator it = mOO.begin(); it != mOO.end(); it++)
	{
		vtemp.push_back(it->first);
	}

	for (vector<string>::iterator mit = vtemp.begin(); mit != vtemp.end(); mit++)
	{
		int count = 0;
		//堂食
		for (map<string, vector<Orderin>>::iterator it = mOI.begin(); it != mOI.end(); it++)
		{
			if (it->first == *mit)
			{

				for (vector<Orderin>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
				{
					count++;
					ofs << "订单编号:" << it->first <<  "菜品名称为:" << mit->name << " 菜品价格:" << mit->prise << " 菜品份数:" << mit->number << " 菜品折扣:" << mit->totalprice << mit->adda<< endl;
				}

			}
		}
		
			//外卖
			for (map<string, vector<OrderOut>>::iterator it = mOO.begin(); it != mOO.end(); it++)
			{
				if (it->first == *mit)
				{
					for (vector<OrderOut>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
					{
						count++;
						ofs << "订单编号:" << it->first << "菜品名称为:" << mit->name << " 菜品价格:" << mit->prise << " 菜品份数:" << mit->number << " 菜品折扣:" << mit->totalprice << mit->adda << endl;

					}
				}
			}
		
	}
	cout << "删除成功!" << endl;
}