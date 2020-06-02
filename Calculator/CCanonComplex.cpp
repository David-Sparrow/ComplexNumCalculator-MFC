#include "pch.h"
#include "CCanonComplex.h"

double roundToTwoDecimals(double var)
{
	double value = (int)(var * 100 + .5);
	return (double)value / 100;
}


CCanonComplex::CCanonComplex(const CComplex &x)
{
	this->Set(x.GetRealPart(), x.GetImaginaryPart());
}

std::string & operator<<(std::string & str, const CCanonComplex &x)
{
	if (x.GetImaginaryPart() >= 0.0)
	{
		int delimiter = std::to_string(x.GetRealPart()).find('.');
		str += std::to_string(roundToTwoDecimals(x.GetRealPart())).substr(0, delimiter + 3);
		str.append(" + ");
		delimiter = std::to_string(abs(x.GetImaginaryPart())).find('.');
		str += std::to_string(roundToTwoDecimals(abs(x.GetImaginaryPart()))).substr(0, delimiter + 3);
		str.append("i");
		return str;
	}
	else
	{
		int delimiter = std::to_string(x.GetRealPart()).find('.');
		str += std::to_string(roundToTwoDecimals(x.GetRealPart())).substr(0, delimiter + 3);
		str.append(" - ");
		delimiter = std::to_string(abs(x.GetImaginaryPart())).find('.');
		str += std::to_string(roundToTwoDecimals(abs(x.GetImaginaryPart()))).substr(0, delimiter + 3);
		str.append("i");
		return str;
	}
	
}

CString & operator<<(CString & cstring, const CCanonComplex &x)
{
	std::string str;
	str << x;
	cstring = CString(str.c_str());
	return cstring;
}
