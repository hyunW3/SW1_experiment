#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "print_color.h"
#include "MACRO.h"
#include "def_struct.h"
//선언부
char* news;
// 최근 이평선 정보 
int three[2]; //골든 크로스 
int seven[2];
int twenty[2];
// 모든 일차의 가격정보
int price[1000];

//from recommend

int** knn; 
int correct; // 초기화 정보 main.c에 init_func()에 함
RECOMMENDED recommend(ANALYZED input, int difference, int idx_knn);
double accuracy(int prediction, int fact, int total);

//for func

INFOR infor;
ANALYZED analyzed;

ANALYZED yong(INFOR infor);

//for  rand.c
int half_half();
int pick_random_weighted(int mid, int range, int weight);
int str_copy(char* des, char* src,int pos);
int parse_newsfile(char* news,char* key1,char* pLine);
int new_getter(); // 리턴값 가중치

// for insert_data.c
user_info* user;
trade* trade_info;
// for insert_data.c function
void insert_user_info(user_info* user,int current_money,int benefit,double benefit_percent);
void insert_trade_info(trade* ct,int* price,int* amount_left,int* amount_right);

// for print_session.c
void clear_session();
int print_nth_day(int date,user_info* user,INFOR infor,ANALYZED analyzed ,trade* trade_info); // return action number

//select.c
int select1();
int select2();