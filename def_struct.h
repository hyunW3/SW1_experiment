
typedef struct infor{
	int rf; //상승1 or 하락0
	int price; //오늘 가격
	int day;
}INFOR;

typedef struct analyzed{
	int day3;
	int day7;
	int day20;
	int rise;
	int fall;
	int g_cross;
	int d_cross;
	char t_amount[7];
	char* news; // news string
}ANALYZED;


typedef struct user{
	int current_money;
	int num_coin; // 코인 구매 개수
	double coin_amount; // 코인 총 구매량(코인단가 x 개수)
	double benefit_percent;
	int benefit;
}user_info;

typedef struct current_trade{
	int current_trade_price[numOf_trade_save];			
	// ex){405,400,395,390};
	int current_trade_amount_left[numOf_trade_save]; 	
	// ex) {300,0,0,0};
	int current_trade_amount_right[numOf_trade_save];	
	// ex) {0,400,500,600};
}trade;

typedef struct recommended{
	int rise_cnt; // 가장 가까운 5개점 중 rise 갯수
	int fall_cnt; //   "                fall 갯수
	char most_impact[5][10];
}RECOMMENDED;