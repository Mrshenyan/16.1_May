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

vector<string>wriBuf;

class newBook : public _BookManage {
	public:
		void AddBook(newBook *book) ;
		void DeleteBook(newBook *book) ;
		void ChangeBook(newBook *book) ;
		void FindBook(newBook *book);
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
	cout << "                                        " << endl;
	cout << "��������ţ�";
	book->setBookNum(book);
	cout << "                                        " << endl;
	cout << "���������ߣ�";
	book->setBookWri(book);
	cout << "                                        " << endl;
	cout << "���������";
	book->setBookSty(book);
};

void newBook::DeleteBook(newBook *book) {//ɾ����
	string deleBkNum;
	string deleBkName;
	cout << "��������Ҫɾ���������Ϣ�����磺���������" << endl;
	cin >> deleBkNum;
	cin >> deleBkNum;
	
};

void newBook::ChangeBook(newBook *book) {
	
	
};//������
void newBook::FindBook(newBook *book) {
	
	
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



void bookManage() {
	newBook *anewBook = new newBook;
	ofstream wrifile;
	//string wriBuf;
	wrifile.open("new 1.txt",ios::app);
	cout << "****************************************" << endl;
	cout << "                                        " << endl;
	cout << "*********��ӭ����Ա��������ϵͳ*********" << endl;
	cout << "                                        " << endl;
	cout << "��ѡ����Ҫ���еĲ�����";
	cout << "1.���" << endl;
	cout << "2.ɾ��" << endl;
	cout << "3.�޸�" << endl;
	cout << "4.����" << endl;
	cin >> anewBook->inputCh;
	switch (anewBook->inputCh)
	{
	case 1:anewBook->AddBook(anewBook);//���һ����
		/*printf_s("\n");*/
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
		wrifile.close();
		break;
	case 2:anewBook->ChangeBook(anewBook);

		break;
	case 3:anewBook->setBookWri(anewBook);

		break;
	case 4:anewBook->setBookSty(anewBook);

		break;
	default:
		break;
	}
}

void _ManaB() {
	ofstream infile;
	infile.open("new 1.txt");
	vector<string>bookstr;
	string bookinfoBuf;
	while (!infile.eof())//��ȡ����
	{
		//getline(infile, bookinfoBuf);
		//infile >> bookinfoBuf;
		bookstr.push_back(bookinfoBuf);
	}
}