#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include "adminUI.h"

using namespace std;
using std::setw;
int adConFlag = 0;
void SystemManage() {
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
	case 1:break;
	case 2:bookManage();
	default:
		break;
	}
};
