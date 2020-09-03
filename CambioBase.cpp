#include "iostream"
#include "sstream"
#include "string"
#include "conio.h"
#include "cmath"

using namespace std;

/*
		10a
		11b
		12c
		13d
		14e
		15f
		16g
		17h
		18i
		19j
		20
*/

int cantDigitos(long num) {
	int contador = 1;
	while (num / 10 > 0)
	{
		num = num / 10;
		contador++;
	}
	return contador;
}

bool DigitoMenorABase(long num, int base) {
	bool verificar = true;
	int digito = 0;

	while (digito >= 0 && num > 0)
	{
		digito = num % 10;
		if (digito >= base)
		{
			verificar = false;
			break;
		}
		num = num / 10;
	}
	return verificar;
}

string invertir(string num) {
	string aux_cadena = "";

	for (int i = num.size(); i >= 0; i--)
		aux_cadena += num[i];

	return aux_cadena;
}

long BaseNa10(long num, int base1) {
	int exp = 0, digito;
	long decimal = 0;

	while (num / 10 != 0)
	{
		digito = num % 10;
		decimal = decimal + (digito * (pow(base1, exp)));
		exp++;
		num = num / 10;
	}

	decimal = decimal + (num * (pow(base1, exp)));

	return decimal;
}

string Base10aN(long num, int base) {
	string conversion = "";
	string num_invertido = "";
	int residuo = 0;

	do {
		residuo = num % base;
		if (residuo > 9)
		{
			for (int i = 10, letra = 65; i <= 20 && letra <= 75; i++, letra++)
			{
				if (residuo == i)
				{
					num_invertido = char(letra);
					break;
				}
			}
			num /= base;
			conversion = conversion + (num_invertido);
		}
		else
		{
			num_invertido = to_string(residuo);
			num /= base;
			conversion = conversion + invertir(num_invertido);
		}
	} while (num != 0);

	return invertir(conversion);
}

void BaseNaN(long num, int base1, int base2) {
	long num1 = BaseNa10(num, base1);
	cout << Base10aN(num1, base2);
}

int main() {
	long num;
	int base1, base2;

	do
	{
		cout << "Ingrese base: ";
		cin >> base1;
	} while (base1 < 2 || base1 > 20);

	do
	{
		cout << "Ingrese numero en base " << base1 << ": ";
		cin >> num;
	} while (num < 1 || !(DigitoMenorABase(num, base1)));

	do
	{
		cout << "Ingrese base a la que quiere convertir: ";
		cin >> base2;
	} while (base2 < 1 || base2 > 20);

	cout << endl << "El numero en base " << base2 << ": ";
	BaseNaN(num, base1, base2);

	_getch();
	return 0;
}
