using namespace std;
#include<fstream>
#include <iostream>

int task_2() {
	char* str = new char[1000];
	ifstream output;
	output.open("ex 1.txt");
	if (!output.is_open()) {
		cout << "Error while reading\n";
		return 1;
	}
	int k = 0;
	while (output.get(str[k])) {
		k++;
	}
	str[k] = '\0';
	output.close();
	int add = 0, nul = 0, minus = 0, word = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '-' && ((int)str[i + 1] > 48 && (int)str[i + 1]<58)) {
			while ((int)str[i + 1] > 47 && (int)str[i + 1] < 58) {
				i++;
			}
			minus++;
			continue;
		}
		if (str[i] == '0') {
			nul++;
			continue;
		}
		if ((int)str[i] > 48 && (int)str[i] < 58) {
			while ((int)str[i + 1] > 47 && (int)str[i + 1] < 58) {
				i++;
			}
			add++;
			continue;
		}
		if (((int)str[i] > 64 && (int)str[i] < 91) || ((int)str[i] > 96 && (int)str[i] < 123)) {
			while (((int)str[i+1] > 64 && (int)str[i+1] < 91) || ((int)str[i+1] > 96 && (int)str[i+1] < 123)) {
				i++;
			}
			word++;
			continue;
		}
	}
	ofstream dates;
	dates.open("dates.txt");
	if (!dates.is_open()) {
		return 1;
	}
	dates << "Minus - " << minus << endl;
	dates << "Add --- " << add << endl;
	dates << "Null -- " << nul << endl;
	dates << "Words - " << word << endl;

	cout << "Minus - " << minus << endl;
	cout << "Add --- " << add << endl;
	cout << "Null -- " << nul << endl;
	cout << "Words - " << word << endl;
}