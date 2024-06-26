[Gold 3] 7579: 앱
====================================  
[문제 링크](https://www.acmicpc.net/problem/7579)  

### 알고리즘 분류 :  
다이나믹 프로그래밍, 배낭 문제  

### 시간 제한 :  
1초   

### 문제 설명 :  
우리는 스마트폰을 사용하면서 여러 가지 앱(App)을 실행하게 된다. 대개의 경우 화면에 보이는 ‘실행 중’인 앱은 하나뿐이지만 보이지 않는 상태로 많은 앱이 '활성화'되어 있다. 
앱들이 활성화 되어 있다는 것은 화면에 보이지 않더라도 메인 메모리에 직전의 상태가 기록되어 있는 것을 말한다. 
현재 실행 중이 아니더라도 이렇게 메모리에 남겨두는 이유는 사용자가 이전에 실행하던 앱을 다시 불러올 때에 직전의 상태를 메인 메모리로부터 읽어 들여 실행 준비를 빠르게 마치기 위해서이다.

하지만 스마트폰의 메모리는 제한적이기 때문에 한번이라도 실행했던 모든 앱을 활성화된 채로 메인 메모리에 남겨두다 보면 메모리 부족 상태가 오기 쉽다. 
새로운 앱을 실행시키기 위해 필요한 메모리가 부족해지면 스마트폰의 운영체제는 활성화 되어 있는 앱들 중 몇 개를 선택하여 메모리로부터 삭제하는 수밖에 없다. 이러한 과정을 앱의 ‘비활성화’라고 한다.

메모리 부족 상황에서 활성화 되어 있는 앱들을 무작위로 필요한 메모리만큼 비활성화 하는 것은 좋은 방법이 아니다. 
비활성화된 앱들을 재실행할 경우 그만큼 시간이 더 필요하기 때문이다. 여러분은 이러한 앱의 비활성화 문제를 스마트하게 해결하기 위한 프로그램을 작성해야 한다

현재 N개의 앱, A<sub>1</sub>, ..., A<sub>N</sub>이 활성화 되어 있다고 가정하자. 
이들 앱 A<sub>i</sub>는 각각 m<sub>i</sub> 바이트만큼의 메모리를 사용하고 있다. 또한, 앱 A<sub>i</sub>를 비활성화한 후에 다시 실행하고자 할 경우, 추가적으로 들어가는 비용(시간 등)을 수치화 한 것을 c<sub>i</sub> 라고 하자. 
이러한 상황에서 사용자가 새로운 앱 B를 실행하고자 하여, 추가로 M 바이트의 메모리가 필요하다고 하자. 즉, 현재 활성화 되어 있는 앱 A<sub>1</sub>, ..., A<sub>N</sub> 중에서 몇 개를 비활성화 하여 M 바이트 이상의 
메모리를 추가로 확보해야 하는 것이다. 여러분은 그 중에서 비활성화 했을 경우의 비용 ci의 합을 최소화하여 필요한 메모리 M 바이트를 확보하는 방법을 찾아야 한다.  

### 입력 :   
입력은 3줄로 이루어져 있다. 첫 줄에는 정수 N과 M이 공백문자로 구분되어 주어지며, 둘째 줄과 셋째 줄에는 각각 N개의 정수가 공백문자로 구분되어 주어진다.  
둘째 줄의 N개의 정수는 현재 활성화 되어 있는 앱 A<sub>1</sub>, ..., A<sub>N</sub>이 사용 중인 메모리의 바이트 수인  m<sub>1</sub>, ..., m<sub>N</sub>을 의미하며,  
셋째 줄의 정수는 각 앱을 비활성화 했을 경우의 비용  c<sub>1</sub>, ..., c<sub>N</sub>을 의미한다  

단, 1 ≤ N ≤ 100, 1 ≤ M ≤ 10,000,000이며, 1 ≤ m<sub>1</sub>, ..., m<sub>N</sub> ≤ 10,000,000을 만족한다.  
또한, 0 ≤ c<sub>1</sub>, ..., c<sub>N</sub> ≤ 100이고, M ≤ m<sub>1</sub> + m<sub>2</sub> + ... + m<sub>N</sub>이다.  

### 출력 :   
필요한 메모리 M 바이트를 확보하기 위한 앱 비활성화의 최소의 비용을 계산하여 한 줄에 출력해야 한다.  

-----------------------------------------------------------  
### 나의 해석 :  
축을 설정함에 있어 새로운 관점으로 볼 수 있었던 문제이다.  
일반적인 배낭 문제에서 가치와 무게 중 무게를 축으로 하여 가치를 비교하며 dp 배열을 설정했었는데,  
이 문제도 마찬가지로 메모리를 축으로 하여 비용을 비교하고 싶었지만 최대 1000만이므로 메모리 초과가 발생하여, 비용을 축으로 삼아 진행하였다.  
Mem[i] : i번째 프로그램의 메모리  
C[i] : i번째 프로그램의 재활성 비용  
dp[k] : 비용이 k가 들때 최대 메모리  
Csum : 재활성 비용의 총합
로 정의하고 문제를 해결하였다.  

원래라면 dp배열을 1~N까지의 프로그램을 사용하여 코스트가 k일 때 메모리로 정의한다면  
dp[N][K] = max(dp[N-1][K], dp[N-1][K-C[i]+Mem[i])로 정의할 수 있다.  

하지만 i단계에서는 i-1단계의 정보만 필요하다는 사실을 알 수 있다면, 슬라이딩 윈도우 기법을 사용할 수 있다.    
j만큼 비용을 사용할 수 있을 때, dp[j]와 i번째 프로그램을 비활성화하여 얻는 메모리 Mem[i]를 비교하면 된다.  
이때 비용 j에서 C[i]만큼의 비용을 소모하기 때문에 dp[j]는 dp[j-c[i]] + Mem[i]를 비교하면 된다.   
for(int j=Csum;j>=C[i];j--) {  
    dp[j] = max(dp[j], dp[j-C[i]] + Mem[i]);  
}  

### 참고 문헌 :  
https://travelbeeee.tistory.com/359  
