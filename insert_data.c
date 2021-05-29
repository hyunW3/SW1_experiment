#include "main.h"

//TODO user info와 분리해서 만들자 
// update user info / update coin info
void insert_user_info(user_info* user,int current_money,	int benefit,double benefit_percent){
	user->current_money 			= current_money;
	user->benefit 					=benefit;
	user->benefit_percent 			=benefit_percent;
}
void insert_trade_info(trade* ct,int* price,int* amount_left,int* amount_right){
		for(int i=0; i<4; i++){
			ct->current_trade_price[i] = price[i]; // 이게 호가 쪽이긴한데 대략적으로 적어놓음
			ct->current_trade_amount_left[i] = amount_left[i];
			ct->current_trade_amount_right[i] = amount_right[i];
			
		}
}