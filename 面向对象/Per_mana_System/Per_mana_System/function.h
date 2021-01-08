#pragma once
#include"info_define.h"

void read_info(list<Person>& mylist, PortList*& Port,string &Filename);
void save_info(list<Person>& mylist,string& Filename);
bool cmp_age_de(Person& p1, Person& p2);
bool cmp_age_ri(Person& p1, Person& p2);
bool cmp_wage_de(Person& p1, Person& p2);
bool cmp_wage_ri(Person& p1, Person& p2);
void del_info(list<Person>& mylist, string& Filename);
void dis_info(list<Person>& mylist);
void input_info();

void search_info(list<Person>& mylist);
void mod_info(list<Person>& mylist, string& Filename);
void sort_info(list<Person>& mylist);
void read_count_info(list<Person>& mylist, PortList* &Port);
void dis_count_info(list<Person>& mylist ,PortList*& Port);
void all_sort(list<Person>& mylist, PortList* &Port);
void clear_info();

void dis_main_menu();
void func_main(list<Person>& mylist, PortList*& Port);