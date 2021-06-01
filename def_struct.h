
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
	int val_news;
}ANALYZED;


typedef struct user{
	int current_money;
	int num_coin; // 코인 구매 개수 -> 들고 있는 코인 total 수량을 말하는거지? 매도하면 매도한만큼 없어지고-> 마즘
	double coin_average; // 코인 평균 매수가
	double coin_amount; // 코인 총 구매량(코인단가 x 개수)
	double benefit_percent; // 수익률은 매수 혹은 매도했을 때 (시장가 - 평균매수가) / 평균매수가 백분율로 정의 
	int benefit; // 수익금은 매도했을 때 벌어들인 차익으로 정의
}user_info;


typedef struct recommended{
	int rise_cnt; // 가장 가까운 5개점 중 rise 갯수
	int fall_cnt; //   "                fall 갯수
	char most_impact[5][10];
}RECOMMENDED;