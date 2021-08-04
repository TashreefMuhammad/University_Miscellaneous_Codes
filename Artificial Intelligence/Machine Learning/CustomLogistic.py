# -*- coding: utf-8 -*-
"""
Created on Fri Mar 26 22:30:46 2021

@author: Dragneel
"""

#%%
import pandas as pd
import numpy as np
from sklearn.metrics import confusion_matrix
from sklearn.linear_model import LogisticRegression

def sig(x):
    return 1/(1 + np.exp(-x))

df = pd.read_csv('D:/CSE 4108/Lab 5/Dataset_170104014.csv')
np_arr = df.to_numpy()

X = np.reshape((np_arr[:, 0] - np.average(np_arr[:, 0])) / np.std(np_arr[:, 0]), (df.shape[0], 1))
Y = np.reshape(np_arr[:, 2], (df.shape[0], 1))
ones = np.ones((df.shape[0], 1))
lr = 0.01

X = np.append(ones, X, axis = 1)
XTrain = X[: int(0.9 * df.shape[0])]
YTrain = Y[: int(0.9 * df.shape[0])]

XTest = X[int(0.9 * df.shape[0]) :]
YTest = Y[int(0.9 * df.shape[0]) :]
#theta = np.reshape(np.array([random.randint(1, 100), random.randint(1, 100)]), (2,1))
theta = np.reshape(np.array([0, 0]), (2,1))

#print(np_arr.shape)
#print(X.shape)
#print(Y.shape)
#print(theta.shape)
#print(theta)

for i in range(1000):
    cst = sum(np.multiply(-YTrain, np.log10(sig(np.matmul(XTrain, theta)))) - np.multiply(1 - YTrain, np.log10(1 - sig(np.matmul(XTrain, theta))))) / df.shape[0]
    if i % 100 == 0:
        print(cst)
    #tmp = theta
    #theta = tmp - lr * (np.matmul(X.T, np.matmul(X, theta) - Y) / df.shape[0])
    theta = np.matmul(XTrain.T, sig(np.matmul(XTrain, theta) - YTrain)) / df.shape[0]
    #print(theta)
    
#print(X.shape)
#print(Y.shape)
#print(theta.shape)
#print(theta)   
#y_hat = np.matmul(X, theta)
val = sig(np.matmul(XTest, theta))
YPrediction = [0 if i > 0.6 else 1 for i in val]
print(confusion_matrix(YTest, YPrediction))

#print(y_hat)

logisticRegr = LogisticRegression()
logisticRegr.fit(XTrain, np.reshape(YTrain, ((int(.9 * df.shape[0]), ))))
pred = logisticRegr.predict(XTest)
print(confusion_matrix(YTest, pred))

#plt.plot(df["Feature"], y_hat)
#plt.scatter(df["Feature"], df["Result"], color = 'r', marker = '+', linewidths = .09)
#plt.show()
    