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
	cout << "*************�쳯ͼ���ע��*************" <<endl;
	cout << "������������������������������������" << endl;
	cout << "�������û���(4-8�ַ�)��";
	cin >> reName;
	cout << "���������룺";
	cin >> rePass;
	cout << "������һ�����룺";
	cin >> idPass;
	cout << "��1ȷ��ע�ᣬ��0�����޸ģ�";
	cin >> Button;
	switch (Button)
	{
	case 1: {
		if (!rePass._Equal(idPass)) {
			cout << "������������벻һ����������ע�ᣡ"<<endl;
			Uregist();
		}
		else {
			WriteInfo(reName, rePass);
		}
	}
		break;
	case 0: {
		cout << "�����������û���(4-8�ַ�)��";
		cin >> reName;
		cout << "�������������룺";
		cin >> rePass;
		cout << "������һ�����룺";
		cin >> idPass;
		cout << "��1ȷ��ע�ᣬ��0�����޸ģ�";
		cin >> Button;
	}
	default:
		break;
	}
}

void WriteInfo(string wrName,string wrPass) {
	ifstream infile;
	infile.open("Userinfo.txt");//����Ҫ��ȡ���ļ�
	ofstream upload;
	upload.open("Userinfo.txt",ios::app);
	int lineCount = 0;//��ȡ������
	int nLen = wrName.size();//uname�ĳ���
	int pLen = wrPass.size();//upass�ĳ���
	string infoNcut[100];//��Ž�ȡ����name
	string infoPcut[100];//��Ž�ȡ����pass
	string infostr[100];//��Ŵ��ļ���ȡ������Ϣ
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//���ж�ȡ��Ϣ

											//infostr[lineCount] << infile;
		infoNcut[lineCount - 1] = infostr[lineCount].substr(0, nLen);//��ȡname
		if (infoNcut->_Equal(wrName)) {
			cout << "�Բ�����û����ѱ�ע��" << endl;
			Uregist();
		}
		
	}
	//printf_s("\n");
	upload << (wrName+wrPass);
	infile.close();
	upload.close();
}