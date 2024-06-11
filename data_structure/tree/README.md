# 트리(Tree) 자료구조
**트리**: 계층적 관계(Hierarchical Relationship)를 표현하는 자료구조

![a_tree](https://github.com/kk2415/foundations/assets/79124915/1a5f6cd6-a8ac-48e4-9d94-69962932f5ce)

<br/>
<br/>

# 용어 정리
+ **노드(node)**  
트리의 구성요소에 해당하는 1, 2, 3, 4, 5와 같은 요소 
+ **간선(edge)**  
노드와 노드를 연결하는 연결선 
+ **루트 노드(root node)**  
트리 구조에서 최상위에 존재하는 1과 같은 노드
+ **리프 노드(leaf node), 단말 노드(terminal node)**    
아래로 또 다른 노드가 연결되어 있지 않은 3, 4, 6, 7, 8과 같은 노드
+ **내부 노드(interal node)**  
리프(단말) 노드를 제외한 모든 노드로 1, 2, 5과 같은 노드

## 노드 간에 관계
노드 간에 맺어지는 상대적인 관계
+ **부모(parent)**  
노드 1은 노드 2, 3의 부모 노드(parent node)이다.
+ **자식(child)**  
노드 2, 3은 노드 1의 자식 노드(child node)이다.
+ **형제(sibling)**  
노드 2, 3은 부모 노드가 같으므로, 서로가 서로에게 형제 노드(sibling node)이다.
+ **조상(ancestor)**  
특정 노드 위에 위치한 모든 노드를 가리켜 조상 노드(ancestor node)라 한다. 노드 1, 2는 노드 5의 조상 노드이다.
+ **후손(descendant)**  
특정 노드 아래에 위치한 노드를 가리켜 후손 노드(descendant node)라 한다. 노드 2,3,4,5,6,7,8은 노드 1의 후손 노드이다.

<br/>
<br/>

# 트리의 종류

```
트리(Tree)/
    ├── 이진 트리(Binary Tree)/
    │   ├── 포화 이진 트리(Full Binary Tree)
    │   ├── 완전 이진 트리(Complete Binary Tree)
    │   │   └── 힙(Heap)
    │   ├── 균형 이진 트리(Balanced Binary Tree)
    │   ├── 이진 탐색 트리(Binary Search Tree, BST)
    │   ├── 자기 균형 이진 탐색 트리(Self-Balancing Binary Search Tree)/
    │   │   ├── AVL 트리(AVL Tree)
    │   │   ├── 레드-블랙 트리(Red-Black Tree)
    │   │   └── Splay 트리(Splay Tree)
    │   └── Tango 트리 (Tango Tree)
    ├── B-트리(B-Tree)
    ├── B+트리(B+ Tree)
    ├── R-트리 (R-Tree)
    └── 트라이 (Trie)
```