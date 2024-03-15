nat(0).
nat(N) :- nat(M), N is M + 1.
range(A,B,C) :- nat(C), C >= A, B >= C.

cons([], []).
cons([[A,B]|T], [A,B|Res]) :- cons(T, Res). 

removeDups2([], []).
removeDups2([Head|Tail], [Head|Res]) :- removeDups2(Tail, Res),not(member(Head, Res)).
removeDups2([Head|Tail], Res) :- removeDups2(Tail, Res),member(Head, Res).

getV(E,V) :- cons(E, Temp), removeDups2(Temp, V).

neibour([_,E], A, B) :- member([A,B],E).

%path(G, A, B, P).
path(G, A, B, P) :- path(G, A, B, [], PR), reverse(PR, P).
path(_, A, A, Visited, [A|Visited]).
path(G, A, B, Visited, P) :- neibour(G, A, Next), not(member(Next, Visited)), path(G, Next, B, [A|Visited], P).


cycle([V,E],P) :- member([A,B],E), A \= B, path([V,E], B, A, Curr), append([A,B], Curr,P).




%Etest = [[1,2],[3,4],[1,3],[4,5],[5,2]].
%Gtest = [[1,2,3,4,5],[[1,2],[2,3],[3,4],[1,3],[4,5],[5,2]]]
%G2 = [[1,2],[[1,2][1,2]]]
%path([[a,b,c,d,e,g],[[a, b], [b, c], [c, e], [e, a], [g, a]]], a, c, P).
%[[1,2,3,4,5,5],[[1,2],[2,3],[3,4],[1,3],[4,5],[5,2]]]

connected(V,E) :- not(( member(A, V), member(B, V), A \= B, not(path([V,E], A , B, _)))).

append([], L2, L2).
append([Head|Tail], L2, [Head|Res]) :- append(Tail, L2, Res).

import(X, L, Res) :- append(A, B, L),  append(A, [X|B], Res).

permutations([], []).
permutations([H|T], Res) :- permutations(T, Curr),import(H, Curr, Res).

hamiltonian_path(V, E, Curr) :- permutations(V, Curr), path([V,E], _, _, Curr).

