#pragma once
#include "CComplex.h"
#include <string>
class CCanonComplex : public CComplex
{
public:
	CCanonComplex(const CComplex&);
	friend std::string& operator<<(std::string&, const CCanonComplex&);
	friend CString& operator<<(CString&, const CCanonComplex&);
};


double roundToTwoDecimals(double var);
