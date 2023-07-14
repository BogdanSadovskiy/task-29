using namespace std;
#include<fstream>
#include <iostream>
#include <string>
#include "task1.h"
#include "task2.h"
#define task 2


int main()
{
	string str;
	ofstream input;
	cout << "Input some str\n";
	getline(cin, str);
	input.open("ex 1.txt");
	if (!input.is_open()) {
		cout << "Error while creating\n";
		return 1;
	}
	input << str;
	input.close();
#if task == 1
	findTheLessSTR();
#elif task == 2
	task_2();

#endif 

}


