#lang racket

(define (leaf tree)
  (null? (cdr tree)))

(define (twig tree)
  (and (not (leaf  tree)) (not (memv #f (map (lambda (x) (leaf x)) (cdr tree))))))

(define (stick tree)
  (if (leaf tree)
      #t
      (and (= 1 (length (cdr tree))) (stick (cadr tree)))))



;(stick '(1))                     ; => #t, single node is a stick
;(stick '(1 (2)))                 ; => #t, one child which is a leaf;
;(stick '(1 (2 (3))))             ; => #t, chain of single-child subtrees
;(stick '(1 (2 (3 (4)))))         ; => #t, longer chain
;(stick '(1 (2) (3)))             ; => #f, two children, not a stick
;(stick '(1 (2 (3)) (4)))         ; => #f, root has two children
;(stick '(1 (2 (3)) (4 (5))))     ; => #f, multiple children at root, some with children

(define (trim tree)
  (cons (car tree)
        (filter (lambda (x) (not (twig x)))
                (map trim (cdr tree)))))





