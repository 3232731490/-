#pragma once
#include<iostream>
#include<ctime>
#include"heap.h"
#include"insert.h"
#include"merge.h"
#include"pop.h"
#include"quick.h"
#include"select.h"
#include"Xier.h"
#define random(x) (rand()%x)
using namespace std;

#define MAXSIZE1 100
#define MAXSIZE2 30000
void Input(int*& a, int& n);

void dis_list(int* a, int n);

void dis_menu();

void arti_menu();

void arti(int* a, int n);

void random_num(int**& a);

void Cmp_time(int** b);