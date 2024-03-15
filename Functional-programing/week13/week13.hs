import Data.List

main :: IO()
main = do
    print (avrT t1)
    
data BTree = Empty | Node Int BTree BTree
    deriving (Eq, Show)

t1 :: BTree
t1 = Node 1 (Node 2 Empty 
                (Node 3 Empty Empty))
            (Node 4 
                (Node 6 Empty Empty) Empty)

leafCount :: BTree -> Int   
leafCount Empty = 0
leafCount (Node _ lef rig) = 1 + (leafCount lef) + (leafCount rig)

sumThree :: BTree -> Int
sumThree Empty = 0
sumThree (Node val l r) = val + sumThree l + sumThree r

getLevel ::Int -> BTree -> [Int]
getLevel 0 Empty = []
getLevel 0 (Node val _ _) = [val]
getLevel lvl (Node _ left right) = (getLevel (lvl-1) left) ++ (getLevel (lvl-1) right)

avrT :: BTree -> Double
avrT t = (fromIntegral (sumThree t)) / (fromIntegral (leafCount t))