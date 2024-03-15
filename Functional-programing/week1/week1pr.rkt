(define (mymin a b)
  (if (< a b)
      a
      b))
;(mymin 4 7)

(define (inside? x a b)
  (if (and (>= x a)(<= x b))
      1
      0))

;(inside? 5 6 8)

(define (sqr1 x)
  (* x x))

;(sqr1 10)

(define (myfib n)
  (define (helper a b n)
    (if (= n 0)
        b
        (helper b (+ a b) (- n 1))))
  (helper 0 1 n))

;(myfib 1)

(define (myfact n)
  (define (helper a pow)
    (if (= a 1)
        pow
        (helper (- a 1) (* pow a))))
  (helper n 1))

;(myfact 5)

(define (fib-iter n)
  (define (helper prev cur i)
    (if (= i n)
        cur
        (helper cur (+ prev cur) (+ i 1))))
  (helper 1 0 0))
;(fib-iter 500)
   
         




    
    
        
