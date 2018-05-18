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

using namespace std;//为什么这个结构体需要放在这？
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

void USign(string uname, string upass);//登陆程序
void SignUp();
#endif // !Login




