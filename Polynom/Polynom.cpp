// Polynom.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "vyraz.h"

float x[] = { 1.0,2.0,3.0,4.0,5.0,6.0 };
float y[] = { 3.0,-1.0,4.0,-2.0,1.0,-3.0 };

int main()
{
	vyraz q(x, 6, y, 6);
	getchar();
    return 0;
}

