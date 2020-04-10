#ifndef CCOMPLEXVECTOR1_H
#define CCOMPLEXVECTOR1_H
#include "complexvector.hpp"

class CCompexVectorHori :public CCompexVector{
	public:
	CCompexVectorHori(int l, const string& path) : CCompexVector(l, path) {}
	virtual bool output(const string& path) ;
};

#endif // CCOMPLEXVECTOR1_H
