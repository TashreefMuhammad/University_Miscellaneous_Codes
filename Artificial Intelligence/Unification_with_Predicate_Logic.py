# -*- coding: utf-8 -*-
"""
Created on Thu Apr  1 23:07:24 2021

@author: Dragneel
"""

#%%
# Func(var, val(what), "what")
# Func(var, "what", val(what))
# P1("any", "now", this)
#%% Needed Functions

def findIdentity(isValid, i, ln, sentence):
    i += 1
    val = []
    while i < ln and sentence[i] != ')' and isValid:
        while sentence[i] == ' ':
            i += 1
        st = ''
        j = i
            
        while j < ln and sentence[j] != ',' and sentence[j] != ')':
            st += sentence[j]
            j += 1
        if st[0] == '"':
            if st[len(st) - 1] == '"':
                val.append(['Constant', st])
            else:
                isValid = False
        else:
            brac = 0;
            l = len(st)
                
            k = 0
            while k < l:
                if not brac and st[k] == '(':
                    brac += 1
                k += 1
                    
            if brac == 0:
                val.append(['Variable', st])
            else:
                if brac == 1 and st[len(st) - 1] != ')' and j < ln-1:
                    st += ')'
                    j += 1
                    val.append(['Function', st])
                else:
                    isValid = False
                                  
        i = j + 1
        
    return isValid, val

def validateSentence(sentence1, sentence2):
    isValid = True
    len1 = len(sentence1)
    len2 = len(sentence2)
    
    pred1 = ''
    pred2 = ''
    val1 = []
    val2 = []
    
    i1 = 0
    
    while i1 < len1 and sentence1[i1] != '(':
        pred1 += sentence1[i1]
        i1 += 1
        
    i2 = 0
    
    while i2 < len2 and sentence2[i2] != '(':
        pred2 += sentence2[i2]
        i2 += 1
    
    if i1 == len1 or i2 == len2 or pred1 != pred2:
        isValid = False
        
    if isValid:
        isValid, val1 = findIdentity(isValid, i1, len1, sentence1)
        isValid, val2 = findIdentity(isValid, i2, len2, sentence2)
        
        if len(val1) != len(val2):
            isValid = False
    
        
    return isValid, pred1, val1, pred2, val2
    

#%% Driver Code

# =============================================================================
# print('It is required to provide two (2) atomic sentences')
# print('Please be noted that it is required that the predicates are same')
# print('A predicate is considered having the format "PREDICATE(VALUES)"')
# print('Here, "PREDICATE" represents name of the predicate')
# print('and "VALUES" represent all the terms of the predicate separated by (,) comma')
# =============================================================================

sentence1 = input('Enter First Sentence : ')
sentence2 = input('Enter Second Sentence: ')
print()

isValid, pred1, values1, pred2, values2 = validateSentence(sentence1, sentence2)

# =============================================================================
# print(isValid)
# print(pred1)
# print(values1)
# print(pred2)
# print(values2)
# =============================================================================

if not isValid:
    print('Provided Sentences do not follow expected format')
else:
    theta = {}
    i = 0
    for i in range(len(values1)):
        tp1 = values1[i][0]
        val1 = values1[i][1]
        tp2 = values2[i][0]
        val2 = values2[i][1]
        
        if values1[i][1] != values2[i][1] and (tp1 == 'Variable' or tp2 == 'Variable'):
            if (tp1, val1) in theta.values():
                break
            theta[(tp2, val2)] = (tp1, val1)
            #print(theta)
                
            for j in range(len(values1)):
                if values1[j][1] == val2:
                    values1[j][0] = tp1
                    values1[j][1] = val1
                if values2[j][1] == val2:
                    values2[j][0] = tp1
                    values2[j][1] = val1
        elif values1[i][1] != values2[i][1]:
            break
# =============================================================================
#     print(values1)
#     print(values2)
#     print(theta)
#     print(i)
#     print(len(values1))
# =============================================================================
    
    if i == len(values1) - 1 and values1 == values2:
        print('Unifiable')
        
        st = set()
        
        for key, value in theta.items():
            cat = ''
            if key[0] == 'Variable':
                cat = key[1] + '/' + value[1]
            else:
                cat = value[1] + '/' + key[1]    
            st.add(cat)
        print(st)
    else:
        print('Not Unifiable')
        

