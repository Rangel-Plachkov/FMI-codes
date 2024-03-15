#lang racket

(define (mygcd a b)
  (if (= b 0)
      (abs a)
      (gcd b (remainder a b))))

;(mygcd -2 10)

(define(maxdevisor n)
  (define (helper a b)
    (if (= 0 (remainder a b))
        b
        (helper a (- b 1))))
    (helper n (- n 1)))

;(maxdevisor 21)

(define (sum-odds a b)
  (define (helper x y sum)
    (if (> x y)
        sum
        (helper (+ x 1) y (+ sum (* x (remainder x 2))))))
  (helper a b 0))

;(sum-odds 5 10)

(define (prime? n)
  (define (helper a)   
    (if (= 0 (remainder n a))
        (if ( = 1 a)
            #t
            #f)
        (helper (- a 1))))
  (helper (- n 1)))

;(prime? 19)

(define (count-deviders n)
  (define (helper num count)
    (cond[ ( = 0 num)             count]
         [(= 0 (remainder n num))  (helper (- num 1) (+ count 1)) ]
         [else (helper (- num 1) count)]))
  (helper (- n 1) 0))

;(count-deviders 30)


;(define (palindrobe n)
 ; (define (helper result remain)


;####################################################################  
(define (reverse-number n)
  (define (helper res k)
    (if (< k 10)
        (+ (* res 10) k)
        (helper (+ (* res 10) (remainder k 10))
                (quotient k 10))))
  (helper 0 n))

;(reverse-number 1234)

(define (return-palindrobe n)
  (define (helper res k)
    (if (<= k 0)
        res
        (helper (+ (* res 10) (remainder k 10)) (quotient k 10))))
  (helper 0 n))

;(return-palindrobe 1234)
    

;####################################################################  

(define (isPalindrobe? n)
  (if (= n (reverse-number n))
      #t
      #f))

;(isPalindrobe? 123221)

(define (count-palindromes a b)
  (define (helper x y count)
    (if (<= x y)
        (if (isPalindrobe? x)
            (helper (+ x 1) y (+ count 1))
            (helper (+ x 1) y count))
        count))
  (helper a b 0))

;(count-palindromes 1 9)






















    