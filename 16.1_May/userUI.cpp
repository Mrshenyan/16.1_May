#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "userUI.h"
#define WIDTH 4;


using namespace std;
using std::setw;
void _1Flag();
void _2Flag();
void _3Flag();
void _4Flag();
void ChoiceFun(int choiceFalg);
void userUiMain(string user) {
	int choiceFalg = 0;
	cout << "***************************************" << endl;
	cout << "****当前登陆：" << user << endl;
	cout << "***************************************" << endl;
	cout << "1.借阅" << endl;
	cout << "2.续借" << endl;
	cout << "3.还书" << endl;
	cout << "4.查找" << endl;
	cout << "你想做什么？";
	cin >> choiceFalg;
	ChoiceFun(choiceFalg);
};


void ChoiceFun(int choiceFalg) {
	switch (choiceFalg)
	{
	case 1:_1Flag();//借阅
		break;
	case 2:_2Flag();//续借
		break;
	case 3:_3Flag();//还书
		break;
	case 4:_4Flag();//查找
		break;
	default:
		break;
	}
};

void _1Flag() {//文件的读取有问题，不能正确的读取手动输入的中文字符。或许使用多字节读取

	ifstream infile;
	infile.open("BooksInfo.txt");
	cout << "******" << "书刊号" << "******" << "书名" << "******" << "作者" << "******" << "类别" << "******" << endl;
	/*vector<vector<vector<vector<string>>>>Bookinfo;*/
	vector<string>bookstr;
	string bookinfoBuf;
	//stringbuf* strbuf = cin.rdbuf(infile.rdbuf);

	while (!infile.eof())//读取数据
	{
		//getline(infile, bookinfoBuf);
		infile >> bookinfoBuf;
		bookstr.push_back(bookinfoBuf);

		cout << bookinfoBuf;
		//getline(infile, bookstr);

	}
};

void _2Flag() {

};

void _3Flag() {

};

void _4Flag() {

};