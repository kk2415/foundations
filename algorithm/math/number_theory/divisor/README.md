# 약수
정수론에서 약수(約數, 영어: divisor) 또는 인수(因數, 영어: factor)는 어떤 수를 나누어 떨어지게 하는 수를 말한다. 두 정수 a와 b가 있을 때 a가 b의 약수라면 a는 b를 나눌 수 있다. $(a | b)$

$a, b\in \mathbb{Z}$이고 $(a \neq 0)$일 때, a가 b의 약수$(a\;|\;b)$라는 말은 $b=ak,\;\;$$_{}^{\exists }\textrm{k} \in \mathbb{Z}$라는 말과 동치이다.

## 약수의 성질
+ 약수는 항상 쌍으로 존재. $\Rightarrow a\;|\;b,\;\;b=ak,\;\;$$_{}^{\exists }\textrm{k} \in \mathbb{Z}$
+ $a\;|\;b$이면, b는 a의 배수. 예를 들어, $4\;|\;16$이면 16은 4의 배수
+ 0의 약수는 모든 정수이다. $\Rightarrow n\;|\;0$

## 약수 구하기
자연수 $N$의 약수를 구하자.

먼저 $i=1,2,3,4\cdots\left \lfloor \sqrt N \right \rfloor$일 때, $N$을 $i$로 나눈다. 만약 $N\;mod\;i = 0$ 이라면 $i$는 $N$의 약수.
$$i\;|\;N$$
$i$가 약수라면 $N/i$도 약수다. 
$$\frac{N}{i}\;|\;N$$
그 이유는 $N$의 약수들은 항상 쌍으로 존재하기 때문이다. 예를 들어 $12$가 $3$로 나누어 떨어지면 $3$도 $12$의 약수이고, $12/3$도 $N$의 약수이다. 이 두 약수는 곱해서 $12$이 된다.
$$
i\times \frac{N}{i} = N
$$

범위가 $\left \lfloor \sqrt N \right \rfloor$까지인 이유는 약수의 쌍 중 한 숫자는 항상 $\sqrt N$ 이하이고, 다른 숫자는 $\sqrt N$ 이상이기 때문이다. $i\leq\sqrt N$이면 $\frac{N}{i}\geq\sqrt N$이다.  
예를 들어서 $N=16$이고 $i=2$이면 $2\leq\sqrt 16$, $\frac{16}{2}\geq\sqrt 16$이다.

이를 통해서 $\sqrt N$까지만 약수를 검사해도 되는 이유를 이해할 수 있다. 만약 $\sqrt N$을 넘는 약수가 있다면, 그 약수의 쌍은 반드시 $\sqrt N$ 이하의 값이 된다. 따라서 $\sqrt N$까지만 검사해도 모든 약수를 찾을 수 있다.

## 유클리드 호제법(Euclidean Algorithm)
유클리드 호제법은 두 정수의 최대공약수(Greatest common divisor: GCD)를 구하는 알고리즘입니다. 가장 오래된 알고리즘으로 알려져있다.  

두 정수 $a$와 $b$가 주어졌고 $a$는 $b$보다 크거나 같다고 해보겠습니다. $\left(a, b\in \mathbb{Z}이고\;\;a \geq b\right)$  
$a$와 $b$의 최대공약수를 $gcd(a, b)$라고 표현하겠습니다.
$a$를 $b$로 나눴을 때 $a \div b = q$이고 이는 $a = bq + r$ 이렇게 다시 쓸 수 있습니다.  
$q$는 몫(quotient)이고 $r$은 나머지(remainder)입니다. 이때 아래식이 성립합니다.

$$
gcd(a, b) = gcd(b, r)
$$

$a$와 $b$의 최대공약수와 $a$를 $b$로 나눈 나머지와 $b$의 최대공약수는 같습니다. 몇가지 예를 들어보겠습니다.

$$
\begin{matrix}
gcd(4098, 2024) = 2\\
4098 \div 2024 = 2 \cdots 나머지는\;50
\end{matrix}
$$

$$
\begin{matrix}
gcd(50, 2024) = 2\\
2024 \div 50 = 40 \cdots 나머지는\;24
\end{matrix}
$$

$$
\begin{matrix}
gcd(50, 24) = 2\\
50 \div 24 = 2 \cdots 나머지는\;2
\end{matrix}
$$

$$
\begin{matrix}
gcd(2, 24) = 2\\
24 \div 2 = 12 \cdots 나머지는\;0
\end{matrix}
$$

$$
\begin{matrix}
gcd(2, 0) = 2
\end{matrix}
$$

두 수 4098, 2024의 최대공약수는 2입니다.


$$
\begin{align*}
& gcd(123456, 9999) \\
& = gcd(3468, 9999) \\
& = gcd(3468, 3063) \\
& = gcd(405, 3063) \\
& = gcd(405, 228) \\
& = gcd(177, 228) \\
& = gcd(177, 51) \\
& = gcd(24, 51) \\
& = gcd(24, 3) \\
& = gcd(0, 3)
\end{align*}
$$

두 수 123456과 9999의 최대공약수는 2입니다.

정리하자면 다음과 같습니다.  
1. 두 정수 중 큰 수를 작은 수로 나눈 나머지로 바꿉니다. (만약 $a \gt b$라면 $a = a\;mod\;b$)
2. 두 정수 중 한쪽이 0이 될 때까지 반복합니다. 이때 0이 아닌 쪽이 최대공약수입니다.