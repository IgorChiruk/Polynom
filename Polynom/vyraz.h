#pragma once
#include "stdafx.h"

class vyraz
{
	vector <perem> v;
public:
	vyraz();
	vyraz(float x[], int sizeX, float y[], int sizeY);
	void uprostit();
	vector<perem> del(vector<perem> q, int e);
	vyraz & operator+(vyraz & x);
	vyraz & operator-(vyraz & x);
	vyraz & operator*(vyraz & x);
	vyraz & operator/(vyraz & x);
	vyraz & operator=(vyraz & x);
	void display();
	~vyraz();
};

