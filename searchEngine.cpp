#include "poetry.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "statistics.h"

using namespace std;

void database_loading()
{
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	if (!pty_dat)
	{
		cout << "未找到唐诗数据库！" << endl;
		return;
	}
	else
		cout << "唐诗数据库载入完成...\n\n" << endl;
	pty_dat.close();
}

void search_poems_number_by_poet()
{
	int poems_number = 0;
	poetry pty;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	string str;
	system("cls");
	cin.clear();
	cin.ignore();
	cout << "请输入诗人名字：";
	getline(cin, str);
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{
		char* pty_name_ptr = new char[pty.show_poetry_name_size() + 1];
		char* pty_content_ptr = new char[pty.show_poetry_size() + 1];
		pty_dat.read(pty_name_ptr, pty.show_poetry_name_size() + 1);
		pty_dat.read(pty_content_ptr, pty.show_poetry_size() + 1);
		delete[] pty_name_ptr;
		delete[] pty_content_ptr;
		if (pty.show_poet_name() == str) poems_number++;
	}
	if (poems_number == 0)
	{
		cout << "未找到该诗人的作品。" << endl << endl;
	}
	else
	{
		cout << "诗人" << str << "的作品共收录有" << poems_number << "篇。" << endl;
	}
	pty_dat.close();
	system("pause");
}

void search_poems_by_name()
{
	int poems_number = 0;
	poetry pty;
	vector<string> pty_poet_res;
	vector<string> pty_name_res;
	vector<string> pty_content_res;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	string str, choice;
	system("cls");
	cin.clear();
	cin.ignore();
	cout << "请输入诗题或部分关键词：";
	getline(cin, str);
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{
		char* pty_name_ptr = new char[pty.show_poetry_name_size() + 1];
		char* pty_content_ptr = new char[pty.show_poetry_size() + 1];
		pty_dat.read(pty_name_ptr, pty.show_poetry_name_size() + 1);
		pty_dat.read(pty_content_ptr, pty.show_poetry_size() + 1);
		string name(pty_name_ptr);
		string content(pty_content_ptr);
		delete[] pty_name_ptr;
		delete[] pty_content_ptr;
		if (name.find(str) != string::npos)
		{
			poems_number++;
			pty_poet_res.push_back(pty.show_poet_name());
			pty_name_res.push_back(name);
			pty_content_res.push_back(content);
		}
	}
	if (poems_number == 0)
	{
		cout << "未找到诗题含有相关关键词的作品。" << endl << endl;
	}
	else
	{
		cout << "诗题含有\"" << str << "\"关键词的作品共收录有" << poems_number << "篇,是否查看(Y/N)？" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "诗题含有关键词\"" << str << "\"的作品有：" << endl << endl;
			if (poems_number > 10)
				cout << "作品数目过多，仅列举十首：\n\n";
			for (int i = 0; (i<10 && i<poems_number); i++)
			{
				cout << pty_name_res[i] << " " << pty_poet_res[i] << endl << endl;
				poem_output_0(pty_content_res[i]);
			}
		}

	}
	pty_dat.close();
	system("pause");
}

void search_poems_by_content_keyword()
{
	int poems_number = 0;
	poetry pty;
	vector<string> pty_poet_res;
	vector<string> pty_name_res;
	vector<string> pty_content_res;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	string str, choice;
	system("cls");
	cin.clear();
	cin.ignore();
	cout << "请输入诗句关键字词：";
	getline(cin, str);
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{
		char* pty_name_ptr = new char[pty.show_poetry_name_size() + 1];
		char* pty_content_ptr = new char[pty.show_poetry_size() + 1];
		pty_dat.read(pty_name_ptr, pty.show_poetry_name_size() + 1);
		pty_dat.read(pty_content_ptr, pty.show_poetry_size() + 1);
		string name(pty_name_ptr);
		string content(pty_content_ptr);
		delete[] pty_name_ptr;
		delete[] pty_content_ptr;
		if (content.find(str) != string::npos) 
		{
			poems_number++;
			pty_poet_res.push_back(pty.show_poet_name());
			pty_name_res.push_back(name);
			pty_content_res.push_back(content);
		}
	}
	if (poems_number == 0)
	{
		cout << "未找到诗句含有相关关键词的作品。" << endl << endl;
	}
	else
	{
		cout << "诗句含有关键字词\"" << str << "\"的作品共收录有" << poems_number << "篇,是否查看(Y/N)？" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "含有关键字词\"" << str << "\"的作品有：" << endl << endl;
			if (poems_number > 10)
				cout << "作品数目过多，仅列举十首：\n\n";
			for (int i = 0; (i<10 && i<poems_number); i++)
			{
				cout << pty_name_res[i] << " " << pty_poet_res[i] << endl << endl;
				poem_output_1(pty_content_res[i], str);
			}
		}
	}
	
	pty_dat.close();
	system("pause");
}

