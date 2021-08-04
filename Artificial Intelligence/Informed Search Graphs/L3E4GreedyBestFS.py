# -*- coding: utf-8 -*-
"""
Created on Sat Feb 20 16:42:03 2021

@author: Dragneel
"""

#%% The Greedy best First Search Algorithm Implimentation

import L3E4Classes as clas

def greedyBestFS(start, end, graph, heuristics):
    print('Greedy Best First Search:')
    
    # Create lists for open nodes and closed nodes
    op = []
    cl = []
    
    # Create a start node and an goal node
    start_node = clas.Node(start, None)
    goal_node = clas.Node(end, None)
    
    # Add the start node
    op.append(start_node)
    
    # Loop until the open list is empty
    while len(op) > 0:
        # Sort the open list to get the node with the lowest cost first
        op.sort()
        # Get the node with the lowest cost
        current_node = op.pop(0)
        
        # Add the current node to the closed list
        cl.append(current_node)
        
        # Check if we have reached the goal, return the path
        if current_node == goal_node:
            path = []
            while current_node != start_node:
                path.append(current_node.name + ': ' + str(current_node.g))
                current_node = current_node.parent
            path.append(start_node.name + ': ' + str(start_node.g))
            
            # Return reversed path
            return path[::-1]
        # Get neighbours
        neighbors = graph.get(current_node.name)
        
        # Loop neighbors
        for key, value in neighbors.items():
            # Create a neighbor node
            neighbor = clas.Node(key, current_node)
            # Check if the neighbor is in the closed list
            if(neighbor in cl):
                continue
            # Calculate cost to goal
            neighbor.g = current_node.g + graph.get(current_node.name, neighbor.name)
            neighbor.h = heuristics.get(neighbor.name)
            neighbor.f = neighbor.h
            
            # Check if neighbor is in open list and if it has a lower f value
            if(add_to_open(op, neighbor) == True):
                # Everything is green, add neighbor to open list
                op.append(neighbor)
                
    # Return None, no path is found
    return None

# Check if a neighbor should be added to open list
def add_to_open(op, neighbor):
    for node in op:
        if (neighbor == node and neighbor.f >= node.f):
            return False
    return True