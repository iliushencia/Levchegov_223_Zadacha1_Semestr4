#include<iostream>
#include<string>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
using namespace std;

bool autotest2() {
	ofstream in;          // поток для записи
	in.open("test2.txt");
	in << "hori 5 none.txt 1+1i 2+2i 3+3i 4+4i 5+5i" << endl << "vert 5 none.txt 1+1i 2+2i 3+3i 4+4i 5+5i";
	in.close();
	CCompexVector** res;
	res = new CCompexVector*[0];
	string* paths;
	paths = new string[0];
	int count = 0;
	string check = "", path = "test2.txt";
	ifstream input(path);
	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			string type = "", path = "";
			int l = 0;
			stringstream ss(line);
			ss >> type >> l >> path;
			string* temp;
			temp = paths;
			paths = new string[count + 1];
			for (int i = 0; i < count; i++) paths[i] = temp[i];
			paths[count] = path;
			if (type == "vert") {
				CCompexVector** temp;
				temp = res;
				res = new CCompexVector*[count + 1];
				for (int i = 0; i < count; i++) res[i] = temp[i];
				res[count] = (new CCompexVectorVert(l, line));
				count++;
			}
			else if (type == "hori") {
				CCompexVector** temp;
				temp = res;
				res = new CCompexVector*[count + 1];
				for (int i = 0; i < count; i++) res[i] = temp[i];
				res[count] = (new CCompexVectorHori(l, line));
				count++;
			}
		}
		(*res[0] - *res[1]).output("test2.txt");
	}
	ifstream out("test2.txt");
	string line;
	while (getline(out, line)) {
		if (line == "0+0i" ) continue;
		return false;
	}
	return true;
}