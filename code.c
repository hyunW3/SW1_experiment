#include "main.h"


// 개수 : numberOf_trade_save
void write_trade_info(current_trade* ct,int* price,int* amount_left,int* amount_right){
	for(int i=0; i<numberOf_trade_save; i++){
		ct->current_trade_price[i] = price[i];
		ct->current_trade_amount_left[i] = amount_left[i];
		ct->current_trade_amount_right[i] = amount_right[i];
	}	
}
/*
 test code
int current_trade_price[4] = {405,400,395,390};
int current_trade_amount_left[4] = {300,0,0,0};
int current_trade_amount_right[4] = {0,400,500,600};
	write_trade_info(ct,current_trade_price,current_trade_amount_left,current_trade_amount_right);
	for(int i=0; i<numberOf_trade_save; i++){
		printf("%d %d %d\n",ct->current_trade_price[i],ct->current_trade_amount_left[i],ct->current_trade_amount_right[i]);
	}
*/
// weighted random pick 가중치를 준 랜덤 뽑기
//int pick_random_with_weighted(int mid, int weight){
// |-------------|------------| : random array
//         |----|----|			: mid & range
//            <- mid -> 		: 위에서 가운데가 mid, 좌우로 차이가 range
//50+weight기준으로 좌측 : 하락 , 우측 : 상승 
// mid 기준점 : 0
int pick_random_weighted(int mid, int range, int weight){
	// rand_range 100 , rand_center 50
	srand(time(NULL)+rand());
	int* rand_num;
	int index,val;
	//int val_range[10] = {1,rand_range/10,rand_range/5,rand_range/4,rand_range/2,
	//					 rand_range/2,rand_range/5,rand_range/4,rand_range/10,1};
	int val_range[10] = {rand_range/1.5, rand_range/3, rand_range/5, rand_range/8, 1,
						 1,rand_range/8,rand_range/5,rand_range/3,rand_range/1.5};
	rand_num = calloc(rand_range,sizeof(int));
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			int range_1,index;
			
			if(i<=4) range_1= val_range[i+1]-val_range[i];
			else range_1 = val_range[i] - val_range[i-1];
			index = 10*i+j;
			//if(range_1==0)	rand_num[index] = rand()%30 + (rand_range-30);
			//else rand_num[index] = rand()%range_1 + val_range[i];
			if(range_1==0)	rand_num[index] = rand()%15+1 ;
			else rand_num[index] = rand()%range_1 + val_range[i];
			
			printf("%2d ",rand_num[index]);
		}printf("\n");
	}
	// pick random
	srand(time(NULL));
	index = rand()%(range*2)+(rand_center+mid-range); 
	val = rand_num[index];
	
	free(rand_num);
	if(index <rand_center-weight) val = -val ; // 하락
	else val = val; 				// 상승
	
	printf("index : %d, val : %d\n",index,val);
	return val; // result return
}

int scale_how_much(int val){
	// 얼마나 증가/감소할건지 랜덤으로 선택하기 위해 scale하는 함수
	// 결정변수 x
	double val_s = (val*0.3); // 
	printf("%lf\n",val_s);
	return (int)(val_s);
}
 
 
