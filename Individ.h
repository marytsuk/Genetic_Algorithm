#pragma once
#include <vector>
#include <fstream>

using namespace std;

class Individ
{
public:
	vector <double> genotype;
	double fitness() const;
	void mutation();
	void diff_cross(const Individ&, const Individ&, const Individ&);
	double func();
	double Rosenbrock_func();
	double Griewank_funk();
	void operator=(const Individ&);
	friend Individ operator*(double, const Individ&);
	friend ofstream& operator <<(ofstream&, Individ&);
	Individ operator+(const Individ&);
	Individ operator-(const Individ&);
	bool operator<(const Individ&);
	Individ(int);
	Individ(const Individ&);
	Individ();
	~Individ();
};

