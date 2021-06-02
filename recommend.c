#include "main.h"
// print_session에서 필요한값
// 추천정도 / 정확도 / 추천이유(어떤값이 제일 가까운지?)
RECOMMENDED recommend(ANALYZED input, INFOR infor, int risefall, int idx_knn){ // idx_knn = day
	int rise_cnt;
	int data[4];
	RECOMMENDED output;
	
	if(strcmp(input.t_amount, "low")) data[3] = 0;
	if(strcmp(input.t_amount, "normal")) data[3] = 50;
	if(strcmp(input.t_amount, " high")) data[3] = 100;
	data[0] = risefall * 3;
	data[1] = input.g_cross * 5;
	data[2] = input.d_cross * 5;//디멘션 5개
	char dimension[4][10] = {"rise/fall", "g_cross", "d_cross", "t_amount"};
	
	if(idx_knn > 30){
		int** dist = (int**)malloc(sizeof(int*) * (idx_knn - 1)); // dist[n][5] -> 0~3 각 dimension별로 거리, 4 전체 두 벡터 사이의 거리
		int label[5];
		output.rise_cnt = 0; // 리턴값, nearest 5개중 상승 label 개수 저장변수
		
		for(int i = 0; i < idx_knn - 1; i++){
			dist[i] = (int*)calloc(5, sizeof(int));
			for(int j = 0; j < 4; j++){
				dist[i][j] = (knn[i][j] - data[j]) * (knn[i][j] - data[j]);
				dist[i][4] += (knn[i][j] - data[j]) * (knn[i][j] - data[j]);
			}
		}// 인풋 벡터와의 거리측정
		
		for(int i = 0; i < 5; i++){ //가장 가까운 5개고르기->거리 내림차순 정렬, 5개까지만
			int rise_fall = 0;
			
			for(int j = i + 1; j < idx_knn - 1; j++){
				if(dist[i][4] > dist[j][4]){
					int* temp;
					temp = dist[j];
					dist[j] = dist[i];
					dist[i] = temp;
					label[i] = knn[j][4];
				}
			}
			
			if(label[i] == 1) output.rise_cnt++;
		}
		output.fall_cnt = 5 - output.rise_cnt;
		
		if(output.rise_cnt >= 3){
			int idx_most_impact = 0;
			int idx_dimension;
			for(int i = 0; i < 5; i++){
				if(label[i] == 0) continue;
				int max = 100000000;
				for(int j = 0; j < 4; j++)
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
				for(int j = 0; j < 4; j++)
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
	knn[idx_knn - 1] = (int*)malloc(sizeof(int) * 5);
	
	for(int i = 0; i < 4; i++)
		knn[idx_knn - 1][i] = data[i];
	if(risefall >= 0) knn[idx_knn - 1][4] = 1;
	else knn[idx_knn - 1][4] = 0;
	return output; // 리턴해주는거 가까운 4개 노드중에 rise레이블 갯수, fall 레이블 갯수, 그리고 결정에 지배적인 영향을 준 원인->dimension
}

double accuracy(int prediction, int risefall, int total){
	if((risefall >= 0) && (prediction > 2)) correct++;
	else if((risefall < 0) && (prediction < 2)) correct++;
	return (double)correct / total * 100;
}