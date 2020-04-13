#ifndef CCOMPLEXVECTOR0_H
#define CCOMPLEXVECTOR0_H
#include "complexvector.hpp"
#include"complexvector1.hpp"


class CCompexVectorVert :public CCompexVector{
	public:
	friend CCompexVectorVert& operator - (CCompexVector& a, CCompexVector& b);
	CCompexVectorVert(int l, const string& path) : CCompexVector(l, path) {}
	CCompexVectorVert() : CCompexVector() {}
	virtual bool output(const string& path);
};

CCompexVectorVert& operator + (const CCompexVector& a, const CCompexVector& b) ;


CCompexVectorVert& operator - (CCompexVector& a, CCompexVector& b) ;

#endif // CCOMPLEXVECTOR0_H

