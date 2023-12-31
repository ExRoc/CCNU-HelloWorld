# 小hi分蛋糕咯

## 题目背景

众所周知，$1024$ 程序设计协会是一个温暖的大家庭。今天小 $hi$ 买了很多大小不同的蛋糕，想要分给大家吃。但是因为最近大家提倡健康生活，不能吃太多的蛋糕，所以每个人最多只能吃一块。

## 题目描述

对于每个人 $i$，都有一个饱腹值 $partner[i]$，这是能够使大家吃得饱的最小尺寸；每块蛋糕 $j$，都有一个尺寸 $cake[j]$。

如果 $cake[j]\geq partner[i]$，那么我们可以将这个蛋糕 $j$ 分给社团成员 $i$，他就能够大快朵颐啦！
你的目标是尽可能满足多的社团成员，并输出这个数值的最大值。

## 输入格式

第一行输入两个整数 $m$ 和 $n$，分别代表人的数量和蛋糕的数量

接下来连续输入 $m$ 个整数，分别代表每个人的饱腹值

再接下来连续输入 $n$ 个整数，分别代表每个蛋糕的尺寸.

$1\leq m\leq10^4,~1\leq n\leq10^4\\1\leq partner[i],cake[j]\leq10^9$

**注意数据大小哦**

## 输出格式

一个整数，表示最多能够满足多少人。

## 样例 #1

### 样例输入 #1

```
2 3
1 2
1 2 3
```

### 样例输出 #1

```
2
```

## 提示

一共有两位社团成员和三块蛋糕，两个人的饱腹值分别是 1, 2。
小 hi 拥有的蛋糕数量和尺寸都足以让所有社团成员满足。所以你应该输出 2。