#ifndef LOGIN_H
#define LOGIN_H
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "info.h"
#include "registe.h"
#include "BookManage.h"

using namespace std;//Ϊʲô����ṹ����Ҫ�����⣿
//struct Loginfo
//{
//	string Lname;
//	string Lpass;
//
//};
struct Loginfo
{
	string Lname;
	string Lpass;

};

void USign(string uname, string upass);//��½����
void SignUp();
#endif // !Login




