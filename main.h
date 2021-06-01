#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
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
int price[1000]; // 1일부터 시작 (인덱스 0에 없음)

//from recommend

int** knn; 
int correct; // 초기화 정보 main.c에 init_func()에 함
RECOMMENDED recommend(ANALYZED input, INFOR infor, int risefall, int idx_knn);
double accuracy(int prediction, int risefall, int total);

//for func

INFOR infor;
ANALYZED analyzed;

ANALYZED yong(INFOR infor);
void rank();

//for  rand.c
int half_half();
int pick_random_weighted(int mid, int range, int weight);
int str_copy(char* des, char* src,int pos);
int parse_newsfile(char* news,char* key1,char* pLine);
int new_getter(); // 리턴값 가중치

// for insert_data.c
user_info* user;
// for insert_data.c function
void insert_user_info(user_info* user,int current_money,double coin_average,double coin_amount);
INFOR apply_infor(int price, int risefall,int day);
// rank.c
void rank();

// for print_session.c
void clear_session();
int print_nth_day(int date,user_info* user,INFOR infor,ANALYZED analyzed ,RECOMMENDED rd, double accracy_rate); // return action number
void graph(int day,int *price, int len, int max_val);
//select.c
int select1(int future_price);
int select2(int future_price);
void select4(int future_price);