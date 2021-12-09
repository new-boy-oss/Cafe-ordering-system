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

void Back_stage_management::show()//展示所有原材料
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

void Back_stage_management::add_product()//添加产品
{
	string m_name;
	double m_prise = 0;
	cout << "请输入要添加的产品" << endl;
	cin >> m_name;
	cout << "请输入它的价格" << endl;
	cin >> m_prise;
	if (m_prise<=0)
	{
		cout << "添加失败" << endl;
	}
	else
	{
		cout << "添加成功" << endl;
		prise = m_prise;
	}
}

void Back_stage_management::change()//修改商品数量和价格
{
}

void Back_stage_management::manage_login(string m_manage_account,string m_manage_key)//管理员登录
{
	while (1)
	{
		cout << "请输入管理员账号" << endl;
		cin >> manage_account;
		cout << "请输入您的密码" << endl;
		cin >> manage_account;
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