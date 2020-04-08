// Christina Gerstner
// clgdtf@mail.umkc.edu
// 10/29/2019
// CS201L Lab 11

#include "Fraction.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

// Find the greatest common denominator (GCD) for reducing
int Fraction::getGCD(int num1, int num2) {
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce() {
	if (numerator < 0 && denominator < 0) {
		// if both values are negative, both values return as postive
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
	else if (numerator >= 0 && denominator < 0) {
		int temp_numerator;
		// if numerator is postive & denominator is negative, numerator returned as negative & denominator returned as postive
		denominator = abs(denominator);
		temp_numerator = numerator * 2;
		numerator -= temp_numerator;
	}

	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

Fraction Fraction::operator+(Fraction rhs) {
	Fraction result;
	result.denominator = denominator * rhs.denominator;
	result.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
	result.reduce();
	return result;	// returns object calculated from adding the lhs (left hand side) with the rhs
}

Fraction Fraction::operator-(Fraction rhs) {
	Fraction result;
	result.denominator = denominator * rhs.denominator;
	result.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
	result.reduce();
	return result;	// returns object calculated from subtracting the lhs (left hand side) with the rhs
}

Fraction Fraction::operator*(Fraction rhs) {
	Fraction result;
	result.numerator = numerator * rhs.numerator;
	result.denominator = denominator * rhs.denominator;
	result.reduce();
	return result;	// returns object calculated from multiplying the lhs (left hand side) with the rhs
}

Fraction Fraction::operator/(Fraction rhs) {
	Fraction result;
	result.numerator = numerator * rhs.denominator;
	result.denominator = denominator * rhs.numerator;
	result.reduce();
	return result;	// returns object calculated from dividing the lhs (left hand side) with the rhs
}

bool Fraction::operator==(Fraction rhs) {
	rhs.reduce();
	reduce();	// left hand side
	if ((numerator == rhs.numerator) && (denominator == rhs.denominator)) {
		return true;	// if num or dem on lhs & rhs is the exact same
	}
	else {
		return false;
	}
}
ostream& operator<< (ostream& output, const Fraction& fract) {
	output << fract.numerator << "/" << fract.denominator;
	return output;
}
istream& operator>> (istream& input, Fraction& fract) {
	char slash = ' ';
	input >> fract.numerator >> slash >> fract.denominator;
	return input;
}