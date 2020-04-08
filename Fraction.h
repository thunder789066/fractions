#pragma once
// Christina Gerstner
// clgdtf@mail.umkc.edu
// 10/29/2019
// Lab 11

#include <iostream>
using namespace std;

class Fraction {
private:
	int getGCD(int num1, int num2);
	int numerator;
	int denominator;
public:
	Fraction();
	void reduce();
	friend ostream& operator<< (ostream& output, const Fraction& fract);
	friend istream& operator>> (istream& input, Fraction& fract);
	Fraction operator+(Fraction rhs);
	Fraction operator/(Fraction rhs);
	Fraction operator-(Fraction rhs);
	Fraction operator*(Fraction rhs);
	bool operator==(Fraction rhs);
};

