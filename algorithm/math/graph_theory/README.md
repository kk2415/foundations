# 그래프 이론(Graph Theory)
> 자세한 내용은 https://hump-mountain.tistory.com/31 링크 참조

<br />
<br />

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

<br />

## 그래프 구현
그래프를 구현하는 방법은 배열을 이용하는 방법과 리스트를 이용하는 방법으로 나뉜다.
+ 인접 행렬(adjacent matrix) 기반 그래프: 정방 행렬을 활용
+ 인접 리스트(adjacent list) 기반 그래프: 연결 리스트를 활용