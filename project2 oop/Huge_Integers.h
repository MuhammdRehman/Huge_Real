#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class HugeIntegers
{
	int size;
	int P_size;
	int* Vs;
	int* Ps;
	bool isNeg;
	void assign(const HugeIntegers& S);
	bool QuantittyWise_Less(const HugeIntegers& H)const;
	bool QuantittyWise_Greater(const HugeIntegers& H)const;
	bool QuantittyWise_Less_and_equal(const HugeIntegers& H)const;
	bool QuantittyWise_Greater_and_equal(const HugeIntegers& H)const;
	bool QuantittyWise_equal(const HugeIntegers& H)const;
	bool QuantittyWise_Notequal(const HugeIntegers& H)const;
	HugeIntegers one();
	HugeIntegers& zero();
    void Only_one();
	void Only_zero();
	int I_V(int i)const;
public:
	HugeIntegers();
	HugeIntegers(int _size,int);
	HugeIntegers(const HugeIntegers& S);
	HugeIntegers& operator=(const HugeIntegers& S);
	void read(ifstream& Rdr);
	void Loader(ifstream& Rdr);
	void print();
	HugeIntegers add(const HugeIntegers& S)const;
	int operator[](int i)const;
	int& operator[](int i);
	void Trim();
	HugeIntegers Subtract(const HugeIntegers& S)const;
	friend ostream& operator<<(ostream&, const HugeIntegers& H);
	bool operator<(const HugeIntegers& S)const;
	bool operator>(const HugeIntegers& S)const;
	bool operator==(const HugeIntegers& S)const;
	bool operator!=(const HugeIntegers& S)const;
	bool operator<=(const HugeIntegers& S)const;
	bool operator>=(const HugeIntegers& S)const;
	const HugeIntegers operator+(const HugeIntegers& S)const;
	const HugeIntegers operator-(const HugeIntegers& S)const;
	void operator+=(HugeIntegers& S);
	void operator-=(HugeIntegers& S);
	HugeIntegers operator++();
	HugeIntegers operator++(int);
	HugeIntegers operator--(int);
	HugeIntegers operator*(const HugeIntegers& H)const;
	HugeIntegers operator*=(const HugeIntegers& H);
	HugeIntegers operator/(HugeIntegers& H)const;
	HugeIntegers operator/=(HugeIntegers& H);
	HugeIntegers operator--();
};



