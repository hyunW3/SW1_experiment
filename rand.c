#include "main.h"
int scale_how_much(int val);
int half_half(){
	// 0또는 1 리턴
	srand(time(NULL)*(rand()+100));
	if(rand()%2 ==0){
		return 1;
	}else return 0;
}
// weighted random pick 가중치를 준 랜덤 뽑기
//int pick_random_with_weighted(int mid, int weight){
// |-------------|------------| : random array
//         |----|----|			: mid & range
//            <- mid -> 		: 위에서 가운데가 mid, 좌우로 차이가 range
//50-weight기준으로 좌측 : 하락 , 우측 : 상승 
// mid 기준점 : 0

	
int pick_random_weighted(int mid, int range, int weight){
	// rand_range 100 , rand_center 50
	srand(time(NULL)*rand());
	int* rand_num;
	int index,val;
	//int val_range[10] = {1,rand_range/10,rand_range/5,rand_range/4,rand_range/2,
	//					 rand_range/2,rand_range/5,rand_range/4,rand_range/10,1};
	int val_range[10] = {rand_range/1.6, rand_range/4, rand_range/6, rand_range/8, 1,
						 1,rand_range/8,rand_range/6,rand_range/4,rand_range/1.6};
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
			
	//		printf("%2d ",rand_num[index]);
		}//printf("\n");
	}
	// pick random
	srand(time(NULL)*rand());
	index = rand()%(range*2)+(rand_center+mid-range); 
	//printf("in the rand func -> index : %d",index);
	if(index >100) index =99;
	else if(index <0) index =0;
	val = rand_num[index]; // result return 0~100 사이값
	
	free(rand_num);
	if(index <rand_center-weight) val = -val ; // 하락
	else val = val; 				// 상승
	
	val = scale_how_much(val);
	// 0~100 사이값 -> 0~30으로 리스케일
	printf("DEBUG : index : %d, val : %d\n",index,val);  
	return val; 
}

int scale_how_much(int val){
	// 얼마나 증가/감소할건지 랜덤으로 선택하기 위해 scale하는 함수
	// 결정변수 x
	double val_s = (val*0.29); // 
	//printf("val_s : %.1lf\n",val_s);
	while(val_s > -1 && val_s < 1) val_s *=2;
	return (int)(val_s); // 이거 0~100사이값(위의 함수(에서 나온 val -> 0~30 로 스케일링해주는 함수다)
}
 
// new selection part

int new_getter(){
	int i=0;
	memset(news,LINE_MAX,sizeof(char));
	srand(time(NULL)+rand());
	char* fd[3] = {"./keyword/DOGE.txt","./keyword/Elon Musk.txt","./keyword/Yellon and Powell(FED).txt" };
	// fd[2] -> 0~4 : 앨런 , 5~6 : 제롬
	char* key1[4] = {"풍산 DOGE", "일론머스크","앨런 재무장관","제롬 파월 FED 의장"};  
	int line_ofKeyword[4] = {14,5,6};
	char* pLine;
	char line[LINE_MAX];
	int key1_index = rand()%3;
	//int key1_index = 2; // for debug
	srand(time(NULL)+rand());
	int key2_index = rand()%line_ofKeyword[key1_index];
	//printf("key1 : %d, key2: %d\n",key1_index,key2_index);
	FILE* keyword_file = fopen(fd[key1_index],"r");
	while(!feof(keyword_file)){
		pLine = fgets(line,LINE_MAX,keyword_file);
		//printf("%s",pLine);
		if(i == key2_index) break;
		i++;
	}
	if(key1_index == 2){
		srand(time(NULL)+rand());
		key1_index = key1_index + rand()%2; // 앨런 과 제롬 결정
		//printf("key1_index : %d\n",key1_index);
	}
	int val = parse_newsfile(news,key1[key1_index],pLine);
	fclose(keyword_file);
	return val;
}
int parse_newsfile(char* news,char* key1,char* pLine){
	int i=2;
	int pos =0;
	char selection[LINE_MAX];
	//printf("%s(이)가  %s",key1,pLine);
	pos = str_copy(news,key1,pos);
	pos = str_copy(news,"(이)가 ",pos);
	char* ptr = strtok(pLine,"/");
	int val=0;
	while(ptr != NULL){
		//printf("%s\n",ptr);
		switch(i){
			case 2: // keyword2
				pos = str_copy(news,ptr,pos);
				pos = str_copy(news," ",pos);
				break;
			case 3: // keyword3 (반응)
				strcpy(selection,ptr);
				break;
			case 4:
				val = atoi(ptr);
				//printf("val : %d\n",val);
		}
		ptr = strtok(NULL,"/");
		i++;
	}
	// select keyword3
	srand(time(NULL)+rand());
	int sel = rand()%2;
	ptr = strtok(selection,",");
	if(sel==0){ // 첫번재(호재)
		pos = str_copy(news,ptr,pos);
	}else{ // 두번째 (악재)
		ptr = strtok(NULL,",");
		pos = str_copy(news,ptr,pos);
		val *= -1;
	}
	printf("DEBUG : news: %s in parse_newsfile\n",news);
	return val*10;
}
int str_copy(char* des, char* src,int pos){
	strcpy(news+pos,src);
	pos += strlen(src);
	return pos;
}
