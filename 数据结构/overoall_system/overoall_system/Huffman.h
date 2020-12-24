#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXSIZE 100
struct BTNode {
	int data;
	BTNode* Lchild, * Rchild;
};
void sort(int* a, int n);
void Init(int* a, BTNode** B, int& n);
void merge(BTNode** B, BTNode& min1, BTNode& min2, int n);
void creat_HTree(BTNode** B, int a[], int n);
void dis_Tree(BTNode* B);
void Dis_Tree(BTNode*& B);
int get_weight(BTNode* B, int layer);
void Get_weight(BTNode* B);
void free_BTree(BTNode*& B);
void free_BTREE(BTNode*& B);
void dis_BT(BTNode* B);
void Dis_HTree(BTNode* B);
void dis_Huff_menu();
void Huff_main_func();