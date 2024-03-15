parent(ana,bob).

ansestor(X,Y) :- parent(X,Y).
ansestor(X,Y) :- parent(X,Z), ansestor(Z,Y).

add(X , L , list(X,L)).

member(X, [X|_]).
member(X, [_|L]):-member(X,L).

last(X, [X]).
last(X, [_|L]):-last(X, L).

prefix([], _).
prefix([X|_] , [X|_]).

append([], L2 , L2).
append([H|L1], L2, [H|R]):-append(L1,L2,R).


less(A,B):- A < B.

sumList([], 0).
sumList([x|L], sum):- sumList(L,M), sum is x + M. 


%smallest([X] , X).
%smallest([A|L] , Res).

smallest(L, Res):- member(Res, L),  \+ ( member(A, L), A < Res ).


lesser(A, B, A):- A < B.

min2(X, [X]).
min2(X, [H|T]):- min2(M, T), lesser(H, M, X).
%Ако H e по-голямо никога няма да бъде истина!!!!!!!!!!
min3(X, [X]).
min3(H, [H|T]):- min3(M, T), H < M.

max2(X, [X]).
max2(X, [H|T]):- max2(M, T), \+ lesser(H, M, X).



div(_ , Y) :- Y =:= 0.
div(A, B) :-  B >= A , div(A, B-A).


div2(_ , 0).
div2(A , B):- B >= A , Temp is B - A , div2(A, Temp).

div2(_ , 0).
div2(A , B):- B >= A  , div2(A, B-A).














