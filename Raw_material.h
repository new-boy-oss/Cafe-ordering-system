//制作咖啡的原材料
#pragma once
#include<string>
using namespace std;
class Raw_material
{
public:
	Raw_material();
	~Raw_material();
	int raw_coffee, suger, ice, milk, cup;//原材料的数量，在构造函数里初始化
private:
};
