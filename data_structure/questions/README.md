# 🌈408数据结构真题2009～2023全集🌈

本目录包含2009至2023年408数据结构算法题代码实现

使用指南：
- 代码基本按照C++11语法编写，可直接运行
- 代码中包含一些辅助测试函数，与解答无关
- 如有疑问，敬请提出

#### 2009统考真题

> 已知一个带有表头结点的单链表，结点结构为
> 	| data | link |
> 	|-------|-------|
> 	
> 	假设该链表只给出了头指针list。在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第$k$个位置上的结点（$k$为正整数）。若查找成功，算法输出该结点的data域的值，并返回1；否则，只返回0。要求：
>
> 1）给出算法的基本设计思想
>
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
>
> 3）说明你所设计算法的时间复杂度和空间复杂度。
>

#### 2010统考真题

> 设将$n(n>1)$个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法，将R中保存的序列循环左移$p_{(0<p<n)}$个位置，即将R中的数据由$(X_0,X_1,...,X_{n-1})$变换为$(X_p,X_{p+1},...,X_{n-1},X_0,X_1,...,X_{p-1})$。要求：
> 
> 1）给出算法的基本设计思想
> 
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。
> 

#### 2011统考真题

> 一个长度为$L（L >= 1）$的升序序列$S$，处在第$[L/2]$个位置的数称为$S$的中位数。例如，若序列$S_1=(11,13,15,17,19)$，则$S_1$的中位数是$15$，两个序列的中位数是它们所有元素的升序序列的中位数。例如，若$S_2=(2,4,6,8,20)$，则$S_1$和$S_2$的中位数时$11$。现在有两个等长升序序列$A$和$B$，设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列$A$和$B$的中位数。要求：
> 
> 1）给出算法的基本设计思想
> 
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。

#### 2012统考真题

> 假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空间，例如，“loading”和”being“的存储映像如下图所示:
> 
> (省略图片)
> 
> 设str1和str2分别指向两个单词所在单链表的头结点，链表结点结构为`|data| |next|`，请设计一个时间上尽可能高效的算法，找出由str1和str2所指向的两个链表共同后缀的起始位置（如图中字符i所在结点的位置p）。要求：
> 
> 1）给出算法的基本设计思想
> 
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。

#### 2013统考真题

> 已知一个整数序列$A=(a_0,a_1,...,a{n-1})$，其中$0<=a_i<n_{(0<=i<n)}$。若存在$a_{p1}=a_{p2}=...=a_{pm}=x$且$m>n/2_{(0<=p_k<n,1<=k<=m)}$，则称$x$为$A$的主元素。例如$A=(0,5,5,3,5,7,5,5)$，则$5$为主元素；又如$A=(0,5,3,5,1,5,7)$，则$A$中唯有主元素。
> 假设$A$中的$n$个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出$A$中的主元素。若存在主元素，则输出该元素；否则输出$-1$。要求：
> 
> 1）给出算法的基本设计思想;
> 
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释;
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。
> 

#### 2014统考真题

> 二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和。给定一棵二叉树T，采用二叉链表存储，结点结构为：
> 	| left | weight | right |
> 	|-------|-------|-------|
>
> 其中叶结点的 weight 域保存该结点的非负权值。设root为指向 T 的根结点的指针，请设计求T的WPL的算法，要求：
> 
> 1）给出算法的基本设计思想；
> 
> 2）使用 C 或 C++语言，给出二叉树结点的数据类型定义；
> 
> 3）根据设计思想，采用 C 或 C++语言描述算法，关键之处给出注释。

#### 2015统考真题

> 用单链表保存m个整数，结点的结构为`[data][link]`，且`|data|<=n`（n为正整数）。现在要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。例如，若给定的单链表head如下：
> 
> `head->21->-15->-15->-7->15->^`
> 
> 则删除结点后的head为
> 
> `head->21->-15->-7->^`
> 
> 1）给出算法的基本设计思想
> 
> 2）根据设计思想，采用C或C++描述算法，关键之处给出注释。
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。
> 

#### 2016统考真题

> 已知由$n(n>=2)$个正整数构成的集合$A={a_k} (0≤k<n)$，将其划分为两个不相交的子集$A_1$和$A_2$，元素个数分别是$n_1$和$n_2$，$A_1$和$A_2$中元素之和分别为$S_1$和$S_2$。
> 设计一个尽可能高效的划分算法，满足$|n_1-n_2|$最小且$|S_1-S_2|$最大。要求:
>
> (1)给出算法的基本设计思想。
> 
> (2)根据设计思想，采用C或C++语言描述算法，关键之处给出注释
> 
> (3)说明你所设计算法的平均时间复杂度和空间复杂度。

#### 2017统考真题

> 请设计一个算法,将给定的表达式树(二叉树)转换为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。例如当下列两棵表达式树作为算法的输人时:
> 
> (省略图片)
> 
> 输出的等价中缀表达式分别为: (省略表达式)
> 
> 二叉树结点定义如下：
> ```c
> typedef struct node {
>    char data[10]; // 存储操作符或操作数
>    struct mpde *left, *right;
> } BTree;
>```
> 要求:
> 
> (1)给出算法的基本设计思想。
> 
> (2)根据设计思想,采用C或C++语言描述算法,关键之处给出注释。

#### 2018统考真题

> 给定一个含$n(n>=1)$个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组$\{-5,3,2,3\}$中未出现的最小正整数是1；数组$\{1,2,3\}$中未出现的最小正整数是$4$。要求:
> 
> 1）给出算法的基本设计思想
> 
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。

#### 2020统考真题

> 定义三元组$(a,b,c)$(a、b、c均为正数)的距离$D=|a-b|+|b-c|+|c-a|$。给定3个非空整数集合$S_1、S_2和S_3$，按升序分别存储在3个数组中。请设计一个尽可能高效的算法，计算并输出所有可能的三元组$(a,b,c)(a\subseteq{S_1},b\subseteq{S_2},c\subseteq{S_3})$中的最小距离。例如$S_1=\{-1,0,9\}$，$S_2=\{-25,-10,10,11\}$，$S_3=\{2,9,17,30,41\}$，则最小的距离为2，相应的三元组为$(9,10,9)$。要求：
> 
> 1）给出算法的基本设计思想
> 
> 2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
> 
> 3）说明你所设计算法的时间复杂度和空间复杂度。