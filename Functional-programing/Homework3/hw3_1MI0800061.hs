import Data.List
import Data.Char


main :: IO()
main = do
    --print (concatPairBeh [1,2] [[1,2], [3,4],[4,5]] 1)
    --print (generateAllPairs [10, 15, 25] [1, 5, 20, 30])
    --print ((generate [1,2] [5,10]))

    inputFile <- readFile "input.txt"
    print (countUniques inputFile) 


generateAllPairsByNum :: Int -> [Int] ->[[Int]]
generateAllPairsByNum _ [] = []
generateAllPairsByNum n (b:bs) 
    = if(n < b)
        then (n : [b]) : (generateAllPairsByNum n bs)
        else (generateAllPairsByNum n bs)

generateAllPairs :: [Int] -> [Int] ->[[Int]]
generateAllPairs [] _ = []
generateAllPairs _ [] = []
generateAllPairs (a:as) bs = (generateAllPairsByNum a bs) ++ (generateAllPairs as bs)

concatPairBeh ::[Int] -> [[Int]] -> Int -> [Int]
concatPairBeh [] _ _ = []
concatPairBeh res [] _ = res
concatPairBeh main (x:xs) skips
    = if ( (last main) < (head x) )
        then if(skips == 0)
            then main ++ x
            else concatPairBeh main xs (skips-1)
        else concatPairBeh main xs skips

helper :: [[Int]] -> Int -> [[Int]] -> [[Int]]
helper [] _ res = 




 
generate ::[Int] -> [Int] ->[[Int]]
generate [] _ = []
generate _ [] = []
--generate as bs = (helper (generateAllPairs as bs) [-10] [] )



------------------------------------------------------------------------------------------------------------

getLinesOfFile :: String -> Int
getLinesOfFile str 
    = (length (lines str))

stringToList :: String -> [String]
stringToList str = words str

isLookedNumber :: String -> Bool
isLookedNumber str = (length str == 2) || (length str == 4) || (length str == 3) ||(length str == 7)   

-- Намираме броя на думите с дължина 2,3,4,7 изваждаме за всеки ред 4 и тове е отговора
countUniques :: String -> Int
countUniques str = ( helper (stringToList str) - (getLinesOfFile str) * 4 )
    where 
        helper [] = 0
        helper xs
            = if isLookedNumber (head xs) 
                then 1 + helper (tail xs)
                else helper (tail xs)