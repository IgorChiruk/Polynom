#include "stdafx.h"
#include "perem.h"


perem::perem()
{
	this->koef= 0;
	this->step= 0;
}

perem::perem(int a,float b)
{
	this->setKoef (b);
	this->setStep(a);
}

void perem::setKoef(float a) 
{
	this->koef = a;
}

void perem::setStep(int a)
{
	this->step = a;
}

perem & perem::operator +(perem & x) 
{
	perem *result=new perem;
	if (this->stepen() == x.stepen()) 
	{
		result->setStep(this->stepen());
		result->setKoef(this->koef + x.koef);
	}
	return *result;
}

perem & perem::operator -(perem & x) 
{
	perem result;
	if (this->stepen() == x.stepen())
	{
		result.setStep(this->stepen());
		result.setKoef(this->Koef() - x.Koef());
	}
	return result;
}

perem & perem::operator *(perem & x) 
{
	perem *result=new perem;

	result->setStep(this->stepen() + x.stepen());
	result->setKoef(this->Koef() * x.Koef());

	return *result;
}

perem & perem::operator /(perem & x)
{
	perem result;

	result.setStep(this->stepen() - x.stepen());
	result.setKoef(this->Koef() / x.Koef());

	return result;
}

perem & perem::operator = (perem & x)
{
	this->setKoef(x.Koef());
	this->setStep(x.stepen());
	return *this;
}


void perem::display()
{
	if (this->stepen() == 0)
		printf("%.2lf", 1.0);
}

int perem::stepen() 
{
	return this->step;
}

float perem::Koef()
{
	return this->koef;
}

perem::~perem()
{
}
