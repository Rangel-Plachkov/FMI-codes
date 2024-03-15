import Data.Char

main::IO()
main = do
    print (sumUniqueSinge [1,2,3,2,4,3])
    

----TASK 2

isInList :: Int -> [Int] -> Bool
isInList _ [] = False
isInList a (l:ls) =
    if(a == l) then True
    else isInList a ls

sumUniqueSinge :: [Int] -> Int
sumUniqueSinge [] = 0;
sumUniqueSinge xs = helper xs [] 0
    where
        helper [] _ res = res
        helper (x:xs) ls res = 
            if (isInList x ls) 
                then helper xs ls (res - x)
                else helper xs (x:ls) (res + x)



