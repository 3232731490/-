#pragma once
#pragma once
#include<iostream>
using namespace std;

struct LinkList {
	char data;
	LinkList* next;
};
void init_Link(LinkList** L);

void push_link(LinkList* L);

void dis_Link(LinkList* L);

int get_len(LinkList* L);

bool isEmpty(LinkList* L);

void in_link(LinkList* L);

void del_link(LinkList* L);

void del_link_ele(LinkList* L);

void free_link(LinkList** L);

void find_ele(LinkList* L);

void get_pos(LinkList* L);

void head_push(LinkList* L);

void rear_push(LinkList* L);

void del(LinkList* L);

void push(LinkList* L);

void search(LinkList* L);

void dis_menu();