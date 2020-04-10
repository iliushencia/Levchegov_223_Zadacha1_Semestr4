#include "complexvector.hpp"

	CCompexVector::CCompexVector(int l, const string& path) {
			len=0;
			data = new Complex[l];
			int re=0, im=0;
			char sign = ' ';
			ifstream input(path);
			if(input){
				string line;
				while (getline(input, line)) {
				stringstream ss(line);
				ss>>re>>sign>>im;
				if(sign=='-') im=-im;
				Complex num (re,im);
				data[len]=num;
				len++;
				}
				if(len!=l){
					cout<<"SIZE ERROR"<<endl;
					delete[] data;
				}
			} else { cout<<"ERROR FILE" <<endl;}

		}

	CCompexVector::CCompexVector() {
		len=0;
		data = {};
	}

	CCompexVector::~CCompexVector() {
		delete[] data;
	}

	void CCompexVector::push_back(const Complex& num) {
		Complex* old = data;
		data = new Complex [len+1];
		for (int i = 0; i<len; i++){
			data[i]=old[i];
		}
		data[len]=num;
		len++;
	}
	CCompexVector& CCompexVector::operator = (const CCompexVector& a) {
		this->len=a.len;
		this->data=a.data;
		return *this;
	}
	int CCompexVector::size() const {
		return len;
	}
	Complex* CCompexVector::dat() const {
		return data;
	}

Complex operator * (const CCompexVector& a, const CCompexVector& b) {
	Complex res=0;
	if(a.size()>=b.size()){
		for(int i=0; i<b.size(); i++){
			res=res+a.dat()[i]*b.dat()[i];
		}
	} else {
		for(int i=0; i<a.size(); i++){
			res=res+a.dat()[i]*b.dat()[i];
		}
	}
	return res;
}
