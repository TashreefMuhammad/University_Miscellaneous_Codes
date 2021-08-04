# -*- coding: utf-8 -*-
"""
Created on Fri Jan 22 19:44:59 2021

@author: Dragneel
"""

#%% Recursive Function to find 8 Queen Clashes count

def hCol(pos):
    
    for i in range(len(pos)):
        cntHorizontal(i, pos)
    
    
def duCol(pos):
    for i in range(len(pos)):
        cntDiagonalUp(i, pos)
    
    
def ddCol(pos):
    for i in range(len(pos)):
        cntDiagonalDown(i, pos)
 
    
def cntHorizontal(point, pos):
    global cnt
    for i in range(point + 1, len(pos)):
        if pos[i] == pos[point]:
            cnt += 1
    
def cntDiagonalUp(point, pos):
    global cnt
    for i in range(point + 1, len(pos)):
        if pos[i] == pos[point] + i - point:
            cnt += 1
    
    
def cntDiagonalDown(point, pos):
    global cnt
    for i in range(point + 1, len(pos)):
        if pos[i] == pos[point] - i + point:
            cnt += 1
    
    

#%% The main function

cnt = 0
#pos = [0]*8
pos = [6, 1, 5, 7, 4, 3, 8, 1]

#for i in range(8):
#    pos[i] = int(input('Enter Position for Queen in Column ' + str(i + 1) + ': '))
hCol(pos)
duCol(pos)
ddCol(pos)    
print('Total Number of Collisions: ', cnt)
    
#%%
# 61574381