void search_poems_by_vague()
{
	int poems_number = 0;
	poetry pty;
	vector<string> pty_poet_res;
	vector<string> pty_name_res;
	vector<string> pty_content_res;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	string pty_name_str, pt_str, pty_content_str, choice;
	system("cls");
	cin.clear();
	cin.ignore();
	do 
	{
		cout << "请输入诗题关键字词，若无相关信息请输入‘0’：";
		getline(cin, pty_name_str);
		cout << "请输入诗人的名字或部分名字，若无相关信息请输入‘0’：";
		getline(cin, pt_str);
		cout << "请输入诗句关键字词，若无相关信息请输入‘0’：";
		getline(cin, pty_content_str);
		if (pty_name_str == "0" && pt_str == "0" && pty_content_str == "0")
		{
			cout << "请至少输入一条有效信息。\n" << endl;
			system("pause");
		}
	} while (pty_name_str == "0" && pt_str == "0" && pty_content_str == "0");
	
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{
		char* pty_name_ptr = new char[pty.show_poetry_name_size() + 1];
		char* pty_content_ptr = new char[pty.show_poetry_size() + 1];
		pty_dat.read(pty_name_ptr, pty.show_poetry_name_size() + 1);
		pty_dat.read(pty_content_ptr, pty.show_poetry_size() + 1);
		string name(pty_name_ptr);
		string content(pty_content_ptr);
		delete[] pty_name_ptr;
		delete[] pty_content_ptr;
		if ((name.find(pty_name_str) != string::npos || pty_name_str == "0") && (pty.show_poet_name().find(pt_str) != string::npos || pt_str == "0") && (content.find(pty_content_str) != string::npos || pty_content_str == "0"))
		{
			poems_number++;
			pty_poet_res.push_back(pty.show_poet_name());
			pty_name_res.push_back(name);
			pty_content_res.push_back(content);
		}
	}
	if (poems_number == 0)
	{
		cout << "未找到含有以上相关信息的作品。" << endl << endl;
	}
	else
	{
		cout << "含有以上以上关键内容的作品共有" << poems_number << "篇,是否查看(Y/N)？" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "含有关键信息" << " \'" << pty_name_str << "\'" << " \'" << pt_str << "\'" << " \'" << pty_content_str << "\' 的作品有：" << endl << endl;
			if (poems_number > 10)
				cout << "作品数目过多，仅列举十首：\n\n";
			for (int i = 0; (i<10 && i<poems_number); i++)
			{
				cout << pty_name_res[i] << " " << pty_poet_res[i] << endl << endl;
				poem_output_1(pty_content_res[i], pty_content_str);
			}
		}
	}
	
	pty_dat.close();
	system("pause");
}

void search_poems_by_multiple_content_keywords()
{
	int poems_number = 0;
	int n = 0;
	poetry pty;
	vector<string> str_v;
	vector<string> pty_poet_res;
	vector<string> pty_name_res;
	vector<string> pty_content_res;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	string str, choice;
	system("cls");
	cin.clear();
	cin.ignore();
	do
	{
		cout << "请输入诗句第" << n+1 << "项关键词,若无更多关键词，输入‘0’并回车以结束：";
		getline(cin, str);
		if (str != "0")
		{
			n++;
			str_v.push_back(str);
		}	
	} while (str != "0");
	
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{
		int count = 0;
		char* pty_name_ptr = new char[pty.show_poetry_name_size() + 1];
		char* pty_content_ptr = new char[pty.show_poetry_size() + 1];
		pty_dat.read(pty_name_ptr, pty.show_poetry_name_size() + 1);
		pty_dat.read(pty_content_ptr, pty.show_poetry_size() + 1);
		string name(pty_name_ptr);
		string content(pty_content_ptr);
		delete[] pty_name_ptr;
		delete[] pty_content_ptr;
		for (int i = 0; i < str_v.size(); i++)
		{
			
			if (content.find(str_v[i]) != string::npos)
			{
				count++;
			}
			
		}
		if (count == n)
		{
			poems_number++;
			pty_poet_res.push_back(pty.show_poet_name());
			pty_name_res.push_back(name);
			pty_content_res.push_back(content);
		}
		
	}
	if (poems_number == 0)
	{
		cout << "未找到诗句含有相关关键词的作品。" << endl << endl;
	}
	else
	{
		cout << "诗句含有关键字词 ";
		for (int i = 0; i < n; i++)
		{
			cout << "\"" << str_v[i] << "\" ";
		}
		cout << "的作品共收录有" << poems_number << "篇,是否查看(Y/N)？" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "含有关键字词 ";
			for (int i = 0; i < n; i++)
			{
				cout << "\"" << str_v[i] << "\" ";
			}
			cout << "的作品共有:" << endl << endl;
			if (poems_number > 10)
				cout << "作品数目过多，仅列举十首：\n\n";
			for (int i = 0; (i<10 && i<poems_number); i++)
			{
				cout << pty_name_res[i] << " " << pty_poet_res[i] << endl << endl;
				poem_output_2(pty_content_res[i], str_v);
			}
		}
	}

	pty_dat.close();
	system("pause");
}

int main()
{
	int num;
	do {
		database_loading();
		cout << "\n欢迎使用唐诗搜索引擎：\n" << endl;
		cout << "01.诗人作品收录量查询" << endl;
		cout << "02.诗题关键字词查询" << endl;
		cout << "03.诗句关键字词查询" << endl;
		cout << "04.诗题诗人诗句模糊查询" << endl;
		cout << "05.诗句多项关键字词查询" << endl;
		cout << "06.数据一览" << endl;
		cout << "08.退出\n" << endl;
		cout << "请输入相应数字继续：";
		cin >> num;

		while (cin.fail())
		{
			cout << "非法字符。" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "请输入相应数字继续：";
			cin >> num;
		}

		switch (num)
		{
		case 1:
			search_poems_number_by_poet();
			break;
		case 2:
			search_poems_by_name();
			break;
		case 3:
			search_poems_by_content_keyword();
			break;
		case 4:
			search_poems_by_vague();
			break;
		case 5:
			search_poems_by_multiple_content_keywords();
			break;
		case 6:
			statistics();
			break;
		case 8:
			cout << "\n感谢您的使用！" << endl;
			system("pause");
			break;
		default:
			cout << "无对应选项。" << endl;
			system("pause");
			break;
		}

		system("cls");
	} while (num != 8);
	
	
}