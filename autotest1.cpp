#include<iostream>
#include<string>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
using namespace std;

bool autotest1() {
	ofstream in;          // поток для записи
	in.open("test1.txt");
	in << "hori 5 none.txt 1+1i 2+2i 3+3i 4+4i 5+5i" << endl << "vert 5 none.txt -1-1i -2-2i -3-3i -4-4i -5-5i";
	in.close();
	CCompexVector** res1;
	res1 = new CCompexVector*[0];
	string* paths;
	paths = new string[0];
	int count = 0;
	string check = "", path = "test1.txt";
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
			for (int i = 0; i<count; i++) paths[i] = temp[i];
			paths[count] = path;
			if (type == "vert") {
				CCompexVector** temp;
				temp = res1;
				res1 = new CCompexVector*[count + 1];
				for (int i = 0; i<count; i++) res1[i] = temp[i];
				res1[count] = (new CCompexVectorVert(l, line));
				count++;
			}
			else if (type == "hori") {
				CCompexVector** temp;
				temp = res1;
				res1 = new CCompexVector*[count + 1];
				for (int i = 0; i<count; i++) res1[i] = temp[i];
				res1[count] = (new CCompexVectorHori(l, line));
				count++;
			}
		}
		(*res1[0] + *res1[1]).output("test1.txt");

	}
	ifstream out("test2.txt");
	string line;
	while (getline(out, line)) {
		if (line == "0+0i") continue;
		return false;
	}
	return true;
}