// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "Individ.h"
#include "Param.h"
#include <random>
#include <fstream>

using namespace std;
double MUTATION = 1.0;
double F = 1;
//double MUTATION = 0.5;
int k = 0;
vector <Individ> population(POPULATION_SIZE);
ofstream file;

void Selection()
{
	sort(population.begin(), population.end());

	/*cout << "func: " << population[POPULATION_SIZE - 1].Rosenbrock_func() << endl;*/
	
	//file << population[POPULATION_SIZE - 1];
	switch (k)
	{
	case 1:
	{
		cout << "func: " << population[POPULATION_SIZE - 1].func() << endl;
		file << population[POPULATION_SIZE - 1].func() << endl;
		break;
	}
	case 6:
	{
		cout << "func: " << population[POPULATION_SIZE - 1].Rosenbrock_func() << endl;
		file << population[POPULATION_SIZE - 1].Rosenbrock_func() << endl;
		break;
	}
	case 7:
	{
		cout << "func: " << population[POPULATION_SIZE - 1].Griewank_funk() << endl;
		file << population[POPULATION_SIZE - 1].Griewank_funk() << endl;
		break;
	}

	default:
		break;
	};
	/*file << population[POPULATION_SIZE - 1].Rosenbrock_func() << endl;*/

	//int sum = POPULATION_SIZE * (1 + POPULATION_SIZE) / 2;
	int sum = POPULATION_SIZE;

	random_device rd;
	uniform_real_distribution<double> distribution(0.0, 1.0);  
	mt19937 engine(rd());

	vector<Individ> New_Generation(POPULATION_SIZE); 
	vector<int> free; 

	for (int i = POPULATION_SIZE - 1; i >= 0; i--) 
	{
		if (distribution(engine) < static_cast<double>(i) / static_cast<double>(sum))  
			New_Generation[i] = population[i];
		else
			free.push_back(i);
	}

	while (!free.empty())
	{
		for (vector<int>::iterator it = free.begin(); it != free.end(); ) 
		{
			bool flag = true;
			for (int i = POPULATION_SIZE - 1; i >= 0; i--) 
			{
				if (distribution(engine) < static_cast<double>(i) / static_cast<double>(sum))
				{
					New_Generation[*it] = population[i];
					it = free.erase(it);
					flag = false;
					break;
				}
			}
			if (flag)
				it++;
		}
	}

	population = New_Generation;
}
void Crossover()
{
	vector <Individ> temp(POPULATION_SIZE);
	std::random_device rd; 
	uniform_real_distribution<> distribution(0, POPULATION_SIZE - 1); 
	std::mt19937 gen(rd());  
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		temp[i] = CROSSING_ALPHA * population[distribution(gen)] + (1 - CROSSING_ALPHA) * population[distribution(gen)];
	}
	population = temp;
	/*Individ temp;

	for (int i = 0; i + 1 < POPULATION_SIZE; i += 2)
	{
		temp = population[i];
		population[i] = CROSSING_ALPHA * population[i] + (1 - CROSSING_ALPHA)*population[i + 1];
		population[i + 1] = CROSSING_ALPHA * population[i + 1] + (1 - CROSSING_ALPHA)*temp;
	}*/
}
void Mutate()
{
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		population[i].mutation();
	}
}

int main()
{
	cin >> k;
	file.open("data.txt", ios::out | ios::trunc);
	int iter = 0;

	

	while (iter < 50000)
	{
		file << iter << " ";
		Selection();
		Crossover();
		Mutate();
		iter++;
		MUTATION = (double)(1.0 / ((double)iter / 10));
	}

}

