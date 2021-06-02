#include "main.h"

void init_func();
int main(){
	int day =1; // 유저가 보내는 시간
	init_func(); // include 변수들 동적할당
	// update user, 이평선 업데이트
	int max_val;
	int risefall;
	RECOMMENDED recommend_out;
	double accuracy_rate = 0;
	// DAY_PASSED : 이게 30일이야
	for(day; day<=DAY_PASSED; day++){ //30일 자동 돌아감 + 뉴스 없이!
		printf("Day %d\n",day);
		// TODO 처음에 자동으로 30일 지나가는 부분
		if(day==1){
			infor.price = 500, infor.rf=half_half(); // 맨첫날 가격 500원부터 시작!! 전날 가격정보 없어서 확률 반반 
			max_val = infor.price;
		}else{	//첫날 아님
			infor = apply_infor(infor.price,risefall,day); //  전날과 비교해서 rf/price 넣어줌 insert_data.c 에있음
		}
		price[day] = infor.price;
		if(max_val < price[day]) max_val = price[day];
		printf("DEBUG : infor : %d %d %d\n",infor.rf,infor.price,infor.rf);
		analyzed=yong(infor); // 가중치 결정
		//yong으로 가중치를 구하면 그걸 토대로 내일 가격과 내일 입장의 rf이 나오는데 그걸 else 돌릴때 넣어줘야함. 30일 돌리는거에서 할건 이게 다 인듯
		printf("DEBUG : after analyzed %d\n",analyzed.rise-analyzed.fall);
		risefall = pick_random_weighted(20,rand_range,analyzed.rise-analyzed.fall);
		printf("DEBUG : after rand func risefall : %d(%%)\n",risefall);
		recommend_out = recommend(analyzed, infor, risefall, day);
		printf("DEBUG : label : %d\n", knn[day - 1][5]);
		
		// 30일떄, infor struct 
		// price[1000] 저장
	}
	// 30일 이후
	// TODO 경향성 그래프로 보여주기
	insert_user_info(user,INIT_MONEY,0,0);
	int flag_finish =0; // 끝을 알리는 플래그 변수
	// 용준이 함수는 거의다 포인터가 아니라서 analyzed정보가 그 날 정보야
	//analyzed=yong(infor); // 추천을 위한 가중치 결정 //여기서 결정하는 analyzed는 30일차 정보로 -> ㅇㅇ맞지 그러면 49번째 줄에서 같은짓 하는거 아님? 여기적을 필요있나
	//recommend_out = recommend(analyzed, risefall, day, 0); 위와 마찬가지
	// 저거 방금 넣어놓고 일단 주석처리함 realloc이라 완전하게 메인에 드갈자리 다 넣어야 계속 메모리 정확한 크기로 확장되면서 세그폴트 안뜰거같아서 메인에 다넣고 ㅈ석지우게 확인
	printf("지금부터 시작합니다 잠시만 기다려주세요\n");
	sleep(2);
		
	//유저 세션 시작
	while(1){
		// print session -> 다음날 확률변수 & risefall 결정 -> 매도/매수 select함수 -> 체결여부 print
	//	clear_session();
		infor = apply_infor(infor.price,risefall,day);
		price[day] = infor.price;
		if(max_val < price[day]) max_val = price[day];
		analyzed=yong(infor); // 가중치 결정
		printf("DEBUG : before recommend\n");
		recommend_out = recommend(analyzed, infor, risefall, day);
		int action;
RESTART:
		action = print_nth_day(day-DAY_PASSED,user,infor,analyzed,recommend_out, accuracy_rate); // return action
		// rise&fall 
		printf("DEBUG : infor : %d %d %d\n",infor.rf,infor.price,infor.rf);
		
		//yong으로 가중치를 구하면 그걸 토대로 내일 가격과 내일 입장의 rf이 나옴
		// 추천 관련정보는 print_nth_day 앞에서
		// -> 그거 그냥 pick_random_weighted 여기 마지막에 불러서 해결햇는데 
		// 다른때 쓸일있음?
		// 내일 가격 결정할때 val_s 반영해야하는거 맞지 
		// 아아 맞다 그거 귀찮아서 apply_infor 여기 함수에 넣었음 insert_data.c에 있어
		printf("DEBUG : after analyzed %d\n",analyzed.rise-analyzed.fall);
		risefall = pick_random_weighted(0,rand_range,analyzed.rise-analyzed.fall);
		printf("DEBUG : after rand func risefall : %d(%%)\n",risefall);
		accuracy_rate = accuracy(recommend_out.rise_cnt, risefall, day-DAY_PASSED);
		printf("DEBUG : rise_cnt : %d, fall_cnt : %d \n", recommend_out.rise_cnt, recommend_out.fall_cnt);
		printf("DEBUG : accuracy_rate %.1f: \n", accuracy_rate);
		printf("DEBUG : knn[i][5] : %d\n", knn[day - 1][5]);
		printf("DEBUG : recommend cause : %s %s %s\n", recommend_out.most_impact[0], recommend_out.most_impact[1], recommend_out.most_impact[2]);
		// README.md로 옮겨놓음 210531_23
		// action에 따른 함수 
		printf("DEBUG :action : %d\n",action);
		int fail=0;
		switch(action){
			case 1: //select1;
				fail = select1(infor.price * (1 + risefall * 0.01));
				break;
			case 2: //select2;
				if(user->num_coin == 0) {
					clear_session();
					printf("******************* 코인이 없습니다. *******************\n");
					sleep(1);
					fail = -1;
				}
				else fail = select2(infor.price * (1 + risefall * 0.01));
				break;
			case 3:
				graph(day-1,price,30,max_val); 
				goto RESTART;// 그래프보고 다시 메인화면으로, 다음날로 넘어가지 않음
				break;
			case 4:  // 패스
				select4(infor.price * (1 + risefall * 0.01));
				break;
			case 5:  // 끝
				flag_finish = 1;
				break;
		}
		if(user->current_money<=0 && user->num_coin <=0){
			printf("*******************게임종료 (사유 : 남은 돈을 다 썼습니다.)************************\n");
			sleep(1);
			return -1; // 유저 시드머니 증발
		}
		
		if(flag_finish == 1) break;
		if(fail == -1) goto RESTART;
		
		// update for next day
		
		day++;
	}
	printf("게임이 끝났습니다.\n");
	//게임끝난후 명예의 전당에 등록(순위)
	rank();
	return 0;
}
void init_func(){
	
	knn = (int**)malloc(sizeof(int*));
	user = calloc(1,sizeof(user_info));
	user->benefit 				=0;
	user->benefit_percent 		=0;
	news = calloc(LINE_MAX,sizeof(char));
	infor.rf = half_half();
	infor.price = INIT_COIN_COST;
	infor.day = 0;
	memset(three,0,2*sizeof(int));	
	memset(seven,0,2*sizeof(int));
	memset(twenty,0,2*sizeof(int));
	memset(price,0,1000*sizeof(int));
	correct = 0;
}