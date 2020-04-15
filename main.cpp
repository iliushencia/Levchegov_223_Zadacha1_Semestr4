#include<iostream>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
int main() {
	CCompexVector** res;
	res = new CCompexVector*[0];
	string* paths;
	paths = new string[0];
	int count = 0;
	string check = "", path="data.txt";
	ifstream input(path);
	if(input){
		string line;
		while (getline(input, line)) {
			string type = "", path = "";
			int l = 0;
			stringstream ss(line);
			ss >> type >> l >> path;
			string* temp;
			temp = paths;
			paths = new string[count+1];
			for (int i=0; i<count; i++) paths[i]=temp[i];
			paths[count]=path;
			if (type=="vert"){
				CCompexVector** temp;
				temp = res;
				res = new CCompexVector*[count+1];
				for (int i=0; i<count; i++) res[i]=temp[i];
				res[count]=(new CCompexVectorVert(l,line));
				count++;
			} else if (type=="hori") {
				CCompexVector** temp;
				temp = res;
				res = new CCompexVector*[count+1];
				for (int i=0; i<count; i++) res[i]=temp[i];
				res[count]=(new CCompexVectorHori(l,line));
				count++;
			}
		}
	}
	for (int i =0; i<count; i++){
		if(res[i]->output(paths[i])) continue;
		check = "error";
	}
	if (check=="") {cout<<"check all the output files"<<endl<<"Press any key to continue"<<endl;}
	else {cout<<check<<endl<<"Press any key to continue"<<endl;}
	cin >> check; //для того чтобы консолька не закрывалась
	return 0;
}

