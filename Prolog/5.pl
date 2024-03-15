:- use_module(library(clpfd)).

prime(P) :- P #>= 2, not((K #>= 2, K #< P, P #= K * M, label([K, M]))).

neibour([_,E], A, B) :- member([A,B], E), A \= B.

path([V,E], A, B, P) :- path([V,E], A, B, [], RP), reverse(RP, P). 
path(_, A ,A, Visited, [A|Visited]).
path([V,E], A, B, Visited, P) :- neibour([V,E], A, Next), not(member(Next, Visited)), path([V,E], Next, B,[A|Visited], P).

append([], L2, L2).
append([H|L], L2, [H|Res]) :- append(L, L2 ,Res).
insert(X, L, Res) :- append(A, B, L),append(A, [X|B], Res).
permutations([],[]).
permutations([H|T], Res) :- permutations(T, Curr), insert(H, Curr, Res).
last([X],X).
last([_|L],X) :- last(L, X).
first([X|_],X).
hamiltonPath([V,E], P) :- permutations(V, P),path([V,E],_,_,P).
hamiltonCycle([V,E],C) :- hamiltonPath([V,E],P),first(P, First),last(P,Last),member([Last,First], E),append(P, [First],C).


isEven(X) :- X #= 2*_. 

%[[1,2,3],[[1,2],[2,3],[3,1]]]

split([], [], []).
split([H|T], [H|L], R) :- split(T,L,R).
split([H|T], L, [H|R]) :- split(T,L,R).

removeDups([], []).
removeDups([H|T], [H|Res]) :- removeDups(T, Res), not(member(H, Res)).
removeDups([H|T], Res) :- removeDups(T, Res), member(H, Res).
