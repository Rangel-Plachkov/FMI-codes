#lang racket

;(string? 'abw)

;(cdr (cadr '((a (b)) ((c (d)) e))))
;(cdr '((a (b)) ((c (d)) e)))
;(cons '(a b) (list 'c '((d) e)))
;'( (a b) c ((d)e))
;(append '(a (b c)) (caddr '((a b) c ((d) e))))
;'(a (b c) (d) e)
;(append '(a '(b c)))
;(list '(a b) (list '(c d)))
;'( (a b) (c d))
;(list 'a  '(b c)) 


(define (atom? a)
  (not (list? a)))

(define (count-atoms xs)
  (define (helper remXs count)
    (cond [(empty? remXs) count]
          [(atom? (car remXs)) (helper (cdr remXs) (+ count 1))]
          [else (helper (cdr remXs) (+ count (helper (car remXs) 0) ))]))
  (helper xs 0))

;(count-atoms '((1 2 3) 2 (2 (3)) 4 5))

;(foldr cons ’() ’(1 2 3 4)) ──> (1 2 3 4)
;(foldl cons ’() ’(1 2 3 4)) ──> (4 3 2 1)


(define (list-filter f xs)
  (cond [(empty? xs) null]
        [(f (car xs)) (cons (car xs) (list-filter f(cdr xs)))]
        [else (list-filter f (cdr xs))]))

;(list-filter odd? '(1 2 3 4 5))

;(pair? '('() '() ))
(define (task4)
(map length
     (map (lambda (x)
            (cond [(not (pair? x)) (list x)]
                  [(null? (cdr x)) x]
                  [else (cdr x)]))
            '((2 3 4) (8 5) 6 (7 1 –1 5) (1))
     )
 ))
;(task4)

(define (scons a ll) (map (λ(x) (cons a x)) ll))

;(scons 'a '((1) (2) (3) (4 5)))


;(eq? (expt 2 100) (expt 2 100))


;(eq? "a" "a")

(define x 10)
(define y 10)
(define z 10)

;( (λ(x y z) (+ x y z)) (+ x y) (* y 0) (- z 3)) 


(define (where list-elements list-predicates)
  (define (check x lps)
    (cond [(empty? lps) #t]
          [(not ((car lps) x)) #f]
          [else (check x (cdr lps))]))
  (cond [(empty? list-elements) '()]
        [(check (car list-elements) list-predicates) (cons (car list-elements)
                                                           (where (cdr list-elements) list-predicates))]
        [else (where (cdr list-elements) list-predicates)]))


;(where '(3 4 5 6 7 8 9 10) (list even? (lambda (x) (> x 5))))
;(where '(3 4 5 7) (list even? (lambda (x) (> x 5))))






