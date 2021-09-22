# part 분배
func.c -> 용준이 
recommand.c -> 재원이

print_session.c : 어떤 상태를 출력해주는 함수들 / 메인 화면 등등
insert_data 	: prin session에 필요한 데이터를 저장해주는 함수
rand.c 			: rand 값 뽑아주는 함수 (가운데 index의 비중 높고, 가운데 값은 작음)
-> 현웅

함수 추가후 main.h 에 선언해주면 된다. 예시는 print_f, print_R

210526 회의
1. 타입 정하기(일치)
2. AI추천분석에 추천정도 / 정확도
main.c 에서 해야할것
- 액션 선택했을 때, 행동하기
- print_session / action에 따른
- func.c에서 랜덤함수 어떻게 쓸지 지정
func.c (용준)
- 뉴스 발생기 
- 뉴스 반영
- 거래량 결정(rand함수로) 
recommand.c

 키워드 파일들은 keyword폴더에 저장해두었슴다.

# 시소실 목요일 세부세션결과
인자를 통한 주식 등락결정 / 이전데이터를 이용한 추천기능
+ FILE IO를 통한 멀티 유저 플레이
- 다음날 오르고 내리는 폭기준 매수/매도가에 해당되면 체결되게 

# 추후 TODO
1. gnuplot을 통해서 그래프 그리기
2. setConsoleTextAttribute으로 콘솔 색 바꾸기 


