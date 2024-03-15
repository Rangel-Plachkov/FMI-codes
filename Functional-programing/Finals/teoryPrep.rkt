#lang racket



(cdr (cadr `((a (b)) ((c (d)) e))))
(cons`(a b) (list `c `((d) e)))
(append `(a (b c)) (caddr `((a b) c ((d) e))))
(list `(a b) (list `(c d)))


(define (scons a ll) (map (λ (x) (+ x a))  ll))
;(scons 10 `(1 2 3 4 5))

(map length
 (map (lambda (x)
 (cond [(not (pair? x)) (list x)]
 [(null? (cdr x)) x]
[else (cdr x)]))
 `((2 3 4) (8 5) 6 (7 1 –1 5) (1))))


