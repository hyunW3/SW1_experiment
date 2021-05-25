#include <stdio.h>
#include "print_color.h"
int date=0;
int current_money = 10000000;
int average_coin_unitprice = 700;
int tendency[3] = {300,500,2000}; // 3일선 5일선 20일선
int benefit = 40000;
int current_trade_price[4] = {405,400,395,390};
int current_trade_amount_left[4] = {300,0,0,0};
int current_trade_amount_right[4] = {0,400,500,600};
double benefit_percent = 3.61;
char* today_news= "일론 마스크가 화성에 갔다.";


int main(){
	int action=0;
	printf("================================================\t%3d일차\t\t ==============================================================\n",date);
	printf("  오늘의 뉴스 : %s\n",today_news);
	printf("\t\t내 잔고\t\t\t\t  AI 추천 분석\t\t\t\t\t\t\t호가\n");
	printf(BOLD " 내 잔고\t: %10d(원)\t\t3일선 :%5d\t\t\t\t\t %4d(개) | %5d(원)  |  %4d(개) \n" RESET,current_money,tendency[0],
		   current_trade_amount_left[0],current_trade_price[0],current_trade_amount_right[0]);
	printf(" 코인 평균 단가\t: %5d(원)\t\t\t5일선 :%5d\t\t\t\t\t %4d(개) |  %5d(원) |  %4d(개) \n",average_coin_unitprice,tendency[1],
		   current_trade_amount_left[1],current_trade_price[1],current_trade_amount_right[1]);
	printf(" 평가손익\t:   %5d(원)\t\t\t20일선:%5d\t\t\t\t\t %4d(개) |  %5d(원) |  %4d(개) \n",benefit,tendency[2],
		   current_trade_amount_left[2],current_trade_price[2],current_trade_amount_right[2]);
	printf(" 수익률\t\t: %6.2f%%\t\t\t\t\t\t\t\t\t %4d(개) |  %5d(원) |  %4d(개)\n",benefit_percent,
		   current_trade_amount_left[3],current_trade_price[3],current_trade_amount_right[3]);
	
	printf("\n\t당신의 행동은?\n");
	printf("1. 매수\n");
	printf("2. 매도\n");
	printf("3. 다음날로 넘어가기\n");
	printf("3. 탈출(게임끝)\n");
	printf("숫자만 입력하세요 : ");
	scanf("%d",&action);
	return action;
}
	
