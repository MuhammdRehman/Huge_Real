#include<iostream>
#include<fstream>
#include"Huge_Integers.h"
#include"Huge_Int_Double.h"
using namespace std;
void Part_1()
{
	HugeIntegers* A;
	ifstream Rdr("input.txt");
	int s;
	Rdr >> s;
	A = new HugeIntegers[s];
	for (int i = 0; i < s; i++)
	{
		if (Rdr.peek() == '\n' || Rdr.peek() == ' ')
			Rdr.ignore();
		try
		{
			(A[i]).read(Rdr);
		}
		catch (...)
		{
			cout << "Your input contains 2 (.) points which cannot be exist.So,check in input txt\n\n";
			exit(1);
		}
	}
	while (true) {
		for (int i = 0; i < s; i++)
		{
			cout << "H" << i + 1 << " : "; A[i].print(); cout << endl;;
		}
		int k;
		cout << "\n1.Addition\n2.Subtraction\n3.Less Than Operator\n4.Greater than Operator\n5.Equal to Operator\n6.Trim ";
		cout << "\n7.Multiplication\n8.Division\n9./= :  ";
		cin >> k;
		switch (k)
		{
		case(1):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			HugeIntegers S =((A[l - 1]) + (A[m - 1]));
			cout << endl;
			S.print();
			break;
		}
		case(2):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			HugeIntegers S = (A[l - 1]) - (A[m - 1])
			S.print();
			break;
		}
		case(3):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands1 to 5) : ";
			cin >> l >> m;
			cout << (A[l - 1] < A[m - 1]) ? "True" : "false";
			break;
		}
		case(4):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			cout << (A[l - 1] > A[m - 1]) ? "True" : "false";
			break;
		}
		case(5):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			cout << (A[l - 1] == A[m - 1]) ? "True" : "false";
			break;
		}
		case(6):
		{
			int l;
			cout << "Enter a Huge Number/Operands(1 to 5) : ";
			cin >> l;
			A[l - 1].Trim();
			A[l - 1].print();
			break;
		}
		case(7):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			HugeIntegers H = (A[l - 1] * A[m - 1]);
			cout << endl;
			H.print();
			break;
		}
		case(8):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			HugeIntegers H = A[l - 1] / A[m - 1];
			cout << endl;
			H.print();
			break;
		}
		case(9):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			 A[l - 1] /= A[m - 1];
			cout << endl;
			A[l-1].print();
			break;
		}
		default: return;
		}
		int n;
		cout << "\nDo you want to continue\n1.No\n2.yes\nWhich one you want :  ";
		cin >> n;
		if (n == 1)
			break;
		else
			system("cls");
	}
}
void Part_2()
{
	Huge_Int_Double* A;
	int base;
	cout << "\nIn which Base you want to work(1 to 36)  :  ";
	do {
		cin >> base;
		if ((base <= 0 && base > 36)) {
			cout << "You Entered a wrong Base\nPlease Enter again : ";
		}
	} while (base <= 0 && base > 36);
	ifstream Rdr("Huge_Int.txt");
	int s;
	Rdr >> s;
	A = new Huge_Int_Double[s];
	for (int i = 0; i < s; i++)
	{
		if (Rdr.peek() == '\n' || Rdr.peek() == ' ')
			Rdr.ignore();
		try
		{
			(A[i]).read(Rdr,base);
		}
		catch (...)
		{
			cout << "\n\nThere is a Problem in Text File. File Should be according to base!!!\nPlease Make sure that Huge_Int.txt file must be in that base!!!!!!!!!\n";
			exit(1);
		}
	}
	try
	{
	while (true) {
		for (int i = 0; i < s; i++)
		{
			cout << "H" << i + 1 << " : "; A[i].print(); cout << endl;;
		}
		int k;
		cout << "\n1.Addition\n2.Subtraction\n3.Less Than Operator\n4.Greater than Operator\n5.Equal to Operator\n6.Trim  : ";
		cin >> k;
		switch (k)
		{
		case(1):
		{
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			Huge_Int_Double S = ((A[l - 1])+(A[m - 1]));
			cout << endl;
			S.print();
			break;
		}
		case(2):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			Huge_Int_Double S = (A[l - 1]) - (A[m - 1]);
			S.print();
			break;
		}
		case(3):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			cout << (A[l - 1] < A[m - 1]) ? "True" : "false";
			break;
		}
		case(4):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			cout << (A[l - 1] > A[m - 1]) ? "True" : "false";
			break;
		}
		case(5):
		{
			for (int i = 0; i < s; i++)
			{
				A[i].Trim();
			}
			int l, m;
			cout << "Enter Huge Numbers/Operands(1 to 5) : ";
			cin >> l >> m;
			cout << ((A[l - 1] == A[m - 1])? "Both Numbers are Equal":"Numbers are diffrent");
			break;
		}
		case(6):
		{
			int l;
			cout << "Enter a Huge Number(1 to 5) : ";
			cin >> l;
			A[l - 1].Trim();
			A[l - 1].print();
			break;
		}
		default: return;
		
		}
		int b;
		cout << "\nDo you want to continue\n1.No\n2.yes\nWhich one you want :  ";
		cin >> b;
		if (b == 1)
			exit(1);
		else
			system("cls");
	}
	}
	catch (...)
	{
		system("cls");
		Part_2();
	}
}
int main()
{
	while (true)
	{
		int a;
		do {
			cout << "\nParts of Huge_Real \n\n1.Part 1 : HugeIntegers_Using_Floating_Point\n\n2.Part 2 : Using Double Hexa(0...to...Z\n\nWhich one you want to Perform  :  ";
			cin >> a;
			cout << endl << endl;
			if (a == 1)
				Part_1();
			else if (a == 2)
				Part_2();
		} while (a == 1 || a == 2);
		int b;
		cout << "\nDo you want to continue\n1.No\n2.yes\nWhich one you want :  ";
		cin >> b;
		if (b == 1)
			exit(1);
		else
			system("cls");
	}
	return 0;
}