# HelloWorld 的变迁

## 题目背景

HelloWorld 程序设计协会正式注册于 2017 年，致力于为对编程有兴趣的同学提供编程课外学习、交流平台。

和其他专业性更强的社团不同的是，HelloWorld 是一个更侧重于课外编程学习方向入门及初步深入的兴趣类社团，面向的主要是非计算机专业但想进一步学习编程的同学。

每年寒暑假，社团会有一些优秀的学长学姐指导大家进行课外编程学习，在同学们自主学习的基础上为大家提供各类帮助（如选择资料、减少踩坑、答疑交流等）。这些学长学姐有的是近两年刚参加过社团活动并取得一定成绩的优秀本科生，有的是保研或考入了更好学校的在读研究生，有的是毕业后就职于国内知名互联网公司的在职程序员。他们都曾在社团参与过学习活动，现在热心的帮助社团新同学们更好的成长。

## 题目描述

因为学校某项奇怪的规定，要求社团名字不能带英文，HelloWorld 程序设计协会在 2020 年被迫改名为 1024 程序设计协会。

社团创办者 xzh 时常记不清学校是什么时候提出的这个奇怪要求，请你写一个程序，当 xzh 输入一个数字 n 时，你会它的最后 4 位当成年份，并输出这个年份时社团的名字是 HelloWorld 还是 1024

## 输入格式

输入一个数字，为年份 n

## 输出格式

社团名字，仅需输出 HelloWorld 或 1024

## 样例 #1

### 样例输入 #1

```
20252018
```

### 样例输出 #1

```
HelloWorld
```

## 样例 #2

### 样例输入 #2

```
20202020
```

### 样例输出 #2

```
1024
```

## 样例 #3

### 样例输入 #3

```
2024
```

### 样例输出 #3

```
1024
```

## 提示

保证 n 是一个合法数字, 且最后四位在 2017~2024 之间

$2017\leq n<987654321012345$