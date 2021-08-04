# -*- coding: utf-8 -*-
"""
Created on Fri Jan 22 14:41:18 2021

@author: Dragneel
"""

#%% Function to return path value

def pathValue(startPoint, endPoint, cost = 0):
    if (startPoint, endPoint) in pairList:
        print(str(cost + valueDict[(startPoint, endPoint)]) + ' ')
    
    for (i, j) in pairList:
        if i == startPoint:
            pathValue(j, endPoint, cost + valueDict[(i, j)])

#%% Input Handling and Calling recursive Function

valueDict = {('i', 'a') : 35, ('i', 'b') : 45, ('a', 'c') : 22, ('a', 'd') : 32, ('b', 'd') : 28, ('b', 'e') : 36,
             ('b', 'f') : 27, ('c', 'd') : 31, ('c', 'g') : 47, ('d', 'g') : 30, ('e', 'g') : 26}

pairList = [('i', 'a'), ('i', 'b'), ('a', 'c'), ('a', 'd'), ('b', 'd'), ('b', 'e'), 
            ('b', 'f'), ('c', 'd'), ('c', 'g'), ('d', 'g'), ('e', 'g')]

start = str(input('Enter Starting point: '))
end = str(input('Enter Ending point: '))

print('The length of path is: ')
pathValue(start, end)