#pragma once

#include <iostream>
#include <fstream>
#include "poetry.h"

using namespace std;

void statistics()
{
	int pty_num;
	int pt_num;
	int max_;
	poetry pty;
	ifstream pty_dat;
	pty_dat.open("poetry_dat2.dat", ios::binary);
	while (pty_dat.read((char*)&pty, sizeof(pty)))
	{

	}
}