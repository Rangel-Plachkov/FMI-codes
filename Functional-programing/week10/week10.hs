import Data.List

main :: IO()
main = do
    --print (isPrime 1)
    --print [1 .. 10]
    --print (primesInRange' 1 10)
    --print (prodSumDiv [1..100] 27)
    print (isSorted' [1, 2, 3, 4])


isPrime :: Int -> Bool
isPrime n = [d | d <- [1..n], mod n d == 0] == [1, n]

{-
primesInRange :: Int -> Int -> [Int]
primesInRange a b 
    = if a > b then []
    else if isPrime a then a : (primesInRange (a+1) b)
    else (primesInRange (a+1) b)
-}

primesInRange :: Int -> Int -> [Int]
primesInRange a b = [n | n <- [a .. b] , isPrime n]

primesInRange' :: Int -> Int -> [Int]
primesInRange' a b = filter isPrime [a..b]

sumOfDels :: Integer -> Integer
sumOfDels n = sum [d | d <- [1..n], mod n d == 0]

prodSumDiv :: [Integer] -> Integer -> Integer
prodSumDiv xs k = product [d | d <- xs , mod k d == 0]

isSorted :: [Int] -> Bool
isSorted xs = helper (head xs) (tail xs)
    where 
        helper x xs =
            if null xs then 1 > 0
            else x <= head xs && helper (head xs) (tail xs)

isSorted' :: [Int] -> Bool
isSorted' [] = True
isSorted' [_] = True
isSorted' (a:b:xs) = ( a <= b) && isSorted' ( tail xs)

 --insert :: Int -> [Int] -> [Int]
 --insert x xs = 