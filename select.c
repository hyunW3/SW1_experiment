#include "main.h"
#define YES 1
#define NO 	2
// action : 매수(1)/매도(2) 
int select1(){ // 리턴값으로 체결여부 리턴해도 ㄱㅊ을듯
	int n;//매수or매도 수량
	int price; // 매수 매도 가격
	int yes_or_no=0;
	printf("현재 가격은 :%d입니다. 해당 가격으로 구매하겠습니까?\n 1. 예 2. 아니요 \n",infor.price);
	scanf(" %d",&yes_or_no);
	if(yes_or_no == YES){
		price = infor.price;
	}else if(yes_or_no == NO){
		printf("얼마의 가격으로 하겠습니까? :");
		scanf("%d",&price);
	}else fprintf(stderr,"잘못된 입력입니다.\n");// error handling
	printf("수량을 입력하십시오 : ");
	scanf("%d", &n);
	// 알림
	printf("======= 매수 신청 안내 =======\n코인 가격 : %d 개수 : %d 입니다.\n",price,n);
	// yes_or_no 가 NO일 때, 체결될지 말지 결정하는 건 아직 미구현
	user->current_money -= n * infor.price;
}

int select2(){ 
	int n;//매수or매도 수량
	int price; // 매수 매도 가격
	int yes_or_no=0;
	printf("현재 가격은 :%d입니다. 해당 가격으로 매도하겠습니까?\n 1. 예 2. 아니요 \n",infor.price);
	scanf(" %d",&yes_or_no);
	if(yes_or_no == YES){
		price = infor.price;
	}else if(yes_or_no == NO){
		printf("얼마의 가격으로 하겠습니까? :");
		scanf("%d",&price);
	}else fprintf(stderr,"잘못된 입력입니다.\n");// error handling
	printf("수량을 입력하십시오 : ");
	scanf("%d", &n);
	// 알림
	printf("======= 매도 신청 안내 =======\n코인 가격 : %d 개수 : %d 입니다.\n",price,n);
	// yes_or_no 가 NO일 때, 체결될지 말지 결정하는 건 아직 미구현
	user->current_money += n * infor.price;
	
}
