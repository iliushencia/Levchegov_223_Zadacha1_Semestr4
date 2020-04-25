#include"complexvector0.hpp"

	bool CCompexVectorVert :: output(const string& path) {
		 ofstream out;          // поток для записи
		 out.open(path); // окрываем файл для записи
		if (out.is_open()) {
			int k = this->size();
			for(int i=0; i<k; i++) {
				this->dat()[i].i()>=0 ? out<<this->dat()[i].r()<<"+"<<dat()[i].i()<<"i"<<endl :
						out<<this->dat()[i].r()<<dat()[i].i()<<"i"<<endl;
				
			}
			out.close();
			return true;
		}
		return false;
	}

	CCompexVector&  operator + (const CCompexVector& a,const CCompexVector& b) {
	int size = 0, len =0;
	if (a.size() >= b.size()) {
		size = b.size();
		len = a.size();
	} else {
		size = a.size();
		len = b.size();
	}
	auto res = new CCompexVectorVert(len);
	res->nullall();
	int i = 0;
	for (i = 0; i < size; ++i) {
	res->add(i, a);
	res->add(i, b);
	}
	return *res;
	}


	CCompexVector&  operator - (const CCompexVector& a, const CCompexVector& b) {
		int size = 0, len = 0;
		if (a.size() >= b.size()) {
			size = b.size();
			len = a.size();
		}
		else {
			size = a.size();
			len = b.size();
		}
		auto res = new CCompexVectorVert(len);
		res->nullall();
		int i = 0;
		for (i = 0; i < size; ++i) {
			res->add(i, a);
			res->sub(i, b);
		}
		return *res;
	}