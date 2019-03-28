#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fi("afd.in");


class automat {

	int nr_stari;
	int nr_stari_finale;
	vector<int> stari_finale;
	int nr_alfabet;
	vector<char> alfabet;
	int nr_tranzitii;
	int stare_curenta;

	struct tranzitii {
		int inceput;
		int final;
		char parcugere;
	};

	vector<tranzitii> T;

	int tranzitie(int curenta, char c)
	{
		for (int i = 0;i < nr_tranzitii;i++)
		{
			if (T[i].inceput == curenta && T[i].parcugere == c)
				return T[i].final;
		}

		return -1;
	}

public:

	automat()
	{


		stare_curenta = 1;
		fi >> nr_stari >> nr_stari_finale;

		for (int i = 0;i < nr_stari_finale;i++)
		{
			int x;
			fi >> x;
			stari_finale.push_back(x);
		}

		fi >> nr_alfabet;

		for (int i = 0;i < nr_alfabet;i++)
		{
			char x;
			fi >> x;
			alfabet.push_back(x);
		}

		fi >> nr_tranzitii;

		for (int i = 0;i < nr_tranzitii;i++)
		{
			int a, b;
			char c;

			fi >> a >> b >> c;

			T.push_back({ a,b,c });
		}

		fi.close();

	}

	bool citire(string cuvant)
	{
		for (int i = 0;i < cuvant.length();i++)
		{
			stare_curenta = tranzitie(stare_curenta, cuvant[i]);
			if (stare_curenta == -1)
				return false;
		}

		for (int i = 0;i < nr_stari_finale;i++)
			if (stare_curenta == stari_finale[i])
				return true;

		return false;
	}

};

int main()
{
	automat A;
	string cuvant;

	cout << "Introduceti cuvantul: ";
	cin >> cuvant;


	if (A.citire(cuvant)) cout << "cuvantul apartine limbajului.";
	else cout << "cuvantul nu apartine limbajului.";


	return 0;
}