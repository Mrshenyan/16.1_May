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
	//infomaBook[AddCount][0] = book->BookName;
	cout << "                                        " << endl;
	cout << "请输入书号：";
	book->setBookNum(book);
	//infomaBook[AddCount][1] = book->BookName;
	cout << "                                        " << endl;
	cout << "请输入作者：";
	book->setBookWri(book);
	//infomaBook[AddCount][2] = book->BookName;
	cout << "                                        " << endl;
	cout << "请输入类别：";
	//infomaBook[AddCount][3] = book->BookName;
	book->setBookSty(book);
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
	AddCount++;
	wrifile.close();
	bookManage();
};

void newBook::DeleteBook(vector<string> rbuf) {//删除书
	string deleBkNum;
	string deleBkName;
	string debNumbuf[100];
	string debNamebuf[100];
	int deleline = 0;//删除行标志
	cout << "请输入书序" ;
	cin >> deleBkNum;
	cout << "请输入书名";
	cin >> deleBkName;
	int DBNumLen = deleBkNum.size();
	int DBNameLen = deleBkName.size();
	for (int i = 0; i < rbuf.size(); i++) {
		if (deleBkNum._Equal(rbuf[i].substr(0, DBNumLen))) {//书序是否相等
			if (deleBkName._Equal(rbuf[i].substr(DBNumLen + 1, DBNameLen))) {//书名是否相等
				rbuf[i].erase();//擦除行中的信息
				deleline = i;
				//rbuf[i].erase();
			}
		}
		else {
			cout << "找不到要删除的书，请检查输入是否正确或者输入的书已经被删除" << endl;
			bookManage();
		}
	}
	rbuf.erase(rbuf.begin() + deleline);//删除一整行
	_ManaRewri(rbuf);//重新写入文件
};
void newBook::ChangeBook(vector<string> rbuf) {
	string ChanBkNum;
	string ChanBkName;
	string chbNumbuf[100];
	string chbNamebuf[100];
	int chaneumn = 0;//修改元素标志
	cout << "请输入需要修改的书序";
	cin >> ChanBkNum;
	cout << "请输入需要修改的书名";
	cin >> ChanBkName;
	int CBNumLen = ChanBkNum.size();
	int CBNameLen = ChanBkName.size();
	//int CBWrLen = 
	for (int i = 0; i < rbuf.size(); i++) {
		if (ChanBkNum._Equal(rbuf[i].substr(0, CBNumLen))) {//书序是否相等
			if (ChanBkName._Equal(rbuf[i].substr(CBNumLen + 1, CBNameLen))) {//书名是否相等
				cout << "*************以下是查找结果**************" << endl;
				cout << setw(13) << rbuf[i] << setw(13) << endl;
				cout << "1.书序" << endl;
				cout << "2.书名" << endl;
				cout << "3.作者" << endl;
				cout << "4.类别" << endl;
				cout << "请选择要修改的内容：";
				cin >> chaneumn;
				_ManaCB(chaneumn,rbuf,i, CBNumLen, CBNameLen, AddCount);
			}
		}
		else {
			cout << "找不到要修改的书，请检查输入是否正确" << endl;
			bookManage();
		}
	}
};//更改书
void newBook::FindBook(vector<string> rbuf) {
	string FindBkNum;
	string FindBkName;
	vector<string>viewbuf;
	//int deleline = 0;//删除行标志
	cout << "请输入书序";
	cin >> FindBkNum;
	cout << "请输入书名";
	cin >> FindBkName;
	int FBNumLen = FindBkNum.size();
	int FBNameLen = FindBkName.size();
	for (int i = 0; i < rbuf.size(); i++) {
		if (FindBkNum._Equal(rbuf[i].substr(0, FBNumLen))) {//书序是否相等
			if (FindBkName._Equal(rbuf[i].substr(FBNumLen + 1, FBNameLen))) {//书名是否相等
				//viewbuf.push_back(rbuf[i]);
				cout << "*************以下是查找结果**************" << endl;
				cout << setw(13) <<rbuf[i]<< setw(13) <<endl;
				bookManage();
				break;
			}
		}
		else {
			cout << "未找到，请检查输入是否正确" << endl;
			bookManage();
		}
	}	
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

void bookManage() {//书籍管理模块
	newBook *anewBook = new newBook;
	ofstream wrifile;
	//string wriBuf;
	wrifile.open("new 1.txt",ios::app);
	cout << "****************************************" << endl;
	cout << "                                        " << endl;
	cout << "*********欢迎管理员来到管理系统*********" << endl;
	cout << "                                        " << endl;
	cout << "请选择需要进行的操作：" << endl;
	cout << "1.添加" << endl;
	cout << "2.删除" << endl;
	cout << "3.修改" << endl;
	cout << "4.查找" << endl;
	cin >> anewBook->inputCh;
	switch (anewBook->inputCh)
	{
	case 1:anewBook->AddBook(anewBook);//添加一本书
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

void _ManaRB() {//读取书的信息
	ifstream infile;
	infile.open("new 1.txt");
	
	string bookinfoBuf;
	while (!infile.eof())//读取数据
	{
		//getline(infile, bookinfoBuf);
		infile >> bookinfoBuf;
		readBuf.push_back(bookinfoBuf);
	}
	infile.close();
}
void _ManaRewri(vector<string> mrw) {//重新写入书籍信息
	wrifile.open("new 1.txt");
	for (int i = 0; i < mrw.size(); i++) {
		if (i != 0) {//换行输入
				wrifile << "\n";
		}
		wrifile << mrw[i];//数据写入到文件
		string fengefu = ",";
		if (i < (mrw.size() - 1)) {
			wrifile << fengefu;//添加分隔符
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
		cout << "请输入修改之后的内容：";
		cin >> infomaBook[AddCount][0];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
		rbuf[i] = uploadbuf;
	}
			break;
	case 2: {
		cout << "请输入修改之后的内容：";
		cin >> infomaBook[AddCount][1];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
	}
			break;
	case 3: {
		cout << "请输入修改之后的内容：";
		cin >> infomaBook[AddCount][2];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
	}
			break;
	case 4: {
		cout << "请输入修改之后的内容：";
		cin >> infomaBook[AddCount][3];
		uploadbuf = ((infomaBook[AddCount][0] + "," + infomaBook[AddCount][1] + "," + infomaBook[AddCount][2] + "," + infomaBook[AddCount][3]));
	}
			break;
	case 5:bookManage();
	default:
		break;
	}
}