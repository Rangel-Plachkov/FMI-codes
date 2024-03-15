#lang racket

(define (triangular? mat)
  (define matSize (length mat))
  (define (checkAllZero? xs)
    (cond [(equal? xs null) #t]
          [(not (zero? (car xs))) #f]
          [else (checkAllZero? (cdr xs))]))

  (define (helper count xs)
    (cond [(equal? xs null) #t]
          [(checkAllZero? (take (car xs) count)) (helper (+ count 1) (cdr xs))]
          [else #f]))
  (helper 0 mat))


;(triangular? '((1 1 1) (0 0 0) (0 0 0)))     
;(triangular? '((1 2 3) (0 5 6) (0 0 9)))
;(triangular? '((0 2 3)(0 0 6)(1 0 0))) 
;(triangular? '((1 2 3)(1 5 6)(0 0 9)))
;(triangular? '((1 2 3 4)(0 5 6 7)(0 0 8 9)(0 0 0 9))) ;




(define (shuffle xs)
  (define (takeEven remxs count)
    (cond [(equal? remxs null) '()]
          [(even? count) (cons (car remxs) (takeEven (cdr remxs) (+ count 1)))]
          [else (takeEven (cdr remxs) (+ count 1))]))
  
  (define (takeOdd remxs count)
    (cond [(equal? remxs null) '()]
          [(odd? count) (cons (car remxs) (takeOdd (cdr remxs) (+ count 1)))]
          [else (takeOdd (cdr remxs) (+ count 1))]))

  
  (append (takeEven xs 0) (takeOdd xs 0))
  ;(append (takeOdd xs 0)  )
  ;(append (takeEven xs 0) )
  )

;(shuffle '(2 5 1 3 4 7))
;(shuffle '(1 2 3 4 4 3 2 1))


(define (shuffle2 xs)
  (define lenXs (length xs))
  (define n (quotient lenXs 2))
  (define as (take xs n))
  (define bs (drop xs n))
  (define (helper count as bs)
    (if (= n count)
        '()
        (cons (car as) (cons (car bs) (helper (+ count 1) (cdr as) (cdr bs))))
     )
    )
  (helper 0 as bs))

;(shuffle2 '(2 5 1 3 4 7))
;(shuffle2 '(1 2 3 4 4 3 2 1))
;(shuffle '(1 1 2 2)) 


(define (kth-max-min xs)
  ;(define negS (takef xs negative?))
  
  (define (takef3 xs f)
    (define (helper rs)
      (cond [(equal? rs '()) '()]
            [(f (car rs)) (cons (car rs) (helper (cdr rs)))]
            [else (helper (cdr rs))]))
    (helper xs))
  
  (define negS (takef3 xs negative?))
  
  (define sortNedS (sort negS >))
  (λ (x)
    (define (getPos c rs)
         (if (= c x)
             (car rs)
             (getPos (+ c 1) (rest rs))))
  (getPos 1 sortNedS)))
  

;((kth-max-min '(1 2 3 4 -5 6 7 -2 -1 0)) 2)

(define (dig-pow n p)
  (define (converter n)
    (define (helper rem)
      (cond [(< rem 10) (cons rem '())]
            [else (cons (remainder rem 10) (helper (quotient rem 10)))]))
    (reverse (helper n)))
  
  (define (sumator xs p)
    (define (helper remXS sum count)
      (cond [(equal? remXS null) sum]
          [else (helper (cdr remXS) (+ sum (expt (car remXS) count)) (+ count 1))]))
    (helper xs 0 p))
  
  (define convertedLS (converter n))
  (define result (sumator convertedLS p))
  (if (= 0 (remainder result n))
      (quotient result n)
      -1))



;(dig-pow 89 1)
;(dig-pow 92 1)
;(dig-pow 695 2)
;(dig-pow 46288 3)







