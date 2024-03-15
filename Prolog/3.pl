append([], L , L).
append([H|T], L ,[H|Res]):- append(T,L,Res).

partition(_, [] , [] , []).
partition(Pivot, [H|T], [H|SL], LL):- Pivot >= H , partition(Pivot, T, SL, LL).
partition(Pivot, [H|T], SL, [H|LL]):- Pivot < H, partition(Pivot, T, SL, LL).

quickSort([], []).
quickSort([pivot|L], ResL):- partition(pivot, L, ResSL, ResLL),
                            quickSort(ResLL,LL), 
                            quickSort(ResSL,SL), 
                            append(SL, [pivot|LL], ResL).

prefix([] , _).
prefix([H|L1] , [H|L2]):- prefix(L1, L2).

sufix(L1, L2):- append(_, L1, L2).

infix(L1, L2):- append(Curr, _, L2),append(_ ,L1, Curr).

member(X, [X|_]).
member(X, [H|L]):- member(X,L), H \= X.

isSubset([],_).
isSubset([H|T],L):- member(H , L), subset(T,L).


subsets([] , _).
subsets([_|T] , L):- subset(T,L).
subsets([H|T] , [H|R]):- subset(T,R).

n_elem(H, 1, [H|_]).
n_elem(X, Pos, [_|L]):-  n_elem(X ,Temp, L), Pos is Temp + 1.

in_union(X, A, B):- member(X, A); member(X, B).
in_intersection(X, A, B):- member(X, A), member(X, B).
in_diference(X, A, B):- member(X, A), \+ member(X, B).

is_subset_of(A, B):- not( ( member(X, A), \+ (member(X, B) ) ) ) .

p(L):- \+ ( member(A, L), member(B, L), A \= B, \+ (
        in_intersection(X, A, B),
         member(C, L), A \= C, C \= B,  ( \+ member(X, C)))). 

majors(X, Y):- isSubset(X, Y).

%append([],R,R).
%append([H|L],R,[H|Res]):- append(L,R,Res).

import(X, L, ResL):- append(A, B, L), append(A, [X|B] , ResL).
permutations([],[]).
permutations(L, ResL):-append(_,[H|_],L), import(H, L, ResL). 

isSorted([]).
isSorted([_]).
isSorted( [A,B|L]):- isSorted([B|L]), \+  (majors(B, A)).

majorSort(L,ResL):- permutations(L,ResL), isSorted(ResL).

%majorSort([[1,2],[1,2,3],[1,2,4]],X).



%mergeSort(A,B,ResL).
less(A,B):- A =<B.
more(A,B):- \+ (less(A,B)).
mergeSort([],B, B).
mergeSort(A,[], A).
mergeSort([A|T1],[B|T2],[A|Res]):- less(A,B), mergeSort(T1,[B|T2],Res).
mergeSort([A|T1],[B|T2],[B|Res]):- more(A,B), mergeSort([A|T1],T2,Res).


%mergeSort([1,2,3],[2,3,4],X)

substract([], _, []).
substract([H|T], L2, [H|Res]):- substract(T, L2, Res), not(member(H, L2)).
substract([H|T], L2, Res):- substract(T, L2, Res), member(H, L2).

reverse([],[]).
reverse([H|T], R):- reverse(T, W), append(W, [H], R).

div_gen(_, 0).
div_gen(X, Y):- div_gen(X, Z), Y is X + Z.

remove(X, L, Res):- append(L1, [X|L2],  L), append(L1, L2, Res).

%removeAll(X, L, Res).
removeAll(_, [], []).
removeAll(X, [X|L], Res) :- removeAll(X, L, Res).
removeAll(X, [Y|L], [Y|Res]) :- X \= Y , removeAll(X, L, Res).

removeDups([], []).
removeDups([Head|Tail], [Head|Res]) :- removeDups(Tail, Res),not(member(Head, Res)).
removeDups([Head|Tail], Res) :- removeDups(Tail, Res),member(Head, Res).





