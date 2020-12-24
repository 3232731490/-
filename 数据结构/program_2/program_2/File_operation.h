#pragma once
#include"define.h"

void input_flight(Flight& F);  //输入航班信息
void buy_ticket_no(Flight_list_head* f_head, Flight& F, string no,int c_num);  //通过航班编号买票
void search_path(Flight_list_head* f_head, string loc_begin, string loc_end, queue<queue<Flight>>&);  //求出其他可达路径
void buy_ticket_loc(Flight_list_head* f_head, Flight& F, string loc_begin, string loc_end,int c_num);  //通过起始地点买票
bool input_client(Client& C, Flight_list_head* f_head);  //输入乘客信息
void pushback_client(Client_list_head* c_head, Flight_list_head* f_head); //添加乘客信息
void pushback_flight(Flight_list_head* f_head);  //添加航班信息
void savefile_flight(Flight_list_head* f_head);  //保存航班信息
bool readfile_flight(Flight_list_head* f_head);  //读入航班信息
void savefile_client(Client_list_head* c_head);  //保存乘客信息
bool readfile_client(Client_list_head* c_head);   //读入乘客信息
void search_flight_loc(Flight_list_node* p, string loc_begin, string loc_end);  //通过起始地点查找航班
void search_flight_no(Flight_list_node* p, string no);  //通过航班编号查找航班
void search_flight(Flight_list_head* f_head);  //查询航班
void init_list(Client_list_head*& c_head, Flight_list_head*& f_head);  //初始化航班头和乘客头
void refund_ticket(Client_list_head*& c_head, Flight_list_head* f_head);  //退票
void delete_flight(Flight_list_head* f_head, Flight flight);  //删除航班
void init_flight(Flight_list_head*& f_head);  //重置机头
void init_client(Client_list_head*& c_head);  //重置客户头
void dis_flight_info(Flight_list_head*& f_head); //展示所有航班
void search_client(Client_list_head* c_head); //查询乘客信息
void modi_flight(Flight_list_head*& f_head);  //修改航班信息
void modi_client(Client_list_head*& c_head);  //修改乘客信息
void dis_client_info(Client_list_head*& c_head);  //展示所有乘客信息