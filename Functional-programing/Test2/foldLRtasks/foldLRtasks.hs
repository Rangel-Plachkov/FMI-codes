import Data.Char

main :: IO()
main = do
    --print (sumsq2 3)
    --print (reverseR [9,1,2,3,4,5,6])
    --print (remove "first" "second")
    --print ([ (f,s) | f <- [1..5], s <- [f ^ 2] ])
    print (chr 1)


sumsq :: Int -> Int
sumsq n = (foldr (+) 0 (map (^ 2) [0 .. n]))

sumsq2 :: Int -> Int
sumsq2 n = (foldr (\cur -> (+) (cur ^ 2) ) 0 [0 .. n])

sumsq3 :: Int -> Int 
sumsq3 n = foldr (\curr acum -> curr^2 + acum) 0 [1..n]

--numInListL :: [a]
--numInListL ls = foldr (\cur -> [cur] ++ ) [] ls

smallestL :: [Int] -> Int
smallestL ls = foldr min (maxBound::Int) ls

smallestE :: [Int] -> Int
smallestE ls = foldl min (maxBound::Int) ls

reverseR :: [Int] -> [Int]
reverseR ls = foldr (\cur acum ->  (++) acum [cur] ) [] ls

isInStr :: Char -> String -> String
isInStr c [] = [c]
isInStr c (s:str) = 
    if (c == s)
        then []
        else isInStr c str 

remove :: String -> String -> String
remove str1 str2 = foldr (\curr -> (++) (isInStr curr str1) )  [] str2

