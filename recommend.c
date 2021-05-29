#include "main.h"
// print_session에서 필요한값
// 추천정도 / 정확도 / 추천이유(어떤값이 제일 가까운지?)
RECOMMENDED recommend(ANALYZED input, int difference, int idx_knn){ //differnece = 어제 오늘 가격 차이, idx_knn = day
	int rise_cnt;
	int data[5];
	RECOMMENDED output;
	
	if(strcmp(input.t_amount, "low")) data[4] = 0;
	if(strcmp(input.t_amount, "normal")) data[4] = 50;
	if(strcmp(input.t_amount, " high")) data[4] = 100;
	data[0] = input.rise;
	data[1] = input.fall;
	data[2] = input.g_cross * 5;
	data[3] = input.d_cross * 5;//디멘션 5개
	char dimension[5][10] = {"rise", "fall", "g_cross", "d_cross", "t_amount"};
	
	if(idx_knn > DAY_PASSED){
		int** dist = (int**)malloc(sizeof(int*) * (idx_knn - 1)); // dist[n][6] -> 0~4 각 dimension별로 거리, 5 전체 두 벡터 사이의 거리
		int label[5];
		output.rise_cnt = 0; // 리턴값, nearest 5개중 상승 label 개수 저장변수
		
		for(int i = 0; i < idx_knn - 1; i++){
			dist[i] = (int*)calloc(6, sizeof(int));
			for(int j = 0; j < 5; j++){
				dist[i][j] = (knn[i][j] - data[j]) * (knn[i][j] - data[j]);
				dist[i][5] += (knn[i][j] - data[j]) * (knn[i][j] - data[j]);
			}
		}// 인풋 벡터와의 거리측정
		
		for(int i = 0; i < 5; i++){ //가장 가까운 5개고르기->거리 내림차순 정렬, 5개까지만
			int rise_fall = 0;
			
			for(int j = i + 1; j < idx_knn - 1; j++){
				if(dist[i][5] > dist[j][5]){
					int* temp;
					temp = dist[j];
					dist[j] = dist[i];
					dist[i] = temp;
					label[i] = knn[j][5];
				}
			}
			
			if(label[i] == 1) output.rise_cnt++;
		}
		output.fall_cnt = 5 - output.rise_cnt;
		
		if(output.rise_cnt >= 3){
			int idx_most_impact = 0;
			int idx_dimension;
			for(int i = 0; i < 5; i++){
				if(label[i] == 1) continue;
				int max = 100000000;
				for(int j = 0; j < 5; j++)
					if(max > dist[i][j]){
						max = dist[i][j];
						idx_dimension = j;
					}
				strcpy(output.most_impact[idx_most_impact++], dimension[idx_dimension]);
			}
		}
		else{
			int idx_most_impact = 0;
			int idx_dimension;
			for(int i = 0; i < 5; i++){
				if(label[i] == 1) continue;
				int max = 100000000;
				for(int j = 0; j < 5; j++)
					if(max > dist[i][j]){
						max = dist[i][j];
						idx_dimension = j;
					}
				strcpy(output.most_impact[idx_most_impact++], dimension[idx_dimension]);
			}
		}
		free(dist);
	}
	
	knn = (int**)realloc(knn, sizeof(int*) * idx_knn);
	knn[idx_knn - 1] = (int*)malloc(sizeof(int) * 6);
	
	for(int i = 0; i < 5; i++)
		knn[idx_knn - 1][i] = data[i];
	if(difference > 0) knn[idx_knn - 1][5] = 1;
	else knn[idx_knn - 1][5] = 0;
	return output; // 리턴해주는거 가까운 5개 노드중에 rise레이블 갯수, fall 레이블 갯수, 그리고 결정에 지배적인 영향을 준 원인->dimension
}

double accuracy(int prediction, int difference, int total){
	if((difference > 0) && (prediction > 2)) correct++;
	else if((difference <= 0) && (prediction <= 2)) correct++;
	return (double)correct / (total - DAY_PASSED) * 100;
}