#include<string>

using namespace std;

class poet
{
private:
	int id;
	char name[15];
public:
	void store_id(int);
	void store_name(char*);
	int show_id();
	char* show_name();
};

void poet::store_id(int _id)
{
	id = _id;
};

void poet::store_name(char* _name)
{
	strcpy_s(name, 15, _name);
};

int poet::show_id()
{
	return id;
};

char* poet::show_name()
{
	return name;
};
