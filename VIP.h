//»áÔ±Àà
#pragma once
#include<string>
using namespace std;
class VIP
{
public:
	void vip_register();//×¢²á
	void vip_login();//µÇÂ¼
	void vip_find_key();//ÕÒ»ØÃÜÂë
	VIP();
	~VIP();
private:
	string vip_account;//ÕËºÅ
	string vip_key;//ÃÜÂë
	string vip_name;
	string vip_Phone_number;
	string vip_number;//±àºÅ
};
