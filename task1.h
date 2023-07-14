
using namespace std;
#include<fstream>
#include <iostream>

int findTheLessSTR() {
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
	char* min = new char[100];
	for (int i = 0; str[i] != ' '; i++) {
		min[i] = str[i];
		if (str[i + 1] == '\0') {
			min[i + 1] = '\0';
		}
	}
	k = 0;
	char* word = new char[100];
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			word[k] = '\0';
			if (strlen(word) < strlen(min)) {
				size_t w = strlen(word);
				for (int j = 0; j<= w; j++) {
					if (j == w) {
						min[j + 1] = '\0';
					}
					min[j] = word[j];
				}
				k = 0;
				i++;
			}
    	}
		word[k] = str[i];
		k++;
	}
	cout << "The less word is \"" << min << "\".\n";
	return 0;
}


	
