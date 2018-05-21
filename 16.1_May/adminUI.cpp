#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include "adminUI.h"

using namespace std;
using std::setw;
int adConFlag = 0;
void UserMana();
void OpenFile();

void SystemManage() {
	string delUname;
	cout << "*********************************************" << endl;
	cout << "                                             " << endl;
	cout << "      欢迎管理员来到天朝图书馆管理系统      " << endl;
	cout << "                                             " << endl;
	cout << "*********************************************" << endl;
	cout << "1.用户管理" << endl;
	cout << "2.书籍管理" << endl;
	cout << "3.退出到登陆" << endl;
	cout << "*********************************************" << endl;
	cout << "请选择你要进行的操作：";
	cin >> adConFlag;
	switch (adConFlag)
	{
	case 1: {
		UserMana();
	}
		break;
	case 2:bookManage();
		break;
	case 3:SignUp();
	default:
		break;
	}
};

void DelUser() {
	string delname;
	ifstream infile;
	ofstream outfile;
	infile.open("Userinfo.txt");//打开需要读取的文件
	//outfile.open("Userinfo.txt");
	int lineCount = 0;//读取的行数
	int nLen=0;//delname的长度
	//int pLen = upass.size();//upass的长度
	string infoNcut[100];//存放截取到的name
	string infoPcut[100];//存放截取到的pass
	//string infostr[100];//存放从文件读取到的信息
	vector<string> infostrx;//文件内容缓存
	vector<string>delbuf;//删除的匹配信息
	while (!infile.eof())
	{
		string data;//infile信息缓存
		//getline(infile, infostrx.at(lineCount-1));//按行读取信息
		infile >> data;
		infostrx.push_back(data);
		cout << infostrx.at(lineCount) << endl;
		lineCount++;
	}
	for (int i = 0; i < infostrx.size(); i++) {
		delbuf.push_back(infostrx.at(i));
	}
	cout << "请输入要删除的用户名：";
	cin >> delname;
	nLen = delname.length();
	nLen = delname.size();
	int FindFlag = 0;
	int i = 0;
	lineCount = 0;
	for (; lineCount < delbuf.size(); lineCount++) {
		infoNcut[lineCount] = delbuf[lineCount].substr(0, nLen);
		for (; i < lineCount; ) {
			i++;
			if (delname._Equal(infoNcut[i])) {
				delbuf[i].erase();//删除匹配行
				FindFlag = 1;
			}
		}
		//cout << infostr[lineCount - 1] << endl;
	}
	if (FindFlag == 0) {
		cout << "找不到该用户" << endl;
	}
	else {
		cout << "删除成功！" << endl;
	}
	//while (infile.eof())//这里也有一个bug
	//{
	//	lineCount++;
	//	getline(infile, infostr[lineCount - 1]);//按行读取信息
	//	infoNcut[lineCount - 1] = infostr[lineCount - 1].substr( nLen);
	//	for (int i = 0; i < infostr->size(); i++) {
	//		
	//		if (delname._Equal(infoNcut[i])) {
	//			delbuf[i].erase();//delbuf中没有数据！
	//			FindFlag = 0;
	//		}
	//	}
	//	if (FindFlag = 0) {
	//		cout << "找不到该用户" << endl;
	//	}
	//	cout << infostr[lineCount - 1] << endl;
	//}
outfile.open("Userinfo.txt");//使用这个的时候要注意，最好是放在操作的前面打开文件，在这里如果放在循环里面会造成操作之后的结果不正确
	for (int i=0;i<infostrx.size();i++)//逻辑不通
	{
		outfile << delbuf[i];
		printf_s("\n");
	}
	infile.close();//关闭文件连接
	outfile.close();
	SystemManage();
}
void AddUser() {
	string uName;
	string uPass;
	string uInfo;
	ofstream wrFile;
	cout << "请输入用户名：";
	cin >> uName;
	cout << "请输入密码：";
	cin >> uPass;
	uInfo = uName + uPass;
	OpenFile();
	wrFile.open("Userinfo.txt", ios::app);
	wrFile << uInfo;
	printf_s("\n");
	cout << "添加成功" << endl;
	SystemManage();
}
void UserMana() {
	int choice;
	cout << "请选择操作内容：" << endl;
	cout << "1.删除用户" << endl;
	cout << "2.增加用户" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:DelUser();
		break;
	case 2:AddUser();
		break;
	default:
		break;
	}
}
void OpenFile() {
	ifstream inFile;
	//ofstream outFile;
	string data;
	vector<string> wrBuf;
	inFile.open("Userinfo.txt");
	while (!inFile.eof())
	{
		inFile >> data;
		wrBuf.push_back(data);
	}
}