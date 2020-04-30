#pragma once
#include "CComplex.h"
#include <string>
class CCanonComplex : public CComplex
{
public:
	CCanonComplex(const CComplex&);
	friend std::string& operator<<(std::string&, const CCanonComplex&);
};

