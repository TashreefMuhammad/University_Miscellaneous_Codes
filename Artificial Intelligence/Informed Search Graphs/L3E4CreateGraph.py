# -*- coding: utf-8 -*-
"""
Created on Sat Feb 20 13:18:25 2021

@author: Dragneel
"""

#%% Graph Generation Function
def createGraph(grp, cnt_nodes = 0, cnt_edges = 0):
    
    '''
    print('Write From Node, To Node and Cost of the Path:')
    
    i = 0
    
    while i < cnt_edges:
        print('Edge ', i+1)
        fr = input('From: ')
        to = input('To: ')
        cs = int(input('Cost: '))
        
        grp.connect(fr, to, cs)
        
        i += 1
        
    print('Write Value of Heuristic of Node:')
    
    hValues = {}
    i = 0
    
    while i < cnt_nodes:
        nd = input('Enter Node: ')
        cs = int(input('Enter Heuristic Cost: '))
        hValues[nd] = cs
    
    '''
    
    hValues = {
        'a' : 55,
        'b' : 42,
        'c' : 34,
        'd' : 25,
        'e' : 20,
        'f' : 17,
        'g' : 0,
        'h' : 80,
        }
    
    
    grp.connect('a', 'h', 35)
    grp.connect('a', 'd', 32)
    grp.connect('a', 'c', 22)
    
    grp.connect('b', 'h', 45)
    grp.connect('b', 'd', 28)
    grp.connect('b', 'f', 27)
    grp.connect('b', 'e', 36)
    
    grp.connect('c', 'd', 31)
    grp.connect('c', 'g', 47)
    
    grp.connect('d', 'g', 30)
    
    grp.connect('e', 'g', 26)
    
    
    return grp, hValues