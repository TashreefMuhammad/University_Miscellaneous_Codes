# -*- coding: utf-8 -*-
"""
Created on Sat Feb 20 16:59:39 2021

@author: Dragneel
"""

#%% Custom classes for easy control on Graph and Node

class Graph:
    
    def __init__(self, graph_dict = None):
        self.graph_dict = graph_dict or {}


    
    def connect(self, A, B, distance = 1):
        self.graph_dict.setdefault(A, {})[B] = distance
        self.graph_dict.setdefault(B, {})[A] = distance
    
    def get(self, a, b = None):
        links = self.graph_dict.setdefault(a, {})
        if b is None:
            return links
        else:
            return links.get(b)
        

    def nodes(self):
        s1 = set([k for k in self.graph_dict.keys()])
        s2 = set([k2 for v in self.graph_dict.values() for k2, v2 in v.items()])
        nodes = s1.union(s2)
        return list(nodes)


class Node:
    # Initialize the class
    def __init__(self, name:str, parent:str):
        self.name = name
        self.parent = parent
        self.g = 0 # Distance to start node
        self.h = 0 # Distance to goal node
        self.f = 0 # Total cost
    
    # Compare nodes
    def __eq__(self, other):
        return self.name == other.name
    
    # Sort nodes
    def __lt__(self, other):
         return self.f < other.f
    
    # Print node
    def __repr__(self):
        return ('({0},{1})'.format(self.name, self.f))
    
    