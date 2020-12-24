#pragma once
#include"define.h"

void input_flight(Flight& F);  //���뺽����Ϣ
void buy_ticket_no(Flight_list_head* f_head, Flight& F, string no,int c_num);  //ͨ����������Ʊ
void search_path(Flight_list_head* f_head, string loc_begin, string loc_end, queue<queue<Flight>>&);  //��������ɴ�·��
void buy_ticket_loc(Flight_list_head* f_head, Flight& F, string loc_begin, string loc_end,int c_num);  //ͨ����ʼ�ص���Ʊ
bool input_client(Client& C, Flight_list_head* f_head);  //����˿���Ϣ
void pushback_client(Client_list_head* c_head, Flight_list_head* f_head); //��ӳ˿���Ϣ
void pushback_flight(Flight_list_head* f_head);  //��Ӻ�����Ϣ
void savefile_flight(Flight_list_head* f_head);  //���溽����Ϣ
bool readfile_flight(Flight_list_head* f_head);  //���뺽����Ϣ
void savefile_client(Client_list_head* c_head);  //����˿���Ϣ
bool readfile_client(Client_list_head* c_head);   //����˿���Ϣ
void search_flight_loc(Flight_list_node* p, string loc_begin, string loc_end);  //ͨ����ʼ�ص���Һ���
void search_flight_no(Flight_list_node* p, string no);  //ͨ�������Ų��Һ���
void search_flight(Flight_list_head* f_head);  //��ѯ����
void init_list(Client_list_head*& c_head, Flight_list_head*& f_head);  //��ʼ������ͷ�ͳ˿�ͷ
void refund_ticket(Client_list_head*& c_head, Flight_list_head* f_head);  //��Ʊ
void delete_flight(Flight_list_head* f_head, Flight flight);  //ɾ������
void init_flight(Flight_list_head*& f_head);  //���û�ͷ
void init_client(Client_list_head*& c_head);  //���ÿͻ�ͷ
void dis_flight_info(Flight_list_head*& f_head); //չʾ���к���
void search_client(Client_list_head* c_head); //��ѯ�˿���Ϣ
void modi_flight(Flight_list_head*& f_head);  //�޸ĺ�����Ϣ
void modi_client(Client_list_head*& c_head);  //�޸ĳ˿���Ϣ
void dis_client_info(Client_list_head*& c_head);  //չʾ���г˿���Ϣ