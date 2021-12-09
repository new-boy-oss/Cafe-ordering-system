//会员类
#pragma once
#include<string>
using namespace std;
class VIP
{
public:
	void vip_register();//注册
	void vip_login();//登录
	void vip_find_key();//找回密码
	VIP();
	~VIP();
private:
	string vip_account;//账号
	string vip_key;//密码
	string vip_name;//会员姓名
	string vip_Phone_number;//电话号
	string vip_number;//编号
};
