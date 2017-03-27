#include "poet.h"
#include "poetry.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace std;

void view_poets();
void add_poetries();
void view_poetries();

int main()
{
	//view_poets();
	//add_poetries();
	view_poetries();
	return 0;
}

void view_poets()
{
	poet _poet;
	ifstream poet_dat;
	poet_dat.open("poet_dat.dat", ios::binary);
	if (!poet_dat)
	{
		cout << "Error: Data File Cannot Be Open!" << endl;
		return;
	};

	
	while(poet_dat.read((char*)(&_poet), sizeof(_poet)))
	{
		cout << _poet.show_id() << " " << _poet.show_name() << endl;
	};
	
	poet_dat.close();
	system("pause");
};

void store_poet_name(poetry &pty)
{
	poet pt;
	ifstream poet_dat;
	poet_dat.open("poet_dat.dat", ios::binary);
	while (poet_dat.read((char*)&pt, sizeof(pt)))
	{
		if (pt.show_id() == pty.show_poet_id())
		{
			pty.store_poet_name(pt.show_name());
		};

	}
};

void add_poetries()
{
	poetry _pty;
	ifstream poetry_dat;
	ofstream poetry_dat2;
	poetry_dat.open("poetry_dat.dat", ios::binary);
	poetry_dat2.open("poetry_dat2.dat", ios::binary);
	if (!poetry_dat || !poetry_dat2)
	{
		cout << "Error: Data File Cannot Be Open!" << endl;
		return;
	}
	while (poetry_dat.read((char*)(&_pty), sizeof(_pty)))
	{
		store_poet_name(_pty);
		poetry_dat2.write((char*)&_pty, sizeof(_pty));
		cout << _pty.show_poetry_id() << " " << _pty.show_poet_name() << endl;
		char* _pty_name_ptr = new char[_pty.show_poetry_name_size()+1];
		char* _pty_content_ptr = new char[_pty.show_poetry_size()+1];
		poetry_dat.read(_pty_name_ptr, _pty.show_poetry_name_size()+1);
		poetry_dat.read(_pty_content_ptr, _pty.show_poetry_size()+1);
		poetry_dat2.write(_pty_name_ptr, _pty.show_poetry_name_size() + 1);
		poetry_dat2.write(_pty_content_ptr, _pty.show_poetry_size() + 1);
		delete [] _pty_name_ptr;
		delete [] _pty_content_ptr;
	}
	poetry_dat.close();
	system("pause");
};

void view_poetries()
{
	poetry _pty;
	ifstream poetry_dat;
	poetry_dat.open("poetry_dat2.dat", ios::binary);
	if (!poetry_dat)
	{
		cout << "Error: Data File Cannot Be Open!" << endl;
		return;
	}
	while (poetry_dat.read((char*)(&_pty), sizeof(_pty)))
	{
		char* _pty_name_ptr = new char[_pty.show_poetry_name_size() + 1];
		char* _pty_content_ptr = new char[_pty.show_poetry_size() + 1];
		poetry_dat.read(_pty_name_ptr, _pty.show_poetry_name_size() + 1);
		poetry_dat.read(_pty_content_ptr, _pty.show_poetry_size() + 1);
		cout << _pty.show_poetry_id() << " " << _pty.show_poet_name() << endl;
		delete[] _pty_name_ptr;
		delete[] _pty_content_ptr;
	}
	poetry_dat.close();
	system("pause");
};
