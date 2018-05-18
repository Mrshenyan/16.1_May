#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include "adminUI.h"

using namespace std;
using std::setw;
int adConFlag = 0;
void SystemManage() {
	string delUname;
	cout << "*********************************************" << endl;
	cout << "                                             " << endl;
	cout << "      欢迎管理员来到天朝图书馆管理系统      " << endl;
	cout << "                                             " << endl;
	cout << "*********************************************" << endl;
	cout << "1.用户管理" << endl;
	cout << "2.书籍管理" << endl;
	cout << "*********************************************" << endl;
	cout << "请选择你要进行的操作：";
	cin >> adConFlag;
	switch (adConFlag)
	{
	case 1: {
		DelUser();
		

	}
		break;
	case 2:bookManage();
		break;
	default:
		break;
	}
};

void DelUser() {
	string delname;
	ifstream infile;
	ofstream outfile;
	infile.open("Userinfo.txt");//打开需要读取的文件
	outfile.open("Userinfo.txt");
	int lineCount = 0;//读取的行数
	int nLen = delname.size();//delname的长度
	//int pLen = upass.size();//upass的长度
	string infoNcut[100];//存放截取到的name
	string infoPcut[100];//存放截取到的pass
	string infostr[100];//存放从文件读取到的信息
	vector<string>delbuf;
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//按行读取信息
		infoNcut[lineCount - 1] = infostr[lineCount - 1].substr(0, nLen);
		delbuf.push_back(infostr[lineCount - 1]);
		cout << infostr[lineCount - 1] << endl;
	}
	cout << "请输入要删除的用户名：";
	cin >> delname;
	for (int i = 0; i < infoNcut->size();i++) {
		if (delname._Equal(infoNcut[i])) {
			delbuf[i].erase();
		}
		else
		{
			cout << "找不到该用户" << endl;
		}
	}
	for (int i=0;i<delbuf.size();i++)
	{
		outfile << delbuf[i];
	}
	infile.close();//关闭文件连接
	outfile.close();
}
