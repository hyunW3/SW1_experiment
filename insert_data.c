 #include "main.h"

//TODO user info와 분리해서 만들자 
// update user info / update coin info
void insert_user_info(user_info* user,int current_money,double coin_average,double coin_amount){
	user->current_money 		= current_money;
	user->coin_average 			= coin_average;
	user->coin_amount 			= coin_amount;
	
}

INFOR apply_infor(int price, int risefall,int day){
	INFOR infor;
	infor.price = price*(1+risefall*0.01);
	if(risefall >0) infor.rf = 1;
	else infor.rf = 0;
	infor.day = day;
	return infor;
}