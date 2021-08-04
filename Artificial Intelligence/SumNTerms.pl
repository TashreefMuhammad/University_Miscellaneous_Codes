sumSeries(1, S, _, S) :- !.
sumSeries(N, S, I, V) :- N1 is N-1, sumSeries(N1, S, I, S1), V is S1+ S + N1*I.

seriesEntry :- write('Starting Number: '), read(A),
               write('Number of Elements: '), read(B),
               write('Interval: '), read(C), write('The sum is: '),
               sumSeries(B, A, C, X), write(X).
