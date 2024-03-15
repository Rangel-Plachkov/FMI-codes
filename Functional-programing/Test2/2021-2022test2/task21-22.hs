import Data.Char

main :: IO()
main = do
    --print (squareDigits 12345)
    --print (stocklist stocks ['A','B','W'])
    --print (matching "12[[]34]")
    print (isPerfectlyBalansed t1)

--------------------------------------------------------------------------------------------------------------------------------------

squareDigits :: Int -> Int
squareDigits n = (read (helper (show n)) )
    where
        helper str =
            if str == "" then []
            else show (digitToInt (head str) ^ 2) ++ helper (tail str)

---------------------------------------------------------------------------------------------------------------------------------------

data Stock = Stock String Int
stocks = [Stock "ABAR" 200 , Stock "CDXE" 500 , Stock "BKWR" 250 , Stock "BTSQ" 890 , Stock "DRTY" 600 ]

getSum :: [Stock] -> Char -> Int
getSum [] _ = 0;
getSum ((Stock str sum):ls) symbol = 
    if (head str) == symbol then sum + getSum ls symbol
    else  getSum ls symbol

stocklist :: [Stock] -> [Char] -> [(Char,Int)]
stocklist _ [] = []
stocklist stL chL = 
    if(null chL) then []
    else  [ ( head chL , getSum stL (head chL) ) ] ++ stocklist stL (tail chL)

----------------------------------------------------------------------------------------------------------------------------------------

matching :: String -> [(Int, Int)]
matching str = helper str [] 0
    where
        helper str ls pos =
            if null str  then []
            else if (head str) == '[' then helper (tail str) (ls ++ [pos]) (pos+1)
            else if (head str) == ']' then [((last ls) , pos)] ++ helper (tail str) (init ls) (pos+1)
            else helper (tail str) ls (pos+1) 

-------------------------------------------------------------------------------------------------------------------------------------

data BTree a = Nil | Node a (BTree a) (BTree a)

t1 :: BTree Int
t1 = Node 1 (Node 2 Nil Nil)
            (Node 3 Nil Nil)

getElementCount :: BTree a -> Int
getElementCount Nil = 0
getElementCount (Node _ left right) = 1 + (getElementCount left) + (getElementCount right)

getTreeDepth :: BTree a -> Int
getTreeDepth Nil = 0;
getTreeDepth (Node _ l r) = 1 + max (getTreeDepth l) (getTreeDepth r) 

isPerfectlyBalansed :: BTree a -> Bool
isPerfectlyBalansed tree = (2 ^ (getTreeDepth tree)) - 1 == (getElementCount tree) 