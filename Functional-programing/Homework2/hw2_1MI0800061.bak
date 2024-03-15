#lang racket

;;############################ЗАДАЧА 1##################

(define (pair-compose fs xs)
  ( λ(y)
     (define (helper remFs remXs value)
       (cond [(empty? remFs) value]
             [(= 1 (length remFs))  (helper (cdr remFs)  (cdr remXs)  (+ value ( (car remFs)(car remXs) ((λ(z) z)     y)) )) ]
             [else                  (helper (cddr remFs) (cddr remXs) (+ value ( (car remFs)(car remXs) ((cadr remFs) (cadr remXs) y)) ))]))
     (helper fs xs 0)))

(define fs (list *
                 (λ (x y) (* x x x y))
                 (λ (x y) (+ x 1 y))
                 (λ (x y) (- x (+ 1 y)))
                 (λ (x y) (* x y 2))))

(define xs '(1 2 3 4 5))
;((pair-compose fs xs) 5)







;;#########################ЗАДАЧА 2###############################

(define (woodcutters xs)
  (define (helper remXs value lastOcup)
    (cond [(empty? remXs) value]
          [(not lastOcup) (helper (cdr remXs) (+ value 1) (caar remXs))]
          [(> (- (caar remXs) (cdar remXs)) lastOcup) (helper (cdr remXs) (+ value 1) (caar remXs))]
          [(empty? (cdr remXs)) (helper (cdr remXs) (+ value 1) #f)]
          [(< (+ (caar remXs) (cdar remXs)) (caadr remXs)) (helper (cdr remXs) (+ value 1) (+ (caar remXs) (cdar remXs)))]
          [else (helper (cdr remXs) value (caar remXs))]))
  (helper xs 0 #f)
)
;(woodcutters '((1 . 2) (2 . 1) (5 . 10) (10 . 9) (19 . 1)))
;(woodcutters '((1 . 2) (2 . 1) (5 . 10) (10 . 9) (20 . 1))) 
;(woodcutters '((10 . 4) (15 . 1) (19 . 3) (20 . 1)))

(define woodTest '((1 . 7)  (3 . 11)  (6 . 12) (7 . 6)  (8 . 5)  (9 . 11) 
               (15 . 3) (16 . 10) (22 . 2) (23 . 3) (25 . 7) (27 . 3)
               (34 . 5) (35 . 10) (37 . 3) (39 . 4) (40 . 5) (41 . 1) 
               (44 . 1) (47 . 7)  (48 . 11)(50 . 6) (52 . 5) (57 . 2)
               (58 . 7) (60 . 4)  (62 . 1) (67 . 3) (68 . 12)(69 . 8)
               (70 . 1) (71 . 5)  (72 . 5) (73 . 6) (74 . 4) ) )
;(woodcutters woodTest) ;-> 10
                            



;Първото ми решение с 2^n сложност
(define (woodcutters0 xs)
  ;xs
  (define (evaluatePath goLeft? value remXS lastOcup)
    (cond [(empty? remXS) value]
          [goLeft? (define curr (car remXS))
                     (if (> (- (car curr) (cdr curr)) lastOcup)
                         (max (evaluatePath #t (+ value 1) (cdr remXS) (car curr)) (evaluatePath #f (+ value 1) (cdr remXS) (car curr)))
                         (max (evaluatePath #t value (cdr remXS) lastOcup)         (evaluatePath #f value (cdr remXS) lastOcup)))]
          [(not goLeft?) (define curr (car remXS))
                           (define contestPos (+ (car curr) (cdr curr)))
                     (if (and (> (car curr) lastOcup) (or (empty? (cdr remXS))  (< contestPos (car (cadr remXS)))))
                         (max (evaluatePath #t (+ value 1) (cdr remXS) contestPos) (evaluatePath #f (+ value 1) (cdr remXS) contestPos))
                         (max (evaluatePath #t value (cdr remXS) (car curr))         (evaluatePath #f value (cdr remXS) (car curr))))]))
  
  (max (evaluatePath #t 0 xs -99999999999999999) (evaluatePath #f 0 xs -99999999999999999))  ;;Може да се направи с #f 
)






