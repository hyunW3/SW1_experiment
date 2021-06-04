#include "main.h"
void init_val(char** r_nick, int* r_money);
void free_val(char** r_nick, int* r_money);
void rank(){ 
	//printf("DEBUG :  rank.c session \n");
	FILE  *result; 
	int i,j,temp;
	int num=0;
	char nick[10],temps[10];
	char r_nick[100][10];
	int r_money[100];
	
	//printf("DEBUG :read txt...\n");
	result = fopen("ranking.txt", "r+");
	//printf("DEBUG :open txt...\n");
	int tmp;
	while(fscanf(result, "%dth %s %dKRW\n",&tmp,r_nick[num],&r_money[num])>0){
		printf("%dth : %s %d\n",num+1,r_nick[num],r_money[num]);
		num++;
	}
	fclose(result);
NICK_RECV:	
	printf("닉네임을 영문으로 열자이내로 입력하세요 : ");
	scanf("%s", nick);
	for(int i=0; i<num; i++){
		if(!strcmp(nick,r_nick[i]) == 1) {
			printf("********중복되는 닉네임이 있습니다 다시 입력하세요********\n");
			memset(nick,0,sizeof(char)*10);
			goto NICK_RECV;
		}
		
	}
	if(strlen(nick)==0) strcpy(nick,"UNKNOWN");
	else strcpy(r_nick[num],nick);
	r_money[num] = user->current_money;
	num++;
	for (i = 0; i < num; i++) {
	for (j = 0; j < (num - 1) - i; j++) {
		if (r_money[j] < r_money[j + 1]) {	// 버블 정렬 사용
			temp = r_money[j];
			r_money[j] = r_money[j + 1];
			r_money[j + 1] = temp;
			strcpy(temps, r_nick[j]);
			strcpy(r_nick[j],r_nick[j+1]);
			strcpy(r_nick[j+1], temps);
			}
	}
	}
	result = fopen("ranking.txt", "w+"); // 다 덮어씌우기
	for(i=0;i<num;i++){ // 해당에서 문제
		if(!strcmp(nick,r_nick[i]) == 1) printf("축하드립니다! %d등입니다!\n",i+1); // 중복 닉네임시 문제
		//printf("%d등 %10s %d\n",i,r_nick[i],r_money[i]);
		//fprintf(result, "%dth %10s %dKRW\n",i+1,r_nick[i], r_money[i]);
		printf("%dth %10s %dKRW\n",i+1,r_nick[i], r_money[i]);
		if(fprintf(result, "%dth %10s %dKRW\n",i+1,r_nick[i], r_money[i])<0) printf("fprintf fail\n");
	}
	printf("현재 1등 : %s 으로, 백만원을 %d으로 불리셨습니다.\n",r_nick[0],r_money[0]);
	
	
	fclose(result);
}

// 동적할당 안해서 의미없는 함수
void init_val(char** r_nick, int* r_money){
	//char r_nick[100][10];
	r_nick = calloc(100,sizeof(char*));
	for(int i=0; i<100; i++){
		r_nick[i]= calloc(10,sizeof(char));
	}
	//int r_money[100];
	r_money = calloc(100,sizeof(int));
}
void free_val(char** r_nick, int* r_money){
	for(int i=0; i<100; i++){
		free(r_nick[i]);
	}
	free(r_nick);
	//int r_money[100];
	free(r_money);
	
}