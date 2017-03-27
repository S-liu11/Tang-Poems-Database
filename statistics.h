#pragma once

#include <iostream>
#include <fstream>
#include "poetry.h"

using namespace std;

void statistics()
{
	system("cls");
	int pty_num;
	int pt_num;
	int maxContentSize=0;
	poetry maxContentPty;
	poetry pty;
	string maxContent;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{
		char* pty_name_ptr = new char[pty.show_poetry_name_size() + 1];
		char* pty_content_ptr = new char[pty.show_poetry_size() + 1];
		pty_dat.read(pty_name_ptr, pty.show_poetry_name_size() + 1);
		pty_dat.read(pty_content_ptr, pty.show_poetry_size() + 1);
		if (pty.show_poetry_size() > maxContentSize) {
			maxContentSize = pty.show_poetry_size();
			maxContentPty = pty;
			maxContent = pty_content_ptr;
		}
	}
	cout << "全数据库最长古诗，共" << maxContentSize / 2 << "字" << endl << endl;
	cout << maxContentPty.show_poet_name() << " " << maxContentPty.show_poet_name() << endl;
	cout << maxContent << endl;
	//poem_output_0(maxContent);
	system("pause");
}