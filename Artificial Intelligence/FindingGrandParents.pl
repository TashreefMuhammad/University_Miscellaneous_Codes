% The following Family Tree will be used
%                   P1
%                   --
%                  /  \
%               ---    \
%              /        \
%           P11         P12 + P13
%           ---         ---------
%          / | \          /   \
%         /  |  \        /     \
% P20 + P21 P22 P23   P24   P25 + P26
% --------- --- ---   ---   ---------
%      \     |        / |     / | \
%       \    |       /  |    /  |  \
%       P31 P32    P33 P34 P35 P36 P37

% Gender Declaration
male('P1').
male('P11').
male('P13').
male('P20').
male('P25').
male('P31').
male('P32').
male('P33').
male('P34').
female('P12').
female('P21').
female('P22').
female('P23').
female('P24').
female('P26').
female('P35').
female('P36').
female('P37').

% Parent Relation Declaration
parent('P1', 'P11'). parent('P1', 'P12').

parent('P11', 'P21'). parent('P11', 'P22'). parent('P11', 'P23').
parent('P12', 'P24'). parent('P12', 'P25').
parent('P13', 'P24'). parent('P13', 'P25').

parent('P20', 'P31').
parent('P21', 'P31').
parent('P22', 'P32').
parent('P24', 'P33'). parent('P24', 'P34').
parent('P25', 'P35'). parent('P25', 'P36'). parent('P25', 'P37').
parent('P26', 'P35'). parent('P26', 'P36'). parent('P26', 'P37').


% Grandparents Relationship
grandparent(X, Z):- parent(X, Y), parent(Y, Z).

% Grandparents of somebody

findGp :- write('Granchild: '), read(Gc), write('Grandparent: '),
    grandparent(Gp, Gc), write(Gp), tab(5), fail.
findGp.