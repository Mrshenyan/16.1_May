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
		void setBookName(newBook *book) ;//设置书名
		void setBookNum(newBook *book) ;//设置书序
		void setBookWri(newBook *book) ;//设置作者
		void setBookSty(newBook *book) ;//设置类别
		void setBookSta(newBook *book) ;//设置状态
};

//BOOK aBook;

void newBook::AddBook(newBook *book) {//添加书
	cout << "                                        " << endl;
	cout << "请输入书名：";
	book->setBookName(book);
	cout << "                                        " << endl;
	cout << "请输入书号：";
	book->setBookNum(book);
	cout << "                                        " << endl;
	cout << "请输入作者：";
	book->setBookWri(book);
	cout << "                                        " << endl;
	cout << "请输入类别：";
	book->setBookSty(book);
};

void newBook::DeleteBook(newBook *book) {//删除书
	string deleBkNum;
	string deleBkName;
	cout << "请输入需要删除的书的信息，例如：书序和书名" << endl;
	cin >> deleBkNum;
	cin >> deleBkNum;
	
};

void newBook::ChangeBook(newBook *book) {
	
	
};//更改书
void newBook::FindBook(newBook *book) {
	
	
};//查找书
void newBook::setBookName(newBook *book) {
	//string NameBuf;
	cin >> book->BookName;
	//NameBuf = book->BookName;
	wriBuf.push_back(book->BookName);
	
};//设置书名
void newBook::setBookNum(newBook *book) {
	cin >> book->BookNum;
	wriBuf.insert(wriBuf.begin(), book->BookNum);
};//设置书序
void newBook::setBookWri(newBook *book) {
	cin >> book->BookWri;
	wriBuf.push_back(book->BookWri);
};//设置作者
void newBook::setBookSty(newBook *book) {
	cin >> book->BookSty;
	wriBuf.push_back(book->BookSty);

};//设置类别



void bookManage() {
	newBook *anewBook = new newBook;
	ofstream wrifile;
	//string wriBuf;
	wrifile.open("new 1.txt",ios::app);
	cout << "****************************************" << endl;
	cout << "                                        " << endl;
	cout << "*********欢迎管理员来到管理系统*********" << endl;
	cout << "                                        " << endl;
	cout << "请选择需要进行的操作：";
	cout << "1.添加" << endl;
	cout << "2.删除" << endl;
	cout << "3.修改" << endl;
	cout << "4.查找" << endl;
	cin >> anewBook->inputCh;
	switch (anewBook->inputCh)
	{
	case 1:anewBook->AddBook(anewBook);//添加一本书
		/*printf_s("\n");*/
		for (int i = 0; i < wriBuf.size(); i++) {
			if (i == 0) {
				wrifile << "\n";
			}
			wrifile << wriBuf[i];//数据写入到文件
			string fengefu = ",";
			if (i < wriBuf.size() - 1) {
				wrifile << fengefu;//添加分隔符
			}
		}
		cout << "添加成功！" << endl;
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
	while (!infile.eof())//读取数据
	{
		//getline(infile, bookinfoBuf);
		//infile >> bookinfoBuf;
		bookstr.push_back(bookinfoBuf);
	}
}