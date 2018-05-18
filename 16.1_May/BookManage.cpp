#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "userUI.h"
#include "login.h"
#include "BookManage.h"
using namespace std;
using std::setw;
using std::allocator;

vector<string>wriBuf;
vector<string>readBuf;

string infomaBook[][5] = {""};
int AddCount = 0;
ofstream wrifile;
//string wriBuf;
void _ManaRB();
void _ManaRewri(vector<string>mrw);
void _ManaCB(int chaneumn, vector<string> rbuf, int i, int CBNumLen, int CBNameLen,int AddCount);

class newBook : public _BookManage {
	public:
		newBook() { _ManaRB(); };
		void AddBook(newBook *book) ;
		void DeleteBook(vector<string> rbuf) ;
		void ChangeBook(vector<string> rbuf) ;
		void FindBook(vector<string> rbuf);

		void setBookName(newBook *book) ;//��������
		void setBookNum(newBook *book) ;//��������
		void setBookWri(newBook *book) ;//��������
		void setBookSty(newBook *book) ;//�������
		void setBookSta(newBook *book) ;//����״̬
};

//BOOK aBook;

void newBook::AddBook(newBook *book) {//�����

	cout << "                                        " << endl;
	cout << "������������";
	book->setBookName(book);
	//infomaBook[AddCount][0] = book->BookName;
	cout << "                                        " << endl;
	cout << "��������ţ�";
	book->setBookNum(book);
	//infomaBook[AddCount][1] = book->BookName;
	cout << "                                        " << endl;
	cout << "���������ߣ�";
	book->setBookWri(book);
	//infomaBook[AddCount][2] = book->BookName;
	cout << "                                        " << endl;
	cout << "���������";
	//infomaBook[AddCount][3] = book->BookName;
	book->setBookSty(book);
	for (int i = 0; i < wriBuf.size(); i++) {
		if (i == 0) {
			wrifile << "\n";
		}
		wrifile << wriBuf[i];//����д�뵽�ļ�
		string fengefu = ",";
		if (i < wriBuf.size() - 1) {
			wrifile << fengefu;//��ӷָ���
		}
	}
	cout << "��ӳɹ���" << endl;
	AddCount++;
	wrifile.close();
	bookManage();
};

void newBook::DeleteBook(vector<string> rbuf) {//ɾ����
	string deleBkNum;
	string deleBkName;
	string debNumbuf[100];
	string debNamebuf[100];
	int deleline = 0;//ɾ���б�־
	cout << "����������" ;
	cin >> deleBkNum;
	cout << "����������";
	cin >> deleBkName;
	int DBNumLen = deleBkNum.size();
	int DBNameLen = deleBkName.size();
	for (int i = 0; i < rbuf.size(); i++) {
		if (deleBkNum._Equal(rbuf[i].substr(0, DBNumLen))) {//�����Ƿ����
			if (deleBkName._Equal(rbuf[i].substr(DBNumLen + 1, DBNameLen))) {//�����Ƿ����
				rbuf[i].erase();//�������е���Ϣ
				deleline = i;
				//rbuf[i].erase();
			}
		}
		else {
			cout << "�Ҳ���Ҫɾ�����飬���������Ƿ���ȷ������������Ѿ���ɾ��" << endl;
			bookManage();
		}
	}
	rbuf.erase(rbuf.begin() + deleline);//ɾ��һ����
	_ManaRewri(rbuf);//����д���ļ�
};
void newBook::ChangeBook(vector<string> rbuf) {
	string ChanBkNum;
	string ChanBkName;
	string chbNumbuf[100];
	string chbNamebuf[100];
	int chaneumn = 0;//�޸�Ԫ�ر�־
	cout << "��������Ҫ�޸ĵ�����";
	cin >> ChanBkNum;
	cout << "��������Ҫ�޸ĵ�����";
	cin >> ChanBkName;
	int CBNumLen = ChanBkNum.size();
	int CBNameLen = ChanBkName.size();
	//int CBWrLen = 
	for (int i = 0; i < rbuf.size(); i++) {
		if (ChanBkNum._Equal(rbuf[i].substr(0, CBNumLen))) {//�����Ƿ����
			if (ChanBkName._Equal(rbuf[i].substr(CBNumLen + 1, CBNameLen))) {//�����Ƿ����
				cout << "*************�����ǲ��ҽ��**************" << endl;
				cout << setw(13) << rbuf[i] << setw(13) << endl;
				cout << "1.����" << endl;
				cout << "2.����" << endl;
				cout << "3.����" << endl;
				cout << "4.���" << endl;
				cout << "��ѡ��Ҫ�޸ĵ����ݣ�";
				cin >> chaneumn;
				_ManaCB(chaneumn,rbuf,i, CBNumLen, CBNameLen, AddCount);
			}
		}
		else {
			cout << "�Ҳ���Ҫ�޸ĵ��飬���������Ƿ���ȷ" << endl;
			bookManage();
		}
	}
};//������
void newBook::FindBook(vector<string> rbuf) {
	string FindBkNum;
	string FindBkName;
	vector<string>viewbuf;
	//int deleline = 0;//ɾ���б�־
	cout << "����������";
	cin >> FindBkNum;
	cout << "����������";
	cin >> FindBkName;
	int FBNumLen = FindBkNum.size();
	int FBNameLen = FindBkName.size();
	for (int i = 0; i < rbuf.size(); i++) {
		if (FindBkNum._Equal(rbuf[i].substr(0, FBNumLen))) {//�����Ƿ����
			if (FindBkName._Equal(rbuf[i].substr(FBNumLen + 1, FBNameLen))) {//�����Ƿ����
				//viewbuf.push_back(rbuf[i]);
				cout << "*************�����ǲ��ҽ��**************" << endl;
				cout << setw(13) <<rbuf[i]<< setw(13) <<endl;
				bookManage();
				break;
			}
		}
		else {
			cout << "δ�ҵ������������Ƿ���ȷ" << endl;
			bookManage();
		}
	}	
};//������

