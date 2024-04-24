-- 定义测试函数。你可以跳过阅读这一段程序。
test :: String -> Bool -> IO()
test description assertion = do
  putStr description
  case assertion of
    False -> putStrLn " failed"
    True  -> putStrLn " passed"

-- 现在，我们给出produce的定义。该函数返回 1 到 n 的列表。
-- 示例：当produce 10时，返回[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

produce :: Int -> [Int]
produce n = [i | i <- [1..n]]

-- 练习：完成produceOdd函数，其返回1-n中的奇数组成的list
-- 要求：在produceOdd的定义中，调用produce函数
-- 示例：当produceOdd 10时，返回[1, 3, 5, 7, 9]

produceOdd :: Int -> [Int]
produceOdd n = [i | i <- [1..n], odd i]

testOdd = do
  test "Odd 1" $ produceOdd 10 == [1,3,5,7,9]
  test "Odd 2" $ all odd $ produceOdd 100
  test "Odd 3" $ (length $ produceOdd 100) == 50
  test "Odd 4" $ (length $ produceOdd 99) == 50

-- 练习：完成produceList函数，其接受一个参数n，返回[[1], [1,2], ..., [1,...,n]]
-- 要求：在produceList的定义中，调用produce函数
-- 示例：当produceList 3时，返回[[1], [1, 2], [1, 2, 3]]

produceList :: Int -> [[Int]]
produceList n = [produce i | i <- produce n]

testList = do
  test "List 1" $ produceList 1 == [[1]]
  test "List 2" $ produceList 2 == [[1],[1,2]]
  test "List 3" $ produceList 3 == [[1],[1,2],[1,2,3]]
  test "List 4" $ (length $ produceList 99) == 99 && (length $ last $ produceList 99) == 99

-- 练习：完成produceStrangeList函数，其接受一个参数n，由其“后i个元素”和“前n-i个元素”组成的list(1 <= i <= n)
-- 提示: ++ 可连接两个list
-- 示例：当produceStrangeList 5时，返回[[2,3,4,5,1],[3,4,5,1,2],[4,5,1,2,3],[5,1,2,3,4],[1,2,3,4,5]]

produceStrangeList :: Int -> [[Int]]
produceStrangeList n = [drop i (produce n) ++ take i (produce n) | i <- produce n]

testStrangeList = do
  test "StrangeList 1" $ produceStrangeList 1 == [[1]]
  test "StrangeList 2" $ produceStrangeList 2 == [[2,1],[1,2]]
  test "StrangeList 3" $ produceStrangeList 3 == [[2,3,1],[3,1,2],[1,2,3]]
  test "StrangeList 4" $ produceStrangeList 5 == [[2,3,4,5,1],[3,4,5,1,2],[4,5,1,2,3],[5,1,2,3,4],[1,2,3,4,5]]

-- 现在，我们给出produce的另一种定义方式。
-- 需要注意的是，produce 是一个函数，接受参数 n 指示生成序列的长度。
-- produce2 是一个无限长度列表，不需要参数。因此如果直接输出该列表将永无终止。
-- 在需要时可以使用 take 函数获取该无限列表的前几项。
-- 示例，当take 5 (produce2)时，返回构造出的produce序列的前5项，为[1, 2, 3, 4, 5]

produce2 :: [Int]
produce2 = [1] ++ [(produce2!!i) + 1  | i <- [0..]]

-- 练习：请在理解 produce2 的基础上，给出 factorial 的定义
-- 示例输出：take 10 (factorial)输出阶乘序列前10项
-- [1,1,2,6,24,120,720,5040,40320,362880]

factorial :: [Int]
factorial = [1] ++ [(factorial!!i) * (i + 1) |i <- [0..]]

testFactorial = do
  test "factorial 1" $ take 10 factorial == [1,1,2,6,24,120,720,5040,40320,362880]
  test "factorial 2" $ factorial!!20 == 2432902008176640000

-- 练习：请在理解 produce2 的基础上，给出 fibonacci 的定义
-- 示例输出：take 10 (fibonacci)输出斐波那契序列前10项
-- [1,1,2,6,24,120,720,5040,40320,362880]

fibonacci :: [Integer]
fibonacci = [0, 1] ++ [(fibonacci !! i) + (fibonacci !! (i + 1)) | i <- [0..]]

testFibonacci = do
  test "fibonacci 1" $ take 10 fibonacci == [0,1,1,2,3,5,8,13,21,34]
--  test "fibonacci 2" $ fibonacci!!60 == 1548008755920

-- 计算机中常用的随机数是“伪随机数”，其中的“伪”体现在给出的“随机数”其实是通过一定的算法确定性的计算出来的。
-- 换句话说，如果仅靠随机函数自己，每次返回的数字都会是同一个。
-- 因此随机函数需要一个参数，称为“随机数种子”，为函数的输出提供随机性。输入不同的“种子”，生成不同的“随机数”。
-- 以 LCG 随机算法为例，其一种常见的定义如下。
random :: Integer -> Integer
random seed = (25214903917 * seed) `rem` 562949953421312

-- 为了生成多个不同的“伪随机数”，显然不能使用同一个随机数种子作为输入。
-- 在实践中，常常使用上一个生成的随机数作为下一个随机数的种子。
-- 即，当随机数种子为 seed 时，第一个随机数是 random seed，第二个随机数是 random random seed。
-- 练习：请完成 randomList 的定义，使得 randomList seed 能够返回一个无限长度的随机数列表
randomList :: Integer -> [Integer]
randomList seed = [random seed] ++ [random (randomList seed !! i) | i <- [0..]]

testRandomList = do
  test "randomList 1" $ (randomList 10)!!10 == 357758112612178
  test "randomList 2" $ (randomList 10)!!20 == 218930212691682
  test "randomList 3" $ (randomList 20)!!10 == 152566271803044


main = do
  testOdd
  testList
  testStrangeList
  testFactorial
  testFibonacci
  testRandomList
