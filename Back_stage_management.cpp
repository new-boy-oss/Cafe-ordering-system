//后台管理
#include"Interface.h"
#include "OrderOut.h"
#include"Back_stage_management.h"
#include"Commodity.h"
#include<string>
#include<fstream>
#include <vector> 
#include<map>
#include <windows.h>
#pragma warning(disable:4996)
using namespace std;

Back_stage_management::Back_stage_management()
{
	
	ifstream ifs;
	manage_account = "000000";
	manage_key = "111111";

	
	//打开文件----菜单文件
	ifs.open("menu.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件夹打开失败" << endl;
		return;
	}

	//打开文件----会员文件
	ifs.open("vip.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件夹打开失败" << endl;
		return;
	}
}

Back_stage_management::~Back_stage_management()
{

}

//管理员登录
void Back_stage_management::manage_login()
{
	string m_manage_account;
	string m_manage_key;
	while (1)
	{
		cout << "----------------请输入管理员账号---------------" << endl;
		cin >> m_manage_account;
		cout << "----------------请输入您的密码-----------------" << endl;
		cin >> m_manage_key;
		if (m_manage_account == manage_account && m_manage_key == manage_key)
		{
			cout << "登录成功" << endl;
			login_choice();
			break;
		}
		else
		{
			cout << "登陆失败，请重新登录" << endl;
		}
	}
}

//展示所有原材料
void Back_stage_management::show()
{
	string str;
	ifstream ifs("menu.txt");
	while (getline(ifs, str))
	{
		cout << str << endl;
	}
	cout << "---------------------------------------------" << endl;
		cout << "原材料数量如下： " << endl;
		cout << "咖啡豆 ： " << raw_coffee << endl;
		cout << "糖 ： " << suger << endl;
		cout << "杯子 ： " << cup << endl;
		cout << "牛奶：" << milk << endl;
		cout << "冰：" << ice << endl;
}

//添加产品
void Back_stage_management::add_product()
{
	cout << "-------------增加产品------------" << endl;
	string m_name, m_No;
	int m_prise, m_number;

	int add_number=0;
	cout << "请输入增加的产品数量" << endl;
	cin >> add_number;

	for (int i = 0; i < add_number; i++)
	{
		cout << "请输入产品编号" << endl;
		cin >> m_No;
		cout << "请输入要添加的产品名称" << endl;
		cin >> m_name;
		cout << "请输入它的价格" << endl;
		cin >> m_prise;
		cout << "请输入产品数量" << endl;
		cin >> m_number;

		//Commodity c;
		//起始有12个商品在售
		pro[11 + i].No = m_No;
		pro[11 + i].Name = m_name;
		pro[11 + i].prise = m_prise;
		pro[11 + i].number = m_number;

		//vCommodity.push_back(c);
		//写入产品
		ofstream ofs;
		ofs.open("menu.txt", ios::app);//ios::trunc 如果文件存在，把文件长度设为0 app:从文件末尾写

		//for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
		//{
			ofs <<"产品编号： " << endl << pro[11 + i].No << endl << "产品名称： " << endl << pro[11 + i].Name
				<< endl << "产品价格： " << endl << pro[11 + i].prise
				<< endl << "产品数量： " << endl << pro[11 + i].number << endl;
		//}
		ofs.close();

		cout << "添加成功" << endl;

	}
	
	
}

