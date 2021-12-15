#pragma once
#include"Interface.h"
#include"Back_stage_management.h"
#include"VIP.h"
using namespace std;


Interface::Interface()
{
	//
}

Interface::~Interface()
{
}

void Interface::gbiao(int x, int y)
{
	while (!_kbhit())//判断是否有键盘事键，若无，光标闪烁
	{
		setlinecolor(RGB(0, 0, 0));
		setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE, 1);
		//setrop2(R2_XORPEN); //设置异或绘图方式
		line(x, y, x, y + 20);
		Sleep(400);
		setlinecolor(WHITE);
		line(x, y, x, y + 20);
		Sleep(400);
	}
}



//主界面
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
	while (1)
	{
		m = getmessage();//获取鼠标操作

		//用户点餐
		if (m.x >= 650 && m.x <= 850 && m.y >= 80 && m.y <= 180) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				cleardevice();
				//跳转到商品展示界面
				show_product();
				break;
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
				break;
			}
		}
	}
	system("pause");
}

//商品栏界面
void Interface::inferface2()
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

string Interface::getNo()
{
	if (temp == 1)
	{
		return pro[0].No;

	}
	else if (temp == 2)
	{
		return pro[1].No;
	}
	else if (temp == 3)
	{
		return pro[2].No;
	}
	else if (temp == 4)
	{
		return pro[3].No;
	}
	else if (temp == 5)
	{
		return pro[4].No;
	}
	else if (temp == 6)
	{
		return pro[5].No;
	}
	else if (temp == 7)
	{
		return pro[6].No;
	}
	else if (temp == 8)
	{
		return pro[7].No;
	}
	else if (temp == 9)
	{
		return pro[8].No;
	}
	else if (temp == 10)
	{
		return pro[9].No;

	}
	else if (temp == 11)
	{
		return pro[10].No;
	}
	else if (temp == 12)
	{
		return pro[11].No;
	}
}

string Interface::getName()
{
	if (temp == 1)
	{
		return pro[0].Name;

	}
	else if (temp == 2)
	{
		return pro[1].Name;
	}
	else if (temp == 3)
	{
		return pro[2].Name;
	}
	else if (temp == 4)
	{
		return pro[3].Name;
	}
	else if (temp == 5)
	{
		return pro[4].Name;
	}
	else if (temp == 6)
	{
		return pro[5].Name;
	}
	else if (temp == 7)
	{
		return pro[6].Name;
	}
	else if (temp == 8)
	{
		return pro[7].Name;
	}
	else if (temp == 9)
	{
		return pro[8].Name;
	}
	else if (temp == 10)
	{
		return pro[9].Name;

	}
	else if (temp == 11)
	{
		return pro[10].Name;
	}
	else if (temp == 12)
	{
		return pro[11].Name;
	}
}

int Interface::getPrise()
{
	if (temp == 1)
	{
		return pro[0].prise;

	}
	else if (temp == 2)
	{
		return pro[1].prise;
	}
	else if (temp == 3)
	{
		return pro[2].prise;
	}
	else if (temp == 4)
	{
		return pro[3].prise;
	}
	else if (temp == 5)
	{
		return pro[4].prise;
	}
	else if (temp == 6)
	{
		return pro[5].prise;
	}
	else if (temp == 7)
	{
		return pro[6].prise;
	}
	else if (temp == 8)
	{
		return pro[7].prise;
	}
	else if (temp == 9)
	{
		return pro[8].prise;
	}
	else if (temp == 10)
	{
		return pro[9].prise;

	}
	else if (temp == 11)
	{
		return pro[10].prise;
	}
	else if (temp == 12)
	{
		return pro[11].prise;
	}
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
				break;
			}
		}
		//咖啡
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
				break;
			}
		}
		//奶茶
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
				break;
			}
		}
		//果茶
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
				break;
			}
		}

		//蛋糕
		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
				break;
			}
		}
		//返回主界面
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
				break;
			}
		}
	}
}

