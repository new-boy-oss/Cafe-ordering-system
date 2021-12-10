//会员类,继承商品
#pragma once
#include"Commodity.h"
#include<string>
using namespace std;
class VIP:public Commodity
{
public:
	void vip_register();//注册
	void vip_login();//登录
	VIP();
	~VIP();
private:
	string vip_account;//账号
	string vip_key;//密码
	string vip_name;//会员姓名
	string vip_Phone_number;//电话号
	int vip_number;//编号
	int get_rows_number();//获取行数
};
