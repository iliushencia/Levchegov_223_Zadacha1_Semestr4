#include<iostream>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
using namespace std;

bool autotest1();
bool autotest2();

int main() {
	cout << "Test1: ";
	if (autotest1()) {
		cout << "done" << endl;
	}
	else {
			cout << "error" << endl;
			return -1;
	}
	cout << "Test2: ";
	if (autotest2()) {
		cout << "done" << endl;
	}
	else {
		cout << "error" << endl;
		return -1;
	}
	CCompexVector** res;
	res = new CCompexVector*[0];
	string* paths;
	paths = new string[0];
	int count = 0;
	string check = "", path="data.txt";
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
				temp = res;
				res = new CCompexVector*[count + 1];
				for (int i = 0; i<count; i++) res[i] = temp[i];
				res[count] = (new CCompexVectorVert(l, line));
				count++;
			}
			else if (type == "hori") {
				CCompexVector** temp;
				temp = res;
				res = new CCompexVector*[count + 1];
				for (int i = 0; i<count; i++) res[i] = temp[i];
				res[count] = (new CCompexVectorHori(l, line));
				count++;
			}
		}
		
	} else {
		cout << "Error! Cannot open " << path << endl;
		return -1;
	}
	for (int i =0; i<count; i++){
		if(res[i]->output(paths[i])) continue;
		check = "error";
	}
	if (check=="") {cout<<"check all the output files"<<endl<<"Press any key to continue"<<endl;}
	else {cout<<check<<endl<<"Press any key to continue"<<endl;}
	cin >> check; //��� ���� ����� ��������� �� �����������
	return 0;
}
