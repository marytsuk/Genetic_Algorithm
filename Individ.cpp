#include "pch.h"
#include "Individ.h"
#include "Param.h"
#include <random>
#include <math.h>
using namespace std;

//double Individ::fitness() const
//{
//	double sum = 0;
//	for (int i = 0; i < GENOME_SIZE; i++)
//	{
//		sum += genotype[i] * genotype[i];
//	}
//	return 1 / (1 + sum);
//}
double Individ::Rosenbrock_func()
{
	double sum = 0;
	for (int i = 0; i < GENOME_SIZE - 1; i++)
	{
		sum += 100 * (genotype[i] * genotype[i] - genotype[i + 1]) *
			(genotype[i] * genotype[i] - genotype[i + 1]) + (genotype[i] - 1) * (genotype[i] - 1);
	}
	return sum;
}
double Individ::Griewank_funk()
{
	double sum = 0;
	double p = 1;
	for (int i = 0; i < GENOME_SIZE; i++)
	{
		sum += genotype[i] * genotype[i] / 4000.0;
		p *= cos(genotype[i] / sqrt(i + 1));
	}
	return sum - p + 1;
}
double Individ::fitness() const
{
	double sum = 0;
	switch (k)
	{
	case 1:
	{
		for (int i = 0; i < GENOME_SIZE; i++)
		{
			sum += genotype[i] * genotype[i];
		}
		break;
	}
	case 6:
	{
		for (int i = 0; i < GENOME_SIZE - 1; i++)
		{
			sum += 100 * (genotype[i] * genotype[i] - genotype[i + 1]) *
				(genotype[i] * genotype[i] - genotype[i + 1]) + (genotype[i] - 1) * (genotype[i] - 1);
		}
		break;
	}
	case 7:
	{
		double p = 1;
		for (int i = 0; i < GENOME_SIZE; i++)
		{
			sum += (genotype[i] * genotype[i]) / 4000.0;
			p *= cos(genotype[i] / sqrt(i + 1));
		}
		return 1.0 / sum - p + 1;
	}
	default:
		break;
	};
		
		return 1.0 / (double)(1 + sum);
}
void Individ::mutation()
{
	random_device rd;
	uniform_real_distribution<double> distribution(-MUTATION, MUTATION);
	mt19937 engine(rd());

	for (int i = 0; i < GENOME_SIZE; i++)
	{
		genotype[i] += distribution(engine);
	}
}

//void Individ::diff_cross(const Individ& a, const Individ& b, const Individ& c)
//{
//	random_device rd;
//	uniform_real_distribution<double> distribution(0, 1.0);
//	mt19937 engine(rd());
//
//	for (int i = 0; i < GENOME_SIZE; i++)
//	{
//		if (distribution(engine) < CROSSING_ALPHA)
//			genotype[i] = a.genotype[i] + F * (b.genotype[i] - c.genotype[i]);
//	}
//}
void Individ::operator=(const Individ &ob)
{
	genotype = ob.genotype;
}

Individ operator*(double x, const Individ& ob)
{
	Individ temp(0);
	for (int i = 0; i < GENOME_SIZE; i++)
	{
		temp.genotype[i] = ob.genotype[i] * x;
	}
	return temp;
}
ofstream& operator <<(ofstream& out, Individ& ob)
{
	for (int i = 0; i < GENOME_SIZE; i++)
	{
		out << ob.genotype[i] << ' ';
	}
	return out;
}

Individ Individ::operator+(const Individ & ob)
{
	Individ temp(0);
	for (int i = 0; i < GENOME_SIZE; i++)
	{
		temp.genotype[i] = genotype[i] + ob.genotype[i];
	}
	return temp;
}
Individ Individ::operator-(const Individ & ob)
{
	Individ temp(0);
	for (int i = 0; i < GENOME_SIZE; i++)
	{
		temp.genotype[i] = genotype[i] - ob.genotype[i];
	}
	return temp;
}
bool Individ::operator<(const Individ &ob)
{
	return fitness() < ob.fitness();

}
double Individ::func()
{
	double sum = 0;
	for (int i = 0; i < GENOME_SIZE; i++)
	{

		sum += genotype[i] * genotype[i];
	}
	return sum;
}

Individ::Individ(const Individ &ob)
{
	genotype = ob.genotype;
}

Individ::Individ(): genotype(GENOME_SIZE)
{
	random_device rd;
	uniform_real_distribution<double> distribution(GENOME_INIT_LO, GENOME_INIT_HI);
	mt19937 engine(rd());

	for (int i = 0; i < GENOME_SIZE; i++)
	{
		genotype[i] = distribution(engine);
	}

}

Individ::Individ(int): genotype(GENOME_SIZE, 0)
{
}

Individ::~Individ()
{
}
