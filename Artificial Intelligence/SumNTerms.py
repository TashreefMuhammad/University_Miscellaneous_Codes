# -*- coding: utf-8 -*-
"""
Created on Fri Jan 22 14:29:48 2021

@author: Dragneel
"""

#%% The recursive function
def sumSeries(start, n, inv):
    if n == 1:
        return start
    return start + (n-1)*inv + sumSeries(start, n-1, inv)

#%% Input Handling and Calling recursive Function

print('Printing the sum of First N terms of an equal interval Series')

start = int(input('Enter the first element of series: '))
n = int(input('Number of Elements to Calculate the Sum: '))
inv = int(input('Interval among consecutive numbers: '))

ans = sumSeries(start, n, inv)

print('The sum is: ', ans)