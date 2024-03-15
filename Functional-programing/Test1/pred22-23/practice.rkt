#lang racket

(define (next-pali n)
  (define (reverce-num n)
    (define (helper rem res)
      (if (< rem 10)
          ( + (* res 10) rem)
          (helper (quotient rem 10) ( + (* res 10) (remainder rem 10))   )))
    (helper n 0))
  (define (isPalindorme? n)
    (= n (reverce-num n)))
  (define (helper next)
    (if (isPalindorme? next)
        next
        (helper (+ next 1))))
  (helper (+ 1 n))
  )


;(next-pali 808)
;(next-pali 2133)
;(next-pali 5645)
;(next-pali 2863)
;(next-pali 99)
;(next-pali 4224)
;(next-pali 2222)

(define (alt-split xs)
  (define (getEven xs)
    (define (helper xs count)
      (cond [(empty? xs) '()]
            [(even? count) (cons (car xs) (helper (cdr xs)(+ count 1)))]
            [else (helper (cdr xs)(+ count 1))]))
    (helper xs 1))
  (define (getOdd xs)
    (define (helper xs count)
      (cond [(empty? xs) '()]
            [(odd? count) (cons (car xs) (helper (cdr xs)(+ count 1)))]
            [else (helper (cdr xs)(+ count 1))]))
    (helper xs 1))
  (list (getOdd xs)(getEven xs)))
          



;(alt-split '(1 2 3 4 5))


(define (intersect xs ys)
  (define (f x l)
    (if (empty? (filter ( λ(y) (= x y)) ys))  l   (cons x  l)) 
  )
  (foldr f '()  xs)
)

;(intersect '(1 2 3) '(4 5 6 1 2))



(define (get-dist p)
  (define (dist a b)
    (+ (abs (- (car a) (car b))) (abs (- (cdr a) (cdr b)))))
  (define A '(0 . 0))
  (define B '(a . b))
  ;(define len ( / (dist A B) 2) )
  (car p))
  ;'( (/ (car p) 2) . (/ (cdr p) 2)))

(get-dist '(49 . 3))
    



















  
