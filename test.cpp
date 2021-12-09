//²âÊÔÎÄ¼ş
#include "Back_stage_management.h"
#include<iostream>
using namespace std;
int main()
{
	Back_stage_management a;
	
	a.manage_login();
	a.add_product();
	a.change();
	a.delete_product();
	a.show();
	return 0;
}