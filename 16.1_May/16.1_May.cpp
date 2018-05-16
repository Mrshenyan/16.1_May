// 16.1_May.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "login.h"
#include "info.h"
using namespace std;


int main()
{
	
	Loginfo linfo;
	ofstream outfile;
	ifstream infile;
	outfile.open("infoUser.txt");
	infile.open("infoUser.txt");
	cout << "***************************************" << endl;
	cout << setw(30) << "欢迎进入天朝图书管理系统" << setw(8) << endl;
	cout << "***************************************" << endl;
	cout << "请输入用户名：";
	cin >> linfo.Lname;
	cout << "请输入密码：";
	cin >> linfo.Lpass;
	USign(linfo.Lname,linfo.Lpass);//登陆程序
	system("pause");
    return 0;
}

