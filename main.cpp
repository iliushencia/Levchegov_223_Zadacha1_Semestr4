#include<iostream>
#include<stdio.h>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
int main() {
	Complex a (1,1);
	Complex b = a + a;
	Complex c = a - a;
	Complex d = b * c;
	CCompexVectorVert data1 (4,"data.txt");
	CCompexVectorHori data2 (4,"data.txt");
	data1.push_back(b);
	data2.push_back(c);
	data1.push_back(c);
	data2.push_back(d);
	data1.output("vertres.txt");
	data2.output("horires.txt");
return 0;
}
