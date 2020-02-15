#include "stdafx.h"
#include "vyraz.h"

vyraz::vyraz()
{
}

vyraz::vyraz(float x[], int sizeX, float y[],int sizeY)
{
	vyraz itog;
	for (int j = 0; j < sizeY; j++) {
		vector<vyraz> temp;
		for (int i = 0; i < sizeX; i++)
		{
			if (i == j)
				continue;
			else
			{
				perem a, b;
				a.setKoef(1.0);
				a.setStep(1);
				b.setKoef(0 - x[i]);
				vyraz s;
				s.v.push_back(a);
				s.v.push_back(b);
				temp.push_back(s);
			}
		}
		vyraz chisl=temp[0];
		for (int k = 1; k < temp.size(); k++) 
		{
			chisl = chisl * temp[k];
		}

		float znam=1;
		for (int i = 0; i < sizeX; i++) 
		{
			if (i == j)
				continue;
			else
				znam = znam*(x[j] - x[i]);
		}
		perem mn(0,(y[j]/znam));
		for (int i = 0; i < chisl.v.size(); i++)
			chisl.v[i] = chisl.v[i] * mn;

		for (int i = 0; i < chisl.v.size(); i++)
			itog.v.push_back(chisl.v[i]);
	}
	itog.uprostit();
	itog.display();
}

void vyraz::uprostit() 
{
	vector<perem> q(this->v);
	vector<perem> result;
	this->v.clear();
	for (int i = 0; i < q.size(); i++) 
	{
		perem temp(q[i].stepen(), q[i].Koef());
		perem temp1;
		q = this->del(q, i);
		i--;
		/*q.erase(q.begin() + i);*/                          /*бнопня!!!!!!!*/
		for (int j = 0; j < q.size(); j++) 
		{
			if (q[j].stepen() == temp.stepen()) 
			{
				temp1 = q[j];
				q = this->del(q, j);
				j--;
				/*q.erase(q.begin() + i);*/					/*бнопня!!!!!!!*/
				temp =temp+temp1;
			}
		}
		result.push_back(temp);
	}
	this->v = result;
}

vector<perem> vyraz::del(vector<perem> q,int e)
{
	vector<perem> result;
	for (int i = 0; i < q.size(); i++) 
	{
		if (i == e)
			continue;
		else 
		result.push_back(q[i]);
	}
	return result;
}

vyraz & vyraz::operator +(vyraz & x)
{
	vyraz result;
	
	return result;
}

vyraz & vyraz::operator -(vyraz & x)
{
	vyraz result;
	vyraz temp;
	return result;
}

vyraz & vyraz::operator *(vyraz & x)
{
	vyraz *result=new vyraz;
	for (int i = 0; i < this->v.size(); i++) 
	{
		for (int j = 0; j < x.v.size(); j++) 
		{
			perem q;
			q = this->v[i] * x.v[j];
			result->v.push_back(q);
		}
	}

	result->uprostit();
	return *result;
}

vyraz & vyraz::operator /(vyraz & x)
{
	vyraz result;

	return result;
}

vyraz & vyraz::operator = (vyraz & x)
{
	this->v = x.v;
	return *this;
}

void vyraz::display() 
{
	printf("\n%.2lfx^%d", this->v[0].Koef(), this->v[0].stepen());
	for (int i = 1; i < this->v.size(); i++) 
	{
		if(this->v[i].Koef()>0)
			printf("+%.2lfx^%d", this->v[i].Koef(), this->v[i].stepen());
		else
			printf("%.2lfx^%d", this->v[i].Koef(), this->v[i].stepen());
	}
}


vyraz::~vyraz()
{
}
