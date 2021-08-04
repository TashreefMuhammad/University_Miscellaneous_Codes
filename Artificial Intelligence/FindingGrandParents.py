# -*- coding: utf-8 -*-
"""
Created on Sun Jan 10 21:45:17 2021

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

#%% Exercise Code

X = str(input('Grandchild: '))
print('Grandparents: ', end=' ')

i = 0

while(i < len(parentList)):
    if parentList[i][0] == 'child' and parentList[i][1] == X:
        for j in range(len(parentList)):
            if parentList[j][0] == 'child' and parentList[i][2] == parentList[j][1]:
                print(parentList[j][2], end=' ') 
    i += 1