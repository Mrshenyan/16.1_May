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
	cout << "      ��ӭ����Ա�����쳯ͼ��ݹ���ϵͳ      " << endl;
	cout << "                                             " << endl;
	cout << "*********************************************" << endl;
	cout << "1.�û�����" << endl;
	cout << "2.�鼮����" << endl;
	cout << "*********************************************" << endl;
	cout << "��ѡ����Ҫ���еĲ�����";
	cin >> adConFlag;
	switch (adConFlag)
	{
	case 1:break;
	case 2:bookManage();
	default:
		break;
	}
};
