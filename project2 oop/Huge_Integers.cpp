#include "Huge_Integers.h"
#include<string>
using namespace std;
void HugeIntegers::assign(const HugeIntegers& S)
{
	size = S.size;
	P_size = S.P_size;
	this->Vs = new int[size];
	this->Ps = new int[P_size];
	for (int i = 0; i < size; i++)
	{
		Vs[i] = S.Vs[i];
	}
	for (int i = 0; i < P_size; i++)
	{
		Ps[i] = S.Ps[i];
	}
	this->isNeg = S.isNeg;
}
HugeIntegers::HugeIntegers()
{
	this->size = 0;
	this->Vs = nullptr;
	this->isNeg = false;
	this->P_size = 0;
	this->Ps = nullptr;
}
HugeIntegers::HugeIntegers(int _size,int P_s)
{
	this->size = _size;
	this->P_size = P_s;
	this->Ps = new int[P_size];
	this->Vs = new int[this->size];
	this->isNeg = false;
}
HugeIntegers::HugeIntegers(const HugeIntegers& S)
{
	this->assign(S);
}
HugeIntegers& HugeIntegers::operator=(const HugeIntegers& S)
{
	if (this == &S)
		return *this;
	delete[] Vs;
	delete[]Ps;
	this->assign(S);
	return *this;
}
void HugeIntegers::read(ifstream& Rdr)
{
	this->Loader(Rdr);
}
void HugeIntegers::Loader(ifstream& Rdr)
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
		this->Vs[size - 1 - i] = S[i] - '0';
	}
	if (size == S.size() )
	{
		P_size = 1;
		Ps = new int[P_size];
		Ps[0] = 0;
	}
	else
	{
		P_size = S.size() - size - 1;
		Ps = new int[P_size];
		for (int i = size + 1, j = 0; i < S.size(); i++, j++)
		{
			if (S[i] == '.')
				throw(1);
			else
				this->Ps[j] = S[i] - '0';
		}
	}
}
void HugeIntegers::print()
{
	cout << ((isNeg == true) ? "-" : "+");
	for (int i = 0; i < size; i++)
	{
		cout << Vs[size - 1 - i];
	}
	cout << ".";
	for (int i = 0; i < P_size; i++)
	{
		cout << Ps[i];
	}
}
ostream& operator<<(ostream&, const HugeIntegers& H)
{
	cout << ((H.isNeg == true) ? "-" : "+");
	for (int i = 0; i < H.size; i++)
	{
		cout << H.Vs[H.size - 1 - i];
	}
	cout << ".";
	for (int i = 0; i < H.P_size; i++)
	{
		cout << H.Ps[i];
	}
	/*cout << ((H.isNeg == true) ? "-" : "+");
	for (int i = 0; i < H.size; i++)
	{
		cout << H.Vs[H.size - 1 - i];
	}*/
	return cout;
}
int HugeIntegers::I_V(int i)const
{
	if (i >= this->P_size || i < 0)
		return 0;
	return this->Ps[i];
}
HugeIntegers HugeIntegers::add(const HugeIntegers& S)const
{
	int carry = 0;
	HugeIntegers Hi;
	Hi.size = this->size + 1;
	Hi.Vs = new int[size + 1];
	
	if (P_size >= S.P_size)
	{
		carry = 0;
		Hi.P_size = this->P_size;
		Hi.Ps = new int[P_size];
		for (int i = P_size - 1; i >= 0; i--)
		{
			int ans = (*this).I_V(i) + S.I_V(i) + carry;
			Hi.Ps[i] = ans % 10;
			carry = ans / 10;
		}
	}
	else
	{
		carry = 0;
		Hi.P_size = S.P_size;
		Hi.Ps = new int[S.P_size];
		for (int i = S.P_size - 1; i >= 0; i--)
		{
			int ans = (*this).I_V(i) + S.I_V(i) + carry;
			Hi.Ps[i] = ans % 10;
			carry = ans / 10;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int ans = (*this)[i] + S[i] + carry;
		Hi.Vs[i] = ans % 10;
		carry = ans / 10;
	}
	Hi.Vs[size] = carry;
	Hi.Trim();
	return Hi;
}
HugeIntegers HugeIntegers::Subtract(const HugeIntegers& S)const
{
	int carry = 0;
	HugeIntegers Hi;
	Hi.size = this->size ;
	Hi.Vs = new int[size ];

	if (P_size >= S.P_size)
	{
		carry = 0;
		Hi.P_size = this->P_size;
		Hi.Ps = new int[P_size];
		for (int i = P_size - 1; i >= 0; i--)
		{
			if ((*this).I_V(i)+carry >= S.I_V(i))
			{
				Hi.Ps[i] = (*this).I_V(i) - S.I_V(i) + carry;
				carry = 0;
			}
			else
			{
				int ans = (*this).I_V(i) - S.I_V(i) + carry;
				if (ans < 0)
				{
					Hi.Ps[i] = ans + 10;
					carry = -1;
				}
			}
		}
	}
	else
	{
		carry = 0;
		Hi.P_size = S.P_size;
		Hi.Ps = new int[S.P_size];
		for (int i = S.P_size - 1; i >= 0; i--)
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
					Hi.Ps[i] = ans + 10;
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
			Hi.Vs[i] = ans + 10;
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
bool HugeIntegers::operator<(const HugeIntegers& S)const
{
	return S > (*this);
}
bool HugeIntegers::operator>(const HugeIntegers& S)const
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
bool HugeIntegers::operator==(const HugeIntegers& S)const
{
	return (!(*this < S) && !(*this > S));
}
bool HugeIntegers::operator!=(const HugeIntegers& S)const
{
	return (*this) == S;
}
bool HugeIntegers::operator<=(const HugeIntegers& S)const
{
	return((*this) < S || (*this) == S);
}
bool HugeIntegers::operator>=(const HugeIntegers& S)const
{
	return((*this) > S || (*this) == S);

}
void HugeIntegers::Trim()
{
	// Before Point
	int j = size-1;
	for (int i = size - 1; i >= 0; i--)
	{
		if (Vs[i] != 0) {
			j = i;
			break;
		}
	}
	HugeIntegers I;
	I.size = j + 1;
	I.Vs = new int[I.size];
	for (int i = I.size - 1; i >= 0; i--)
	{
		I.Vs[i] = Vs[i];
	}
	// After point
	j = 0;
	for (int i = P_size - 1; i >= 0; i--)
	{
		if (Ps[i] != 0) {
			break;
		}
		else
			j++;
	}
	I.P_size = P_size-j ;
	I.Ps = new int[I.P_size];
	for (int i =0; i <I.P_size; i++)
	{
		I.Ps[i] = Ps[i];
	}
	I.isNeg = this->isNeg;
	*this = I;
}
int HugeIntegers::operator[](int i) const
{
	if (i >= size)
		return 0;
	return this->Vs[i];
}
int& HugeIntegers:: operator[](int i)
{
	return Vs[i];
}
bool HugeIntegers::QuantittyWise_Less(const HugeIntegers& S)const
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
	if (this->P_size != S.P_size)
	{
		if (this->P_size < S.P_size)
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		for (int i = 0; i < P_size; i++)
		{
			if (Ps[i] != S.Ps[i])
			{
				if (Ps[i] < S.Ps[i])
					return true;
				return false;
			}
		}
	}
	return false;
}
bool HugeIntegers::QuantittyWise_Greater(const HugeIntegers& S)const
{
	return S.QuantittyWise_Less(*this);
}
bool HugeIntegers::QuantittyWise_Less_and_equal(const HugeIntegers& H)const
{
	return ((*this).QuantittyWise_Less(H)) || ((*this).QuantittyWise_equal(H));
}
bool HugeIntegers::QuantittyWise_Greater_and_equal(const HugeIntegers& H)const
{
	return ((*this).QuantittyWise_Greater(H)) || ((*this).QuantittyWise_equal(H));

}
bool HugeIntegers::QuantittyWise_equal(const HugeIntegers& S)const
{
	return (!(*this).QuantittyWise_Less(S)) && !(!(*this).QuantittyWise_Greater(S));
}
bool HugeIntegers::QuantittyWise_Notequal(const HugeIntegers& H)const
{
	return (!(*this).QuantittyWise_equal(H));
}
const HugeIntegers HugeIntegers::operator+(const HugeIntegers& S)const
{
	if (this->isNeg != S.isNeg)
	{
		if (this->QuantittyWise_Greater(S))
		{
			HugeIntegers H = (*this).Subtract(S);
			H.isNeg = this->isNeg;
			return H;
		}
		else
		{
			HugeIntegers H = (S).Subtract(*this);
			H.isNeg = S.isNeg;
			return H;
		}
	}
	else
	{
		if (this->QuantittyWise_Greater(S))
		{
			HugeIntegers H = (*this).add(S);
			H.isNeg = this->isNeg;
			return H;
		}
		else
		{
			HugeIntegers H = (S).add(*this);
			H.isNeg = S.isNeg;
			return H;
		}
	}
}
const HugeIntegers HugeIntegers::operator-(const HugeIntegers& S)const
{
	HugeIntegers S1 = S;
	S1.isNeg = !S.isNeg;
	return (*this) + (S1);
}
void HugeIntegers::operator+= (HugeIntegers& S)
{
	(*this) = (*this) + (S);
}
void HugeIntegers::operator-=(HugeIntegers& S)
{
	(*this) = (*this) - (S);
}
HugeIntegers HugeIntegers::operator++()
{
	HugeIntegers H = *this + one();
	(*this) = H;
	return (*this);
}
HugeIntegers HugeIntegers::operator--()
{
	HugeIntegers H = *this - one();
	(*this) = H;
	return *this ;
}
HugeIntegers HugeIntegers::one()
{
	HugeIntegers H;
	H.size = 1;
	H.Vs = new int[H.size];
	H.Vs[0] = 1;
	H.P_size = 1;
	H.Ps = new int[P_size];
	H.Ps[0] = 0;
	H.isNeg = false;
	return H;
}
HugeIntegers& HugeIntegers::zero()
{
	HugeIntegers H;
	H.size = 1;
	H.Vs = new int[H.size];
	H.Vs[0] = 0;
	H.P_size = 1;
	H.Ps = new int[P_size];
	H.Ps[0] = 0;
	H.isNeg = false;
	return H;
}
HugeIntegers HugeIntegers::operator++(int a)
{
	HugeIntegers H = *this + one();
	(*this) = H;
	return *this;
}
HugeIntegers HugeIntegers::operator--(int a)
{
	HugeIntegers H = *this - one();
	(*this) = H;
	return *this;
}
HugeIntegers HugeIntegers::operator*(const HugeIntegers& H)const
{
	HugeIntegers A; 
	HugeIntegers F;
	HugeIntegers count; HugeIntegers L = H; HugeIntegers B = *this;
	F.Only_zero();
	//A.Only_one();
	//count.Only_one();
	
	
	if (L.isNeg == true)
	{
		L.isNeg = false;
		while (L > A.zero())
		{
			count = count.one();
			B = (*this);
			while (count + count <= L)
			{
				B += B;
				count += count;
			}
			F += B; L -= count;
		}
		L.isNeg = true;
	}
	else
	{
		while (L > A.zero())
		{
			count=count.one();
			B = (*this);
			while (count + count <= L)
			{
				B += B;
				count += count;
			}
			F = F + B;
			L =L- count;
		}
	}
	if (this->isNeg != H.isNeg)
		F.isNeg = true;
	else
		F.isNeg = false;
	return F;
}
HugeIntegers HugeIntegers::operator*=(const HugeIntegers& H)
{
	return *this = (*this) * H;
}
void HugeIntegers::Only_one()
{
	//HugeIntegers H;
	this->size = 1, this->P_size = 1;
	this->Ps = new int[P_size];
	this->Vs = new int[size];
	this->Ps[0] = 0;
	this->Vs[0] = 1;
	
}
void HugeIntegers::Only_zero()
{
	size = 1;
	P_size = 1;
	Ps = new int[P_size];
	Vs = new int[size];
	Ps[0] = 0;
	Vs[0] = 0;
}
HugeIntegers HugeIntegers::operator/(HugeIntegers& H)const
{
	HugeIntegers A = *this, T = T.zero(), count = count.one(), B = H, L = L.zero();
	A.isNeg = false;
	B.isNeg = false;
	if (A < B)
		return L;
	
	if (H.isNeg == true)
	{
		H.isNeg = false;
		while (A >= H)
		{
			count=count.one();
			B = H;
			while (B + B <= A)
			{
				B += B;
				count += count;
			}
			L += count;
			A -= B;
		}
		H.isNeg = true;
	}
	else
	{
		while (A >= H)
		{
			count=count.one();
			B = H;
			while (B + B <= A)
			{
				B += B;
				count += count;
			}
			L += count;
			A -= B;
		}
	}
	if (this->isNeg != H.isNeg)
		L.isNeg = true;
	else
		L.isNeg = false;
	return L;
}
HugeIntegers HugeIntegers::operator/=(HugeIntegers& H)
{
	return *this = (*this) / H;

	/*HugeIntegers A = *this, T = T.zero(), count = count.one(), B = H, L = L.zero();
	if (this->isNeg != H.isNeg)
		L.isNeg = true;
	else
		L.isNeg = false;

	if ((*this) < H)
		return L;
	while (A >= H)
	{
		count = count.one();
		B = H;
		while (B + B <= A)
		{
			B += B;
			count += count;
		}
		L += count;
		A -= B;
	}
	return *this=L;*/
}





