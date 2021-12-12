//后台管理
#include"Back_stage_management.h"
#include"Commodity.h"
#include<string>
#include<fstream>
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
		cout << "请输入管理员账号" << endl;
		cin >> m_manage_account;
		cout << "请输入您的密码" << endl;
		cin >> m_manage_key;
		if (m_manage_account == manage_account && m_manage_key == manage_key)
		{
			cout << "登录成功" << endl;;
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
	cout << "增加产品" << endl;
	string m_name,m_No,m_number;
	string m_prise;
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

		Commodity c;
		c.No = m_No;
		c.name = m_name;
		c.prise = m_prise;
		c.number = m_number;

		vCommodity.push_back(c);
		//写入产品
		ofstream ofs;
		ofs.open("menu.txt", ios::trunc);//ios::trunc 如果文件存在，把文件长度设为0 app:从文件末尾写

		for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
		{
			ofs << "产品编号： " << endl << it->No << endl << "产品名称： " << endl << it->name 
				<< endl << "产品价格： " << endl << it->prise 
				<< endl << "产品数量： " << endl << it->number << endl << "---------------" << endl;
		}
		ofs.close();

		cout << "添加成功" << endl;

	}
	
	
}

//修改商品名称，数量和价格
void Back_stage_management::change()
{
	cout << "修改商品" << endl;
	string m_prise, m_name, m_No, m_number;//用于查找
	string M_name, M_prise,M_number;//用于修改

	string str;
	
	int menu_number = 0;

	//输出所有商品
	cout << "所有产品如下: " << endl;
	show();//调用展示所有商品函数
	string* product= new string[1000];
	ifstream ifs("menu.txt");

	//将文件写入临时的数组
	for (int i = 0; i < get_row_number_menu(); i++)
	{
		getline(ifs, str);//获取文件行数
		product[i] = str;//将行的文件存入数组
	}
flag2:
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

	//nemu_munber默认等于0；如果等于一，则账户存在
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
	for (int i = 0; i<x; i++)
	{
		ofs << product[i] << endl ;
	}
	delete[] product;
	ofs.close();
	
	cout << "修改成功" << endl;

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