#include "Huge_Int_Double.h"
#include<string>
using namespace std;
void Huge_Int_Double::assign(const Huge_Int_Double& S)
{
	size = S.size;
	Psize = S.Psize;
	this->Vs = new int[size];
	this->Ps = new int[Psize];
	for (int i = 0; i < size; i++)
	{
		Vs[i] = S.Vs[i];
	}
	for (int i = 0; i < Psize; i++)
	{
		Ps[i] = S.Ps[i];
	}
	this->isNeg = S.isNeg;
}
Huge_Int_Double::Huge_Int_Double()
{
	this->size = 0;
	this->Vs = nullptr;
	this->isNeg = false;
	this->Psize = 0;
	this->Ps = nullptr;
	base = 10;
}
Huge_Int_Double::Huge_Int_Double(int _size, int P_s)
{
	this->size = _size;
	this->Vs = new int[this->size];
	this->isNeg = false;
	this->Psize = P_s;
	this->Ps = new int[Psize];
	base= 10;
	//base = 10;
}
Huge_Int_Double::Huge_Int_Double(const Huge_Int_Double& S)
{
	this->assign(S);
}
Huge_Int_Double& Huge_Int_Double::operator=(const Huge_Int_Double& S)
{
	if (this == &S)
		return *this;
	delete[] Vs;
	delete[]Ps;
	this->assign(S);
	return *this;
}
void Huge_Int_Double::read(ifstream& Rdr,int bas)
{
	base = bas;
	this->Loader(Rdr);
}
void Huge_Int_Double::Loader(ifstream& Rdr)
{
	this->size = 0;
	this->Vs = nullptr;
	if (Rdr.peek() == '-')
	{
		Rdr.ignore();
		isNeg = true;
	}
	else
	{
		if (Rdr.peek() == '+' || Rdr.peek() == '\n' || Rdr.peek() == ' ') {
			Rdr.ignore();
			//this->isNeg = false;
		}
		//else
		this->isNeg = false;
	}
	string S;
	getline(Rdr, S);
	// for Reading before the point
	size = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] != '.')
			size++;
		else
			break;
	}
	this->Vs = new int[size] {};
	for (int i = 0; i < size; i++)
	{
		if (base == 2)
		{
			if (S[i] >= '0' && S[i] <= '1')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 3)
		{
			if (S[i] >= '0' && S[i] <= '2')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 4)
		{
			if (S[i] >= '0' && S[i] <= '3')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 5)
		{
			if (S[i] >= '0' && S[i] <= '4')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 6)
		{
			if (S[i] >= '0' && S[i] <= '5')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 7)
		{
			if (S[i] >= '0' && S[i] <= '6')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 8)
		{
			if (S[i] >= '0' && S[i] <= '7')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}
		else if (base == 9)
		{
			if (S[i] >= '0' && S[i] <= '8')
				this->Vs[size - 1 - i] = S[i] - '0';
			else throw(1);
		}

		else if (base == 10)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
		}
		else if (base == 11)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] == 'A')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 12)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'B')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 13)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'C')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 14)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'D')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 15)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'E')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 16)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'F')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 16)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';

			else if (S[i] >= 'A' && S[i] <= 'G')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 17)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'H')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 18)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'I')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 19)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'J')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 20)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'K')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 21)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'L')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 23)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'M')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 24)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'N')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 25)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'O')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 26)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'P')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 27)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'Q')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 28)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'R')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 29)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'S')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 30)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'T')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 31)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'U')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 32)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'V')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 33)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'W')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 34)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'X')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
		else if (base == 35)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'Y')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}

		else if (base == 36)
		{
			if (S[i] >= '0' && S[i] <= '9')
				this->Vs[size - 1 - i] = S[i] - '0';
			else if (S[i] >= 'A' && S[i] <= 'Z')
			{
				this->Vs[size - 1 - i] = S[i] - 'A' + 10;
			}
			else
				throw(1);
		}
	}
	if (size == S.size())
	{
		Psize = 1;
		Ps = new int[Psize];
		Ps[0] = 0;
	}
	else
	{
		Psize = S.size() - size - 1;
		Ps = new int[Psize];
		for (int i = size + 1, j = 0; i < S.size(); i++, j++)
		{
			if (base == 2)
			{
				if (S[i] >= '0' && S[i] <= '1')
					this->Ps[ j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 3)
			{
				if (S[i] >= '0' && S[i] <= '2')
					this->Ps[ j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 4)
			{
				if (S[i] >= '0' && S[i] <= '3')
					this->Ps[j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 5)
			{
				if (S[i] >= '0' && S[i] <= '4')
					this->Ps[ j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 6)
			{
				if (S[i] >= '0' && S[i] <= '5')
					this->Ps[j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 7)
			{
				if (S[i] >= '0' && S[i] <= '6')
					this->Ps[ j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 8)
			{
				if (S[i] >= '0' && S[i] <= '7')
					this->Ps[ j] = S[i] - '0';
				else throw(1);
			}
			else if (base == 9)
			{
				if (S[i] >= '0' && S[i] <= '8')
					this->Ps[ j] = S[i] - '0';
				else throw(1);
			}

			else if (base == 10)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
			}
			else if (base == 11)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] == 'A')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 12)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'B')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 13)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'C')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 14)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'D')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 15)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'E')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 16)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'F')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 16)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[j] = S[i] - '0';

				else if (S[i] >= 'A' && S[i] <= 'G')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 17)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'H')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 18)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'I')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 19)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'J')
				{
					this->Ps[j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 20)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'K')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 21)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'L')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 23)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'M')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 24)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'N')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 25)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'O')
				{
					this->Ps[j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 26)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'P')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 27)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'Q')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 28)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'R')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 29)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'S')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 30)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'T')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 31)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'U')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 32)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'V')
				{
					this->Ps[j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 33)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'W')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 34)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'X')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
			else if (base == 35)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'Y')
				{
					this->Ps[ j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}

			else if (base == 36)
			{
				if (S[i] >= '0' && S[i] <= '9')
					this->Ps[ j] = S[i] - '0';
				else if (S[i] >= 'A' && S[i] <= 'Z')
				{
					this->Ps[j] = S[i] - 'A' + 10;
				}
				else
					throw(1);
			}
				
		}
	}
}
void Huge_Int_Double::print()
{
	cout << ((isNeg == true) ? "-" : "+");
	for (int i = size-1; i >= 0; i--)
	{
		if (Vs[i] >= 0 && Vs[i] <= 9)
			cout << Vs[i];
		else
		{
			char a = Vs[i] + 'A' - 10;
			cout << a;
		}
			
	}
	cout << ".";
	for (int i = 0; i < Psize; i++)
	{
		if (Ps[i] >= 0 && Ps[i] <= 9)
			cout << Ps[i];
		else
		{
			char a = Ps[i] + 'A' - 10;
			cout << a;
		}
	}
}
int Huge_Int_Double::I_V(int i)const
{
	if (i >= this->Psize || i < 0)
		return 0;
	return this->Ps[i];
}
Huge_Int_Double Huge_Int_Double::add(const Huge_Int_Double& S)const
{
	int carry = 0;
	Huge_Int_Double Hi;
	Hi.size = this->size + 1;
	Hi.Vs = new int[size + 1];

	if (Psize >= S.Psize)
	{
		carry = 0;
		Hi.Psize = this->Psize;
		Hi.Ps = new int[Psize];
		for (int i = Psize - 1; i >= 0; i--)
		{
			int ans = this->I_V(i) + S.I_V(i) + carry;
			Hi.Ps[i] = ans % base;
			carry = ans / base;
		}
	}
	else
	{
		carry = 0;
		Hi.Psize = S.Psize;
		Hi.Ps = new int[S.Psize];
		for (int i = S.Psize - 1; i >= 0; i--)
		{
			int ans = (*this).I_V(i) + S.I_V(i) + carry;
			Hi.Ps[i] = ans % base;
			carry = ans / base;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int ans = (*this)[i] + S[i] + carry;
		Hi.Vs[i] = ans % base;
		carry = ans / base;
	}
	Hi.Vs[size] = carry;
	Hi.Trim();
	return Hi;
}
Huge_Int_Double Huge_Int_Double::Subtract(const Huge_Int_Double& S)const
{
	int carry = 0;
	Huge_Int_Double Hi;
	Hi.size = this->size;
	Hi.Vs = new int[size];

	if (Psize >= S.Psize)
	{
		carry = 0;
		Hi.Psize = this->Psize;
		Hi.Ps = new int[Psize];
		for (int i = Psize - 1; i >= 0; i--)
		{
			if ((*this).I_V(i) + carry >= S.I_V(i))
			{
				Hi.Ps[i] = (*this).I_V(i) - S.I_V(i) + carry;
				carry = 0;
			}
			else
			{
				int ans = (*this).I_V(i) - S.I_V(i) + carry;
				if (ans < 0)
				{
					Hi.Ps[i] = ans + base;
					carry = -1;
				}
			}
		}
	}
	else
	{
		carry = 0;
		Hi.Psize = S.Psize;
		Hi.Ps = new int[S.Psize];
		for (int i = S.Psize - 1; i >= 0; i--)
		{
			if ((*this).I_V(i) + carry >= S.I_V(i))
			{
				Hi.Ps[i] = (*this).I_V(i) - S.I_V(i) + carry;
				carry = 0;
			}
			else
			{
				int ans = (*this).I_V(i) - S.I_V(i) + carry;
				if (ans < 0)
				{
					Hi.Ps[i] = ans + base;
					carry = -1;
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		int ans = (*this)[i] - S[i] + carry;
		if (ans < 0)
		{
			Hi.Vs[i] = ans + 36;
			carry = -1;
		}
		else
		{
			Hi.Vs[i] = ans;
			carry = 0;
		}
	}
	Hi.Trim();
	return Hi;
}
bool Huge_Int_Double::operator<(const Huge_Int_Double& S)const
{
	return S > (*this);
}
bool Huge_Int_Double::operator>(const Huge_Int_Double& S)const
{
	if (this->isNeg != S.isNeg)
	{
		return this->isNeg == false;
	}
	else
	{
		if (this->isNeg == false)
			return (*this).QuantittyWise_Greater(S);
		else
			return (*this).QuantittyWise_Less(S);
	}
}
bool Huge_Int_Double::operator==(const Huge_Int_Double& S)const
{
	return (!(*this < S) && !(*this > S));
}
bool Huge_Int_Double::operator!=(const Huge_Int_Double& S)const
{
	return (*this) == S;
}
bool Huge_Int_Double::operator<=(const Huge_Int_Double& S)const
{
	return((*this) < S || (*this) == S);
}
bool Huge_Int_Double::operator>=(const Huge_Int_Double& S)const
{
	return((*this) > S || (*this) == S);

}
void Huge_Int_Double::Trim()
{
	int j = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (Vs[i] != 0) {
			j = i;
			break;
		}
	}
	Huge_Int_Double I;
	I.size = j + 1;
	I.Vs = new int[I.size];
	for (int i = I.size - 1; i >= 0; i--)
	{
		I.Vs[i] = Vs[i];
	}
	size = I.size;
	I.isNeg = this->isNeg;
	j = 0;
	for (int i = Psize - 1; i >= 0; i--)
	{
		if (Ps[i] != 0) {
			break;
		}
		else
			j++;
	}
	I.Psize = Psize - j;
	I.Ps = new int[I.Psize];
	for (int i = 0; i < I.Psize; i++)
	{
		I.Ps[i] = Ps[i];
	}
	//I.isNeg = this->isNeg;
	//*this = I;
	*this = I;
}
int Huge_Int_Double::operator[ ](int i) const
{
	if (i >= size)
		return 0;
	return this->Vs[i];
}
int& Huge_Int_Double:: operator[ ](int i)
{
	return Vs[i];
}
bool Huge_Int_Double::QuantittyWise_Less(const Huge_Int_Double& S)const
{
	if (this->size != S.size)
	{
		if (this->size < S.size)
			return true;
		else
			return false;
	}
	else
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (Vs[i] != S.Vs[i])
			{
				if (Vs[i] < S.Vs[i])
					return true;
				else
					return false;
			}
		}
	}
	for (int i = 0; i < Psize; i++)
	{
		if (Ps[i] != S.Ps[i])
		{
			if (Ps[i] < S.Ps[i])
				return true;
			else
				return false;
		}
	}
	return false;
}
bool Huge_Int_Double::QuantittyWise_Greater(const Huge_Int_Double& S)const
{
	return S.QuantittyWise_Less(*this);
}
bool Huge_Int_Double::QuantittyWise_Less_and_equal(const Huge_Int_Double& H)const
{
	return ((*this).QuantittyWise_Less(H)) || ((*this).QuantittyWise_equal(H));
}
bool Huge_Int_Double::QuantittyWise_Greater_and_equal(const Huge_Int_Double& H)const
{
	return ((*this).QuantittyWise_Greater(H)) || ((*this).QuantittyWise_equal(H));

}
bool Huge_Int_Double::QuantittyWise_equal(const Huge_Int_Double& S)const
{
	return (!(*this).QuantittyWise_Less(S)) && !(!(*this).QuantittyWise_Greater(S));
}
bool Huge_Int_Double::QuantittyWise_Notequal(const Huge_Int_Double& H)const
{
	return (!(*this).QuantittyWise_equal(H));
}
Huge_Int_Double Huge_Int_Double::one()
{
	Huge_Int_Double H;
	H.size = 1;
	H.Vs = new int[1] ;
	H.Vs[0] = 1;
	return H;
}
Huge_Int_Double Huge_Int_Double::zero()
{
	Huge_Int_Double H;
	H.size = 1;
	H.Vs = new int[H.size];
	H.Vs[0] = 0;
	return H;
}
ostream& operator<<(ostream&, const Huge_Int_Double& H)
{
	Huge_Int_Double B = H;
	B.print();
	cout << endl;
	return cout;

}
const Huge_Int_Double Huge_Int_Double::operator+(const Huge_Int_Double& S)const
{
	if (this->isNeg != S.isNeg)
	{
		if (this->QuantittyWise_Greater(S))
		{
			Huge_Int_Double H = (*this).Subtract(S);
			H.isNeg = this->isNeg;
			return H;
		}
		else
		{
			Huge_Int_Double H = (S).Subtract(*this);
			H.isNeg = S.isNeg;
			return H;
		}
	}
	else
	{
		if (this->QuantittyWise_Greater(S))
		{
			Huge_Int_Double H = (*this).add(S);
			H.isNeg = this->isNeg;
			return H;
		}
		else
		{
			Huge_Int_Double H = (S).add(*this);
			H.isNeg = S.isNeg;
			return H;
		}
	}
}
const Huge_Int_Double Huge_Int_Double::operator- (const Huge_Int_Double& S)const
{
	Huge_Int_Double S1 = S;
	S1.isNeg = !S.isNeg;
	return (*this) + (S1);
}
void Huge_Int_Double::operator+= (Huge_Int_Double& S)
{
	(*this) = (*this) + (S);
}
void Huge_Int_Double::operator-=(Huge_Int_Double& S)
{
	(*this) = (*this) - (S);
}
Huge_Int_Double Huge_Int_Double::operator++()
{
	return *this + one();
}
Huge_Int_Double Huge_Int_Double::operator--()
{
	return *this - one();
}
Huge_Int_Double Huge_Int_Double::operator++(int a)
{
	return (*this);
}
Huge_Int_Double Huge_Int_Double::operator--(int a)
{
	return (*this)+one();
}
//Huge_Int_Double Huge_Int_Double::operator*(const Huge_Int_Double& H)const
//{
//	Huge_Int_Double A;
//	Huge_Int_Double F;
//	Huge_Int_Double count; Huge_Int_Double L = H; Huge_Int_Double B = *this;
//	F.zero();
//	//A.Only_one();
//	//count.Only_one();
//	if (L.isNeg == true)
//	{
//		L.isNeg = false;
//		while (L > A.zero())
//		{
//			count = count.one();
//			B = (*this);
//			while (count + count <= L)
//			{
//				B += B;
//				count += count;
//			}
//			F += B; L -= count;
//		}
//		L.isNeg = true;
//	}
//	else
//	{
//		while (L > A.zero())
//		{
//			count = count.one();
//			B = (*this);
//			while (count + count <= L)
//			{
//				B += B;
//				count += count;
//			}
//			F = F + B;
//			L = L - count;
//		}
//	}
//	if (this->isNeg != H.isNeg)
//		F.isNeg = true;
//	else
//		F.isNeg = false;
//	return F;
//}
//Huge_Int_Double Huge_Int_Double::operator*=(const Huge_Int_Double& H)
//{
//	return *this = (*this) * H;
//}
//Huge_Int_Double Huge_Int_Double::operator/(Huge_Int_Double& H)const
//{
//	Huge_Int_Double A = *this, T = T.zero(), count = count.one(), B = H, L = L.zero();
//
//	A.isNeg = false;
//	B.isNeg = false;
//	if (A < B)
//		return L;
//	if (H.isNeg == true)
//	{
//		H.isNeg = false;
//		while (A >= H)
//		{
//			count = count.one();
//			B = H;
//			while (B + B <= A)
//			{
//				B += B;
//				count += count;
//			}
//			L += count;
//			A -= B;
//		}
//		H.isNeg = true;
//	}
//	else
//	{
//		while (A >= H)
//		{
//			count = count.one();
//			B = H;
//			while (B + B <= A)
//			{
//				B += B;
//				count += count;
//			}
//			L += count;
//			A -= B;
//		}
//	}
//	if (this->isNeg != H.isNeg)
//		L.isNeg = true;
//	else
//		L.isNeg = false;
//	return L;
//}
//Huge_Int_Double Huge_Int_Double::operator/=(Huge_Int_Double& H)
//{
//	return *this = (*this) / H;
//
//	/*HugeIntegers A = *this, T = T.zero(), count = count.one(), B = H, L = L.zero();
//	if (this->isNeg != H.isNeg)
//		L.isNeg = true;
//	else
//		L.isNeg = false;
//
//	if ((*this) < H)
//		return L;
//	while (A >= H)
//	{
//		count = count.one();
//		B = H;
//		while (B + B <= A)
//		{
//			B += B;
//			count += count;
//		}
//		L += count;
//		A -= B;
//	}
//	return *this=L;*/
//}
//Huge_Int_Double Huge_Int_Double::operator%(Huge_Int_Double& H)const
//{
//	Huge_Int_Double A = *this, T = T.zero(), count = count.one(), B = H, L = L.zero();
//	A.isNeg = false;
//	B.isNeg = false;
//	if ((A) < B)
//		return (*this);
//
//	if (H.isNeg == true)
//	{
//		H.isNeg = false;
//
//		while (A >= H)
//		{
//			count = count.one();
//			B = H;
//			while (B + B <= A)
//			{
//				B += B;
//				count += count;
//			}
//			L += count;
//			A -= B;
//		}
//		H.isNeg = true;
//		A.isNeg = this->isNeg;
//	}
//	else
//	{
//		while (A >= H)
//		{
//			count = count.one();
//			B = H;
//			while (B + B <= A)
//			{
//				B += B;
//				count += count;
//			}
//			L += count;
//			A -= B;
//		}
//		A.isNeg = this->isNeg;
//	}
//	return A;
//
//}
//Huge_Int_Double Huge_Int_Double::operator%=(const Huge_Int_Double& H)
//{
//	Huge_Int_Double A = *this, T = T.zero(), count = count.one(), B = H, L = L.zero();
//	A.isNeg = false;
//	B.isNeg = false;
//	if ((A) < B)
//		return *this;
//	A.isNeg = this->isNeg;
//	B.isNeg = H.isNeg;
//	while (A >= H)
//	{
//		count = count.one();
//		B = H;
//		while (B + B <= A)
//		{
//			B += B;
//			count += count;
//		}
//		L += count;
//		A -= B;
//	}
//	A.isNeg = this->isNeg;
//	return *this = A;
//}







