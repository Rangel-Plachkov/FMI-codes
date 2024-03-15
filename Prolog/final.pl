member2(X, [X|_]).
member2(X, [H|T]):- X \= H, member2(X,T).
append2([], B, B).
append2([H|T], L, [H|Res]):- append(T, L, Res).

%%%%%%https://github.com/YanaRGeorgieva/Logic-programming/blob/master/.
comp1([A,B], [B,C], [A,C]).
comp1L([_,_], [], []).
comp1L([A,B], [[B,C]|T], [[A,C]|Res]):- comp1L([A,B] , T, Res).
comp1L([A,B], [[N,_]|T], Res):- B \= N , comp1L([A,B] , T, Res).
comp([], _, []).
comp([H|T], L2 , X):- comp1L(H, L2, New) , comp(T, L2, Res), append2(New, Res, X).

isSubset([], _).
isSubset([H|T], L2):- member(H, L2), isSubset(T, L2).
areEquals(A,B):- isSubset(A,B), isSubset(B,A).

leftHalf(R1, R2, Res):- comp(R2, R1, Temp), comp(R1, Temp, Res).
rigtHalf(R1, R2, Res):- comp(R2, R1, Temp), comp(Temp, R2, Res).
sameComp(R1,R2):- leftHalf(R1,R2,Left), rigtHalf(R1,R2,Rigth), areEquals(Left, Rigth).
%areEquals([1,2,3,4,5], [3,2,1,5,2,3,4]).

%comp1L([1,4], [[4,1],[4,7],[3,1]], X).

%comp([[1,2],[1,4],[2,3],[3,4]], 
%    [[4,1],[4,7],[3,1]], X).
% [1,1], [1,7], [3,1], [3,7], [2,1]


%comp1([H|T], L, R).

%%%%%%

insert(X, [], [X]).
insert(X, L, Res):- append(A, B, L), append(A, [X|B], Res).
permutations([],[]).
permutations([H|T], ResL):-  permutations(T, Res) , insert(H, Res, ResL).

isSorted([]).
isSorted([_]).
isSorted([A,B|T]):- B >= A, isSorted([B|T]).

simpleSort(L, ResL):- permutations(L, ResL), isSorted(ResL).

printEven([],[]).
printEven([_], []).
printEven([_,B|T], [B|Res]):- printEven(T, Res).

%%%%%%

neighbor(E,A,X):- member([A,X],E).
neibourList([], _, []).
neibourList([[A,B]|T], A, [B|Res]):- neibourList(T, A, Res).
neibourList([[B,_]|T], A, Res):- neibourList(T, A, Res), B \= A.

pathLenK(_, A, A, 0).
pathLenK(E, A, B, N):-
    N > 0, N1 is N - 1,
    neighbor(E,A,X),
    pathLenK(E, X, B, N1).

subSetAdd(X, [], [X]).
subSetAdd(X, A, A):- member(X,A).
subSetAdd(X, A, [X|A]):- not(member(X,A)).
getV([],[]).
getV([[A,B]|T], Res):- getV(T, Temp1),subSetAdd(A, Temp1, Temp2), subSetAdd(B, Temp2, Res). 

k-ver(_, _, [], _).
k-ver(E, A, [H|T], K):- pathLenK(E, A, H, K), k-ver(E,A,T,K).

k-verAll(_, [], _).
k-verAll(E, [H|T], K):- k-verAll(E,T,K),neibourList(E,H,L),k-ver(E,H,L,K).

k-raf(E, K):- getV(E, V), k-verAll(E, V, K).
%[[1,2],[2,3],[3,4],[1,3],[4,2]]

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:-use_module(library(clpfd)).

isOdd(N):- N mod 2 #= 1.
isPrime(N):- N #> 1 , not(( N #= A*B, A #> 1, B #> 1, A #< N, B #< N, label([A,B]) )).
isSmall(N):- N #< 10, N #> 0.

findSmallOddPrime(L,Res):- findall(A, (member(A, L), isPrime(A), isSmall(A), isOdd(A)), Res).

subset2(A,B):- forall( member(X,A), member(X,B) ).

%findSmallOddPrime([1,2,3,5,8,7,13,21,100,22],X).
%findall(P, (P in 0..1000, label([P]), isPrime(P)), X).

path(E,A,B,P):- path(E,A,B, [], P1), reverse(P1, P).
path(_,A,A,Vis, [A|Vis]).
path(E,A,B,Vis,P):- 
    neighbor(E,A,C), 
    not(member(C,Vis)),
    path(E,C,B,[A|Vis],P).



nat(0).
nat(N):- nat(M),N is M + 1.

range(A,A,[A]).
range(A,B,[A|Res]):- C is A + 1 ,range(C,B,Res).

range2(A, A, [A]).
range2(A, B, [A|R]):- A < B, A1 is A + 1, range(A1, B, R).


%genKS(1, S, [S]).
%genKS(K, S, [XI|Result]):- K > 1, K1 is K - 1, 
%	between(0, S, XI), S1 is S - XI, genKS(K1, S1, Result).

between2(A,A,A).
between2(A,B,X):- N #= A + 1, between2(N,B,X).
between2(A,B,X):- N #= B - 1, between2(A,N,X).

isPr2(N):- N #> 1, not((N #= A*B, A #>1 ,B#>1, A #< N, B #<N, label([A,B]))).

toSubset([], []).
toSubset([H|T], Res):- toSubset(T,Res),member(H, Res).
toSubset([H|T],[H|Res]):- toSubset(T, Res), not(member(H,Res)).

isList([]).
isList([_|_]).

flat([],[]).
flat([H|T], Res):- isList(H), flat(T, Temp), append(H, Temp, Res).
flat([H|T], Res):- not(isList(H)), flat(T, Temp), append([H], Temp, Res).