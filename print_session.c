#include "main.h"
void clear_session(){
	system("clear");
}
int print_nth_day(int date,user_info* user,INFOR infor,ANALYZED analyzed ,RECOMMENDED rd, double accuracy_rate){
	char prediction[6][15] = {"fall(high)", "fall(normal)", "fall(low)", "rise(low)", "rise(normal)", "rise(high)"};
	int cnt;
	if(rd.rise_cnt >= 3) cnt = rd.rise_cnt;
	else cnt = rd.fall_cnt;
	if(strlen(news)==0) strcpy(news,"뉴스 없습니다.");
	char action;
	printf("================================================\t%3d일차\t\t ==============================================================\n",date);
	// line 0
	printf("  오늘의 뉴스 : %s\n",news);
	// line 1
	printf("\t\t내 잔고\t\t\t\t\t\t");
	printf("AI 추천 분석\t\t\t\t\t\t\t\n"); 
	// line 2
	printf(BOLD " 내 잔고\t: %10d(원)\t\t\t",user->current_money);
	printf("3일선 \t:%5d\t\t\t\t\t\n" RESET,analyzed.day3);
	// line 3
	printf(" 코인 평균 단가\t: %10.1f(원)\t\t\t",user->coin_average);
	printf("7일선 \t:%5d\t\t\t\t\t \n",analyzed.day7);
	// line 4
	printf(" 코인 개수\t: %10d(개)\t\t\t",user->num_coin);
	printf("20일선\t:%5d\t\t\t\t\t\t\n",analyzed.day20);
	// line 5
	printf(" 평가손익\t: %10d(원)\t\t\t",user->benefit);
	printf("코인가격:%5d(거래량 %s)\t\t\t\t\t\n",
		   infor.price,analyzed.t_amount);
	// line 6
	printf(" 수익률\t\t: %10.2f(%%)\t\t\t\t",
		   user->benefit_percent);
	printf("등락예측: %s\t\t\t\t", 
		  prediction[rd.rise_cnt]);
	printf("아래의 5개가 제일 가까운 값들입니다.(KNN base) \n");
	// line 7
	printf(" \t\t\t\t\t\t\t예측 정확도: %.1f(%%)\t\t\t\t", accuracy_rate);
	for(int i = 0; i < cnt; i++){
		if(i==0) printf("%s", rd.most_impact[i]);
		else printf(", %s", rd.most_impact[i]);
		
	} 
	printf("\n");
	//(infor.rf==1)?('↑'):('↓'),
	while(1){
		printf("\n\t당신의 행동은?\n");
		printf("1. 매수\n");
		printf("2. 매도\n");
		printf("3. 지난 30일간 그래프로 보기\n");
		printf("4. 다음날로 넘어가기\n");
		printf("5. 탈출(게임끝)\n");
		printf("숫자만 입력하세요 : ");
		scanf(" %c",&action);
		if(action >'0' && action <='5'){
			return action-'0';
		}else {
			printf("\n입력오류(%c) 숫자만 입력하세요\n",action);
			action=0;
			continue;
		}
	}
	return action;
}


void graph(int day,int *price, int len, int max_val){
	printf("                      ");
	printf("==============================");
	printf("최근 %2d일간 그래프",len);
	printf("==============================\n");
	int num_divide = 10; // 10등분
	int divide_val = max_val/num_divide; 
	int start = (day-len>0)? day-len : 1;
	int end = day;
	for(int j=start; j<day; j++){
		//printf("%d-> %d\n",j,price[j]);
		
	}
	printf("%10d원 ~              ",max_val);
	for(int j=start; j<day; j++){
		if(price[j]>=max_val) printf(" ~  ");
		else printf("    ");
	}printf("\n");
	for(int i=10; i>=1; i--){ // 10 등분해서 표현
		int bottom = divide_val*(i-1);
		int top = divide_val*i;
		printf("%10d원 ~ %10d원 ",bottom,top);
		for(int j=start; j<day; j++){
			if((bottom<=price[j]) && (price[j]<top)) printf(" =  ");
			else if(price[j] >= divide_val*i) printf(" |  ");
			else printf("    ");
		}printf("\n");
	}
	printf("           ");
	printf("    ");
	printf("           ");
	printf(" ");
	for(int j=start; j<day; j++){
		printf("%2d일",j);
	}printf("\n");
	printf("메인 화면으로 넘어가시려면 아무키나 눌러주세요..");
	char buf;
	scanf(" %c",&buf);
		
	
}