#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include "userUI.h"

#define WIDTH 4;


using namespace std;
using std::setw;
void _1Flag();
void _2Flag();
void _3Flag();
void _4Flag();
void ChoiceFun(int choiceFalg,string user);
void userUiMain(string user) {
	int choiceFalg = 0;
	cout << "***************************************" << endl;
	cout << "****��ǰ��½��" << user << endl;
	cout << "***************************************" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.�˳�" << endl;
	cout << "������ʲô��";
	cin >> choiceFalg;
	ChoiceFun(choiceFalg, user);
};


void ChoiceFun(int choiceFalg,string user) {
	switch (choiceFalg)
	{
	case 1: {_1Flag(); //����
		userUiMain(user);
	}
		break;
	case 2: {_2Flag();//����
		userUiMain(user);
	}
		break;
	case 3: {_3Flag();//����
		userUiMain(user);
	}
		break;
	case 4: {_4Flag();//����
		userUiMain(user);
	}
		break;
	case 5: {
		cout << "ϵͳ����5���Ӻ��˻ص�½����" << endl;
		//exit(10);
		Sleep(5000);
		SignUp();
	}
	default:
		break;
	}
};

void _1Flag() {//�ļ��Ķ�ȡ�����⣬������ȷ�Ķ�ȡ�ֶ�����������ַ�������ʹ�ö��ֽڶ�ȡ

	ifstream infile;
	infile.open("new 1.txt");
	cout << "******" << "�鿯��" << "******" << "����" << "******" << "����" << "******" << "���" << "******" << endl;
	vector<string>bookstr;
	string bookinfoBuf;
	string BookNum;
	int lineCount = 0;
	while (!infile.eof())//��ȡ����
	{
		//getline(infile, bookinfoBuf);
		infile >> bookinfoBuf;
		bookstr.push_back(bookinfoBuf);
		cout << "     " <<bookinfoBuf<<endl;
		lineCount++;
		//getline(infile, bookstr);

	}
	cout << "��ѡ����Ҫ���ĵ������ţ�";
	cin >> BookNum;
	string data;

	cout << "��ѡ������ǣ�" << endl;
	for (int i=0; i < lineCount;i++) {
		data = bookstr[i].substr(0, 1);
		if (BookNum._Equal(bookstr[i].substr(0, 1))) {
			cout << bookstr[i] << endl;
		}
	}
	infile.close();
};

void _2Flag() {

};

void _3Flag() {

};

void _4Flag() {

};