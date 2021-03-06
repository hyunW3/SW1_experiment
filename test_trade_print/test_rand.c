#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define rand_range 100
#define rand_center 50
int pick_random_weighted(int mid, int range, int weight);
int scale_how_much(int val);


//for rand.c 디버그용
int main(){
	int val = pick_random_weighted(0,10,0);
	val = scale_how_much(val);
	val = pick_random_weighted(val,10,0);
	printf("val : %d\n",val);
	return 0;
}

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
			int loc_range,index;
			
			if(i<=4) loc_range= val_range[i+1]-val_range[i];
			else loc_range = val_range[i] - val_range[i-1];
			index = 10*i+j;
			//if(loc_range==0)	rand_num[index] = rand()%30 + (rand_range-30);
			//else rand_num[index] = rand()%range_1 + val_range[i];
			if(loc_range==0)	rand_num[index] = rand()%15+1 ;
			else rand_num[index] = rand()%loc_range + val_range[i];
			
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
	double val_s = (val*0.27); // 
	printf("%lf\n",val_s);
	while(val_s > -1 && val_s < 1) val_s *=2;
	return (int)(val_s);
}