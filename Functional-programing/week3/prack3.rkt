#lang racket

(require racket/trace)

(define (prime? n)
  (define (helper a)   
    (if (= 0 (remainder n (- a 1)))
        (if ( = 1 (- a 1))
            #t
            #f)
        (helper (- a 1))))
  (helper n))

(define (sum-of-prime-dividors n)
  (define (helper counter sum)
    (if (> counter n)
        sum
        ( if (and (prime? counter) (= 0 (remainder n counter)))
             (helper (+ counter 1) (+ sum counter))
             (helper (+ counter 1) sum))))
    (helper 2 0))

;(sum-of-prime-dividors 26)

(define (pow x n)
  
  (define (helper result steps)
    (if (= steps n)
        result
        (helper (* result x) (+ steps 1))))
  (helper 1 0))

;(pow 2 10)

(define (count-occuurences d n)
  (define (helper remaining count)
    (if (< remaining 10)
        (if (= d remaining)
            (+ 1 count)
            count)
        (if (= d (remainder remaining 10))
               (helper (quotient remaining 10) (+ count 1))
               (helper (quotient remaining 10) count))))
  ;(trace helper)
  (helper n 0))


;(count-occuurences 1 101)

(define (ascending? n)
  (define (helper remaining lastNumber)
    (if (< remaining 10)
        (if (>= lastNumber remaining)
            #t
            #f)
        (if (>= lastNumber (remainder remaining 10))
            (helper (quotient remaining 10) (remainder remaining 10))
            #f)))
  (helper n 10))

;(ascending? 12335334)

(define (perfect-number? n)
  (define (helper count sum)
    (if (> sum n)
        #f
        (if (>= count n)
            (if (= sum n)
                #t
                #f)
            (if (= 0 (remainder n count))
                (helper (+ count 1) (+ sum count))
                (helper (+ count 1) sum)))))
  (helper 1 0))

;(perfect-number? 500)

(define (calc-sum x n)
  (define (helper counter result)
    (if (> counter n)
        result
        (helper (+ counter 1) ( + result (pow x counter )))))
  (helper 0 0))

;(calc-sum 2 8)

(define (calc-sum2 x n)
  (define (helper sum count previous)
    (define next (* previous x))
    (if (= count n)
        sum
        (helper (+ sum next)  (+ count 1) next)))
  (helper 0 0 1))

;(calc-sum 2 9)
;Ctrl + \  -> λλλλ

















    