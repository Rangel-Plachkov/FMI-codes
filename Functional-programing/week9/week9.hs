import Data.Char
import Data.List

main :: IO()
main = do
    --print([1,2,3])
    --print(v2)
    --print(incrementAllBy xs 5)
    --print(multiplyAllBy xs 5)
    print(filterSmallerThan' xs 9)


xs :: [Int]
xs = [5,10,15]

v2 :: (Char, [Int])
v2 = ('a', [1,2,3])

incrementAllBy ::[Int] -> Int -> [Int]
incrementAllBy xs n =
    if null xs then []
    else (n + head xs): incrementAllBy (tail xs) n


multiplyAllBy ::[Int] -> Int -> [Int]
multiplyAllBy xs n =
    if null xs then []
    else (n * head xs) : multiplyAllBy (tail xs) n

multiplyAllBy' ::[Int] -> Int -> [Int]
multiplyAllBy' [] _ = []
multiplyAllBy' (x:xs) n = (n * x): multiplyAllBy' xs n


{-
filterSmallerThan ::[Int] -> Int -> [Int]
filterSmallerThan xs n =
    if null xs then []
    else if n < head xs then (head xs) : filterSmallerThan (tail xs) n
    else  filterSmallerThan (tail xs) n
-}


filterSmallerThan ::[Int] -> Int -> [Int]
filterSmallerThan [] _ = []
filterSmallerThan (x:xs) n = 
    if x > n then x : filterSmallerThan xs n
    else filterSmallerThan xs n

filterSmallerThan'::[Int] -> Int -> [Int]
filterSmallerThan' xs n
    | null xs = []
    | head xs > n = head xs: filterSmallerThan'(tail xs) n
    | otherwise = filterSmallerThan (tail xs) n

 
filterSmallerThan'' :: [Int] -> Int -> [Int]
filterSmallerThan'' xs n = [x | x <- xs, x >= n]

toList :: Int -> [Int]
toList n = helper n []
    where 
        helper k res = 
            if k < 10 then k:res
            else helper (k `div` 10) (mod k 10 : res)

check :: [Int] -> Bool
check []         = True
check [_]        = True
check (x1:x2:xs) = x1 < x2 && check (x2:xs)

isAscending :: Int -> Bool
isAscending n = check (toList n)
