#ifndef BOOKMANAGE
#define BOOKMANAGE
#include "stdafx.h"
#include <iomanip>
#include <iostream>
//#include "adminUI.h"
#include "userUI.h"
#include "login.h"
using namespace std;
using std::setw;

//struct BOOK
//{
//	string BookName;
//	string BookNum;
//	string BookWri;
//	string BookSty;
//	string BookSta;
//	
//};


class _BookManage {
	public:
		int inputCh = 0;
		virtual void setBookName() {};//��������
		virtual void setBookNum() {};//��������
		virtual void setBookWri() {};//��������
		virtual void setBookSty() {};//�������
		virtual void setBookSta() {};//����״̬
		
		virtual void AddBook() {};
		virtual void DeleteBook() {};
		virtual void ChangeBook() {};
		virtual void FindBook() {};
	protected :
		string BookName;
		string BookNum;
		string BookWri;
		string BookSty;
};

void bookManage();

#endif // !BOOKMANAGE

