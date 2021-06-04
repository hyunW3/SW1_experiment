#include "main.h"
#include "stdlib.h"
#include "string.h"
#define LINE_MAX 128

ANALYZED yong(INFOR infor){
	int g_cross,d_cross,day,i;
	int rf; //오늘 상승(1)인지 하락(0)인지
	int rise=50; //상승확률 50%
	int fall; // 하락확률
	int val = 0;
	//char t_amount; 거래량이고 low, normal, high 로 받을 예정
	ANALYZED output;
	
	day = infor.day;
	price[day] = infor.price;
	rf = infor.rf;
	
	//오늘 price와 day를 받아와야됨, 1일차는 day=1 이라고 가정할게
	if(day>2) three[1] = (price[day]+price[day-1]+price[day-2])/3; // day일째에 가격들의 평균선
	if(day>6) seven[1] = (price[day]+price[day-1]+price[day-2]+price[day-3]+price[day-4]+price[day-5]+price[day-6])/7;
	if(day>19){
		for(int i=0;i<20;i++){
			twenty[1] += price[day-i];
		}
		twenty[1] /= 20;
	}
	if(day>30 && day%4==3){ //뉴스 있음, 뉴스는 랜덤 30일 이후부터 + 4일에 한번 day31, 35, 39 ...
		val = new_getter();//int val = -40; 뉴스에 따른 값 받기, 테스트용
		int val_s = (abs(val))/10; //찐 계수형태
	
		if(val_s==1 || val_s==2){ //거래량 normal:high = 1:1 , low안나옴, 아 그리고 뉴스 없으면 low:normal = 1:1에 high없는걸로
			// 거래량 normal,high 50%확률로 
			if(half_half() ==0){//if(val_s==2){
				strcpy(output.t_amount,"high");
			}	else strcpy(output.t_amount,"normal");
			rise = rise + val;
		}
		else if(val_s==3 || val_s==4){ //거래량 high만 나와야됨
			strcpy(output.t_amount,"high");
			rise = rise + val;
		}
	}else{	//뉴스 없음
		memset(news,0,LINE_MAX*sizeof(char));
		if(half_half() ==0){ //low, normal 반반
			strcpy(output.t_amount,"low");
		}
		else strcpy(output.t_amount,"normal");		
	}
	//fall = 100-rise;
	g_cross =0;
	d_cross =0;
	while(day>20){	//cross 판단 이평선 돌파 관련
		if(three[0]<twenty[0] && three[1]>twenty[1]){
			g_cross = 20; //확률 +20이라는뜻
			break; //ex : 3이 7돌파, 3이 20돌파를 모두 만족하면 후자가 우선이므로, 확률이 10+20이되면 안돼서
		}
		if(three[0]>twenty[0] && three[1]<twenty[1]){
			d_cross = 20; //이건 하락 확률 +20퍼라는뜻
			break;
		}
		if(seven[0]<twenty[0] && seven[1]>twenty[1]){
			g_cross = 15;
			break;
		}
		if(seven[0]>twenty[0] && seven[1]<twenty[1]){
			d_cross = 15;
			break;
		}
		if(three[0]<seven[0] && three[1]>seven[1]){
			g_cross = 10;
			break;
		}
		if(three[0]>seven[0] && three[1]<seven[1]){
			d_cross = 10;
			break;
		}
		else break; //아무것도 충족 못함
	}
	if(g_cross) rise = rise + g_cross;
	if(d_cross) rise = rise - d_cross;
	if(rise>100) rise =100;
	if(rise<0) rise = 0;
	fall = 100-rise;
	
	
	if(rf){ //상승일시(추세) 
		if(strcmp(output.t_amount,"low")==0) rise *=1.05;
		if(strcmp(output.t_amount,"normal")==0) rise *=1.1;
		if(strcmp(output.t_amount,"high")==0) rise *=1.25;
		if(rise>100) rise =100;
		fall = 100-rise;
	}
	else{ //하락일시(추세)
		if(strcmp(output.t_amount,"low")==0) fall *=1.05;
		if(strcmp(output.t_amount,"normal")==0) fall *=1.1;
		if(strcmp(output.t_amount,"high")==0) fall *=1.25;
		if(fall>100) fall =100;
		rise = 100-fall;
	}
	output.day3 = three[1];
	output.day7 = seven[1];
	output.day20 = twenty[1];
	output.rise = rise;
	output.fall = fall;
	output.g_cross = g_cross;
	output.d_cross = d_cross;
	// 과거의 정보로 바꾼다. 
	three[0] = three[1]; // for cross test
	seven[0] = seven[1];
	twenty[0] = twenty[1];
	output.val_news = val;

	
	return output;
}


