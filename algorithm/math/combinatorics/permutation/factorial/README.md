# 팩토리얼(factorial)
## 정의
$$
n! = n \times (n-1) \times (n-2) \times (n-3) \times \cdots \times 2 \times 1
$$

## 구현
$$
f(n)=

\begin{cases}
 & \text{ n x f(n-1)} \cdots n \geq 1 \\
 & \text{ 1 } \cdots n = 0 
\end{cases} 
$$

+ 재귀함수
  + 각 함수 호출마다 스택 프레임이 추가되므로 오버헤드가 있다. 재귀 호출이 깊어질 경우 스택 오버플로우가 발생할 수 있다.
+ 반복문
  + 코드가 조금 더 복잡해질 수 있지만 스택 오버헤드가 없고 메모리 사용이 효율적이다.