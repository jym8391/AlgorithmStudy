[Gold 4] 1197: 최소 스패닝 트리
====================================  
[문제 링크](https://www.acmicpc.net/problem/1197)  

### 알고리즘 분류 :  
최소 스패닝 트리

### 시간 제한 :  
1초   

### 문제 설명 :  
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.  
최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.  

### 입력 :   
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다.  
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.  
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.  
그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다.  
최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.  

### 출력 :   
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.  

-----------------------------------------------------------  
### 나의 해석 :  
크루스칼 알고리즘을 이용하여 해결  
Union-find를 이용해서 사이클이 발생하는지 확인한다. 

### 참고 문헌 :  
없음  

### 유사한 문제 :   
[BOJ 1922. 네트워크 연결](https://www.acmicpc.net/problem/1922)   
[BOJ 6497. 전력난](https://www.acmicpc.net/problem/6497)   
[BOJ 4386. 별자리 만들기](https://www.acmicpc.net/problem/4386)   
