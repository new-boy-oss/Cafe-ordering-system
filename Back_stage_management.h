//后台管理
#include"Commodity.h"
#include"Interface.h"
#include "Orderin.h"
#include "OrderOut.h"
#include<fstream>
#include<vector>
#include<map>
#pragma once
class Back_stage_management: virtual public Order, public Interface
{
public:
	vector<Order> vOrder;
	vector<Commodity> vCommodity;
	void manage_login();//管理员登录
	void login_choice();//登陆成功后的操作选择

	void show();//展示所有商品信息
	void add_product();//添加商品
	void change();//修改商品数量和价格

	void vip_information_maintenance();//会员信息维护
	int get_row_number_menu();//获取商品文件行数

	
	void UpdateOrder();//更新订单
	void displayOrder();//显示订单
	void SeekOrder();//查找订单
	void DeleteAllOrder();//删除全部订单
	void DeleteoneOrder();//删一个
	//存储堂食订单的信息
	map<string, vector<Orderin>> mOI;
	vector<Orderin> vOI;

	//存储外卖订单的信息
	map<string, vector<OrderOut>> mOO;
	vector<OrderOut> vOO;

	//存储临时的从文件中读入的信息
	vector<string> vinfo;

	Back_stage_management();
	~Back_stage_management();
	//void delete_product();//删除商品
	//void DeleteoneOrder();//删除一个订单
private:
	string manage_account;//管理员账号
	string manage_key;//管理员密码
};

