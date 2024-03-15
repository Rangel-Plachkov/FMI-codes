#lang racket
;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (size-of-number n)
  (define (helper a count)
    (if (= 0 a)
      count
      (helper (quotient a 10) (+ count 1))))
  (helper n 0))


(define (pow x n)
  (define (helper result steps)
    (if (= steps n)
        result
        (helper (* result x) (+ steps 1))))
  (helper 1 0))



(define (substr? a b)
  (define (helper subB size)
    (cond  [(< subB a) #f]
           [(= a (remainder subB size)) #t]
           [else (helper (quotient subB 10) size)]))
  
  (helper b (pow 10 (size-of-number a))))



;(substr? 123 888123888)

(define (my-identity x) x);
;(my-identity 10)

(define (my-compose f g)
  (λ(x) (f (g x))))

;((my-compose (λ (x) (* x 2)) (λ (x) (+ x 5))) 7)
;((my-compose (λ(x) (+ x 1)) (λ(x) (* x 3))) 7)

(define (my-negate p?)
  (λ(x) (not (p? x))))

;((my-negate (λ(x) (odd? x))) 14)

;;;;;;;;;;;;
(define (my-curry f x)
  (λ (y z) (f x y z)))

(define (difference F a b)
  ( - (F a) (F b)))

(define (mul3 n)
  (* n 3))
  
;(difference  (λ(x) (* x 3)) 10 5)
;(difference (λ (x) (* x 2)) 5 2)

(define (f x) (* 2 x))
;(f 10)
;(define f-2 (λ(x) (* 2 x)))
;(f-2 10)

(define (derive f eps)
  (λ(x) ( / ( - (f (+ x eps))(f x)) eps)))


(define (h x) (* 2 x x))

;((derive h 1e-4) 1)
;((derive f 1e-4) 1)

(define (derive-n f n eps)
  (if (= n 0)
      f
      (derive (derive-n f (- n 1) eps) eps)))

;((derive-n h 0 1e-3) 5)

(define (make-pair a b)
  (λ (x) (if x a b)))

(define (one p)
  (p #t))

(define (two p)
  (p #f))

(define p1 (make-pair 1 2))
(one p1)
(two p1)
    