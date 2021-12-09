//后台管理
#include"Back_stage_management.h"
#include"Commodity.h"
#include<string>
#include<fstream>
Back_stage_management::Back_stage_management()
{
	Commodity fdis;
	ifstream ifs;
	manage_account = "000000";
	manage_key = "111111";

	Commodity f;
	//打开文件----菜单文件---编号、名称、价格、
	ifs.open("menu.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件夹打开失败" << endl;
		return;
	}
}

Back_stage_management::~Back_stage_management()
{

}

//展示所有原材料
void Back_stage_management::show()
{
	for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
	{
		cout << "产品编号： " <<it->No<<"产品名称： "<<it->name<<"产品价格： "<<it->prise<<endl;
	}
		cout << "数量如下： " << endl;
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
	string m_name,m_No;
	double m_prise;
	cout << "请输入产品编号" << endl;
	cin >> m_No;
	cout << "请输入要添加的产品名称" << endl;
	cin >> m_name;
	cout << "请输入它的价格" << endl;
	cin >> m_prise;
	
	Commodity c;
	c.No = m_No;
	c.name = m_name;
	c.prise = m_prise;

	vCommodity.push_back(c);
	cout << "---------------" << endl;

	//写入产品
	ofstream ofs;
	ofs.open("menu.txt", ios::trunc);//ios::trunc 如果文件存在，把文件长度设为0
	
	for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
	{
		ofs << it->No << " " << it->name << " " << it->prise;
	}
	ofs.close();

	cout << "添加成功" << endl;
}

//修改商品数量和价格
void Back_stage_management::change()
{
	cout << "修改商品" << endl;
	string m_name, m_No;
	double m_prise;
	cout << "请输入产品编号" << endl;
	cin >> m_No;
	cout << "请输入要修改的产品名称" << endl;
	cin >> m_name;
	cout << "请输入它的价格" << endl;
	cin >> m_prise;

	for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
	{
		if (it->No == m_No)
		{
			it->name = m_name;
			it->prise = m_prise; 
		}
	}

	//写入文件
	ofstream ofs;
	ofs.open("menu.txt", ios::trunc);
	for (vector<Commodity>::iterator it = vCommodity.begin(); it != vCommodity.end(); it++)
	{
		ofs << it->No << " " << it->name << " " << it->prise << endl;
	}
	ofs.close();

	cout << "修改成功" << endl;

}

//删除商品
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
	cout << "剩余的商品数量是" << vCommodity.size()<<endl;

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

//登录
void Back_stage_management::manage_login()//管理员登录
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