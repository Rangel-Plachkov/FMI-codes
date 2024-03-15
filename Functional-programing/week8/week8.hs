main :: IO()
main = do
    --print 123
    --print "abc"
    --print a
    --print (f1 10 a)
    --print (myMin 5 8)
    --print (isInside 7 6 10)
    print (myFunc 3 4)

a :: Int
a = 12

f1 :: Int -> Int -> Int
f1 a b = a * (2 + b)

myMin :: Int ->Int -> Int
myMin a b = 
    if a < b then a else b

isInside :: Int ->  Int -> Int -> Bool
isInside x a b =
    --if x > a && x < b then True else False
    x > a && x < b

myFunc :: Double -> Double -> Double
myFunc a b = (a*a + b* b)/2

myFib :: Int -> Int
myFib n = 
    if n <= 1 then 1 else myFib (n - 2) + myFib (n - 1)


myfib' :: Integer -> Integer
myfib' n = helper 0 0 1
  where
    helper i prev cur =
      if i == n then cur
      else helper (i + 1) cur (prev + cur)

      