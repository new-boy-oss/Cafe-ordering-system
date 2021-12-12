#pragma once
#include"Interface.h"
#include"Back_stage_management.h"
using namespace std;

Interface::Interface()
{
	char* No[12] = {};//编号
	char* name[12] = {};//咖啡的名字，比如：拿铁，美式等
	int prise[12] = {};//价格
	int number[12] = {};//数量
	char NO[20] = {};
	string Name[12] = {};
	string Prise[12] = {};
	char weight[20] = {};
	char temperature[20] = {};
	char suger[20] = {};
	char delivery[20] = {};
}

Interface::~Interface()
{
}

//用户点餐或管理员登陆
void Interface::admin_login_OR_guest_choice()
{
	while (1)
	{
		ExMessage m;//鼠标
		m = getmessage();//获取鼠标操作

		//用户点餐
		if (m.x >= 650 && m.x <= 850 && m.y >= 80 && m.y <= 180) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				cleardevice();
				//跳转到商品展示界面
				show_product();
			}
		}

		//管理员登陆
		else if (m.x >= 650 && m.x <= 850 && m.y >= 240 && m.y <= 340) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				closegraph();
				initgraph(800, 600, SHOWCONSOLE);//跳转到管理员控制界面
				closegraph();
				//管理员登陆界面开启，图形化界面关闭
				Back_stage_management a;
				a.manage_login();
			}
		}
	}
}

//主界面（用户点餐或管理员登陆）
void Interface::inferface()
{
	ExMessage m;//鼠标
	IMAGE img;// 定义图像对象
	initgraph(1000, 600);
	loadimage(&img, _T("界面.jpg"), 1000, 600);//背景
	putimage(0, 0, &img);
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(650, 80, 850, 180, 30, 30);
	fillroundrect(650, 240, 850, 340, 30, 30);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(660, 110, "用户点餐");
	outtextxy(660, 270, "管理员登录");

	//用户点餐or管理员登陆
	admin_login_OR_guest_choice();

	system("pause");
}

//商品栏界面
void Interface::inferface_product()
{
	IMAGE img;
	initgraph(1000, 600);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	line(20, 15, 980, 15);
	line(20, 15, 20, 580);
	line(20, 580, 980, 580);
	line(980, 580, 980, 15);
	line(20, 150, 980, 150);
	loadimage(&img, _T("欢迎光临.jpg"), 290, 120);
	putimage(200, 25, &img);
	loadimage(&img, _T("coffee.jpg"), 290, 120);
	putimage(500, 25, &img);
	line(200, 150, 200, 580);
	line(20, 220, 200, 220);
	line(20, 290, 200, 290);
	line(20, 360, 200, 360);
	line(20, 430, 200, 430);
	line(20, 500, 200, 500);
	settextstyle(45, 0, _T("楷体"));
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(60, 170, "会员");
	outtextxy(60, 240, "咖啡");
	outtextxy(60, 310, "奶茶");
	outtextxy(60, 380, "果茶");
	outtextxy(60, 450, "蛋糕");
	outtextxy(60, 520, "返回");

}

//选择跳转界面
void Interface::choice()
{
	ExMessage m;//鼠标
	while (1)
	{
		m = getmessage();//获取鼠标操作
		//会员（选择登录还是注册）
		if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
			}
		}
		//咖啡
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
			}
		}
		//奶茶
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
			}
		}
		//果茶
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
			}
		}
		//蛋糕
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
			}
		}
		//返回主界面
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
			}
		}
	}
}

