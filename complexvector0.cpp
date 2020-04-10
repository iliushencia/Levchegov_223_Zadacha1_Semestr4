#include"complexvector0.hpp"

	virtual void CCompexVectorVert::output(const string& path) {
		 ofstream out;          // поток для записи
		 out.open(path); // окрываем файл для записи
		if (out.is_open()) {
			for(int i=0; i<this->size(); i++) {
				this->dat()[i].i()>=0 ? out<<this->dat()[i].r()<<"+"<<dat()[i].i()<<"i"<<endl :
						out<<this->dat()[i].r()<<dat()[i].i()<<"i"<<endl;
			}
		}
	}

CCompexVectorVert&  operator + (const CCompexVector& a, const CCompexVector& b) {
	CCompexVectorVert* res = new CCompexVectorVert [0];
	if(a.size()>=b.size()){
		for(int i=0; i<b.size(); i++){
			res->push_back(a.dat()[i]+b.dat()[i]);
		}
		for(int i=b.size(); i<a.size(); i++){
			res->push_back(a.dat()[i]);
		}
	} else {
		for(int i=0; i<a.size(); i++){
			res->push_back(a.dat()[i]+b.dat()[i]);
		}
		for(int i=a.size(); i<b.size(); i++){
			res->push_back(b.dat()[i]);
		}
	}
	return *res;
}


CCompexVectorVert& operator - (CCompexVector& a, CCompexVector& b) {
	CCompexVectorVert* res = new CCompexVectorVert [0];
	if(a.size()>=b.size()){
		for(int i=0; i<b.size(); i++){
			res->push_back(a.dat()[i]-b.dat()[i]);
		}
		for(int i=b.size(); i<a.size(); i++){
			res->push_back(a.dat()[i]);
		}
	} else {
		for(int i=0; i<a.size(); i++){
			res->push_back(a.dat()[i]-b.dat()[i]);
		}
		for(int i=a.size(); i<b.size(); i++){
			res->push_back(0-b.dat()[i]);
		}
	}
	return *res;
}
