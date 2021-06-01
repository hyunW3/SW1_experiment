#include "main.h"

void rank(){ 
	printf("==========rank.c session========\n");
	FILE  *result; 
	int i,j,temp;
	int num=0;
	char nick[10],temps[10];
	char r_nick[100][10];
	int r_money[100];
	result = fopen("ranking.txt", "a+");
	printf("닉네임을 영문으로 열자이내로 입력하세요 : ");
	scanf("%s", nick);
	fprintf(result, "100th %10s %dKRW\n", nick,user->current_money);
	//printf("%10s %d\n",nick,user->current_money);
	fclose(result);
	
	result = fopen("ranking.txt", "r+");
	int tmp;
	while(fscanf(result, "%dth %s %dKRW\n",&tmp,r_nick[num],&r_money[num])>0){
		printf("%dth : %s %d\n",num,r_nick[num],r_money[num]);
		num++;
	}
	fclose(result);
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
	result = fopen("ranking.txt", "w"); // 다 덮어씌우기
	
	for(i=0;i<num;i++){
		if(!strcmp(nick,r_nick[i]) == 1) printf("축하드립니다! %d등입니다!\n",i+1);
		//printf("%d등 %10s %d\n",i,r_nick[i],r_money[i]);
		fprintf(result, "%dth %10s %dKRW\n",i+1,r_nick[i], r_money[i]);
	}
	printf("현재 1등 : %s 으로, 백만원을 %d으로 불리셨습니다.\n",r_nick[0],r_money[0]);
	
	
	
	fclose(result);
}

/*int main(){
	return 0;
}*/