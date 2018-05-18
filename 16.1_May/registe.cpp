#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "registe.h"
#include "info.h"
void Uregist() {
	string reName;
	string rePass;
	string idPass;
	int Button;
	cout << "*************天朝图书馆注册*************" <<endl;
	cout << "　　　　　　　　　　　　　　　　　　" << endl;
	cout << "请输入用户名(4-8字符)：";
	cin >> reName;
	cout << "请输入密码：";
	cin >> rePass;
	cout << "请再输一遍密码：";
	cin >> idPass;
	cout << "按1确认注册，按0返回修改：";
	cin >> Button;
	switch (Button)
	{
	case 1: {
		if (!rePass._Equal(idPass)) {
			cout << "两次输入的密码不一样，请重新注册！"<<endl;
			Uregist();
		}
		else {
			WriteInfo(reName, rePass);
		}
	}
		break;
	case 0: {
		cout << "请重新输入用户名(4-8字符)：";
		cin >> reName;
		cout << "请重新输入密码：";
		cin >> rePass;
		cout << "请再输一遍密码：";
		cin >> idPass;
		cout << "按1确认注册，按0返回修改：";
		cin >> Button;
	}
	default:
		break;
	}
}

void WriteInfo(string wrName,string wrPass) {
	ifstream infile;
	infile.open("Userinfo.txt");//打开需要读取的文件
	ofstream upload;
	upload.open("Userinfo.txt",ios::app);
	int lineCount = 0;//读取的行数
	int nLen = wrName.size();//uname的长度
	int pLen = wrPass.size();//upass的长度
	string infoNcut[100];//存放截取到的name
	string infoPcut[100];//存放截取到的pass
	string infostr[100];//存放从文件读取到的信息
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//按行读取信息

											//infostr[lineCount] << infile;
		infoNcut[lineCount - 1] = infostr[lineCount].substr(0, nLen);//截取name
		if (infoNcut->_Equal(wrName)) {
			cout << "对不起该用户名已被注册" << endl;
			Uregist();
		}
		
	}
	//printf_s("\n");
	upload << (wrName+wrPass);
	infile.close();
	upload.close();
}