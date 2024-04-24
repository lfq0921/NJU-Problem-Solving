import qualified Data.Set as Set
import Data.List (permutations)

-- 下面的程序尝试使用 Haskell 求解 24 点。我们暂时不考虑程序效率。
-- 核心思路非常简单：使用函数生成每一种可能的运算组合，直到得出结果。

-- 为了能够输出最终的计算表达式，我们需要一种方式定义“运算”。
-- 以下代码为框架代码，如果你暂时无法理解，可以先跳过这段程序。
data Exp = Value Double
         | Add Exp Exp
         | Sub Exp Exp
         | Mul Exp Exp
         | Div Exp Exp
         deriving (Show, Eq, Ord)

-- eval 函数接受一个 Exp 作为输入，递归计算该表达式并返回结果。
-- 你可以试试看执行下面几个函数调用，想想返回值是怎么计算的：
-- eval $ Value 10
-- eval $ Add (Value 10) (Value 1)
-- eval $ Mul (Value 10) (Sub (Value 3) (Value 2))
-- eval $ Mul (Sub 10 6) (Sub (Value 3) (Value 2))
eval :: Exp -> Double
eval (Value v) = v
eval (Add a b) = eval a + eval b
eval (Sub a b) = eval a - eval b
eval (Mul a b) = eval a * eval b
eval (Div a b) = eval a / eval b

-- 和 eval 类似，showExp 函数接受一个 Exp 作为输入，返回该表达式的数学表示。
-- 你可以试试看执行下面几个函数调用，想想返回值是怎么计算的：
-- showExp $ Value 10
-- showExp $ Add (Value 10) (Value 1)
-- showExp $ Mul (Value 10) (Sub (Value 3) (Value 2))
-- showExp $ Mul (Sub 10 6) (Sub (Value 3) (Value 2))
showExp :: Exp -> String
showExp (Value v) = show $ round v
showExp (Add a b) = "(" ++ showExp a ++ "+" ++ showExp b ++ ")"
showExp (Sub a b) = "(" ++ showExp a ++ "-" ++ showExp b ++ ")"
showExp (Mul a b) = "(" ++ showExp a ++ "*" ++ showExp b ++ ")"
showExp (Div a b) = "(" ++ showExp a ++ "/" ++ showExp b ++ ")"

test :: String -> Bool -> IO()
test description assertion = do
  putStr description
  case assertion of
    False -> putStrLn " failed"
    True  -> putStrLn " passed"
    
unique xs = Set.toList $ Set.fromList xs

-- 练习：完成 buildOperations 的定义。
-- 对于输入的表达式 a b，应该返回所有形如 Op a b 的表达式。
-- 其中，a b 分别为 xs ys 中给出的表达式，“Op”为 Add/Sub/Mul/Div 中的任意一个。
-- 如果不是很明白函数的作用，你可以参考下面的样例测试。
-- 另外，这个函数的参考实现只有一行。
-- 如果你的实现过于复杂，推荐重新看看教程中的 List Comprehension 小节，获取一些灵感。
buildOperations :: [Exp] -> [Exp] -> [Exp]
buildOperations xs ys = []

testBuildOperations = do
  test "buildOperations 1" $ (Set.fromList $ unique $ map eval $ buildOperations [Value 1] [Value 2]) ==
    Set.fromList [1+2, 1-2, 1*2, 1/2]
  test "buildOperations 2" $ (Set.fromList $ unique $ map eval $ buildOperations [Value 1, Value 2] [Value 3]) ==
    Set.fromList [1+3, 1-3, 1*3, 1/3, 2+3, 2-3, 2*3, 2/3]
  test "buildOperations 3" $ (Set.fromList $ unique $ map eval $ buildOperations [Value 1, Value 2] [Value 3, Value 4]) ==
    Set.fromList [1+3, 1-3, 1*3, 1/3, 2+3, 2-3, 2*3, 2/3, 1+4, 1-4, 1*4, 1/4, 2+4, 2-4, 2*4, 2/4]

-- 练习：完成 buildExpressions 的定义。
-- 对于输入的表达式 a b c d，利用 buildOperations 返回所有可能的表达式。
-- 如 (a + b) * (c + d)。不需要交换 a b c d 的顺序。
-- 提示：你可以通过递归完成该函数。
-- 例如，buildExpressions [1,2,3,4] = 
--         buildOperations (buildExpressions [1]) (buildExpressions [2,3,4])
--      ++ buildOperations (buildExpressions [1,2]) (buildExpressions [3,4])
--      ++ buildOperations (buildExpressions [1,2,3]) (buildExpressions [4])
-- 其中，多个 list 的合并可以使用 concat 函数。
-- 推荐的定义形如
-- buildExpression xs = concat [buildOperations ??? ??? | n <- [1..(length xs)-1] ]
-- 你可以执行下面一行来查看你的 buildExpressions 函数的返回值：
-- putStr $ unlines $ map showExp $ unique $ buildExpressions $ map Value [1,2,3]

