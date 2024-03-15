#lang racket

(define (sum-numbers a b)
  (define (deserting-number? number last)
    (cond [(< number 10) (>= number last)]
          [(< (remainder number 10) last) #f]
          
          [else (deserting-number? (quotient number 10) (remainder number 10)) ]))
  (define (helper c sum)
    (cond [(> c b) sum]
          [(deserting-number? c 0) (helper (+ c 1) (+ sum c))]
          [else (helper (+ c 1) sum)]))
  (helper a 0))


;(sum-numbers 219 225)

(define (num-bigger-elements lst)
  (define (bigger-count n xs count)
    (cond [(equal? xs null) count]
          [(> (car xs) n) (bigger-count n (cdr xs) (+ count 1))]
          [else (bigger-count n (cdr xs) count)]))
  
  (define (helper xs)
    (cond [(equal? xs null) '()]
          [else (cons (list (car xs) (bigger-count (car xs) lst 0)) (helper (rest xs)))]))
  
  (helper lst))

;(num-bigger-elements '(5 6 3 4)); → '((5 1) (6 0) (3 3) (4 2))
;(num-bigger-elements '(1 1 1)) ; '((1 0) (1 0) (1 0))


(define (switchsum f g n)
  (define (result x)
    (define (helper count sum prev)
      (cond [(= count n) sum]
            [(even? count) (helper (+ count 1) (+ sum (f prev)) (f prev))]
            [else          (helper (+ count 1) (+ sum (g prev)) (g prev))]))
    (helper 0 0 x))
  result)



;((switchsum (lambda (x) (+ x 1)) (lambda (x) (* x 2)) 1) 2) ;3
;((switchsum (lambda (x) (+ x 1)) (lambda (x) (* x 2)) 2) 2) ;9
;((switchsum (lambda (x) (+ x 1)) (lambda (x) (* x 2)) 3) 2) ;16
;((switchsum (lambda (x) (+ x 1)) (lambda (x) (* x 2)) 4) 2) ;30

;(define (repeater str)
 ; ( λ (count glue)
  ;   (define (helper c)
   ;    (cond [(= c count) " "]
    ;         [else (string-append str glue (helper (+ 1 c)))]))))

(define (repeater str)
  (λ (count glue)
    (define (helper c)
    (if (= c (- count 1))
        str
        (string-append str glue (helper (+ c 1)))))
    (helper 0))
  )


;((repeater "I love Racket") 3 " ")

(define (sum-sum-digits a b k)
  (define (sum-of-digits n)
    (define (helper num sum)
      (if (< num 10)
          (+ sum num)
          (helper (quotient num 10) (+ sum (remainder num 10)))))
    (helper n 0))
  (define (shoudAdd? num k)
    (if (= 0 (remainder (sum-of-digits num) k))
        #t
        #f))
  (define (helper c sum)
    (cond [(> c b) sum]
          [(shoudAdd? c k) (helper (+ c 1) (+ sum c))]
          [else (helper (+ c 1) sum)]))
  (helper a 0))

;(sum-sum-digits 10 15 3)
(require racket/trace)
(define (max-ordered-sublist lst)
  (define (find-pos maxPos currPos maxLen currLen lastNum counter xs)
    ;(trace find-pos)
    (cond [(> currLen maxLen)   (find-pos  currPos currPos currLen currLen lastNum counter xs)]
          [(equal? xs null) maxPos ]
          
          
          [(> lastNum (car xs)) (find-pos  maxPos  (+ counter 1) maxLen 1             0        (+ counter 1) (cdr xs)) ]
          [else                 (find-pos  maxPos  currPos       maxLen (+ currLen 1) (car xs) (+ counter 1) (cdr xs))]))
  
  (define position (find-pos 0 0 0 0 0 0 lst))
  (define (helper count xs)
    (if (< count position)
        (helper (+ count 1) (cdr xs))
        xs))
  (helper 1 lst))

;(max-ordered-sublist '(1 2 3 1 2 3 4 5))
;(max-ordered-sublist '(1 5 2 4 6 8 3 4 1)) 

;;;;fix 6

;(define(where list-elem list-predicates)
 ; (define (helper result count)
  ;  (cond [(equal? list-predicates null) '()]
   ;       [else (map (car list-predicates) list-elem)
          


;(sort '(1 5 2 6 8) <)


(define (set-union xs ys)
  (define (remove-duplicates ls lastNumber)
    (cond [(equal? ls null) '()]
          [(equal? (car ls) lastNumber) (remove-duplicates (cdr ls) (car ls))]
          [else (cons (car ls) (remove-duplicates (cdr ls) (car ls)))]))
  (remove-duplicates (sort (append xs ys) <) #f))


;(set-union '(1 3 5 7) '(5 7 13))
;(set-union '(5 7 13) '(1 3 5 7))
  





;(eq? '(1) 1)














