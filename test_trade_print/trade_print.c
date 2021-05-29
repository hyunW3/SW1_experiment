#include "main1.h"


char* news= "일론 마스크가 화성에 갔다.";


int tendency[3] = {300,500,2000}; // 3일선 5일선 20일선
int current_money = 10000000;
int average_coin_unitprice = 700;
int benefit = 40000;
double benefit_percent = 3.61;

int current_trade_price[4] = {405,400,395,390};
int current_trade_amount_left[4] = {300,0,0,0};
int current_trade_amount_right[4] = {0,400,500,600};


int main(){
	int day =1;
	coin_info = calloc(1,sizeof(coin));
	trade_info = calloc(1,sizeof(trade));
	user = calloc(1,sizeof(user));
	
	insert_user_info(user,INIT_MONEY,benefit,0);
	
		int action = print_nth_day(day,user,infor,analyzed,trade_info);
	printf("action :%d\n",action);
	return 0;
}


int print_nth_day(int date,user_info* user,INFOR infor,ANALYZED analyzed ,trade* trade_info){
	// trade* trade_info 여기서 만들자
	if(strlen(news)==0) strcpy(news,"뉴스 없습니다.");
	char action;
	printf("================================================\t%3d일차\t\t ==============================================================\n",date);
	printf("  오늘의 뉴스 : %s\n",news);
	printf("\t\t내 잔고\t\t\t\t  AI 추천 분석\t\t\t\t\t\t\t호가\n");
	printf(BOLD " 내 잔고\t: %10d(원)\t\t\t3일선 :%5d\t\t\t\t\t %4d(개) |  %5d(원) |   \n" RESET,user->current_money,analyzed.day3,
		   trade_info->current_trade_amount_left[0],trade_info->current_trade_price[0],trade_info->current_trade_amount_right[0]);
	printf(" 코인 평균 단가\t: %10d(원)\t\t\t7일선 :%5d\t\t\t\t\t %4d(개) |  %5d(원) |   \n",infor.price,analyzed.day7,
		   trade_info->current_trade_amount_left[1],trade_info->current_trade_price[1],trade_info->current_trade_amount_right[1]);
	printf(" 평가손익\t: %10d(원)\t\t\t20일선:%5d\t\t\t\t\t\t     %5d(원) |  %4d(개) \n",user->benefit,analyzed.day20,
		   trade_info->current_trade_amount_left[2],trade_info->current_trade_price[2],trade_info->current_trade_amount_right[2]);
	printf(" 수익률\t\t: %10.2f(%%)\t\t\t\t코인가격:%5d(%s)\t\t\t\t\t     %5d(원) |  %4d(개)\n",user->benefit_percent,
		   infor.price,analyzed.t_amount,
		   trade_info->current_trade_amount_left[3],trade_info->current_trade_price[3],trade_info->current_trade_amount_right[3]);
	//(infor.rf==1)?('↑'):('↓'),
	while(1){
		printf("\n\t당신의 행동은?\n");
		printf("1. 매수\n");
		printf("2. 매도\n");
		printf("3. 다음날로 넘어가기\n");
		printf("4. 탈출(게임끝)\n");
		printf("숫자만 입력하세요 : ");
		scanf(" %c",&action);
		if(action >'0' && action <='4'){
			return action-'0';
		}else {
			printf("\n입력오류(%c) 숫자만 입력하세요\n",action);
			action=0;
			continue;
		}
	}
}




//TODO user info와 분리해서 만들자 
void insert_user_info(user_info* user,int current_money,	int benefit,double benefit_percent){
	user->current_money 			= current_money;
	user->benefit 					=benefit;
	user->benefit_percent 			=benefit_percent;
}
void insert_trade_info(trade* ct,int* price,int* amount_left,int* amount_right){
		for(int i=0; i<numOf_trade_save; i++){
			ct->current_trade_price[i] = price[i]; // 이게 호가 쪽이긴한데 대략적으로 적어놓음
			ct->current_trade_amount_left[i] = amount_left[i];
			ct->current_trade_amount_right[i] = amount_right[i];
			
		}
}