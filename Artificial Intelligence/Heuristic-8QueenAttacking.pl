% [6,1,5,7,4,3,8,1].

:-dynamic(hval/1).

/* Evaluates a 8-queens' state given as list of 8 digits */

evalState(L,V):- assert(hval(0)),hl(1,L), di_up(1,L),di_dn(1,L),hval(V),
                 retractall(hval(_)).

hl(8,_):-!.
hl(I,L):- nthel(I,L,X), chk_incr(I,L,X), I1 is I+1, hl(I1,L).

chk_incr(8,_,_):-!.
chk_incr(I,L,X):- I1 is I+1, nthel(I1,L,Y),
                                       do_incr(X,Y),chk_incr(I1,L,X).
do_incr(X,Y):- X=Y, incr_hval.
do_incr(_,_).

incr_hval:-hval(V), V1 is V+1, retract(hval(_)), assert(hval(V1)).

% =========================================================================

di_up(8,_):-!.
di_up(I,L):- nthel(I,L,X), chkup_incr(I,L,X,0), I1 is I+1, di_up(I1,L).

chkup_incr(8,_,_,_):-!.
chkup_incr(I,L,X,K):- I1 is I+1, nthel(I1,L,Y), K1 is K+1, doup_incr(X,Y,K1), chkup_incr(I1,L,X,K1).

doup_incr(X,Y,K1):- X1 is X+K1, Y=X1, incr_hval.
doup_incr(_,_,_).

% =========================================================================

di_dn(8,_):-!.  di_dn(I,L):- nthel(I,L,X), chkdn_incr(I,L,X,0), I1 is I+1, di_dn(I1,L).

chkdn_incr(8,_,_,_):-!.
chkdn_incr(I,L,X,K):- I1 is I+1, nthel(I1,L,Y), K1 is K+1, dodn_incr(X,Y,K1), chkdn_incr(I1,L,X,K1).

dodn_incr(X,Y,K1):- X1 is X-K1, Y=X1, incr_hval.  dodn_incr(_,_,_).


% A procedure to find the nth element of a list

nthel(1,[H|T],H):- write('FinState: '), write(H), tab(5), write(T),write('\n').
%nthel(1,[H|_],H):- !.
nthel(N,[_|T],El):- N1 is N-1, write(N1), tab(2), nthel(N1,T,El).

entry :- write('Enter the List for Data: '), read(X),write('Total Collisons: '),
    evalState(X, V), write(V).
