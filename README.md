	Problem
	1. 게임 끝난 후 랭킹 FILE IO 
		- File write 문제
		- 같은 닉네임시 문제
11th        JOT 499696KRW
12th 1000000KRWJOT 0KRW
13th        JOT 0KRW	
	해야 할것

# part 분배
func.c -> 용준이 
recommand.c -> 재원이

print_session.c : 어떤 상태를 출력해주는 함수들 / 메인 화면 등등
insert_data 	: prin session에 필요한 데이터를 저장해주는 함수
rand.c 			: rand 값 뽑아주는 함수 (가운데 index의 비중 높고, 가운데 값은 작음)
-> 현웅

함수 추가후 main.h 에 선언해주면 된다. 예시는 print_f, print_R



//210525 
coin,trade 구조체-> coin,user 구조체로 수정해야함

//210526
자기가 필요한 데이터들 구조체 만들어서 했는데 insert_data에 있는것들이랑 겹치는게 있는거같음
데이터들 정리한번 할 필요가 있을듯
메인에서 사용하는 변수는 당일날 데이터만 쓰는걸로 통일하고 본인이 변수 전날거 저장해야한다는가 하면 받아서 본인함수에다가 저장하는걸로 하는게 어떰
그래도 힘들면 나중 -에 변수관련 얘기를 하면되고
변수 근데 그렇게 저장하려면 동적할당으로 해야되는데 ㄱㅊ? , 아니 전역변수로 선언하겠다는건가? 그렇게하면 같이 써도 되는거고
나는 배열 하나 전역변수로 선언하고 내 함수에서 동적할당으로 메모리 조절해가면서 씀<< 내배열은 나만쓰는거라
-> ㅇㅋㅇㅋ 
그래도 코인정보는 다같이 쓰지 안남..? 
나(현웅)경우는 coin 평균단가, user 수익, 수익률, 코인 매수 개수 -> main 함수에서 print_session 하려면 필요해서
나(재원)경우는 상관없긴함 어차피나는 코인정보 당일날것만 필요해서 전체를 관통하는 코인정보는 최대한 모두에게 편한 타입으로 ㄱㄱ
위에 나열한 평균단가 ~~ 수익률 등등 다 누적정보가 필요한거임?? 그러면 배열 ㄱㄱ 근데 이건 용준이랑도 애기를 해봐야함 기본적으로 저 구조체를 용준이가 만들어서 걔가 저걸로 코딩했을테니
ㅇㅎㅇㅎ 고렇고만 하나의 변수를 main에서 필요하긴해 누적은 아니어도? 

-> 난 오늘 3일선/7일선/.../ 등등 분석한 정보를 가지고 내일 등락을 맞추는거라서 당일것만 씀 
물론 학습용으로 위의 정보를 계속 쌓아두기 위한 배열이 필요한데 그건 아까말했듯이 내가 전역변수로 따로만들어서 내 함수에서 씀 main.h //recommend int** knn <- 트레이닝용 ㅇㅋㅇㅋ(현웅)

우선 내가 맞춰서 쓸게 그리고 정 필요하면 info struct에 추가하도록하겠슴다

// 우선 coin_info 삭제할것같은데 확인해보고 지울게요

//호가 프린트하는거 주식처럼 해놨습니다 일단(원래대로 4개만) + func.c 에서 구하는 확률은 다 된듯! - 5/27 22:09

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

// 용준이가 작성한 키워드 파일들은 keyword폴더에 저장해두었슴다.

//시소실 목요일 세부세션결과
인자를 통한 주식 등락결정 / 이전데이터를 이용한 추천기능
+ FILE IO를 통한 멀티 유저 플레이
- 다음날 오르고 내리는 폭기준 매수/매도가에 해당되면 체결되게 

// 210531_23

		//int future_price = price_next_day(int ) // 이거 그냥 line42에서 해결하자
		// 42에서 그럼 오늘가격 사라지는거고 바로내일가격으로 갱신되는거지
		// ㅇㅇ 현재는 그럼 action할때 현재가격 살려둘려구
		// 그럼 risefall이랑 infor.price로 다음날 가격 계산하면 될듯?
		//infor.price = price*(1+risefall*0.01); 이런식으로
		// select(infor.price,risefall) 이렇게 받으면 되지않을까
		// select가 apply_infor보다 아래에 있고, apply_infor에서 내일가격으로 최신화하면 오늘가격 다시 복구되? 아아 맞다 맞다 잠시 플로우를 착각함 -> ㅇㅋㅇㅋ
		// infor가 우선 포인터가 아니라 함수마다 각기 다른놈이야(함수 들어갈때 값복사)
		// select에서 업데이트한다고 메인문에서 바꾸지 않음 ->
		// 음 오늘가격 복구라는건 어떤의미야? action들어갈때,(스위치문)
		// infor.price : 현재가격
		// price*(1+risefall*0.01) : 다음날 가격 이렇게 유추가능할거같은데


추후 TODO
// gnuplot을 통해서 그래프 그리기
// setConsoleTextAttribute으로 콘솔 색 바꾸기 


```
┌───────────────────────────────────────────────┐
                                       _       
     __ _  ___   ___  _ __ _ __ ___   (_) ___  
    / _` |/ _ \ / _ \| '__| '_ ` _ \  | |/ _ \ 
   | (_| | (_) | (_) | |  | | | | | |_| | (_) |
    \__, |\___/ \___/|_|  |_| |_| |_(_)_|\___/ 
    |___/                                      
			     🌩 𝘼𝙣𝙮𝙤𝙣𝙚 𝙘𝙖𝙣 𝙙𝙚𝙫𝙚𝙡𝙤𝙥!
└───────────────────────────────────────────────┘
```

# goormIDE
Welcome to goormIDE!

goormIDE is a powerful cloud IDE service to maximize productivity for developers and teams.  
**DEVELOP WITH EXCELLENCE**  

`Happy coding! The goormIDE team`


## 🔧 Tip & Guide

* Command feature
	* You can simply run your script using the shortcut icons on the top right.
	* Check out `PROJECT > Common/Build/Run/Test/Find Command` in the top menu.
	
* Get URL and Port
	* Click `PROJECT > URL/PORT` in top menu bar.
	* You can get default URL/Port and add URL/Port in the top menu.

* Useful shortcut
	
| Shortcuts name     | Command (Mac) | Command (Window) |
| ------------------ | :-----------: | :--------------: |
| Copy in Terminal   | ⌘ + C         | Ctrl + Shift + C |
| Paste in Terminal  | ⌘ + V         | Ctrl + Shift + V |
| Search File        | ⌥ + ⇧ + F     | Alt + Shift + F  |
| Terminal Toggle    | ⌥ + ⇧ + B     | Alt + Shift + B  |
| New Terminal       | ⌥ + ⇧ + T     | Alt + Shift + T  |
| Code Formatting    | ⌥ + ⇧ + P     | Alt + Shift + P  |
| Show All Shortcuts | ⌘ + H         | Ctrl + H         |

## 💬 Support & Documentation

Visit [https://ide.goorm.io](https://ide.goorm.io) to support and learn more about using goormIDE.  
To watch some usage guides, visit [https://help.goorm.io/en/goormide](https://help.goorm.io/en/goormide)
# SW1_experiment
# SW1_experiment
