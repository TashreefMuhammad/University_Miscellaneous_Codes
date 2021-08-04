# -*- coding: utf-8 -*-
"""
Created on Sat Feb 20 12:29:19 2021

@author: Dragneel
"""

#%% Reference Articles

'''
Besides class materials the following references were used
Greedy Best First Search: https://www.annytab.com/best-first-search-algorithm-in-python/?fbclid=IwAR0KyjGS3wn0sumGUslydSakVa68HG5GJg2gcBoJFUr64qD1q75eHgr7Kh4
A* Search: https://www.annytab.com/a-star-search-algorithm-in-python/?fbclid=IwAR15tQEsLHHkTyUGIkPqvekeI2tE5VOKA-5FtfrkvelIGrHkx2CvFBNzLC4 
'''

#%% Main Driver Code

import L3E4Classes as clas
import L3E4CreateGraph as makeGraph
import L3E4GreedyBestFS as GBFS
import L3E4AStar as AStar

#cnt_nodes = int(input('Enter Number of Nodes: '))
#cnt_edges = int(input('Enter Number of Edges: '))
print()

grp = clas.Graph()

grp, hValues = makeGraph.createGraph(grp, 0, 0)

path = GBFS.greedyBestFS('h', 'g', grp, hValues)

for i in path:
    pth, cst = i.split(': ')
    print(pth, end = ' ')
print('\nCost of Path:' + cst)

print('\n')

path = AStar.aStartSearch('h', 'g', grp, hValues)

for i in path:
    pth, cst = i.split(': ')
    print(pth, end = ' ')
    
print('\nCost of Path:' + cst)