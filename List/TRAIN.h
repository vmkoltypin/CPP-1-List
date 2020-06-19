#pragma once
#include <string>  
#include <fstream>
using namespace std;
class Train
{
private:
	string dest;
	int num;
	int time;
public:
	Train();
	Train(string dest, int num,int time);

	int getNum();

	bool operator>(const Train& a);
	bool operator<(const Train& a);
	bool operator==(const Train& a);
	bool operator!=(const Train& a);
	Train& operator=(const Train& a);
	bool compare(const Train& a, const Train& b);
	static int compNum(const void* a, const void* b);
	//static int compSpree(const void* a, const void* b);

	friend ostream& operator << (ostream& os, const Train& a);
	friend istream& operator >>(istream& os, Train& a);
};

