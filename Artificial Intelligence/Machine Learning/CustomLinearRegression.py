# -*- coding: utf-8 -*-
"""
Created on Fri Mar 26 12:50:10 2021

@author: Dragneel
"""



#%%
import pandas as pd
import numpy as np
import random
from sklearn import metrics
import matplotlib.pyplot as plt

df = pd.read_csv('D:/CSE 4108/Lab 5/Dataset_170104014.csv')
np_arr = df.to_numpy()

X = np.reshape((np_arr[:, 0] - np.average(np_arr[:, 0])) / np.std(np_arr[:, 0]), (df.shape[0], 1))
Y = np.reshape(np_arr[:, 1], (df.shape[0], 1))
ones = np.ones((df.shape[0], 1))
lr = 0.01

X = np.append(ones, X, axis = 1)
XTrain = X[: int(0.9 * df.shape[0])]
YTrain = Y[: int(0.9 * df.shape[0])]

XTest = X[int(0.9 * df.shape[0]) :]
YTest = Y[int(0.9 * df.shape[0]) :]
theta = np.reshape(np.array([random.randint(1, 100), random.randint(1, 100)]), (2,1))

#print(np_arr.shape)
print(X.shape)
print(Y.shape)
print(XTrain.shape)
print(YTrain.shape)
print(XTest.shape)
print(YTest.shape)
#print(theta.shape)
#print(theta)

for i in range(1000):
    cst = sum(np.power(np.matmul(XTrain, theta) - YTrain, 2)) / (2 * df.shape[0])
    if i % 100 == 0:
        print(cst)
    tmp = theta
    theta = tmp - lr * (np.matmul(XTrain.T, np.matmul(XTrain, theta) - YTrain) / df.shape[0])
    
#print(X.shape)
#print(Y.shape)
#print(theta.shape)
#print(theta)   
y_hat = np.matmul(X, theta)
YPrediction = np.matmul(XTest, theta)

#print(y_hat)

plt.plot(df["Feature"], y_hat)
plt.scatter(df["Feature"], df["Result"], color = 'r', marker = '+', linewidths = 1)
plt.legend(['Predicted', 'Real'])
plt.show()
    

# Displaying errors
print('Mean Absolute Error:', metrics.mean_absolute_error(YTest, YPrediction))
print('Mean Squared Error:', metrics.mean_squared_error(YTest, YPrediction))
print('Root Mean Squared Error:', np.sqrt(metrics.mean_squared_error(YTest, YPrediction)))