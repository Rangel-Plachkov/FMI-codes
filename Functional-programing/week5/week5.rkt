#lang racket

;(cons 1 2)
;'(1 . 2)

(define (count xs)
  (if (empty? xs)
      0
      (+ 1 (count (rest xs)))))
;(count '(1 2 3 4))

(define (in? xs f)
  (cond [(empty? xs) #f]
        ;[(= f (first xs)) #t]
        ;[(eq? f (first xs)) #t]
        [(equal? f (first xs)) #t]
        [else (in? (rest xs) f)]))
;(in? '(1 2 3 4) 10)

(define (find-smallest xs) 
  (define (helper restXS smallest)
    (cond [(empty? restXS) smallest]
          [(> smallest (first restXS)) (helper (rest restXS) (first restXS))]
          [else (helper (rest restXS) smallest)]))
  (if (empty? xs)
      #f
      (helper (rest xs) (first xs))))


;(find-smallest '(9 5 3 6 7 2 8))

;(min 10 5 6 7)
;(apple min '(43 61 7 23 7))

(define (reverce-list xs)
  ;(if (empty? xs)
   ;   '()
    ;  (cons (last xs)) (first xs) ))
      

;(reverce-list '(1 2 3))