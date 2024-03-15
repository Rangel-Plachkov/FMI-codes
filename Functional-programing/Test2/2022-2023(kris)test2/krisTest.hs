import Data.Char
import Data.List

main :: IO()
main = do
    --print (isPerfectSq 1)
    --print (solve ["abcde" , "ABc" , "xyzD"])
    --print (solve ["abide" , "ABc" , "xyz"])
    --print (solve ["encode" , "abc" , "ABmD"])
    --print (studAvg l1)
    --print (studAvg l1)
    print (show 11)


l1 :: [(Int, Double)]
l1 = [(1,100) ,(1, 50),(2, 100), (2, 93), (1, 39), (2, 87), (1, 89), (1, 87), (1, 90), (2, 100), (2, 76)]

l2 :: [(Int, Double)]
l2 = [(3, 55), (2, 50), (1, 21), (3, 53), (2, 48), (1, 3), (3, 4), (2, 28), (1, 10), (3, 80), (2, 68), (1, 15), (3, 91), (2, 45), (1, 49)]

getMaxId :: [(Int, Double)] -> Int
getMaxId [] = (minBound::Int) 
getMaxId ((id,mark):ls) = max id (getMaxId ls)

getIdGrades :: Int -> [(Int, Double)] -> [Double]
getIdGrades _ [] = []
getIdGrades n ((id , mark):ls)  = 
    if (id == n)
        then (mark : (getIdGrades n ls))
        else getIdGrades n ls


getMaxNGradesAvr :: Int -> [(Int, Double)] -> Double -> (Int , Double)
getMaxNGradesAvr id ls times = helper ( reverse (sort (getIdGrades id ls) )) 0.0 0
    where
        helper [] res _ = (id , res / times)
        helper (g:gs) res count = 
            if(count == 5) 
                then (id , res / times)
                else helper gs (res + g) (count + 1)

isInList :: Int -> [(Int, Double)] -> Bool
isInList _ [] = False
isInList n ((id, _):ls) = n == id || isInList n ls

studAvg :: [(Int,Double)] -> [(Int,Double)]
times = 5
studAvg ls = helper 1
    where
        maxId = (getMaxId ls)
        helper cur= 
            if(cur > maxId)
                then []
                else if (isInList cur ls)
                    then [(getMaxNGradesAvr cur ls times)] ++ (helper (cur + 1))
                    else (helper (cur + 1))




isPerfectSq :: Int -> Bool
isPerfectSq n = 
    if ( n < 0 )
        then error "Argument have to be natural number"
        else helper 0
            where 
                helper i =
                    if(i^2 == n)
                        then True
                    else if ( i^2 > n)
                        then False
                        else helper (i+1)


solveSingle :: String -> Int
solveSingle str = helper str 0
    where 
        helper [] _ = 0
        helper (s:str) pos = 
            if ( (fromEnum s) == pos + fromEnum ('a') ) || ( (fromEnum s) == pos + fromEnum ('A') ) then 1 + helper str (pos+1)
            else helper str (pos +1)


solve :: [String] -> [Int]
solve [] = []
solve (x:xs) = [solveSingle x] ++ solve xs


data BTree a =  NullT | Node a (BTree a) (BTree a)

maxSumSubT :: Num a => Ord a => BTree a -> a
maxSumSubT NullT = 0
maxSumSubT (Node val left right) = max  (val + (max (maxSumSubT left)   (maxSumSubT right) ))
                                        (max        (maxSumSubT left)   (maxSumSubT right)  )  


t1 :: BTree Int
t1 = Node 3 (Node 0 NullT NullT) (Node 2 (Node 0 NullT NullT)NullT)
t2 :: BTree Int
t2 = Node (-3) (Node 0 NullT NullT) (Node 2 (Node 0 NullT NullT)NullT)
