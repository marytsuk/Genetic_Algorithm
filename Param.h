#pragma once
#define GENOME_SIZE 3//����� ������ 
#define POPULATION_SIZE 50 //����� ���������
//#define MUTATION_LO -0.5 //������ ������� �������� �������
//#define MUTATION_HI 0.5 //������� ������� �������� �������
#define GENOME_INIT_LO -100 //������ ������� ������������� ��������� �����
#define GENOME_INIT_HI 100 //������� ������� ������������� ��������� �����
#define CROSSING_ALPHA 0.5 //���������� �����������
extern double MUTATION;
extern double F; //[0; 2]
extern int k;