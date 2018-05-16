#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.h"
#include "info.h"
#include "adminUI.h"
#include "userUI.h"

using namespace std;
void Isuser(string infoNcut[100], string infoPcut[100], string uname, string upass);

void USign(string uname, string upass) {//登陆
	//Loginfo sinfo;
	ifstream infile;
	infile.open("Userinfo.txt");//打开需要读取的文件
	int lineCount = 0;//读取的行数
	int nLen = uname.size();//uname的长度
	int pLen = upass.size();//upass的长度
	string infoNcut[100];//存放截取到的name
	string infoPcut[100];//存放截取到的pass
	string infostr[100];//存放从文件读取到的信息
	/*string *iNcut = infoNcut;
	string *iPcut = infoPcut;*/
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//按行读取信息
		
		//infostr[lineCount] << infile;
		infoNcut[lineCount-1] = infostr[lineCount].substr(0,nLen);//截取name
		infoPcut[lineCount-1] = infostr[lineCount].substr(nLen,pLen+1);//截取pass
	}
	infile.close();//关闭文件连接
	Isuser(infoNcut, infoPcut,uname, upass);//对是否是注册人员进行判断
	
}

void Isuser(string infoNcut[100],string infoPcut[100],string uname,string upass) {
	int loginCount = 0;
	bool Isreg = false;
	for (int i = 0; i < infoNcut->size(); i++) {
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
		if (infoNcut[i]._Equal(uname)) {//是否有这个人
			if (infoPcut[i]._Equal(upass)) {//密码对不
				cout << "*****欢迎" << uname << "登陆天朝图书馆******" << endl;
				userUiMain(uname);
				break;
			}
			else {
				cout << "用户名或者密码错误！" << endl;//提示密码错误

				loginCount++;
			}
		}
		else {
			cout << "对不起该用户还未注册，是否注册？1：是，0；否。" << endl;
			int re;
			cin >> re;
			if (re == 1) {
				Uregist();//没有这个人提示是否要注册
				break;
			}
			else {

				break;
			}
		}
	}
	if (loginCount > 15) {//登陆限制
		cout << "对不起尝试登录次数过多，即将退出系统！" << endl;
		exit(5);
	}
}



