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
		virtual void setBookName() {};//设置书名
		virtual void setBookNum() {};//设置书序
		virtual void setBookWri() {};//设置作者
		virtual void setBookSty() {};//设置类别
		virtual void setBookSta() {};//设置状态
		
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