//选择规格界面
void Interface::specifications(int temp = 0)
{
	int temp1 = temp;
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 200, 830, 540, 30, 30);// 画填充圆角矩形(有边框)
	fillroundrect(340, 280, 390, 305, 10, 10);
	fillroundrect(420, 280, 470, 305, 10, 10);
	fillroundrect(340, 330, 390, 355, 10, 10);
	fillroundrect(420, 330, 470, 355, 10, 10);
	fillroundrect(500, 330, 550, 355, 10, 10);
	fillroundrect(340, 380, 390, 405, 10, 10);
	fillroundrect(420, 380, 470, 405, 10, 10);
	fillroundrect(340, 430, 390, 455, 10, 10);
	fillroundrect(420, 430, 470, 455, 10, 10);
	fillroundrect(350, 490, 450, 535, 15, 15);
	fillroundrect(650, 490, 820, 535, 15, 15);
	setlinecolor(BLACK);
	line(330, 240, 830, 240);
	line(330, 470, 830, 470);
	line(600, 240, 600, 470);
	line(600, 270, 830, 270);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(490, 205, "选择规格");
	settextstyle(30, 0, "楷体");
	outtextxy(650, 240, "已选规格");
	settextstyle(20, 0, "楷体");
	outtextxy(340, 260, "份量");
	outtextxy(340, 310, "温度");
	outtextxy(340, 360, "糖度");
	outtextxy(340, 410, "配送方式");
	outtextxy(345, 283, "大杯");
	outtextxy(425, 283, "小杯");
	outtextxy(345, 333, "常温");
	outtextxy(425, 333, "加冰");
	outtextxy(515, 333, "热");
	outtextxy(345, 383, "加糖");
	outtextxy(425, 383, "无糖");
	outtextxy(345, 433, "外卖");
	outtextxy(425, 433, "自提");
	settextstyle(40, 0, "楷体");
	outtextxy(360, 493, "返回");
	outtextxy(655, 493, "确认支付");

	//展示页面 
	while (1)
	{
		//coffee
		m = getmessage();//获取鼠标操作
		if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();
			}
		}

		//pay方式
		else if (m.x >= 650 && m.x <= 850 && m.y >= 490 && m.y <= 540) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(temp1);
				break;
			}
		}

		//大杯
		else if (m.x >= 340 && m.x <= 390 && m.y >= 280 && m.y <= 305) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 285, 730, 315);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char weight[20] = { "大杯" };
				outtextxy(680, 285, weight);
			}
		}

		//小杯
		else if (m.x >= 420 && m.x <= 470 && m.y >= 280 && m.y <= 305) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 285, 730, 315);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char weight[20] = "小杯";
				outtextxy(680, 285, weight);
			}
		}

		//常温
		else if (m.x >= 340 && m.x <= 390 && m.y >= 330 && m.y <= 355) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 315, 730, 345);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char temperature[20] = "常温";
				outtextxy(680, 315, temperature);
			}
		}

		//加冰
		else if (m.x >= 420 && m.x <= 470 && m.y >= 330 && m.y <= 355) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 315, 730, 345);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char temperature[20] = "加冰";
				outtextxy(680, 315, temperature);
			}
		}

		//热
		else if (m.x >= 500 && m.x <= 550 && m.y >= 330 && m.y <= 355) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 315, 730, 345);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char temperature[20] = "热";
				outtextxy(680, 315, temperature);

			}
		}

		//加糖
		else if (m.x >= 340 && m.x <= 390 && m.y >= 380 && m.y <= 405) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 345, 730, 375);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char suger[20] = "加糖";
				outtextxy(680, 345, suger);
			}

		}

		//无糖
		else if (m.x >= 420 && m.x <= 470 && m.y >= 380 && m.y <= 405) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(675, 345, 730, 375);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char suger[20] = "无糖";
				outtextxy(680, 345, suger);
			}
		}

		//外卖
		else if (m.x >= 340 && m.x <= 390 && m.y >= 430 && m.y <= 455) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(735, 375, 800, 405);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char delivery[20] = "外卖";
				outtextxy(740, 375, delivery);
			}
		}

		//堂食
		else if (m.x >= 420 && m.x <= 470 && m.y >= 430 && m.y <= 455) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(735, 375, 800, 405);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char delivery[20] = "堂食";
				outtextxy(740, 375, delivery);
			}
		}


		settextstyle(30, 0, "楷体");
		setbkmode(TRANSPARENT);// 去掉文字背景
		settextcolor(RGB(0, 0, 15));
		outtextxy(600, 280, "份量：");
		outtextxy(600, 310, "温度：");
		outtextxy(600, 340, "糖度：");
		outtextxy(600, 370, "配送方式：");


	}
}

