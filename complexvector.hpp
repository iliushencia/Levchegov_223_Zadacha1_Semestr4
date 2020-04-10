#ifndef CCOMPLEXVECTOR_H
#define CCOMPLEXVECTOR_H
#include "complexnumber.h"
#include <iomanip>
#include <fstream>
class CCompexVector {
protected:
	CCompexVector(int l, const string& path) ;

public:
	virtual void output(const string& path)=0;
	CCompexVector() ;

	virtual ~CCompexVector() ;

	void push_back(const Complex& num) ;
	CCompexVector& operator = (const CCompexVector& a) ;
	int size() const ;
	Complex* dat() const ;
private:
	int len;
	Complex* data;
};

Complex operator * (const CCompexVector& a, const CCompexVector& b) ;
#endif // CCOMPLEXVECTOR_H

