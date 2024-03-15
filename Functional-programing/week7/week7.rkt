#lang racket


;(define (diaonal-mat xs)
;(define (get-list-n count row n)
; (cond [ ( = null row) '()]
;      [ (= count n) (car row)]
;     [else (get-list-n (+ 1 count) (cdr row) n)]))
;(define (helper count matrix)
; (cond [(= null matrix) '()]
;      [else (cond (get-list-n 0 count (car matrix)))])))
;)



(define (mising-len xss)
  (define (minLen xs min)
    (cond [(equal? xs '()) min]
          [(> min (length (first xs))) (minLen (rest xs) (length (first xs)))]
          [else (minLen (rest xs) min)]))
  (define (maxLen xs min)
    (cond [(equal? xs '()) min]
          [(< min (length (first xs))) (maxLen (rest xs) (length (first xs)))]
          [else (maxLen (rest xs) min)]))
  (define MIN (minLen xss 9999999999999))
  (define MAX (maxLen xss 0))
  
  (define (sumator2 a b sum)
    (if (> a b)
        sum
        (sumator2 (+ 1 a) b (+ sum a))))
  
  (define suma (sumator2 MIN MAX 0))
  
  (define (substractLens xs sum)
    (cond [(equal? xs '()) sum]
          [else (substractLens (rest xs)  (- sum (length (first xs))))]))
  
  (substractLens xss suma))
  
  


(mising-len '( (1 2 3) (1 2) (1 2 3 4 5) (1 2 3 4 5 6)))
  
;(symbol? 8)

;'( (1 2 3) . (2 2 3))

;(take xs n) връща смисък от първите n елемента
;(drop xs n) Бръща xs без първите n елемента