void newBook::setBookName(newBook *book) {
	//string NameBuf;
	cin >> book->BookName;
	//NameBuf = book->BookName;
	wriBuf.push_back(book->BookName);
	
};//��������
void newBook::setBookNum(newBook *book) {
	cin >> book->BookNum;
	wriBuf.insert(wriBuf.begin(), book->BookNum);
};//��������
void newBook::setBookWri(newBook *book) {
	cin >> book->BookWri;
	wriBuf.push_back(book->BookWri);
};//��������
void newBook::setBookSty(newBook *book) {
	cin >> book->BookSty;
	wriBuf.push_back(book->BookSty);

};//�������

void bookManage() {//�鼮����ģ��
	newBook *anewBook = new newBook;
	ofstream wrifile;
	//string wriBuf;
	wrifile.open("new 1.txt",ios::app);
	cout << "****************************************" << endl;
	cout << "                                        " << endl;
	cout << "*********��ӭ����Ա��������ϵͳ*********" << endl;
	cout << "                                        " << endl;
	cout << "��ѡ����Ҫ���еĲ�����" << endl;
	cout << "1.���" << endl;
	cout << "2.ɾ��" << endl;
	cout << "3.�޸�" << endl;
	cout << "4.����" << endl;
	cin >> anewBook->inputCh;
	switch (anewBook->inputCh)
	{
	case 1:anewBook->AddBook(anewBook);//���һ����
		/*printf_s("\n");*/
		
		break;
	case 2:anewBook->DeleteBook(readBuf);
		break;
	case 3:anewBook->ChangeBook(readBuf);

		break;
	case 4:anewBook->FindBook(readBuf);

		break;
	default:
		break;
	}
}

void _ManaRB() {//��ȡ�����Ϣ
	ifstream infile;
	infile.open("new 1.txt");
	
	string bookinfoBuf;
	while (!infile.eof())//��ȡ����
	{
		//getline(infile, bookinfoBuf);
		infile >> bookinfoBuf;
		readBuf.push_back(bookinfoBuf);
	}
	infile.close();
}
void _ManaRewri(vector<string> mrw) {//����д���鼮��Ϣ
	wrifile.open("new 1.txt");
	for (int i = 0; i < mrw.size(); i++) {
		if (i != 0) {//��������
				wrifile << "\n";
		}
		wrifile << mrw[i];//����д�뵽�ļ�
		string fengefu = ",";
		if (i < (mrw.size() - 1)) {
			wrifile << fengefu;//��ӷָ���
		}
	}
}
void _ManaCB(int chaneumn, vector<string> rbuf, int i,int CBNumLen,int CBNameLen,int AddCount) {


	int chanNuLen = infomaBook[AddCount][0].length();
	int chanNaLen = infomaBook[AddCount][1].length();
	int chanWrLen = infomaBook[AddCount][2].length();
	int chanStyLen = infomaBook[AddCount][3].length();
	string uploadbuf;
	uploadbuf = ((infomaBook[AddCount][0]+"," + infomaBook[AddCount][1]+ "," + infomaBook[AddCount][2]+"," + infomaBook[AddCount][3]));
	switch (chaneumn)
	{
	case 1: {
		cout << "�������޸�֮������ݣ�";
		cin >> infomaBook[AddCount][0];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
		rbuf[i] = uploadbuf;
	}
			break;
	case 2: {
		cout << "�������޸�֮������ݣ�";
		cin >> infomaBook[AddCount][1];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
	}
			break;
	case 3: {
		cout << "�������޸�֮������ݣ�";
		cin >> infomaBook[AddCount][2];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
	}
			break;
	case 4: {
		cout << "�������޸�֮������ݣ�";
		cin >> infomaBook[AddCount][3];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
	}
			break;
	case 5:bookManage();
	default:
		break;
	}
}