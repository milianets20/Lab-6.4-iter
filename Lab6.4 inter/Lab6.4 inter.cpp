#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void create(double* a, int n, const double HIGH, const double LOW);
void print(double* a, int n, const double HIGH, const double LOW);
double Dobutok(double* a, int n, const int i, double& dobutok);
double Suma(double* a, const int n, const int i, double& suma, double& minimum);
double find_min(double* a, int n, const int i, double& minimum);
void sort_parni(double* a, const int n);
void sort_neparni(double* a, const int n);

int main()
{
	srand(time(NULL));


	cout << "F: " << endl;
	int n;
	cout << "n = "; cin >> n;
	double* a = new double[n];
	const double HIGH = 53.;
	const double LOW = -17.;
	cout << "a[] = { ";
	create(a, n, HIGH, LOW);
	print(a, n, HIGH, LOW);
	cout << " }" << endl;
	double dobutok = 1;
	int i = 0;
	cout << "D = " << Dobutok(a, n, i, dobutok) << endl;
	double suma = 0;
	double minimum = a[0];
	cout << "FM = " << find_min(a, n, i, minimum) << endl;
	cout << "S = " << Suma(a, n, i, suma, minimum) << endl;
	cout << "G: " << endl;
	sort_parni(a, n);
	cout << "a[] = { ";
	print(a, n, HIGH, LOW);
	cout << "}" << endl;
	cout << "J: " << endl;
	sort_neparni(a, n);
	cout << "a[] = { ";
	print(a, n, HIGH, LOW);
	cout << "}" << endl;
	cout << endl;
	delete[]a;
}
void create(double* a, int n, const double HIGH, const double LOW)
{
	for (int i = 0; i < n; i++)
		a[i] = LOW + rand() * (HIGH - LOW) / RAND_MAX;
}
void print(double* a, int n, const double HIGH, const double LOW)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
double Dobutok(double* a, int n, const int i, double& dobutok)
{
	for (int i = 0; i < n; i++)
	{
		bool umova = false;
		if (a[i] > 0)
		{
			umova = true;
		}
		if (umova)
		{
			dobutok *= a[i];
		}
	}
	return dobutok;
}
double Suma(double* a, const int n, const int i, double& suma, double& minimum)
{
	double minimum_element = find_min(a, n, i, minimum);
	for (int i = 0; i < n; i++)
	{
		suma += a[i];
		if (a[i] == minimum_element)
			return suma;
	}
}
double find_min(double* a, int n, const int i, double& minimum)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < minimum)
			minimum = a[i];
	}
	return minimum;
}
void sort_parni(double* a, const int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i + 2; j < n; j++)
			if (a[j] < a[i])
			{
				double temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
	}
}
void sort_neparni(double* a, const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
			{
				double temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
	}
}