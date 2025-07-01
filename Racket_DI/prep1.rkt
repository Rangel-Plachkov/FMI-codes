#lang racket

;0
;(display "Hello, world!")



;1
;(min 10 15)

(define (my-min-if a b)
  (if (< a b)
      a
      b
  )
)

;(my-min-if 10 7)

(define (my-min-guard x y)
  (cond
    [(< x y) x]
    [else y]
    ))


(define (last-digit x)
  (remainder x 10))

;(last-digit 1567)

(define (quotient-whole n d)
  (quotient n d)
  )

;(quotient-whole 41 8)

(define (div-whole n d)
  (/ n d)
  )
;(div-whole 100 8)




;4

(define (factorial-rec n)
  (cond
    [(< n 0) "Invalid input"]
    [(= n 0) 1]
    [else (* n (factorial-rec (- n 1)))]
   ))

;(= (factorial-rec 0) 1)
;(= (factorial-rec 1) 1)
;(= (factorial-rec 11) 39916800)

(define (fact-iter n)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (* result leftover) (sub1 leftover))
        )
    )
  (if (negative? n)
      (error "n has to be non-negative")
      (helper 1 n)
      )
  )

;(= (fact-iter 0) 1)
;(= (fact-iter 1) 1)
;(= (fact-iter 11) 39916800)


#lang racket

(define (gcd x y)
  (cond
    [(= x 0) y]                           ; GCD(0, y) = y
    [(= y 0) x]                           ; GCD(x, 0) = x
    [else
     (define r (remainder x y))          ; x = A*y + r
     (gcd y r)]))                        ; GCD(x, y) = GCD(y, r)


