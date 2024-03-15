#lang racket

(define (get-distribution n)
  (define n2 (* n n))
  (define (ocur digit)
    (define (helper rem count)
      (cond [(= rem 0) count]
            [(= (remainder rem 10) digit) (helper (quotient rem 10) (+ count 1))]
            [else (helper (quotient rem 10) count)]))
    (if  (and (= 0 digit) (= n2 0))
         1
         (helper n2 0)))
  (define (result digit)
    (cond [(= digit 10) '()]
          [(= (ocur digit) 0) (result (+ digit 1))]
          [else (cons (cons digit (ocur digit)) (result (+ digit 1)))]))
  (result 0))


;(get-distribution 100)

(define (trailing-zero n)
  (define (get-zeroes n)
    (define (helper k sum)
      (if (> k n)
          sum
          (helper (+ k 1) (+ sum (quotient n (expt 5 k))))))
    (helper 1 0))
     
  (λ (p) (p (get-zeroes n)))
  )
;((trailing-zero 10000) even?)

(define (persistence n)
  (define (mult-digit number)
    (define (helper mult rem)
      (if (< rem 10)
          (* rem mult)
          (helper (* mult (remainder rem 10)) (quotient rem 10))))
    (helper 1 number))
  (define (first-elem num)
    (define (helper curr)
      (if (< (mult-digit curr) 10)
        (cons (mult-digit curr) '())
        (cons (mult-digit curr) (helper (mult-digit curr)))))
    (helper num))

  
  (define ys (first-elem n))
  
  ;ys)
  (cons  ys (length ys)))

;(persistence 39)
;(persistence 126)
;(persistence 4)
;(persistence 999)

















