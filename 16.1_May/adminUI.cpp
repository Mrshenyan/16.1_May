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
	cout << "      ��ӭ����Ա�����쳯ͼ��ݹ���ϵͳ      " << endl;
	cout << "                                             " << endl;
	cout << "*********************************************" << endl;
	cout << "1.�û�����" << endl;
	cout << "2.�鼮����" << endl;
	cout << "3.�˳�����½" << endl;
	cout << "*********************************************" << endl;
	cout << "��ѡ����Ҫ���еĲ�����";
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
	infile.open("Userinfo.txt");//����Ҫ��ȡ���ļ�
	//outfile.open("Userinfo.txt");
	int lineCount = 0;//��ȡ������
	int nLen=0;//delname�ĳ���
	//int pLen = upass.size();//upass�ĳ���
	string infoNcut[100];//��Ž�ȡ����name
	string infoPcut[100];//��Ž�ȡ����pass
	//string infostr[100];//��Ŵ��ļ���ȡ������Ϣ
	vector<string> infostrx;//�ļ����ݻ���
	vector<string>delbuf;//ɾ����ƥ����Ϣ
	while (!infile.eof())
	{
		string data;//infile��Ϣ����
		//getline(infile, infostrx.at(lineCount-1));//���ж�ȡ��Ϣ
		infile >> data;
		infostrx.push_back(data);
		cout << infostrx.at(lineCount) << endl;
		lineCount++;
	}
	for (int i = 0; i < infostrx.size(); i++) {
		delbuf.push_back(infostrx.at(i));
	}
	cout << "������Ҫɾ�����û�����";
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
				delbuf[i].erase();//ɾ��ƥ����
				FindFlag = 1;
			}
		}
		//cout << infostr[lineCount - 1] << endl;
	}
	if (FindFlag == 0) {
		cout << "�Ҳ������û�" << endl;
	}
	else {
		cout << "ɾ���ɹ���" << endl;
	}
	//while (infile.eof())//����Ҳ��һ��bug
	//{
	//	lineCount++;
	//	getline(infile, infostr[lineCount - 1]);//���ж�ȡ��Ϣ
	//	infoNcut[lineCount - 1] = infostr[lineCount - 1].substr( nLen);
	//	for (int i = 0; i < infostr->size(); i++) {
	//		
	//		if (delname._Equal(infoNcut[i])) {
	//			delbuf[i].erase();//delbuf��û�����ݣ�
	//			FindFlag = 0;
	//		}
	//	}
	//	if (FindFlag = 0) {
	//		cout << "�Ҳ������û�" << endl;
	//	}
	//	cout << infostr[lineCount - 1] << endl;
	//}
outfile.open("Userinfo.txt");//ʹ�������ʱ��Ҫע�⣬����Ƿ��ڲ�����ǰ����ļ����������������ѭ���������ɲ���֮��Ľ������ȷ
	for (int i=0;i<infostrx.size();i++)//�߼���ͨ
	{
		outfile << delbuf[i];
		printf_s("\n");
	}
	infile.close();//�ر��ļ�����
	outfile.close();
	SystemManage();
}
void AddUser() {
	string uName;
	string uPass;
	string uInfo;
	ofstream wrFile;
	cout << "�������û�����";
	cin >> uName;
	cout << "���������룺";
	cin >> uPass;
	uInfo = uName + uPass;
	OpenFile();
	wrFile.open("Userinfo.txt", ios::app);
	wrFile << uInfo;
	printf_s("\n");
	cout << "��ӳɹ�" << endl;
	SystemManage();
}
void UserMana() {
	int choice;
	cout << "��ѡ��������ݣ�" << endl;
	cout << "1.ɾ���û�" << endl;
	cout << "2.�����û�" << endl;
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