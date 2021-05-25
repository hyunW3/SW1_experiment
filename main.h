#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
// for main game
#define day_passed 30 // 30일이후 게임시작

//선언부
int print_f();

//from recommand
int recommend(double** knn, double* input, int input_size, int idx_knn, double output);
//for func

//for code
#define numberOf_trade_save 4
typedef struct current_trade{
	int current_trade_price[4];			// ex){405,400,395,390};
	int current_trade_amount_left[4]; // ex) {300,0,0,0};
	int current_trade_amount_right[4];	// ex) {0,400,500,600};
}current_trade;
current_trade* ct;
int pick_random_weighted(int mid, int range, int weight);
#define rand_range 100
#define rand_center 50