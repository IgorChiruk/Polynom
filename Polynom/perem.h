#pragma once
class perem
{
	float koef;
	int step;
public:
	perem();
	perem(int a, float b);
	void setKoef(float a);
	void setStep(int a);
	perem & operator+(perem & x);
	perem & operator-(perem & x);
	perem & operator*(perem & x);
	perem & operator/(perem & x);
	perem & operator=(perem & x);
	void display();
	int stepen();
	float Koef();
	~perem();
};