//vip注册界面
void Interface::VIP_register()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(400, 240, 850, 500, 30, 30);
	fillrectangle(500, 340, 800, 380);
	fillrectangle(500, 400, 800, 440);
	fillroundrect(780, 510, 940, 560, 30, 30);
	setlinecolor(BLACK);
	line(400, 290, 850, 290);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(540, 250, "会员注册");
	outtextxy(410, 345, "账号");
	outtextxy(410, 405, "密码");
	outtextxy(820, 520, "返回");

	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 780 && m.x <= 940 && m.y >= 510 && m.y <= 560) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//返回上一界面
			}
		}
	}

}

//vip登录界面
void Interface::VIP_login()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(400, 240, 850, 500, 30, 30);
	fillrectangle(500, 340, 800, 380);
	fillrectangle(500, 400, 800, 440);
	fillroundrect(780, 510, 940, 560, 30, 30);
	setlinecolor(BLACK);
	line(400, 290, 850, 290);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(540, 250, "会员登录");
	outtextxy(410, 345, "账号");
	outtextxy(410, 405, "密码");
	outtextxy(820, 520, "返回");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 780 && m.x <= 940 && m.y >= 510 && m.y <= 560) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//返回上一界面
			}
		}
	}
}

//商品展示
void Interface::show_product()
{
	inferface_product();
	choice();
	system("pause");
}

//vip选择登陆or注册
void Interface::VIP_show()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 300, 530, 440, 30, 30);
	fillroundrect(630, 300, 830, 440, 30, 30);
	settextstyle(50, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(335, 340, "会员注册");
	outtextxy(635, 340, "会员登录");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 330 && m.x <= 530 && m.y >= 300 && m.y <= 440) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_register();
			}
		}
		else if (m.x >= 630 && m.x <= 830 && m.y >= 300 && m.y <= 440)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_login();
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
			}
		}

		//果汁
		/*
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
			}
		}
		
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruitjuice_show();//响应功能
			}
		}
		*/
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
			}
		}
	}
	system("pause");
}

//咖啡
void Interface::coffee_show()
{
	ExMessage m;//鼠标
	IMAGE img2, img3, img4;
	setlinecolor(BLACK);
	line(200, 250, 980, 250);
	line(200, 350, 980, 350);
	line(200, 450, 980, 450);
	line(300, 150, 300, 450);
	loadimage(&img2, _T("美式咖啡.jpg"), 99, 99);
	loadimage(&img3, _T("拿铁咖啡.jpg"), 99, 99);
	loadimage(&img4, _T("抹茶拿铁.jpg"), 99, 99);
	putimage(201, 151, &img2);
	putimage(201, 251, &img3);
	putimage(201, 351, &img4);
	//for (int i = 1; i < 4; i++)//输入咖啡的信息
	//{
		//cout << "请输入第" << i << "个咖啡的编号、名称、价格、数量：" << endl;
		//cin >> No[i] >> name[i] >> prise[i] >> number[i];
		//cout << "第" << i << "个咖啡的信息是：" << endl;
		//cout << "编号：" << No[i] << " " << "名称" << name[i] << " " << "价格" << prise[i] << " " << "数量" << number[i] << endl;

	//};
	//outtextxy(330, 200, No[1]);
	//outtextxy(330, 300, No[2]);
	//outtextxy(330, 400, No[3]);
	//outtextxy(350, 200, name[1]);
	//outtextxy(350, 300, name[2]);
	//outtextxy(350, 400, name[3]);
	//char c1[20],c2[20],c3[20],c4[20],c5[20],c6[20];
	//sprintf_s(c1, " % d", prise[1]);
	//sprintf_s(c2, " % d", prise[2]);
	//sprintf_s(c3, " % d", prise[3]);
	//outtextxy(350, 230, prise[1]);
	//outtextxy(350, 330, prise[2]);
	//outtextxy(350, 430, prise[3]);
	//sprintf_s(c4, " % d", number[1]);
	//sprintf_s(c5, " % d", number[2]);
	//sprintf_s(c6, " % d", number[3]);
	//outtextxy(330, 230, number[1]);
	//outtextxy(330, 330, number[2]);
	//outtextxy(330, 430, number[3]);
	settextstyle(25, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(330, 170, "No1");
	outtextxy(330, 270, "No2");
	outtextxy(330, 370, "No3");
	outtextxy(380, 170, "美式咖啡");
	outtextxy(380, 270, "拿铁咖啡");
	outtextxy(380, 370, "抹茶拿铁");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	outtextxy(320, 220, "货存：30");
	outtextxy(320, 320, "货存：30");
	outtextxy(320, 420, "货存：30");
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格：10元");
	outtextxy(800, 310, "价格：13元");
	outtextxy(800, 410, "价格：15元");
	string Name[1] = { "美式咖啡" };
	string Prise[1] = { "10元" };
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				int temp;
				clearrectangle(201, 151, 979, 579);
				temp = 1;
				specifications(temp);//跳转到选择规格界面
				break;


			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				int temp;
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 2;
				specifications(temp);
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				int temp;
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 3;
				specifications(temp);
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
			}
		}
		//果茶
		/*
			else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruitjuice_show();//响应功能
			}
		}
		*/
		
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
			}
		}
	}
	system("pause");
}

