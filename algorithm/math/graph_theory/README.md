# 그래프 이론(Graph Theory)

# 그래프의 역사
그래프 이론은 저명한 수학자 레온하르트 오일러(Leonhard Euler)에 의해 고안되었습니다. 오일러는 '쾨니히스베르크의 다리 문제'를 해결하기 위해 처음으로 그래프 이론을 사용했다고 합니다. 쾨니히스베르크의 다리 문제는 다음과 같습니다.

![쾨니히스베르크의 다리](https://github.com/kk2415/foundations/assets/79124915/dc6ed44f-080d-42e9-b13f-c73fa4ef6479)


당시 쾨니히스베르크에는 7개의 다리가 있었습니다. 모든 다리를 한 번씩만 건너서 처음 출발했던 장소로 되돌아 오는 게 가능한지에 대한 문제가 '쾨니히스베르크의 다리 문제' 입니다. 오일러는 이 문제를 해결하면서 그래프의 개념을 도입했습니다.



위 문제의 답은 불가능하다입니다. 각 정점에서 들어오는 간선과 나가는 간선의 수가 동일해야 , 즉 모든 정점의 차수가 짝수여야 처음 출발했던 정점으로 되돌아 올 수 있습니다.





# 그래프
## 그래프

![graph1](https://github.com/kk2415/foundations/assets/79124915/2e6f89b4-bc16-4d8f-9839-4b9a0b99ccf3)

그래프(Graph)는 정점(vertex)의 집합과 간선(모서리, 영어: edge)집합으로 구성됩니다. 정점(vertex)은 위 사진에서 숫자 6, 4, 3에 해당하는 것처럼 연결의 대상이 되는 개체 또는 위치를 의미하고, 간선(edge)은 이들 정점 사이를 연결하는 선입니다. 그래프를 \(G=(V, E) \)로 표시합니다. 정점과 간선의 개수는 각각 \(V\), \(E\)로 표시합니다.

위 그래프를 집합으로 표현하면 다음과 같습니다.

$$
\begin{align*}
& V = \begin{Bmatrix}6, 4, 5, 1, 2, 3\end{Bmatrix} \\
& E = \begin{Bmatrix}
\begin{Bmatrix}6, 4 \end{Bmatrix}, 
\begin{Bmatrix}4, 5 \end{Bmatrix}, 
\begin{Bmatrix}5, 1 \end{Bmatrix}, 
\begin{Bmatrix}1, 2 \end{Bmatrix}, 
\begin{Bmatrix}2, 5 \end{Bmatrix}, 
\begin{Bmatrix}3, 2 \end{Bmatrix}, 
\begin{Bmatrix}3, 4 \end{Bmatrix}
\end{Bmatrix}
\end{align*}
$$

그래프의 예) 소셜 네트워크, 지하철 노선도

<br/>
<br/>

## 무방향 그래프(Undirected graph)의 종류
### 단순 그래프(Simple graph)

![graph1](https://github.com/kk2415/foundations/assets/79124915/2e6f89b4-bc16-4d8f-9839-4b9a0b99ccf3)


정점과 정점이 하나의 간선으로 연결되어 있거나 연결되어 있지 않은 그래프를 단순 그래프라고 합니다.



### 멀티그래프(Multigraph)
![multigraph](https://github.com/kk2415/foundations/assets/79124915/9bc14ed1-5aef-4571-a2ff-164f8d29ea5d)

두 정점 사이에 여러 개의 간선이 존재할 수 있는 그래프입니다. 특히 위 그래프에서 자기 자신과 자기 자신을 연결하는 간선을 loop 간선이라고 부릅니다. 단순 그래프는 loop 간선이 없습니다.




## 방향 그래프(Directed graph)의 종류
### 방향 그래프(Directed graph)

![directed_graph](https://github.com/kk2415/foundations/assets/79124915/04bd8e1a-3337-4c86-90e0-cd3c7e72956d)

간선에 방향정보가 포함된 그래프를 가리켜 방향 그래프라고 합니다. 방향 그래프에서 정점 2과 정점 3를 연결하는 간선을 (3, 2)로 표시합니다. 간선 (3, 2)는 정점 3에서 2로의 방향성을 가집니다. (3, 2)을 3으로부터 2로의 방향 간선(arc 또는 directd edge)라고 부릅니다. (소괄호는 보통 순서쌍을 표현한다는 의미)

정점 3은 (3, 2)의 시작점(initial vertext)라고 한다.
정점 2는 (3, 2)의 끝점(terminal vertex)라고 한다.


### 방향 멀티그래프(Directed multigraph)

![directed_multigraph](https://github.com/kk2415/foundations/assets/79124915/5ef00896-a963-4cd5-a624-f946d8f10db9)

두 정점 사이에 여러 개의 방향 간선이 존재할 수 있는 그래프입니다. b 정점에서 a 정점으로 향하는 간선이 총 2개가 있습니다. 이처럼 한 정점에서 다른 정점으로의 복수 연결을 허용하는 그래프를 방향 멀티그래프라고 합니다.





인접(adjacent), 이웃(neighbor)
두 정점 \(u\)와 \(v\)가 간선(모서리)로 연결되어 있으면 \(u\)와 \(v\)는 인접(adjacent) 또는 이웃(neighbors)한다고 합니다. 기호로는 다음과 같이 표현합니다.



$$
u \sim v
$$



또한, 정점 \(v\)의 모든 이웃들의 집합을 \(N(v)\)라 표시하고. \(v\)의 이웃(neighbors)이라고 부릅니다.





## 차수(Degree)
![loop_graph](https://github.com/kk2415/foundations/assets/79124915/1ccd18cb-9d6c-41be-8860-a3699b55e6c5)

정점 \(v\)의 차수는 정점 \(v\)에 붙어있는 간선들의 개수입니다. \(deg(v)\) 또는 \(d(v)\)로 표시합니다. 루프 간선은 정점 차수에 2번 가산합니다. 예를 들어 아래 그래프에서 \(deg(2) = 3\)이고 \(deg(1) = 4\) 입니다.


![directed_graph](https://github.com/kk2415/foundations/assets/79124915/04bd8e1a-3337-4c86-90e0-cd3c7e72956d)


정점 \(v\)의 출력차수(out-degree) \(deg^+(v)\): 정점 \(v\)에서 나가는 간선의 수
정점 \(v\)의 입력차수(in-degree) \(deg^-(v)\): 정점 \(v\)으로 들어오는 간선의 수
$$
\begin{align*}
deg^+(3)=2 \\
deg^-(3)=2
\end{align*}
$$


## 악수 정리(Handshaking lemma)
정리1:
𝐺=(𝑉,𝐸)가 𝑚개의 간선을 갖는 그래프이면, 모든 노드의 degree의 합은 2𝑚 이다.


어떤 그래프 \(G=(V, E)\)가 \(m\)개의 간선을 갖는다고 할 때,

$$
\sum_{v\in V}^{} deg(v) = 2m
$$

임이 성립합니다.

모든 정점의 차수(degree)를 전부 더한 값과 간선의 개수(\(\left|E \right|\))에 2를 곱한 값은 같습니다.

![directed_multigraph](https://github.com/kk2415/foundations/assets/79124915/5ef00896-a963-4cd5-a624-f946d8f10db9)


위 그래프에서 간선의 수는 \(m=8\). 그리고 각 정점의 차수는 다음과 같습니다.

$$
\begin{align*}
deg(a) = 4 \\
deg(b) = 7 \\
deg(c) = 3 \\
deg(d) = 2
\end{align*}
$$

따라서 다음과 같습니다.

$$
\begin{align*}
& \sum_{v\in V}^{} deg(v) = 2m \\
& = 4 + 7 + 3 + 2 = 2 \cdot 8 = 16
\end{align*}
$$



특히 위 식을 통해서 알 수 있는 건 모든 차수(degree)의 합이 짝수라는 사실입니다. 모든 수에 2를 곱하면 짝수가 되는데 우변에서 \(m\)에다가 2를 곱하여 \(2m\)이 되니 결국 좌변도 짝수가 됩니다.



정리2:
𝐺=(𝑉,𝐸)에서 홀수 차수를 가지는 정점들은 짝수개 있다.


위 정리는 귀류볍을 사용하여 간단하게 증명할 수 있습니다. 홀수 차수를 가지는 정점이 홀수개 있다고 가정하고 모순을 찾으면 됩니다. 우선 모든 차수의 합이 짝수라는 아래 식을 염두해두고 모순을 찾아야합니다.



$$
\sum_{v\in V}^{} deg(v) = 2m = 짝수
$$



위 식에 의해서 모든 차수의 합은 짝수입니다. 홀수 차수를 가지는 정점이 홀수개 있다는 가정에서 위 식과 모순된 점을 찾아야합니다.



$$
\sum_{v\in V}^{} deg(v) = \sum_{v: 홀수 차수}^{} deg(v) + \sum_{v: 짝수 차수}^{} deg(v)
$$

시그마의 성질에 의해 각각 홀수 차수와 짝수 차수로 시그마를 분리했습니다. 일단 짝수 차수를 가지는 정점이 홀수개이든 짝수개든 상관이 없습니다. 짝수는 홀수번 더하든 짝수번 더하든 언제나 짝수입니다. 하지만 홀수 차수는 다릅니다. 홀수 차수를 가지는 정점이 홀수개 있다면 그 총합은 홀수가 됩니다. 그리고 홀수와 짝수를 더하면 홀수가 되므로 정리1을 만족하지 못합니다. 즉 위에서 세운 가정은 모순되므로 정리2가 증명되었습니다.





## 방향 그래프의 성질
$$
\sum_{v\in V}^{} deg^-(v) = \sum_{v\in V}^{} deg^+(v) = \left|A \right|
$$



방향 그래프  \(D=(V, A)\)에서 모든 정점의 출력차수(out-degree)의 합과 입력차수(in-degree) 합 그리고 간선의 수는 서로 같습니다. 참가로 \(D\)의 의미는 Directed의 앞글자입니다. \(A\)는 Arc의 앞글자 입니다. 방향 간선은 arc라고도 부릅니다.



