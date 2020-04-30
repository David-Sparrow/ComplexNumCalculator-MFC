#pragma once
#include <math.h>

class CComplex
{
private:
	double m_re;
	double m_im;

public:
	CComplex(double realPart = 0.0, double imaginaryPart = 0.0);
	void operator=(const CComplex& num); //Tu byl problem
	friend bool operator==(const CComplex& left, const CComplex& right);
	friend bool operator!=(const CComplex& left, const CComplex& right);
	friend CComplex operator+(const CComplex& left, const CComplex& right);
	friend CComplex operator-(const CComplex& left, const CComplex& right);
	friend CComplex operator*(const CComplex& left, const CComplex& right);
	friend CComplex operator/(const CComplex& left, const CComplex& right);
	void operator+=(const CComplex& num);
	void operator-=(const CComplex& num);
	void operator*=(const CComplex& num);
	void operator/=(CComplex& num);
	void SetRealPart(double realPart);
	void SetImaginaryPart(double imaginaryPart);
	void Set(double realPart, double imaginaryPart);
	double GetRealPart() const;
	double GetImaginaryPart() const;
	CComplex Module() const;
	CComplex Coupled() const;
};

