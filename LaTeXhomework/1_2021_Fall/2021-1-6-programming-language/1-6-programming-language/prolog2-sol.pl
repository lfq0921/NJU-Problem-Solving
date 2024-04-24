/* 定义八个将军 */
general(zhao).
general(qian).
general(sun).
general(li).
general(zhou).
general(wu).
general(zheng).
general(wang).

/* 射中鹿的位置 */
position(head).
position(other).

/* 赵的猜测，X 代表射中鹿的人 */
zhaoGuess(X) :-
    X = wu.
zhaoGuess(X) :-
    X = wang.

/* 钱的猜测，X 代表射中鹿的人，Pos 代表射中鹿的位置 */
qianGuess(X, Pos) :-
    Pos = head,
    X = qian.
qianGuess(X, Pos) :-
    Pos = other.

sunGuess(X) :-
    X = zheng.

liGuess(X, Pos) :-
    Pos = head,
    X \= qian.

zhouGuess(X) :-
    X \= wu,
    X \= wang.

wuGuess(X) :-
    X \= wu,
    X \= wang.

zhengGuess(X) :-
    X \= sun.

wangGuess(X) :-
    X = wu.
wangGuess(X) :-
    X = wang.

/* 计算列表中为“真”的谓词数量 */
count([], 0).
count([X|L], Count) :-
    X,
    count(L, Count1),
    Count is Count1 + 1.
count([X|L], Count) :-
    \+ X,
    count(L, Count).

writeAnswer(X, Pos) :-
    write('射死鹿的人是'), write(X), nl,
    (zhaoGuess(X), write('赵猜对了'), nl ; true),
    (qianGuess(X, Pos), write('钱猜对了'), nl ; true),
    (sunGuess(X), write('孙猜对了'), nl ; true),
    (liGuess(X, Pos), write('李猜对了'), nl ; true),
    (zhouGuess(X), write('周猜对了'), nl ; true),
    (wuGuess(X), write('吴猜对了'), nl ; true),
    (zhengGuess(X), write('郑猜对了'), nl ; true),
    (wangGuess(X), write('王猜对了'), nl ; true).

/* 判定射死鹿的人为 X，射中部位为 Pos 是否满足题目条件 */
ans(X, Pos) :-
    general(X),
    position(Pos),
    count([zhaoGuess(X),
           qianGuess(X, Pos),
           sunGuess(X),
           liGuess(X, Pos),
           zhouGuess(X),
           wuGuess(X),
           zhengGuess(X),
           wangGuess(X)],
          3),
    writeAnswer(X, Pos).

/*
 * 在交互模式中使用 ans(X, Pos) 输出所有满足条件的解。
 */
