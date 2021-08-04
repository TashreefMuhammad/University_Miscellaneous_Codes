# -*- coding: utf-8 -*-
"""
Created on Sun Jan 10 22:57:00 2021

@author: Dragneel
"""

#%% Tree structure
'''
 The following Family Tree will be used
                   P1
                   --
                  /  \
               ---    \
              /        \
           P11         P12 + P13
           ---         ---------
          / | \          /   \
         /  |  \        /     \
 P20 + P21 P22 P23   P24   P25 + P26
 --------- --- ---   ---   ---------
      \     |        / |     / | \
       \    |       /  |    /  |  \
       P31 P32    P33 P34 P35 P36 P37
'''

#%% Relation Variables
parentList = [('child', 'P11', 'P1'), ('child', 'P12', 'P1'),
              ('child', 'P21', 'P11'), ('child', 'P22', 'P11'), ('child', 'P23', 'P11'),
              ('child', 'P24', 'P12'), ('child', 'P25', 'P12'), ('child', 'P24', 'P13'), ('child', 'P25', 'P13'),
              ('child', 'P31', 'P20'), ('child', 'P31', 'P21'), ('child', 'P32', 'P22'),
              ('child', 'P33', 'P24'), ('child', 'P34', 'P24'),
              ('child', 'P35', 'P25'), ('child', 'P36', 'P25'), ('child', 'P37', 'P25'),
              ('child', 'P35', 'P26'), ('child', 'P36', 'P26'), ('child', 'P37', 'P26')]

maleList = [ 'P1', 'P11', 'P13', 'P20', 'P25', 'P31', 'P32', 'P33', 'P34']
femaleList = [ 'P12', 'P21', 'P22', 'P23', 'P24', 'P26', 'P35', 'P36', 'P37']

#%% Functions for work

def brother(X):
    i = 0
    
    while(i < len(parentList)):
        if parentList[i][1] == X:
            for j in range(len(parentList)):
                if parentList[i][2] == parentList[j][2] and parentList[i][1] != parentList[j][1] and parentList[j][1] in maleList:
                    print(parentList[j][2], end=' ') 
        i += 1
    
    
def sister(X):
    i = 0
    
    while(i < len(parentList)):
        if parentList[i][1] == X:
            for j in range(len(parentList)):
                if parentList[i][2] == parentList[j][2] and parentList[i][1] != parentList[j][1] and parentList[j][1] in femaleList:
                    print(parentList[j][2], end=' ') 
        i += 1
    
def uncle(X):
    i = 0
    
    while(i < len(parentList)):
        if parentList[i][1] == X:
            for j in range(len(parentList)):
                if parentList[j][1] == parentList[i][2]:
                    for k in range(len(parentList)):
                        if parentList[k][2] == parentList[j][2] and parentList[k][1] != parentList[j][1] and parentList[k][1] in maleList:
                            print(parentList[k][1])
        i += 1

def aunt(X):
    i = 0
    
    while(i < len(parentList)):
        if parentList[i][1] == X:
            for j in range(len(parentList)):
                if parentList[j][1] == parentList[i][2]:
                    for k in range(len(parentList)):
                        if parentList[k][2] == parentList[j][2] and parentList[k][1] != parentList[j][1] and parentList[k][1] in femaleList:
                            print(parentList[k][1])
        i += 1
    

#%% Exercise Code

X = str(input('Name: '))
Y = str(input('Relation: '))
print(Y, end=' ')

if Y == 'Brother':
    brother(X)
elif Y == 'Sister':
    sister(X)
elif Y == 'Uncle':
    uncle(X)
elif Y == 'Aunt':
    aunt(X)
else:
    print('Relation is not defined')