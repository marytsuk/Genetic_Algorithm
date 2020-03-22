#pragma once
#define GENOME_SIZE 3//длина генома 
#define POPULATION_SIZE 50 //объем попул€ции
//#define MUTATION_LO -0.5 //нижни€ граница мощности мутации
//#define MUTATION_HI 0.5 //верхн€€ граница мощности мутации
#define GENOME_INIT_LO -100 //нижн€€ граница инициализации отдельных генов
#define GENOME_INIT_HI 100 //верхн€€ рганица инициализации отдельных генов
#define CROSSING_ALPHA 0.5 //коэффицент скрещивани€
extern double MUTATION;
extern double F; //[0; 2]
extern int k;