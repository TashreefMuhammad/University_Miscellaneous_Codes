# -*- coding: utf-8 -*-
"""
Created on Sat Feb 20 11:50:12 2021

@author: Dragneel
"""

fl = 'D:/CSE 4108/Lab 3/input.txt'
dct = {}

with open(fl, 'r') as f:
    content = f.readline()
    while content:
        name, dept, cgpa = content.split('\t')
        cgpa = float(cgpa)
        cgpa = (cgpa * 4.0) / 5.0
        dct[name] = [dept, cgpa]
        content = f.readline()

with open(fl, 'w') as f:
    for name, [dept, cgpa] in dct.items():
        f.write(name + '\t' + dept + '\t' + str(cgpa) + '\n')