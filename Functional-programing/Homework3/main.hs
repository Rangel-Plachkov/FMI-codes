import Data.Char

main :: IO()
main = do
    sample <- readFile "sample.txt"
    print (length(words sample))
    --print ((sum . (map (\ s -> read s :: Int)) . lines) sample)
