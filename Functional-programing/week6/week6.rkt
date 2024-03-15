#lang racket


(define (count-ocurunces xs subX)
  (cond [(empty? xs) 0]
        [(= (first xs) subX) (+ 1 (count-ocurunces (rest xs) subX))]
        [else (count-ocurunces (rest xs) subX)]))

;(count-ocurunces '(1 2 3 2 3 4) 3)

(define (count-ocuruncesList xs subXs)
  (define (subL? master slave)
    (cond [(empty? slave) #t]
          [( or (empty? master) ( not (=  (first master) (first slave))))  #f]
          [else (subL? (rest master) (rest slave))]))
  (cond [(empty? xs) 0]
        [(subL? xs subXs) (+ 1 (count-ocuruncesList (rest xs) subXs))]
        [else (count-ocuruncesList (rest xs) subXs)]))
                          
;(count-ocuruncesList '(1 2 3 1 2 3 1 2 3 1) '(1 2 3 4))


        
(define (fllaten xs)
  (if (or (not (list? xs)) (empty? xs))
      xs
      (cons (first xs) (flatten xs))))



;(fllaten '(1 2 3 (4 5 () ( 6 7 8) 5 ( 7))))
;(append '(1 2 3 (4 5 () ( 6 7 8) 5 ( 7))))
;(flatten 7)

(define (deep-delete xs)
  (define (helper level restXS)
    (cond [(empty? restXS) '()]
          [ (< (first restXS) level) (helper (+ 1 level) (rest(restXS))) ]
          [else (cond (first restXS) (helper (+ 1 level) (rest(restXS)) ))]))
  (helper 0 xs))
;(deep-delete '(1 2 3 (0 0 () ( 6 7 8) 5 ( 7))))

          