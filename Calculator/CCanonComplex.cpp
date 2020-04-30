#include "pch.h"
#include "CCanonComplex.h"

CCanonComplex::CCanonComplex(const CComplex &x)
{
	this->Set(x.GetRealPart(), x.GetImaginaryPart());
}

std::string & operator<<(std::string & str, const CCanonComplex &x)
{
	if (x.GetImaginaryPart() >= 0.0)
	{
		str += std::to_string(x.GetRealPart());
		str.append(" + ");
		str += std::to_string(x.GetImaginaryPart());
		str.append("i");
		return str;
	}
	else
	{
		str += std::to_string(x.GetRealPart());
		str.append(" - ");
		str += std::to_string(abs(x.GetImaginaryPart()));
		str.append("i");
		return str;
	}
	
}
