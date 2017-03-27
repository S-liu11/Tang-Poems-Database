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
		cout << "δ�ҵ���ʫ���ݿ⣡" << endl;
		return;
	}
	else
		cout << "��ʫ���ݿ��������...\n\n" << endl;
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
	cout << "������ʫ�����֣�";
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
		cout << "δ�ҵ���ʫ�˵���Ʒ��" << endl << endl;
	}
	else
	{
		cout << "ʫ��" << str << "����Ʒ����¼��" << poems_number << "ƪ��" << endl;
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
	cout << "������ʫ��򲿷ֹؼ��ʣ�";
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
		cout << "δ�ҵ�ʫ�⺬����عؼ��ʵ���Ʒ��" << endl << endl;
	}
	else
	{
		cout << "ʫ�⺬��\"" << str << "\"�ؼ��ʵ���Ʒ����¼��" << poems_number << "ƪ,�Ƿ�鿴(Y/N)��" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "ʫ�⺬�йؼ���\"" << str << "\"����Ʒ�У�" << endl << endl;
			if (poems_number > 10)
				cout << "��Ʒ��Ŀ���࣬���о�ʮ�ף�\n\n";
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
	cout << "������ʫ��ؼ��ִʣ�";
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
		cout << "δ�ҵ�ʫ�京����عؼ��ʵ���Ʒ��" << endl << endl;
	}
	else
	{
		cout << "ʫ�京�йؼ��ִ�\"" << str << "\"����Ʒ����¼��" << poems_number << "ƪ,�Ƿ�鿴(Y/N)��" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "���йؼ��ִ�\"" << str << "\"����Ʒ�У�" << endl << endl;
			if (poems_number > 10)
				cout << "��Ʒ��Ŀ���࣬���о�ʮ�ף�\n\n";
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
		cout << "������ʫ��ؼ��ִʣ����������Ϣ�����롮0����";
		getline(cin, pty_name_str);
		cout << "������ʫ�˵����ֻ򲿷����֣����������Ϣ�����롮0����";
		getline(cin, pt_str);
		cout << "������ʫ��ؼ��ִʣ����������Ϣ�����롮0����";
		getline(cin, pty_content_str);
		if (pty_name_str == "0" && pt_str == "0" && pty_content_str == "0")
		{
			cout << "����������һ����Ч��Ϣ��\n" << endl;
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
		cout << "δ�ҵ��������������Ϣ����Ʒ��" << endl << endl;
	}
	else
	{
		cout << "�����������Ϲؼ����ݵ���Ʒ����" << poems_number << "ƪ,�Ƿ�鿴(Y/N)��" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "���йؼ���Ϣ" << " \'" << pty_name_str << "\'" << " \'" << pt_str << "\'" << " \'" << pty_content_str << "\' ����Ʒ�У�" << endl << endl;
			if (poems_number > 10)
				cout << "��Ʒ��Ŀ���࣬���о�ʮ�ף�\n\n";
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
		cout << "������ʫ���" << n+1 << "��ؼ���,���޸���ؼ��ʣ����롮0�����س��Խ�����";
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
		cout << "δ�ҵ�ʫ�京����عؼ��ʵ���Ʒ��" << endl << endl;
	}
	else
	{
		cout << "ʫ�京�йؼ��ִ� ";
		for (int i = 0; i < n; i++)
		{
			cout << "\"" << str_v[i] << "\" ";
		}
		cout << "����Ʒ����¼��" << poems_number << "ƪ,�Ƿ�鿴(Y/N)��" << endl;
		getline(cin, choice);
		if (choice == "Y")
		{
			system("cls");
			cout << "���йؼ��ִ� ";
			for (int i = 0; i < n; i++)
			{
				cout << "\"" << str_v[i] << "\" ";
			}
			cout << "����Ʒ����:" << endl << endl;
			if (poems_number > 10)
				cout << "��Ʒ��Ŀ���࣬���о�ʮ�ף�\n\n";
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
		cout << "\n��ӭʹ����ʫ�������棺\n" << endl;
		cout << "01.ʫ����Ʒ��¼����ѯ" << endl;
		cout << "02.ʫ��ؼ��ִʲ�ѯ" << endl;
		cout << "03.ʫ��ؼ��ִʲ�ѯ" << endl;
		cout << "04.ʫ��ʫ��ʫ��ģ����ѯ" << endl;
		cout << "05.ʫ�����ؼ��ִʲ�ѯ" << endl;
		cout << "06.����һ��" << endl;
		cout << "08.�˳�\n" << endl;
		cout << "��������Ӧ���ּ�����";
		cin >> num;

		while (cin.fail())
		{
			cout << "�Ƿ��ַ���" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "��������Ӧ���ּ�����";
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
			cout << "\n��л����ʹ�ã�" << endl;
			system("pause");
			break;
		default:
			cout << "�޶�Ӧѡ�" << endl;
			system("pause");
			break;
		}

		system("cls");
	} while (num != 8);
	
	
}