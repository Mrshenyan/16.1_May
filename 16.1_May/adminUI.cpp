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
	infile.open("Userinfo.txt");//����Ҫ��ȡ���ļ�
	outfile.open("Userinfo.txt");
	int lineCount = 0;//��ȡ������
	int nLen = delname.size();//delname�ĳ���
	//int pLen = upass.size();//upass�ĳ���
	string infoNcut[100];//��Ž�ȡ����name
	string infoPcut[100];//��Ž�ȡ����pass
	string infostr[100];//��Ŵ��ļ���ȡ������Ϣ
	vector<string>delbuf;
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//���ж�ȡ��Ϣ
		infoNcut[lineCount - 1] = infostr[lineCount - 1].substr(0, nLen);
		delbuf.push_back(infostr[lineCount - 1]);
		cout << infostr[lineCount - 1] << endl;
	}
	cout << "������Ҫɾ�����û�����";
	cin >> delname;
	for (int i = 0; i < infoNcut->size();i++) {
		if (delname._Equal(infoNcut[i])) {
			delbuf[i].erase();
		}
	}
	for (int i=0;i<delbuf.size();i++)
	{
		outfile << delbuf[i];
	}
	infile.close();//�ر��ļ�����
	outfile.close();
}
