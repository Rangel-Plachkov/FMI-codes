
main::IO()
main = do
    --print(findNb 1)
    --print(dominates (+4) (*2) [1..5])
    --print(splitPoints (1,1) 5 [(1,2),(2,3),(10,15),(-1,1),(12,14)])
    print (maxBound :: Int)
    --print (isBinarySearchTree t3)


findNb :: Integer -> Integer
findNb 0 = 0
findNb m = helper 1 0
    where 
        helper n res =
            if(res == m) then n-1
            else if (res > m) then -1
            else helper (n+1) (res + (n^3))

------------------------------------------------------------------------------------------------------------------------------

dominates :: (Int -> Int) -> (Int -> Int) -> [Int] -> Bool
dominates _ _ [] = True
dominates f g (x:xs) = ((f x) >= (g x)) && (dominates f g xs)

---------------------------------------------------------------------------------------------------------------------------------

type Point = (Double,Double)
isInRad :: Point -> Double -> Point->Bool
isInRad (x,y) r (a,b) = (a-x)^2 + (b-y)^2 <= r^2 

splitPoints :: Point -> Double -> [Point] -> ([Point],[Point])
splitPoints c r ls = helper ls [] []
    where 
        helper [] inLs outLs = (inLs,outLs)
        helper (l:ls) inLs outLs =
            if(isInRad c r l)
                then helper ls (l:inLs) outLs
                else helper ls inLs (l:outLs)


-----------------------------------------------------------------------------------------------------------------------------

data BTree = Empty | Node Int BTree BTree

isBinarySearchTree :: BTree -> Bool
isBinarySearchTree Empty = True
isBinarySearchTree (Node val left right) = (helper left (minBound::Int) val) && (helper right val (maxBound :: Int))
    where 
        helper Empty _ _ = True
        helper (Node val left right) minV maxV = 
            if(val > minV && val <= maxV)
                then (helper left minV val ) && (helper right val maxV)
                else False


t1 :: BTree 
t1 = Node 8 (Node 3  (Node 1 Empty Empty) 
                     (Node 4 Empty Empty)) 
            (Node 10 (Node 9 Empty Empty) 
                     (Node 14 Empty Empty))

t2 :: BTree
t2 = Node 8 (Node 3  (Node 1 Empty Empty)
                     (Node 4 Empty Empty))
            (Node 10 (Node 5 Empty Empty) 
                     (Node 14 Empty Empty))

t3 :: BTree
t3 = Node 8     (Node 3  (Node 5 Empty Empty)
                         (Node 6 Empty Empty))
                (Node 10 (Node 9 Empty Empty)
                         (Node 14 Empty Empty))