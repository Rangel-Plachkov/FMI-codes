#lang racket

(define my-sublists
  '((1)
    (1 2)
    (1 2 3)
    (1 2 3 4)
    (2)
    (2 3)
    (2 3 4)
    (3)
    (3 4)
    (4)))


(define (maxByLength ls)
  (foldr (lambda (newL currL)
           (if (> (length newL) (length currL))
               newL
               currL))
         '()  
         ls))

(maxByLength my-sublists)