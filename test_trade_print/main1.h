#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "MACRO.h"
#include "print_color.h"

// struct 

typedef struct infor{
	int rf; //상승1 or 하락0
	int price; //오늘 가격
	int day;
}INFOR;

typedef struct analyzed{
	int day3;
	int day7;
	int day20;
	int rise;
	int fall;
	int g_cross;
	int d_cross;
	char t_amount[7];
	char* news; // news string
}ANALYZED;

typedef struct coin{
	int average_coin_unitprice; // price
	int tendency[3]; // day3 day7 day20
}coin;

typedef struct user{
	int current_money;
	double benefit_percent;
	int benefit;
}user_info;

typedef struct current_trade{
	int current_trade_price[4];			
	// ex){405,400,395,390};
	int current_trade_amount_left[4]; 	
	// ex) {300,0,0,0};
	int current_trade_amount_right[4];	
	// ex) {0,400,500,600};
}trade;



user_info* user;
coin* coin_info;
INFOR infor;
ANALYZED analyzed;
trade* trade_info;

int print_nth_day(int date,user_info* user,INFOR infor,ANALYZED analyzed ,trade* trade_info);

void clear_session(){
	system("clear");
}

void insert_coin_info(coin* coin_info, INFOR infor,ANALYZED analyzed );
void insert_user_info(user_info* user,int current_money,int benefit,double benefit_percent);
void insert_trade_info(trade* ct,int* price,int* amount_left,int* amount_right);