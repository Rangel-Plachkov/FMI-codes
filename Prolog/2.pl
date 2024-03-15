isList([]).
isList([_|_]).

append1([] , L, L).
append1([H|T], L, [H|Res]):-append1(T, L, Res).

member2(X , L):-append(_, [X|_], L).

length2([] , 0).
length2([_|L] , Res):-length2(L, Prev), Res is Prev + 1.

reverse1(L ,RL):- rev(L, [], RL).
rev([], Stack , Stack).
rev([H|T] , Stack, R):- rev(T, [H|Stack], R).

isPalindrome(L):-reverse1(L, L).

insert(X, L, ResL):- append1(A, B, L),append1(A, [X|B] , ResL).

remove(X, L, ResL):-append1(A,[X|B],L),append1(A,B,ResL).

permutations([], []).
permutations([X|L], Perm):- permutations(L, Curr),insert(X, Curr, Perm).

isSorted([]).
isSorted([_]).
isSorted( [A,B|L] ):- isSorted([B|L]), B >= A.

sort1(L,Res):- permutations(L, Res),isSorted(Res).


simplestSort(L, SL):- permutations(L, SL), isSorted(SL).