//奶茶
void Interface::milktea_show()
{
	ExMessage m;//鼠标
	IMAGE img2, img3, img4;
	setlinecolor(BLACK);
	line(200, 250, 980, 250);
	line(200, 350, 980, 350);
	line(200, 450, 980, 450);
	line(300, 150, 300, 450);
	loadimage(&img2, _T("生椰桂花酿.jpg"), 99, 99);
	loadimage(&img3, _T("芋泥波波奶茶.jpg"), 99, 99);
	loadimage(&img4, _T("珍珠奶茶.jpg"), 99, 99);
	putimage(201, 151, &img2);
	putimage(201, 251, &img3);
	putimage(201, 351, &img4);
	settextstyle(25, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(330, 170, "No4");
	outtextxy(330, 270, "No5");
	outtextxy(330, 370, "No6");
	outtextxy(380, 170, "生椰桂花酿");
	outtextxy(380, 270, "芋泥波波奶茶");
	outtextxy(380, 370, "珍珠奶茶");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	outtextxy(320, 220, "货存：40");
	outtextxy(320, 320, "货存：40");
	outtextxy(320, 420, "货存：40");
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格：17元");
	outtextxy(800, 310, "价格：20元");
	outtextxy(800, 410, "价格：15元");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
			}
		}
		/*
			else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruitjuice_show();//响应功能
			}
		}
		*/
		
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
			}
		}
	}
	system("pause");
}

//果茶
void Interface::fruittea_show()
{
	ExMessage m;//鼠标
	IMAGE img2, img3, img4;
	setlinecolor(BLACK);
	line(200, 250, 980, 250);
	line(200, 350, 980, 350);
	line(200, 450, 980, 450);
	line(300, 150, 300, 450);
	loadimage(&img2, _T("快乐水果桶.jpg"), 99, 99);
	loadimage(&img3, _T("草莓清茶.jpg"), 99, 99);
	loadimage(&img4, _T("鲜百香果茶.jpg"), 99, 99);
	putimage(201, 151, &img2);
	putimage(201, 251, &img3);
	putimage(201, 351, &img4);
	settextstyle(25, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(330, 170, "No7");
	outtextxy(330, 270, "No8");
	outtextxy(330, 370, "No9");
	outtextxy(380, 170, "快乐水果桶");
	outtextxy(380, 270, "草莓清茶");
	outtextxy(380, 370, "鲜百香果茶");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	outtextxy(320, 220, "货存：45");
	outtextxy(320, 320, "货存：45");
	outtextxy(320, 420, "货存：45");
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格：25元");
	outtextxy(800, 310, "价格：19元");
	outtextxy(800, 410, "价格：19元");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
			}
		}
		/*
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruitjuice_show();//响应功能
			}
		}

		*/
		
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
			}
		}
	}
	system("pause");
}