//修改商品名称，数量和价格
void Back_stage_management::change()
{
	cout << "修改商品" << endl;
	string m_prise, m_name, m_No, m_number;//用于查找
	string M_name; int M_prise, M_number;//用于修改

	string str;
	
	int menu_number = 0;// nemu_munber默认等于0；如果等于一，则存在

	//输出所有商品
	cout << "所有产品如下: " << endl;
	show();//调用展示所有商品函数

	//临时数组
	string* product= new string[1000];
	ifstream ifs("menu.txt");

	//将文件写入临时的数组
	for (int i = 0; i < get_row_number_menu(); i++)
	{
		getline(ifs, str);//获取文件行数
		product[i] = str;//将行的文件存入数组
	}


flag2:
	//按编号查找商品
	cout << "请输入产品编号" << endl;
	cin >> m_No;
	for (int j = 0; j < get_row_number_menu(); j++)
	{
		if (product[j] == m_No)
		{
			menu_number = 1;
			break;
		}
	}

	//判断商品是否存在 nemu_munber默认等于0；如果等于一，则存在
	if (menu_number == 0)
	{
		cout << "产品不存在，请重新选择" << endl;
		goto flag2;
	}
	if (menu_number == 1)
	{
		cout << "产品存在" << endl;
	}
	
	//修改名称
	cout << "请输入原始产品名称" << endl;
	cin >> m_name;
	for (int j = 0; j < get_row_number_menu(); j++)
	{
		if (product[j] == m_name)
		{
			cout << "请输入修改后的名称" << endl;
			cin >> M_name;
			product[j] = M_name;
			break;
		}
	}

	//修改价格
	cout << "请输入它的原始价格" << endl;
	cin >> m_prise;
	for (int j = 0; j < get_row_number_menu(); j++)
	{
		if (product[j] == m_prise)
		{
			cout << "请输入修改后的价格" << endl;
			cin >> M_prise;
			product[j] = M_prise;
			break;
		}
	}

	//修改数量
	cout << "请输入它的原始数量" << endl;
	cin >> m_number;
	for (int j = 0; j < get_row_number_menu(); j++)
	{
		if (product[j] == m_number)
		{
			cout << "请输入修改后的数量" << endl;
			cin >> M_number;
			product[j] = M_number;
			break;
		}
	}

	cout << "___________________________________________" << endl;
	//写入文件
	int x = get_row_number_menu();
	ofstream ofs;
	ofs.open("menu.txt", ios::trunc);

	for (int i = 0; i < x; i++)
	{
		ofs << product[i] << endl;
	}

	//写入结构体
	int ssss = 0;
	for (int sss = 0; sss <= (x / 8); sss++)
	{	
		pro[sss].No = product[ssss + 1];
		pro[sss].Name = product[ssss + 3];
		string s = product[ssss + 5];//string转int
		string ss = product[ssss + 7];
		pro[sss].prise = atoi(s.c_str());
		pro[sss].number = atoi(ss.c_str());
	}


	delete[] product;
	ofs.close();


	cout << "修改成功" << endl;

}

//会员信息维护
void Back_stage_management::vip_information_maintenance()
{
	ifstream ifs("vip.txt");

	string str;
	while (getline(ifs, str))
	{
		cout << str << endl;
	}
}

//获取行数
int Back_stage_management::get_row_number_menu()
{
	int rows_number_menu = 0;//行数
	string str;
	ifstream ifs("menu.txt");
	while (getline(ifs, str))
	{
		rows_number_menu++;
	}
	return rows_number_menu;
}

//	登陆成功后的操作选择
void Back_stage_management::login_choice()
{
	cout << "-----------------------------------" << endl;
	cout << "---------1.显示所有原材料----------" << endl;
	cout << "---------2.添加产品----------------" << endl;
	cout << "---------3.修改产品名称数量及价格--" << endl;
	cout << "---------4.会员信息维护------------" << endl;
	cout << "---------5.显示当天的所有订单------" << endl;
	cout << "---------6.查询订单----------------" << endl;
	cout << "---------7.更新订单----------------" << endl;
	cout << "---------8.删除全部订单------------" << endl;
	cout << "---------9.回到主页面--------------" << endl;
	//cout << "---------9.删除一个订单------------" << endl;
	cout << "---------0.退出程序----------------" << endl;
	cout << "-----------------------------------" << endl;
	int choice;
	Interface aa;
flag3:
	cout << "请选择接下来的操作" << endl;
	cin >> choice;
	
		switch (choice)
		{
			//展示所有原料
		case 1:
			show();
			goto flag3;
			break;

			//添加产品
		case 2:
			add_product();
			goto flag3;
			break;

			//修改商品名称，数量和价格
		case 3:
			change();
			goto flag3;
			break;
			//会员信息维护
		case 4:
			vip_information_maintenance();
			goto flag3;
			break;
			//显示当天的所有订单
		case 5:
			displayOrder();
			goto flag3;
			break;
			//查询订单
		case 6:
			SeekOrder();
			goto flag3;
			break;
			//更新订单
		case 7:
			UpdateOrder();
			goto flag3;
			break;
			//删除全部订单
		
		case 8:
			DeleteAllOrder();
			goto flag3;
			break;
			//回到主页面
		case 9:
			
			aa.inferface();
			break;

			//删除一个订单
		/*
		case 9:
			DeleteoneOrder();
			goto flag3;
			break;
		*/
			//退出程序
		case 0:
			exit(0);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			goto flag3;
			break;
		}	
}

//显示当天的所有订单
void Back_stage_management::displayOrder()
{
	ifstream ifs;
	ifs.open("order.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件夹打开失败" << endl;
	}
	string str;
	while (getline(ifs, str))//一行一行的读取信息
	{
		cout << str << endl;
	}
}

