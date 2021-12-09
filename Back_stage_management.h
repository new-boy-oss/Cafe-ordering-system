//后台管理
#include"Commodity.h"
#include<fstream>
#include<vector>
#pragma once
class Back_stage_management:public Commodity
{
public:
	vector<Commodity> vCommodity;
	void manage_login(string m_manage_account, string m_manage_key);//管理员登录
	void show();//展示所有
	void add_product();//添加商品
	void delete_product();//删除商品
	void change();//修改商品数量和价格
	void SetDiscount();//设置折扣
	Back_stage_management();
	~Back_stage_management();
private:
	string manage_account;//管理员账号
	string manage_key;//管理员密码
};

