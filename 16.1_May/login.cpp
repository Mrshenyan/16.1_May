#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.h"
#include "info.h"
#include "adminUI.h"
#include "userUI.h"

using namespace std;
//void Isuser(string infoNcut[100], string infoPcut[100], string uname, string upass);
void Isuser(string *infoNcut, string *infoPcut, string uname, string upass,int lineCount);
//bool adminFlag = false;


void USign(string uname, string upass) {//登陆
	ifstream infile;
	infile.open("Userinfo.txt");//打开需要读取的文件
	int lineCount = 0;//读取的行数
	int nLen = uname.size();//uname的长度
	int pLen = upass.size();//upass的长度
	string infoNcut[100];//存放截取到的name
	string infoPcut[100];//存放截取到的pass
	string infostr[100];//存放从文件读取到的信息
	int NcutLen, PcutLen;
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//按行读取信息
		infoNcut[lineCount-1] = infostr[lineCount].substr(0,nLen);//截取name
		infoPcut[lineCount-1] = infostr[lineCount].substr(nLen,pLen+1);//截取pass,这里有时会出现一个Run-Time#0的错误
	}
	infile.close();//关闭文件连接
	NcutLen = infoNcut->length();
	PcutLen = infoPcut->size();
	Isuser(infoNcut, infoPcut,uname, upass,lineCount);//对是否已注册/管理员进行判断
	//return;
}

void Isuser(string *infoNcut,string *infoPcut,string uname,string upass,int lineCount) {//这里要说明指针加1
	int loginCount = 0;
	//bool Isreg = false;
	int IsEnSM = 0;
	int re = 0;
	int i = 0;
	for (; i < lineCount; i++) {
		//for (int j = 0; j < infoPcut->size(); j++) {
		//	if ((infoNcut->_Equal(uname)) && (infoPcut->_Equal(upass))) {
		//		cout << "*****欢迎" << uname << "登陆天朝图书馆******" << endl;
		//		break;
		//	}
		//	else {
		//		cout << "用户名或者密码错误！" << endl;
		//		loginCount++;
		//		break;
		//	}
		//}
		if ((infoNcut+i)->_Equal(uname)) {//是否有这个人
			if ((infoPcut+i)->_Equal(upass)) {//密码对不
				re = 1;
				cout << "                                                                                            " << endl;
				cout << "********欢迎" << uname << "登陆天朝图书馆*********" << endl;
				if (infoNcut[i] == "admin") {
					//adminFlag = true;
					cout << "是否进入系统管理模块？1：是，0，否";
					cin >> IsEnSM;
					if (IsEnSM == 1) {
						SystemManage();//系统后台管理里
						break;
					}
				}
				userUiMain(uname);//普通用户登陆成功界面
				break;
			}
			else {
				cout << "用户名或者密码错误！" << endl;//提示密码错误
				SignUp();
				loginCount++;
			}
		}
	}
	if (re == 0) {
		cout << "对不起该用户还未注册，是否注册？" << endl;
		cout << "1：是，0；否。:";
		int zhuce = 0;
		cin >> zhuce;
		if (zhuce == 1) {
			Uregist();//没有这个人提示是否要注册注册结束调用登陆程序
		}
		else {
			SignUp();
		}
	}
	if (loginCount > 15) {//登陆限制
		cout << "对不起尝试登录次数过多，即将退出系统！" << endl;
		exit(5);
	}
}

void SignUp() {
	Loginfo linfo;
	//ofstream outfile;
	ifstream infile;
	//outfile.open("Userinfo.txt");
	infile.open("Userinfo.txt");
	cout << "***************************************" << endl;
	cout << setw(30) << "欢迎进入天朝图书管理系统" << setw(8) << endl;
	cout << "***************************************" << endl;
	cout << "请输入用户名：";
	cin >> linfo.Lname;
	cout << "请输入密码：";
	cin >> linfo.Lpass;
	USign(linfo.Lname, linfo.Lpass);//登陆程序
	//outfile.close();
	infile.close();
}


