#lang racket

(define (++ x)
  (+ x 1))

(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a)
          (accumulate op nv (next a) b term next))))


(define (accumulate-i op nv a b term next)
  (if (> a b) nv
     (accumulate-i op (op nv (term a)) (next a) b term next)))


(define (id x)
  x)

(define (argmin f a b)
  (accumulate-i ( lambda(u i) (if (< (f u) (f i)) u i))
                a
                a b
                id ++))

(define (mod7 x) (modulo x 7))
;(argmin mod7 40 50)

;(mod7 49)


;(define (best-pair a b)
 ; (accumulate-i op nv
  ;              a b
   ;             term next))


