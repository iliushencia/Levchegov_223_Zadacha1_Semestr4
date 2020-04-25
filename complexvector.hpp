#ifndef CCOMPLEXVECTOR_H
#define CCOMPLEXVECTOR_H
#include "complexnumber.h"
#include <iomanip>
#include <fstream>
class CCompexVector {
protected:
	CCompexVector(int l, const string& line) ;
	CCompexVector(int l) ;

public:
	virtual bool output(const string& path)=0;
	CCompexVector() ;

	virtual ~CCompexVector() ;

	void push_back(const Complex& num) ;
	CCompexVector& operator = (const CCompexVector& a) ;
	int size() const ;
	Complex* dat() const ;
	void add(int i, const CCompexVector& a) ;
	void sub(int i, const CCompexVector& a);
	void nullall() ;
private:
	int len;
	Complex* data;
};

Complex operator * (const CCompexVector& a, const CCompexVector& b) ;
#endif // CCOMPLEXVECTOR_H

