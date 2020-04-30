#include "pch.h"
#include "CComplex.h"



CComplex::CComplex(double realPart, double imaginaryPart)
{
	m_re = realPart;
	m_im = imaginaryPart;
}

void CComplex::operator=(const CComplex & num)//Tu byl problem
{
	this->m_re = num.m_re;
	this->m_im = num.m_im;
}

void CComplex::operator+=(const CComplex & num)
{
	this->m_im += num.m_im;
	this->m_re += num.m_re;
}

void CComplex::operator-=(const CComplex & num)
{
	this->m_im -= num.m_im;
	this->m_re -= num.m_im;
}

void CComplex::operator*=(const CComplex & num)
{
	double firstReal = this->m_re * num.m_re;
	double secondReal = -this->m_im * num.m_im;
	double firstIm = this->m_re * num.m_im;
	double secondIm = this->m_im * num.m_re;
	this->m_re = firstReal + secondReal;
	this->m_im = firstIm + secondIm;
}

void CComplex::operator/=(CComplex & num)
{
	CComplex counter = *this * num.Coupled();
	CComplex denominator = num * num.Coupled();
	this->m_re = counter.m_re / denominator.m_re;
	this->m_im = counter.m_im / denominator.m_re;
}

void CComplex::SetRealPart(double realPart)
{
	m_re = realPart;
}

void CComplex::SetImaginaryPart(double imaginaryPart)
{
	m_im = imaginaryPart;
}

void CComplex::Set(double realPart, double imaginaryPart)
{
	m_re = realPart;
	m_im = imaginaryPart;
}

double CComplex::GetRealPart() const
{
	return m_re;
}

double CComplex::GetImaginaryPart() const
{
	return m_im;
}

CComplex CComplex::Module() const
{
	return CComplex(sqrt(m_re * m_re + m_im * m_im), 0.0);
}

CComplex CComplex::Coupled() const
{
	return CComplex(m_re, -m_im);
}


bool operator==(const CComplex& left, const CComplex & right)
{
	if (left.m_re == right.m_re && left.m_im == right.m_im)
	{
		return true;
	}
	else
		return false;
}

bool operator!=(const CComplex & left, const CComplex & right)
{
	return !(left == right);
}

CComplex operator+(const CComplex& left, const CComplex& right)
{
	return CComplex(left.m_re + right.m_re, left.m_im + right.m_im);
}

CComplex operator-(const CComplex & left, const CComplex & right)
{
	return CComplex(left.m_re - right.m_re, left.m_im - right.m_im);
}

CComplex operator*(const CComplex & left, const CComplex & right)
{
	double firstReal = left.m_re * right.m_re;
	double secondReal = -left.m_im * right.m_im;
	double firstIm = left.m_re * right.m_im;
	double secondIm = left.m_im * right.m_re;
	return CComplex(firstReal + secondReal, firstIm + secondIm);
}

CComplex operator/(const CComplex & left, const CComplex& right)
{
	CComplex counter = left * right.Coupled();
	CComplex denominator = right * right.Coupled();
	return CComplex(counter.m_re / denominator.m_re, counter.m_im / denominator.m_re);
}