//蛋糕
void Interface::cake_show()
{
	ExMessage m;//鼠标
	IMAGE img2, img3, img4;
	setlinecolor(BLACK);
	line(200, 250, 980, 250);
	line(200, 350, 980, 350);
	line(200, 450, 980, 450);
	line(300, 150, 300, 450);
	loadimage(&img2, _T("榴莲千层蛋糕.jpg"), 99, 99);
	loadimage(&img3, _T("草莓蛋糕.jpg"), 99, 99);
	loadimage(&img4, _T("提拉米苏.jpg"), 99, 99);
	putimage(201, 151, &img2);
	putimage(201, 251, &img3);
	putimage(201, 351, &img4);
	settextstyle(25, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(330, 170, "No13");
	outtextxy(330, 270, "No14");
	outtextxy(330, 370, "No15");
	outtextxy(390, 170, "榴莲千层蛋糕");
	outtextxy(390, 270, "草莓蛋糕");
	outtextxy(390, 370, "提拉米苏");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	outtextxy(320, 220, "货存：30");
	outtextxy(320, 320, "货存：30");
	outtextxy(320, 420, "货存：30");
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格：10元");
	outtextxy(800, 310, "价格：30元");
	outtextxy(800, 410, "价格：16元");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(2);//跳转到支付界面
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(2);//跳转到支付界面
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(2);//跳转到支付界面
			}

		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
			}
		}
		/*
			else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruitjuice_show();//响应功能
			}
		}
		*/
		
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
			}
		}
	}
	system("pause");
}

//支付界面
void Interface::pay_show(int temp1 = 0)
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 200, 830, 540, 30, 30);
	fillroundrect(340, 340, 520, 480, 30, 30);
	fillroundrect(640, 340, 820, 480, 30, 30);
	fillroundrect(350, 490, 450, 535, 15, 15);
	setlinecolor(BLACK);
	line(330, 240, 830, 240);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(490, 205, "支付界面");
	outtextxy(450, 250, "请选择支付方式");
	outtextxy(350, 380, "微信支付");
	outtextxy(645, 380, "支付宝支付");
	outtextxy(360, 493, "返回");
	settextstyle(25, 0, "楷体");
	outtextxy(400, 300, "您需要支付：");
	if (temp1 == 1)
	{
		settextstyle(25, 0, "楷体");
		setbkmode(TRANSPARENT);// 去掉文字背景
		settextcolor(RGB(0, 0, 15));
		outtextxy(500, 300, Prise[1].c_str());
	}
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 340 && m.x <= 520 && m.y >= 300 && m.y <= 440) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				WeChat_pay();
			}
		}
		else if (m.x >= 640 && m.x <= 820 && m.y >= 300 && m.y <= 440) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				Alipay_pay();
			}
		}
		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();
			}
		}
	}
}

//微信支付
void Interface::WeChat_pay()
{
	IMAGE img;
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 200, 830, 540, 30, 30);
	fillroundrect(350, 490, 450, 535, 15, 15);
	fillroundrect(690, 490, 790, 535, 15, 15);
	setlinecolor(BLACK);
	line(330, 240, 830, 240);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(490, 205, "微信支付");
	outtextxy(430, 250, "支付成功请点击确认");
	outtextxy(365, 493, "返回");
	outtextxy(705, 493, "确认");
	loadimage(&img, _T("微信支付.jpg"), 170, 170);//背景
	putimage(480, 300, &img);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 690 && m.x <= 790 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				order_show();
			}
		}

		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show();
			}
		}
	}
}

//支付宝支付
void Interface::Alipay_pay()
{
	IMAGE img;
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 200, 830, 540, 30, 30);
	fillroundrect(350, 490, 450, 535, 15, 15);
	fillroundrect(690, 490, 790, 535, 15, 15);
	setlinecolor(BLACK);
	line(330, 240, 830, 240);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(490, 205, "支付宝支付");
	outtextxy(430, 250, "支付成功请点击确认");
	outtextxy(365, 493, "返回");
	outtextxy(705, 493, "确认");
	loadimage(&img, _T("支付宝支付.jpg"), 170, 170);//背景
	putimage(480, 300, &img);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 690 && m.x <= 790 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				order_show();
			}
		}
		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show();
			}
		}
	}
}

//订单界面
void Interface::order_show()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 200, 830, 540, 30, 30);
	fillroundrect(350, 490, 450, 535, 15, 15);
	fillroundrect(690, 490, 790, 535, 15, 15);
	setlinecolor(BLACK);
	line(330, 240, 830, 240);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(490, 205, "订单界面");
	outtextxy(365, 493, "返回");
	outtextxy(705, 493, "收取");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 690 && m.x <= 790 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(350, 250, 800, 480);
				clearrectangle(690, 490, 790, 535);
				settextstyle(50, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				outtextxy(350, 280, "祝您用餐愉快！");
				Sleep(500);
				inferface();
			}
		}
		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				show_product();
			}
		}
	}
}