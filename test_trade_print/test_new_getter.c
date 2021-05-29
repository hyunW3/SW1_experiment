#include "main.h"
char* news;
// parsing하는거지 -> ㅇㅇ
int main(){
	news = calloc(LINE_MAX,sizeof(char));

	printf("val : %d\n",LINE_MAX);
	
	free(news);
	return 0;
}