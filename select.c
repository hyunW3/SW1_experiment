#include "main.h"
#define YES 1
#define NO 	2
// action : 매수(1)/매도(2) 
int select1(int future_price){ // 리턴값으로 체결여부 리턴해도 ㄱㅊ을듯 future_price = 내일가격
	int n;//매수or매도 수량
	int price; // 매수 매도 가격 -> 현재 시장가가 아닌 내가 지르는 가격
	int yes_or_no=0;
	int success = 0; //결과적으로 체결되었는가 1=체결 0=실패
LABEL1: 
	printf("현재 가격은 :%d입니다. 해당 가격으로 구매하겠습니까?\n 1. 예 2. 아니요 ",infor.price);
	scanf(" %d",&yes_or_no);
	if(yes_or_no == YES){
		price = infor.price;
		success = 1;
	}else if(yes_or_no == NO){ // 여기서 내일가격이랑 내가 지른 매수가랑 비교해서 매수가 > 내일가격이면 체결된거 success = 1

		printf("얼마의 가격으로 하겠습니까? :");
		scanf(" %d",&price);
		if(price >= future_price){
			success = 1;
		} 
	}else{
		fprintf(stderr,"잘못된 입력입니다. \n");// error handling
		goto LABEL1;
	} 
LABEL2:
	printf("수량을 입력하십시오 : ");
	scanf("%d", &n);
	if(price * n > user->current_money){
		clear_session();
		printf("*************************** 잔고가 부족합니다. ***************************\n");
		sleep(1);
		return -1;
	}else if(n<=0) {
		fprintf(stderr,"잘못된 입력입니다.\n");// error handling
		goto LABEL2;
	}
	// 알림
	printf("======= 매수 신청 안내 =======\n코인 가격 : %d 개수 : %d 입니다.\n",price,n);
	if(success == 1){
		printf("sucess!\n");
		user->current_money -= n * price;
		//printf("DEBUG : user->coin_amount : %.2lf\n", user->coin_amount); // 
		user->coin_amount += (n * price); // 이친구 문제
		user->num_coin += n;
		user->coin_average = (double)user->coin_amount / user->num_coin;
		//printf("DEBUG : user->coin_average : %.2lf(%.2lf나누기%d)\n", user->coin_average,user->coin_amount,user->num_coin); // 
	}else {
		clear_session();
		printf("***************************매수 실패***************************\n");
		sleep(1);
	}
	user->benefit = (future_price - user->coin_average) * user->num_coin;
	user->benefit_percent = ((double)future_price - user->coin_average) / user->coin_average * 100;
	return success;
}

int select2(int future_price){ 
	int n;//매수or매도 수량
	int price; // 매수 매도 가격
	int yes_or_no=0;
	int success = 0; // 체결 = 1 불가 = 0
LABEL3:
	printf("현재 가격은 :%d입니다. 해당 가격으로 매도하겠습니까?\n 1. 예 2. 아니요 ",infor.price);
	scanf(" %d",&yes_or_no);
	if(yes_or_no == YES){
		price = infor.price;
		success = 1;
	}else if(yes_or_no == NO){
		printf("얼마의 가격으로 하겠습니까? :");
		scanf("%d",&price);
		if(price <= future_price)
			success = 1;
	}else {
		fprintf(stderr,"잘못된 입력입니다.\n");// error handling
		goto LABEL3;
	} 
LABEL4:
	printf("수량을 입력하십시오(현재 보유 코인 %d(개)) : ",user->num_coin);
	scanf("%d", &n);
	if(n > user->num_coin){
		clear_session();
		printf("*************************** 보유 코인보다 더 많은 코인을 매도할 수 없습니다. ***************************\n");
		sleep(1);
		return -1; // fail 메인문에서 fail로 받음 
	}else if(n<=0) {
		fprintf(stderr,"잘못된 입력입니다.\n");// error handling
		goto LABEL4;
		
	}
	// 알림
	printf("======= 매도 신청 안내 =======\n코인 가격 : %d 개수 : %d 입니다.\n",price,n);
	if(success == 1){
		user->current_money += n * price;
		user->coin_amount -= n * price;
		user->num_coin -= n;
		if(user->num_coin == 0) {
			user->coin_average = 0;
			user->coin_amount = 0;
		}else user->coin_average = (double)user->coin_amount / user->num_coin;
		//user->
		//매도했을 때 수익금
	}else printf("***************************매도 실패***************************\n");
	
	if(user->coin_average == 0){
		user->benefit_percent = 0;
		user->benefit = 0;
	}
	else {
		user->benefit = (future_price - user->coin_average) * user->num_coin;
		user->benefit_percent = ((double)future_price - user->coin_average) / user->coin_average * 100;
	}
	return success;
}

void select4(int future_price){
	if(user->coin_average == 0){
		user->benefit_percent = 0;
		user->benefit = 0;
	}
	else {
		user->benefit = (future_price - user->coin_average) * user->num_coin;
		user->benefit_percent = ((double)future_price - user->coin_average) / user->coin_average * 100;
	}
}