/*
void Interface::chance(int temp1)
{
	if (temp1 == 1)
	{
		no = pro[0].No;
		name = pro[0].Name;
		Prise = pro[0].prise;

	}
	else if (temp1 == 2)
	{
		no = pro[1].No;
		name = pro[1].Name;
		Prise = pro[1].prise;
	}
	else if (temp1 == 3)
	{
		no = pro[2].No;
		name = pro[2].Name;
		Prise = pro[2].prise;
	}
	else if (temp1 == 4)
	{
		no = pro[3].No;
		name = pro[3].Name;
		Prise = pro[3].prise;
	}
	else if (temp1 == 5)
	{
		no = pro[4].No;
		name = pro[4].Name;
		Prise = pro[4].prise;
	}
	else if (temp1 == 6)
	{
		no = pro[5].No;
		name = pro[5].Name;
		Prise = pro[5].prise;
	}
	else if (temp1 == 7)
	{
		no = pro[6].No;
		name = pro[6].Name;
		Prise = pro[6].prise;
	}
	else if (temp1 == 8)
	{
		no = pro[7].No;
		name = pro[7].Name;
		Prise = pro[7].prise;
	}
	else if (temp1 == 9)
	{
		no = pro[8].No;
		name = pro[8].Name;
		Prise = pro[8].prise;;
	}
	else if (temp1 == 10)
	{
		no = pro[9].No;
		name = pro[9].Name;
		Prise = pro[9].prise;

	}
	else if (temp1 == 11)
	{
		no = pro[10].No;
		name = pro[10].Name;
		Prise = pro[10].prise;
	}
	else if (temp1 == 12)
	{
		no = pro[11].No;
		name = pro[11].Name;
		Prise = pro[11].prise;
	}
}
*/

//选择规格界面
void Interface::specifications()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(330, 200, 830, 540, 30, 30);
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
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();
				break;
			}
		}
		else if (m.x >= 650 && m.x <= 850 && m.y >= 490 && m.y <= 540) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(getPrise());
				break;
			}
		}
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
		else if (m.x >= 420 && m.x <= 470 && m.y >= 430 && m.y <= 455) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(735, 375, 800, 405);
				settextstyle(25, 0, "楷体");
				setbkmode(TRANSPARENT);// 去掉文字背景
				settextcolor(RGB(0, 0, 15));
				char delivery[20] = "自提";
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

//vip注册界面   //改动
void Interface::VIP_register()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(400, 240, 850, 500, 30, 30);
	fillrectangle(500, 340, 800, 380);
	//fillrectangle(500, 400, 800, 440);
	fillroundrect(780, 510, 940, 560, 30, 30);
	setlinecolor(BLACK);
	//line(400, 290, 850, 290);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(540, 250, "会员注册");
	//outtextxy(410, 345, "账号");
	//outtextxy(410, 405, "密码");
	outtextxy(820, 520, "返回");
	outtextxy(500, 345, "开始");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 780 && m.x <= 940 && m.y >= 510 && m.y <= 560) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);//清空矩形区域
				VIP_show();//返回上一界面
				break;
			}
		}
		if (m.x >= 500 && m.x <= 800 && m.y >= 340 && m.y <= 380) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				cleardevice();
				VIP a;
				a.vip_register();
				show_product();
				break;
			}
		}
	}


}

//vip登录界面   //改动
void Interface::VIP_login()
{
	ExMessage m;//鼠标
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(400, 240, 850, 500, 30, 30);
	fillrectangle(500, 340, 800, 380);
	//fillrectangle(500, 400, 800, 440);
	fillroundrect(780, 510, 940, 560, 30, 30);
	setlinecolor(BLACK);
	//line(400, 290, 850, 290);
	settextstyle(35, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(540, 250, "会员注册");
	//outtextxy(410, 345, "账号");
	//outtextxy(410, 405, "密码");
	outtextxy(820, 520, "返回");
	outtextxy(500, 345, "开始");
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 780 && m.x <= 940 && m.y >= 510 && m.y <= 560) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);//清空矩形区域
				VIP_show();//返回上一界面
				break;
			}
		}
		if (m.x >= 500 && m.x <= 800 && m.y >= 340 && m.y <= 380) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				cleardevice();
				VIP a;
				a.vip_login();
				show_product();
				break;
			}
		}
	}
}

