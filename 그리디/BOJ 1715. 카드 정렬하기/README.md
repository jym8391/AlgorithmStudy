[Gold 4] 1715: 카드 정렬하기
====================================  
[문제 링크](https://www.acmicpc.net/problem/1715)  

### 알고리즘 분류 :  
그리디, 우선순위 큐  

### 시간 제한 :  
2초   

### 문제 설명 :  
정렬된 두 묶음의 숫자 카드가 있다고 하자. 각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는 A+B 번의 비교를 해야 한다. 
이를테면, 20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.  
매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 
예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면 (10 + 20) + (30 + 40) = 100번의 비교가 필요하다.  
그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면 (10 + 40) + (50 + 20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.
N개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.  

### 입력 :   
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100,000) 이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다.  
숫자 카드 묶음의 크기는 1,000보다 작거나 같은 양의 정수이다.  

### 출력 :   
첫째 줄에 최소 비교 횟수를 출력한다.  

-----------------------------------------------------------  
### 나의 해석 :  
그리디스럽게 접근한다면, 원소를 2개씩 더하는 횟수는 어떤 방법이든 같지만, 더하는 원소의 값이 작아질 수록 결과값이 작아지기에 유리하다.  
1. 우선순위 큐를 생성하여 안에 원소를 삽입한다.  
2. 가장 작은 원소 2개를 꺼내어 더한 뒤, 다시 큐에 삽입한다.
3. 이때 전체 비교횟수를 알기 위해 더한 값을 따로 Sum에 더해준다. 1,2,3을 반복해주면 된다.
  
결국에는 정렬 후 누적합을 구하는 문제와도 동일해진다.  

### 참고 문헌 :  
없음  
