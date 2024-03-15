import Data.List

main :: IO()
main = do
    print (mapTree func t1)
    
data BTree a = Empty | Node a (BTree a) (BTree a) 
    deriving (Show)

t1 :: BTree Int           
t1 = Node 1 (Node 2 (Node 5 Empty Empty)
                                   Empty)
                     (Node 3 (Node 7 Empty Empty)
                                   (Node 6 Empty Empty))


sumTree :: Num a => BTree a -> a
sumTree Empty = 0
sumTree (Node val l r) = val + sumTree l + sumTree r


mirrorTree :: BTree a -> BTree a
mirrorTree Empty = Empty
mirrorTree (Node v left right) = (Node v (mirrorTree right) (mirrorTree left)  ) 

func :: Int -> Int
func a = a*2

mapTree :: (a -> b) -> BTree a -> BTree b
mapTree _ Empty = Empty
mapTree f (Node val left right) = (Node (f val) (mapTree f left) (mapTree f right))



--show()   str -> Int
--read()   int -> str