buildExpressions :: [Exp] -> [Exp]
buildExpressions xs = []

testBuildExpressions = do
  -- buildExpress 对于 [1, 2] 应该能够返回如下的 4 种结果（顺序不必相同）
  test "buildExpressions 1" $ Set.fromList (map eval $ buildExpressions [Value 1, Value 2]) == 
    Set.fromList [1+2, 1-2, 1*2, 1/2]
  -- 按照规律，对于 [1, 2, 3] 应该能够返回20种不同的结果。
  test "buildExpressions 2" $ (length $ unique $ map eval $ buildExpressions [Value 1, Value 2, Value 3]) == 20
  test "buildExpressions 3" $ (length $ unique $ map eval $ buildExpressions [Value 1, Value 2, Value 3, Value 4]) == 104
    
-- 练习：完成 calc24 的定义。
-- 利用上面定义的 buildExpressions 生成所有可能的表达式，然后使用 eval 求解，仅保留。
-- 在生成表达式的过程中，不必交换 a b c d 的顺序。
-- 也即生成的表达式仅相当于在数字间插入 +-*/ 和括号。
-- 你可以使用下面这行代码查看你的 calc24 的返回值。
-- putStr $ unlines $ map showExp $ unique $ calc24 $ map Value [1,2,3,4]

calc24 :: [Exp] -> [Exp]
calc24 xs = []

testCalc24 = do
  test "calc24 1" $ sols [1,5,5,5] == 0
  test "calc24 2" $ sols [5,5,1,5] > 0
  test "calc24 3" $ sols [1,1,1,8] > 0
  test "calc24 4" $ sols [1,8,1,1] == 0
  test "calc24 5" $ sols [4,7,4,7] == 0
  test "calc24 6" $ sols [4,4,7,7] > 0
  test "calc24 7" $ sols [3,7,9,13] == 0
  test "calc24 8" $ sols [2,2,13,13] > 0
  test "calc24 9" $ sols [10,11,13,13] == 0
  test "calc24 10" $ sols [1,3,10,13] == 0
  test "calc24 11" $ sols [3,4,11,11] == 0
  
  -- 特殊测试：5个数的24点，你的程序理论上可以不做修改通过
  test "calc24 12" $ sols [2,3,4,5,6] > 0
  test "calc24 13" $ sols [4,5,6,7,8] > 0
  -- 计算解的个数
  where sols xs = length $ calc24 $ map Value xs

-- 如果我们想任意顺序的使用数字得到24点？
-- 简单，只需要对输入数字的每一种排列都调用一次写好的 calc24 即可。
-- 下面已给出参考实现。

calc24' :: [Exp] -> [Exp]
calc24' xs = concat [calc24 xs' | xs' <- permutations xs]

testCalc24' = do
  test "calc24' 1" $ sols [1,5,5,5] > 0
  test "calc24' 2" $ sols [5,5,1,5] > 0
  test "calc24' 3" $ sols [1,1,1,8] > 0
  test "calc24' 4" $ sols [1,8,1,1] > 0
  test "calc24' 5" $ sols [4,7,4,7] > 0
  test "calc24' 6" $ sols [1,6,11,13] > 0
  test "calc24' 7" $ sols [3,7,9,13] > 0
  test "calc24' 8" $ sols [2,2,13,13] > 0
  test "calc24' 9" $ sols [10,11,13,13] == 0
  test "calc24' 10" $ sols [1,3,10,13] == 0
  test "calc24' 11" $ sols [3,4,11,11] == 0
  
  -- 特殊测试：5个数的24点，你的程序理论上可以不做修改通过
  test "calc24' 12" $ sols [2,3,4,5,6] > 0
  test "calc24' 13" $ sols [4,5,6,7,8] > 0
  -- 计算解的个数
  where sols xs = length $ calc24’ $ map Value xs

main = do
  testBuildOperations
  testBuildExpressions
  testCalc24
  testCalc24'
  putStr $ unlines $ map showExp $ unique $ calc24' $ map Value [1,5,5,5]
