# lj 的赌局

## 题目背景

lj 和 lty 正在进行一场财富与生死的赌局！

## 题目描述

在赌桌上，有一排筹码，每个筹码上均有一个数字（整数）$x$，它代表这个筹码价值 $x$ 万元。我们使用一个数组 `nums` 来记录这一排筹码，例如：`nums = [1, 5, 2]`，它代表桌上有 3 个筹码，依次为：1 万元，5 万元，2 万元。

现在 lj 和 lty 要进行一场游戏：依次选取筹码**最左边**或者**最右边**的筹码（仅有这两个选择），并把筹码放在自己的面前。在所有筹码全部选取完成之后，如果lj的筹码总额大于等于 lty 的筹码总额，则lj可以掠夺 lty 所有财富（lty 的一等学业奖学金）！

现在，给定一个数组 `nums`，请选择 lj 或者 lty **先手**，以使 lj 必能赢下这场游戏，这样他就可以有钱去 nustc 去看 hhq！如果选择 lj 先手，请返回 `1`，否则，请返回 `0`.

## 输入格式

多行数据，每行输入代表一场游戏中lj面前的筹码总数 $K$ 和各个筹码的价值 $x_i$，每行输入的第一个数字代表这场游戏桌子上的筹码数，接着是 $K$ 个数据，如果桌上的筹码数为 $0$ 则表示游戏结束

## 输出格式

一个整数，1 或者 0，代表是 lty 先手还是 lj 先手

## 样例 #1

### 样例输入 #1

```
3 1 5 2
4 1 5 5 2
0
```

### 样例输出 #1

```
0
1
```

## 提示

解释：第一行的第一个数字 3 代表第一场游戏桌上筹码数为 3。这里你得输出 0，因为 lty 第一次只能选择 1 或者 2，那么 lj 就可以选择5，lty 拿走剩下的一个数字，但 lj 的总额为 5，而 lty 的总额仅为 3，lj 就必定赢得这场游戏！第二场游戏桌上筹码数为 4，lj 先手则必定赢下。第三场游戏桌上筹码数为 0，所以游戏结束

每场游戏有整数 $K$ 个筹码，$0<K\le20$，每个筹码的价值 $0<x\le 10^9$

