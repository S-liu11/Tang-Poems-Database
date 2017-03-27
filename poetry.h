#include<string>

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

