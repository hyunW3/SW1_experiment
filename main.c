#include "main.h"

void init_func();
int main(){
	int day =1; // 유저가 보내는 시간
	init_func();; // include 동적할당
	// update user, 이평선 업데이트
	int benefit =0;
	insert_user_info(user,INIT_MONEY,benefit,0);
	for(int i=0; i<DAY_PASSED; i++){
		// TODO 처음에 자동으로 30일 지나가는 부분
		/*
			등락/하락을 위한 값을 뽑는다 by 가중치
			랜덤값이 코인의 가격에 영향주게 한다.
			코인값 반영
		*/
		asdf=yong(infor); // 가중치 결정
		printf("Day %d\n",i+1);
		// 30일떄, infor struct 
		// price[1000] 저장
	}
	// 
	while(1){
		//asdf=yong(infor); // 가중치 결정
		/* 다음날을 위한 준비 
		hyun(asdf); // 받은 가중치로 오를지 내릴지 결정
		오늘의 추천(내일 오를지말지)=recommend(오늘의 ANALYZED);  // 추천값 출력
		*/
		sleep(3);
		clear_session();
		
		int action = print_nth_day(day,user,infor,analyzed,trade_info); // return action
		// action에 따른 함수 
		// 매수 매도 액션을 위해서 print_nth_day에서 1리턴하도록함
		
		switch(action){
			case 1: //select1;
				select1();
				break;
			case 2: //select2;
				select2();
				break;
			case 3:  // 패스
				break;
			case 4:  // 끝
				break;
		}
		
		// action 반영(매수,매도,)
		break;
		// update for next day
		
		day++;
	}
	
	//pick_random_weighted(0,10,-50); 
	
	return 0;
}
void init_func(){
	
	knn = (int**)malloc(sizeof(int*));
	trade_info = calloc(1,sizeof(trade)); // current_trade 호가를 위한 값
	user = calloc(1,sizeof(user));
	news = calloc(LINE_MAX,sizeof(char));
	memset(three,2,sizeof(int));	
	memset(seven,2,sizeof(int));
	memset(twenty,2,sizeof(int));
	memset(price,2,sizeof(int));
	correct = 0;
}