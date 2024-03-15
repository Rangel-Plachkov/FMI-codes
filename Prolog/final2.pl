

pathK(_, A, A, 0).
pathK(E, A, B, N):- 
    N > 0, N1 is N - 1,
    member([A,C], E),
    pathK(E,C,B,N1).

%[[1,2],[2,3],[3,4],[1,3],[4,2]]

path(E, A, B, P):- path(E, A, B, [], P1), reverse(P1, P).
path(_, A, A, Vis, [A|Vis]).
path(E, A, B, Vis, P):- 
    member([A,C],E),C \= A,
    not(member(C, Vis)),
    path(E, C, B, [A|Vis], P).

reverse2(L1, L2):- reverse2(L1, [], L2).
reverse2([], L2, L2).
reverse2([H|T], St, L2):- reverse2(T, [H|St], L2).

neibour(E, A, X):- member([A,X],E);member([X,A],E).