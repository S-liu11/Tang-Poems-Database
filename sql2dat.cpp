#include "sqlite3.h"
#include "poet.h"
#include "poetry.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <string>

#pragma comment(lib, "kernel32.lib")

using namespace std;



void write_poet(poet _pt)
{
	ofstream poet_dat;
	poet_dat.open("poet_dat.dat", ios::binary | ios::app);
	if (!poet_dat)
	{
		cout << "poet_dat.dat cannot be opened!" << endl;
		return;
	}
	poet_dat.write((char*)&_pt, sizeof(_pt));
	poet_dat.close();
};

void write_poetry(poetry _pty, string _poetry_name, string _poetry)
{
	ofstream poetry_dat;
	poetry_dat.open("poetry_dat.dat", ios::binary | ios::app);
	if (!poetry_dat)
	{
		cout << "poetry_dat.dat cannot be opened!" << endl;
		return;
	}
	poetry_dat.write((char*)&_pty, sizeof(_pty));
	cout << _pty.show_poetry_name_size() << " " << _pty.show_poetry_size() << endl;
	cout << _poetry_name.size() << " " << _poetry.size() << endl;

	poetry_dat.write(_poetry_name.c_str(), _pty.show_poetry_name_size()+1);
	poetry_dat.write(_poetry.c_str(), _pty.show_poetry_size()+1);
	poetry_dat.close();
};

//Transform UTC-8 to GB2312
char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

//sqlite callback function, including present resluts in command prompt and write data in binary file.
static int callback_poet(void *data, int argc, char **argv, char **azColName) {
	//int i;
	poet pt;

	fprintf(stderr, "%s: ", (const char*)data);
	/*for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? U2G(argv[i]) : "NULL");
	}*/
	//write_poet();
	pt.store_id(atoi(argv[0]));
	pt.store_name(U2G(argv[1]));
	cout << pt.show_id() << ' ' << pt.show_name() << endl;
	write_poet(pt);
	printf("\n");
	return 0;
}
static int callback_poetries(void *data, int argc, char **argv, char **azColName) {
	//int i;
	poetry pty;
	string poetry_name_temp;
	string poetry_temp;

	fprintf(stderr, "%s: ", (const char*)data);
	/*for (i = 0; i<argc; i++) {
	printf("%s = %s\n", azColName[i], argv[i] ? U2G(argv[i]) : "NULL");
	}*/
	poetry_temp = U2G(argv[2]);
	poetry_name_temp = U2G(argv[3]);

	pty.store_poetry_id(atoi(argv[0]));
	pty.store_poet_id(atoi(argv[1]));
	pty.store_poetry_size(poetry_temp.size());
	pty.store_poetry_name_size(poetry_name_temp.size());

	//cout << pty.show_poetry_id() << ' ' << pty.show_poet_id() << ' ' << pty.show_poetry_size() << ' ' << pty.show_poetry_name_size() << endl;
	write_poetry(pty, poetry_name_temp, poetry_temp);
	printf("\n");
	return 0;
}

static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i<argc; i++) {
	printf("%s = %s\n", azColName[i], argv[i] ? U2G(argv[i]) : "NULL");
	}
	printf("\n");
	return 0;
}

sqlite3 * open_database()
{
	sqlite3 * res;
	int rc;
	/* Open database */
	rc = sqlite3_open("tangshi.sqlite", &res);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(res));
		return 0;
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
		return res;
	}

}

void create_poets_data_from(sqlite3 * database)
{
	char *sql;
	const char* data = "Callback function called";
	char *zErrMsg = 0;
	int rc;
	/* Create SQL statement */
	sql = "SELECT id, name FROM poets"; //extract id and name information from 'poets' table
										/* Execute SQL statement */
	rc = sqlite3_exec(database, sql, callback_poet, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
}
//main;

void create_poetries_data_from(sqlite3 * database)
{
	char *sql;
	const char* data = "Callback function called";
	char *zErrMsg = 0;
	int rc;
	/* Create SQL statement */
	sql = "SELECT * FROM poetries"; //extract id and name information from 'poets' table
										/* Execute SQL statement */
	rc = sqlite3_exec(database, sql, callback_poetries, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
}
//main;

void show_data_from(sqlite3 * database)
{
	char *sql;
	const char* data = "Callback function called";
	char *zErrMsg = 0;
	int rc;
	/* Create SQL statement */
	sql = "SELECT * FROM poets"; //extract id and name information from 'poets' table
									/* Execute SQL statement */
	rc = sqlite3_exec(database, sql, callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
}

int main()
{
	sqlite3 *db;
	db = open_database();
	//create_poets_data_from(db);
	create_poetries_data_from(db);
	//show_data_from(db);
	sqlite3_close(db);
	system("pause");
}

//id,poet_id,content,title