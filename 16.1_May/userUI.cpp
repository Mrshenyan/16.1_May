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
void ChoiceFun(int choiceFalg);
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
	ChoiceFun(choiceFalg);
};


void ChoiceFun(int choiceFalg) {
	switch (choiceFalg)
	{
	case 1:_1Flag();//����
		break;
	case 2:_2Flag();//����
		break;
	case 3:_3Flag();//����
		break;
	case 4:_4Flag();//����
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
	while (!infile.eof())//��ȡ����
	{
		//getline(infile, bookinfoBuf);
		infile >> bookinfoBuf;
		bookstr.push_back(bookinfoBuf);
		cout << "     " <<bookinfoBuf<<endl;
		//getline(infile, bookstr);

	}
};

void _2Flag() {

};

void _3Flag() {

};

void _4Flag() {

};