#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.h"
#include "info.h"
#include "adminUI.h"
#include "userUI.h"

using namespace std;
void Isuser(string infoNcut[100], string infoPcut[100], string uname, string upass);

void USign(string uname, string upass) {//��½
	//Loginfo sinfo;
	ifstream infile;
	infile.open("Userinfo.txt");//����Ҫ��ȡ���ļ�
	int lineCount = 0;//��ȡ������
	int nLen = uname.size();//uname�ĳ���
	int pLen = upass.size();//upass�ĳ���
	string infoNcut[100];//��Ž�ȡ����name
	string infoPcut[100];//��Ž�ȡ����pass
	string infostr[100];//��Ŵ��ļ���ȡ������Ϣ
	/*string *iNcut = infoNcut;
	string *iPcut = infoPcut;*/
	while (!infile.eof())
	{
		lineCount++;
		getline(infile, infostr[lineCount]);//���ж�ȡ��Ϣ
		
		//infostr[lineCount] << infile;
		infoNcut[lineCount-1] = infostr[lineCount].substr(0,nLen);//��ȡname
		infoPcut[lineCount-1] = infostr[lineCount].substr(nLen,pLen+1);//��ȡpass
	}
	infile.close();//�ر��ļ�����
	Isuser(infoNcut, infoPcut,uname, upass);//���Ƿ���ע����Ա�����ж�
	
}

void Isuser(string infoNcut[100],string infoPcut[100],string uname,string upass) {
	int loginCount = 0;
	bool Isreg = false;
	for (int i = 0; i < infoNcut->size(); i++) {
		//for (int j = 0; j < infoPcut->size(); j++) {
		//	if ((infoNcut->_Equal(uname)) && (infoPcut->_Equal(upass))) {
		//		cout << "*****��ӭ" << uname << "��½�쳯ͼ���******" << endl;
		//		break;
		//	}
		//	else {
		//		cout << "�û��������������" << endl;
		//		loginCount++;
		//		break;
		//	}
		//}
		if (infoNcut[i]._Equal(uname)) {//�Ƿ��������
			if (infoPcut[i]._Equal(upass)) {//����Բ�
				cout << "*****��ӭ" << uname << "��½�쳯ͼ���******" << endl;
				userUiMain(uname);
				break;
			}
			else {
				cout << "�û��������������" << endl;//��ʾ�������

				loginCount++;
			}
		}
		else {
			cout << "�Բ�����û���δע�ᣬ�Ƿ�ע�᣿1���ǣ�0����" << endl;
			int re;
			cin >> re;
			if (re == 1) {
				Uregist();//û���������ʾ�Ƿ�Ҫע��
				break;
			}
			else {

				break;
			}
		}
	}
	if (loginCount > 15) {//��½����
		cout << "�Բ����Ե�¼�������࣬�����˳�ϵͳ��" << endl;
		exit(5);
	}
}