//查询订单
void  Back_stage_management::SeekOrder()
{

	string temp = "0";
	UpdateOrder();
	cout << "欢迎您使用查找订单功能！注意:只可查找当日订单" << endl;
	cout << "请输入您要查找的方式！1、按照订单编号查找  2.退出" << endl;
	int op = 0;
	string seekid;//输入查找的订单号
	string seeknumber;
	cin >> op;//temp;
	//使用外卖单号查找
	if (op == 1) {
		while (1)
		{
			cout << "请输入您要查找的订单编号！" << endl;
			cin >> seekid;
			if (seekid.length() > 4)
			{
				if (seekid[4] == 'o' || seekid[4] == 'i')//5位订单号，否则报错
				{
					if (seekid[4] == 'o')
					{
						cout << "此订单是外卖订单,具体信息如下" << endl;
						for (map<string, vector<OrderOut>>::iterator it = mOO.begin(); it != mOO.end(); it++)
						{
							string y = it->first;
							if (y == seekid)
							{
								cout << "订单编号：" << it->first << endl;
								int count = 0;

								for (vector<OrderOut>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
								{
									count++;
									cout << "菜品名称为：" << mit->name << " 菜品价格：" << mit->prise << " 菜品份数："
										<< mit->number << " 总费用：" << mit->totalprice << mit->adda << endl;
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
					cout << "编号输入错误！" << endl;
					return;
				}
				break;
			}
			else
			{
				cout << "编号为5位，请重新输入！" << endl;
				
			}
		}

	}

}
		
//更新订单
void Back_stage_management::UpdateOrder()
{
	Orderin oi;//堂食
	OrderOut oo;//外卖
	ifstream ifs;

	//存储堂食订单的信息
	mOI.clear();
	vOI.clear();

	//存储外卖订单的信息
	mOO.clear();
	vOO.clear();

	//存储临时的从文件中读入的信息

	vinfo.clear();

	ifs.open("order.txt", ios::in);
	//打开文件失败，创建文件
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	//打开成功

	//按行读取
	string line;
	if (ifs)
	{
		while (getline(ifs, line))
		{
			vinfo.push_back(line);
		}
	}

	//找到每一个订单的起始行

	int temp[100];
	int count = 0;//行数
	int c = 1;//判断容器大小
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


	temp[c] = vinfo.size() + 1;
	
	string orderid, foodname, adda;//外卖订单编号
	int foodprice, foodnum, totalprice;//菜品价格、菜品数量
	int pos1, pos2;

	//遍历
	int i = 0;
	int o = 0;
	for (vector<string>::iterator it = vinfo.begin(); it != vinfo.end(); it++)
	{
		line = *it;

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
}

//删除全部订单
void Back_stage_management::DeleteAllOrder()
{
	cout << endl;
	cout << "     正在删除所有的文本信息......" << endl;
	Sleep(3000);
	try
	{
		fstream fout("order.txt", ios::out | ios::trunc);

		fout.close();

	}
	catch (exception& e)
	{
		cout << "error happened:" << e.what() << endl;
	}
	cout << "-----------已完成------------" << endl;
}

//删除商品
/*

 void Back_stage_management::delete_product()
{
	string delete_No;

	cout << "删除商品" << endl;
	cout << "请输入要删除的商品编号" << endl;
	cin >> delete_No;
	for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
	{
		if (it->No == delete_No)
		{
			vCommodity.erase(it);//删除向量中迭代器指向元素
			break;
		}
	}
	cout << "成功" <<endl;

	//写入
	ofstream ofs;
	ofs.open("menu.txt", ios::trunc);

	for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
	{
		ofs << it->No << " " << it->name << " " << it->prise << endl;
	}
	ofs.close();

	cout << "删除成功" << endl;
}

*/

//删除一个订单
/*
void Back_stage_management::DeleteoneOrder()
{
	cout << "-----------删除订单--------------" << endl;

	string temp = "0";

	//删除的订单编号
	string deleteid;

	while (1)
	{
		cout << "请输入您要删除的订单编号！" << endl;
		cin >> deleteid;

		if (deleteid[4] == 'i')
		{
			mOI.erase(deleteid);
			cout << "删除成功!" << endl;
			break;
		}
		else if (deleteid[4] == 'o')
		{
			mOO.erase(deleteid);
			cout << "删除成功!" << endl;
			break;
		}
		else
		{
			cout << "输入错误" << endl;
			break;
		}
	}
	

	//写入文件
	ofstream ofs;
	ofs.open("order.txt", ios::trunc);

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
					ofs << "订单编号:" << it->first << "菜品名称为:" << mit->name << " 菜品价格:" << mit->prise << " 菜品份数:" << mit->number << " 菜品折扣:" << mit->totalprice << mit->adda << endl;
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

}
*/