//商品展示
void Interface::show_product()
{
	inferface2();
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
				break;
			}
		}
		else if (m.x >= 630 && m.x <= 830 && m.y >= 300 && m.y <= 440)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_login();
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
				break;
			}
		}

		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
				break;
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
	settextstyle(25, 0, "楷体");
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	outtextxy(330, 170, pro[0].No.c_str());
	outtextxy(330, 270, pro[1].No.c_str());
	outtextxy(330, 370, pro[2].No.c_str());
	outtextxy(390, 170, pro[0].Name.c_str());
	outtextxy(390, 270, pro[1].Name.c_str());
	outtextxy(390, 370, pro[2].Name.c_str());
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	char c1[20], c2[20], c3[20], c4[20], c5[20], c6[20];
	sprintf_s(c1, " % d", pro[0].number);
	sprintf_s(c2, " % d", pro[1].number);
	sprintf_s(c3, " % d", pro[2].number);
	sprintf_s(c4, " % d", pro[0].prise);
	sprintf_s(c5, " % d", pro[1].prise);
	sprintf_s(c6, " % d", pro[2].prise);
	outtextxy(320, 220, "货存： ");
	outtextxy(320, 320, "货存： ");
	outtextxy(320, 420, "货存： ");
	outtextxy(350, 220, c1);
	outtextxy(350, 320, c2);
	outtextxy(350, 420, c3);
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格： ");
	outtextxy(800, 310, "价格： ");
	outtextxy(800, 410, "价格： ");
	outtextxy(840, 210, c4);
	outtextxy(840, 310, c5);
	outtextxy(840, 410, c6);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 1;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 2;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 3;
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
				break;
			}
		}

		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
				break;
			}

		}
		temp = 0;
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
	outtextxy(330, 170, pro[3].No.c_str());
	outtextxy(330, 270, pro[4].No.c_str());
	outtextxy(330, 370, pro[5].No.c_str());
	outtextxy(390, 170, pro[3].Name.c_str());
	outtextxy(390, 270, pro[4].Name.c_str());
	outtextxy(390, 370, pro[5].Name.c_str());
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	char c1[20], c2[20], c3[20], c4[20], c5[20], c6[20];
	sprintf_s(c1, " % d", pro[3].number);
	sprintf_s(c2, " % d", pro[4].number);
	sprintf_s(c3, " % d", pro[5].number);
	sprintf_s(c4, " % d", pro[3].prise);
	sprintf_s(c5, " % d", pro[4].prise);
	sprintf_s(c6, " % d", pro[5].prise);
	outtextxy(320, 220, "货存： ");
	outtextxy(320, 320, "货存： ");
	outtextxy(320, 420, "货存： ");
	outtextxy(350, 220, c1);
	outtextxy(350, 320, c2);
	outtextxy(350, 420, c3);
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格： ");
	outtextxy(800, 310, "价格： ");
	outtextxy(800, 410, "价格： ");
	outtextxy(840, 210, c4);
	outtextxy(840, 310, c5);
	outtextxy(840, 410, c6);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 4;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 5;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 6;
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
				break;
			}
		}

		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
				break;
			}
		}
		temp = 0;
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
	outtextxy(330, 170, pro[6].No.c_str());
	outtextxy(330, 270, pro[7].No.c_str());
	outtextxy(330, 370, pro[8].No.c_str());
	outtextxy(390, 170, pro[6].Name.c_str());
	outtextxy(390, 270, pro[7].Name.c_str());
	outtextxy(390, 370, pro[8].Name.c_str());
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	char c1[20], c2[20], c3[20], c4[20], c5[20], c6[20];
	sprintf_s(c1, " % d", pro[6].number);
	sprintf_s(c2, " % d", pro[7].number);
	sprintf_s(c3, " % d", pro[8].number);
	sprintf_s(c4, " % d", pro[6].prise);
	sprintf_s(c5, " % d", pro[7].prise);
	sprintf_s(c6, " % d", pro[8].prise);
	outtextxy(320, 220, "货存： ");
	outtextxy(320, 320, "货存： ");
	outtextxy(320, 420, "货存： ");
	outtextxy(350, 220, c1);
	outtextxy(350, 320, c2);
	outtextxy(350, 420, c3);
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格： ");
	outtextxy(800, 310, "价格： ");
	outtextxy(800, 410, "价格： ");
	outtextxy(840, 210, c4);
	outtextxy(840, 310, c5);
	outtextxy(840, 410, c6);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 7;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 8;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();//跳转到选择规格界面
				temp = 9;
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
				break;
			}
		}

		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
				break;
			}
		}
		temp = 0;
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
	outtextxy(330, 170, pro[9].No.c_str());
	outtextxy(330, 270, pro[10].No.c_str());
	outtextxy(330, 370, pro[11].No.c_str());
	outtextxy(400, 170, pro[9].Name.c_str());
	outtextxy(400, 270, pro[10].Name.c_str());
	outtextxy(400, 370, pro[11].Name.c_str());
	setbkmode(TRANSPARENT);// 去掉文字背景
	settextcolor(RGB(0, 0, 15));
	settextstyle(15, 0, "楷体");
	char c1[20], c2[20], c3[20], c4[20], c5[20], c6[20];
	sprintf_s(c1, " % d", pro[9].number);
	sprintf_s(c2, " % d", pro[10].number);
	sprintf_s(c3, " % d", pro[11].number);
	sprintf_s(c4, " % d", pro[9].prise);
	sprintf_s(c5, " % d", pro[10].prise);
	sprintf_s(c6, " % d", pro[11].prise);
	outtextxy(320, 220, "货存： ");
	outtextxy(320, 320, "货存： ");
	outtextxy(320, 420, "货存： ");
	outtextxy(350, 220, c1);
	outtextxy(350, 320, c2);
	outtextxy(350, 420, c3);
	settextstyle(24, 0, "楷体");
	outtextxy(800, 210, "价格： ");
	outtextxy(800, 310, "价格： ");
	outtextxy(800, 410, "价格： ");
	outtextxy(840, 210, c4);
	outtextxy(840, 310, c5);
	outtextxy(840, 410, c6);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 200 && m.x <= 980 && m.y >= 150 && m.y <= 250) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				temp = 10;
				pay_show(getPrise());//跳转到支付界面
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 250 && m.y <= 350) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				temp = 11;
				pay_show(getPrise());//跳转到支付界面
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 980 && m.y >= 350 && m.y <= 450) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				temp = 12;
				pay_show(getPrise());//跳转到支付界面
				break;
			}

		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 150 && m.y <= 220) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				VIP_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 220 && m.y <= 290)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				coffee_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 290 && m.y <= 360)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				milktea_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 360 && m.y <= 430)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				fruittea_show();//响应功能
				break;
			}
		}

		else if (m.x >= 20 && m.x <= 200 && m.y >= 430 && m.y <= 500)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				cake_show();//响应功能
				break;
			}
		}
		else if (m.x >= 20 && m.x <= 200 && m.y >= 500 && m.y <= 580)//检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				inferface();//响应功能
				break;
			}
		}
		temp = 0;
	}
	system("pause");
}

//支付界面
void Interface::pay_show(int a)
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
	outtextxy(580, 300, "元");
	char c1[20];
	sprintf_s(c1, " % d", a);
	outtextxy(520, 300, c1);
	while (1)
	{
		m = getmessage();//获取鼠标操作
		if (m.x >= 340 && m.x <= 520 && m.y >= 300 && m.y <= 440) //检测鼠标的位置 是否满足条件
		{

			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				WeChat_pay();
				break;
			}
		}
		else if (m.x >= 640 && m.x <= 820 && m.y >= 300 && m.y <= 440) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				Alipay_pay();
				break;
			}
		}
		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				specifications();
				break;
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
				break;
			}
		}

		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(getPrise());
				break;
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
				break;
			}
		}
		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				pay_show(getPrise());
				break;
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
				break;
			}
		}
		else if (m.x >= 350 && m.x <= 450 && m.y >= 490 && m.y <= 535) //检测鼠标的位置 是否满足条件
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				clearrectangle(201, 151, 979, 579);
				show_product();
				break;
			}
		}
	}
}





