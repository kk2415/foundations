# 선택 정렬 알고리즘
선택 정렬 알고리즘은 우선순위가 제일 큰 요소를 선택해서 첫 번째 위치에 옮기고 그 다음에 두 번째로 우선순위가 큰 요소를 집어서(선택해서) 두 번째 위치에 옮기는 작업을 배열 길이 만큼 반복하는 알고리즘이다.

실제 정렬 작업은 두 데이터간의 교환으로 진행되지만 이것은 데이터를 선택해서 옮길 때 마다 비게되는 공간을 활용하는 것이란 걸 이해해야한다.

비교연산 횟수를 기준으로 선택 정렬 알고리즘의 시간 복잡도는 다음과 같다.

$$
\begin{align*}
	& T\left (n  \right ) = \frac{n^2-n}{2} \\
	& O\left ( n^2 \right )
\end{align*}
$$