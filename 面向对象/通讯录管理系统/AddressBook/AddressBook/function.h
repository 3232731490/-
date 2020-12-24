#pragma once
#include"add_define.h"

void open_File(list<User> &list);

void save_File(list<User> &list, string Filename);

void add_File();

void search_info(list<User> &list);

void dis_menu();

bool read_File( list<User>& User_List, string& File_name, int& begin);

void mod_User(list<User>& User_List);

void del_User(list<User>& User_List);

void clear_User(list<User>& User_List);

void merge_File(list<User>& User_List);