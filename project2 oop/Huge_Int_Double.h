#pragma once
#include<iostream>
#include<fstream>
#include"Huge_Integers.h"
using namespace std;
class Huge_Int_Double 
{
	int* Vs;
	int size;
	bool isNeg;
	int* Ps;
	int Psize;
	int base;
	void assign(const Huge_Int_Double & S);
	bool QuantittyWise_Less(const Huge_Int_Double& H)const;
	bool QuantittyWise_Greater(const Huge_Int_Double& H)const;
	bool QuantittyWise_Less_and_equal(const Huge_Int_Double& H)const;
	bool QuantittyWise_Greater_and_equal(const Huge_Int_Double& H)const;
	bool QuantittyWise_equal(const Huge_Int_Double& H)const;
	bool QuantittyWise_Notequal(const Huge_Int_Double& H)const;
	Huge_Int_Double one();
	Huge_Int_Double zero();
	int I_V(int i)const;
public:
	Huge_Int_Double();
	Huge_Int_Double(int _size, int);
	Huge_Int_Double(const Huge_Int_Double& S);
	Huge_Int_Double& operator=(const Huge_Int_Double& S);
	void read(ifstream& Rdr,int bas);
	void Loader(ifstream& Rdr);
	void print();
	Huge_Int_Double add(const Huge_Int_Double& S)const;
	int operator[](int i)const;
	int& operator[](int i);
	void Trim();
	Huge_Int_Double Subtract(const Huge_Int_Double& S)const;
	friend ostream& operator<<(ostream&, const Huge_Int_Double& H);
	bool operator<(const Huge_Int_Double& S)const;
	bool operator>(const Huge_Int_Double& S)const;
	bool operator==(const Huge_Int_Double& S)const;
	bool operator!=(const Huge_Int_Double& S)const;
	bool operator<=(const Huge_Int_Double& S)const;
	bool operator>=(const Huge_Int_Double& S)const;
	const Huge_Int_Double operator+(const Huge_Int_Double& S)const;
	const Huge_Int_Double operator-(const Huge_Int_Double& S)const;
	void operator+=(Huge_Int_Double& S);
	void operator-=(Huge_Int_Double& S);
	Huge_Int_Double operator++();
	Huge_Int_Double operator++(int);
	Huge_Int_Double operator--(int);
	/*Huge_Int_Double operator*(const Huge_Int_Double& H)const;
	Huge_Int_Double operator*=(const Huge_Int_Double& H);
	Huge_Int_Double operator/(Huge_Int_Double& H)const;
	Huge_Int_Double operator/=(Huge_Int_Double& H);*/
	Huge_Int_Double operator--();
};

