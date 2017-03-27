#pragma once
#include<string>
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

class poetry
{
private:
	int poet_id;
	int poetry_id;
	int poetry_size;
	int poetry_name_size;
	char poet_name[15];

public:
	void store_poet_id(int);
	void store_poetry_id(int);
	void store_poetry_size(int);
	void store_poetry_name_size(int);
	void store_poet_name(char*);
	int show_poet_id();
	int show_poetry_id();
	int show_poetry_size();
	int show_poetry_name_size();
	string show_poet_name();
};

void poetry::store_poet_id(int _id)
{
	poet_id = _id;
};

void poetry::store_poetry_id(int _id)
{
	poetry_id = _id;
};

void poetry::store_poetry_size(int _size)
{
	poetry_size = _size;
};

void poetry::store_poetry_name_size(int _size)
{
	poetry_name_size = _size;
};

void poetry::store_poet_name(char* _name)
{
	strcpy_s(poet_name, 15, _name);
};

int poetry::show_poet_id()
{
	return poet_id;
};

int poetry::show_poetry_id()
{
	return poetry_id;
};

int poetry::show_poetry_size()
{
	return poetry_size;
};

int poetry::show_poetry_name_size()
{
	return poetry_name_size;
};

string poetry::show_poet_name()
{
	return poet_name;
};


void poem_output_0(string content)
{
	for (size_t n = 0; n < content.size(); n += 2)
	{
		cout << content.substr(n, 2);
		if (content.substr(n, 2) == "¡£")
			cout << endl;
	}
	cout << endl << endl;
}

void poem_output_1(string content, string keyword)
{
	int num = content.size() / 2;
	size_t pos = 0;
	vector<size_t> keyword_pos;
	do
	{
		pos = content.find(keyword, pos) + 2;
		keyword_pos.push_back(pos - 2);
	} while (content.find(keyword, pos) != string::npos);

	for (size_t n = 0; n < content.size(); n += 2)
	{
		for (int i = 0; i < keyword_pos.size(); i++)
			if (n >= keyword_pos[i] && n <= keyword_pos[i] + keyword.size() - 2)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << content.substr(n, 2);
		if (content.substr(n, 2) == "¡£")
			cout << endl;
	}

	cout << endl << endl;
}

void poem_output_2(string content, vector<string> keyword_v)
{
	int num = content.size() / 2;
	vector<size_t> keyword_pos;
	for (int i = 0; i < keyword_v.size(); i++)
	{
		size_t pos = 0;
		do
		{
			pos = content.find(keyword_v[i], pos) + 2;
			keyword_pos.push_back(pos - 2);
			keyword_pos.push_back(keyword_v[i].size());
		} while (content.find(keyword_v[i], pos) != string::npos);

	}

	for (size_t n = 0; n < content.size(); n += 2)
	{
		bool logic = true;
		for (int i = 0; i < keyword_pos.size() && logic == true; i += 2)
			if (n >= keyword_pos[i] && n <= keyword_pos[i] + keyword_pos[i + 1] - 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				logic = false;
			}
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << content.substr(n, 2);
		if (content.substr(n, 2) == "¡£")
			cout << endl;
	}

	cout << endl << endl;
}
