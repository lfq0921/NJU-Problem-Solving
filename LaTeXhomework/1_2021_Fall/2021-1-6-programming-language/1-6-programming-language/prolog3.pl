/*
 * 在C++中，我们可以这样定义阶乘函数
 int factorial(int n)
 {
    if (n == 1) return 1;
    int tmp = factorial(n - 1);
    return tmp * m;
 }
 
 * 在prolog的视角下，我们可以将其中函数看成一组关系：
   - 在谓词factorial下，(1, 1)构成一组关系。
   - 在谓词factorial下，(n - 1, tmp)构成一组关系。
   - 在谓词factorial下，(n, tmp * m)构成一组关系。
 
 *  因此，我们可以写出以下的代码：
 */

factorial(0, 1). 
factorial(1, 1).      
 
factorial(N, M) :-     
    N > 1,       
    N1 is N - 1,  
    factorial(N1, M1),  
    M is M1 * N.  

% 上述定义为：
% 在 N > 1时，谓词factorial采用递归定义
% 条件（N > 1）
% 定义N1（其值为N - 1）
% 寻找与N1在谓词factorial下构成关系的变量：M1
% 推出与N在谓词factorial下构成关系的变量：M1 * N

% 注意，此时用 N1 = N - 1是错的
/* 
 int fibonacci(int n)
 {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
 }
 
 练习：请给出斐波那契数列，在prolog下的递归定义
 
*/

fibonacci(1, 1).

fibonacci(2, 1).

fibonacci(N, M) :- 
    true.

/* 
 练习：
 findFibonacci(N, M, T)代表第T个斐波那契数为N，第T + 1个斐波那契数为M的一组关系。
 请给出findFibonacci的定义。
*/

findFibonacci(1, 1, 1).
findFibonacci(1, 2, 2).

findFibonacci(N, M, T) :-
    true.
 
test(Description, Assertion) :-
    Assertion, write(Description), write(' passed.'), nl;
    \+ Assertion, write(Description), write(' failed!'), nl.

main:-
    test("fibonacci Tset 1", \+ fibonacci(1, 2)),
    test("fibonacci Tset 2", fibonacci(5, 5)),
    test("fibonacci Tset 3", \+ fibonacci(10, 66)),
    test("fibonacci Tset 4", fibonacci(20, 6765)),
    test("fibonacci Tset 5", fibonacci(25, 75025)),
    test("findFibonacci Tset 1", \+ findFibonacci(2, 3, 4)),
    test("findFibonacci Tset 2", findFibonacci(3, 5, 4)),
    test("findFibonacci Tset 3", \+ findFibonacci(5, 8, 8)),
    test("findFibonacci Tset 4", findFibonacci(8, 13, 6)),
    test("findFibonacci Tset 5", findFibonacci(13, 21, 7)).


