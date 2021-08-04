# -*- coding: utf-8 -*-
"""
Created on Sat Mar 27 15:14:55 2021

@author: Dragneel
"""

#%%

import pandas as pd
import numpy as np
from sklearn import metrics
from sklearn.model_selection import KFold
from sklearn.linear_model import LogisticRegression
from sklearn.neural_network import MLPClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC
#import warnings
#warnings.simplefilter("ignore")

def crossValid(name, n_splits, model, X, Y):
    kf = KFold(n_splits)
    acc = 0
    prec = 0
    recall = 0
    f1Score = 0

    print('===', name, '===')
    for train_index, test_index in kf.split(X):
        XTrain, XTest = X[train_index], X[test_index]
        YTrain, YTest = Y[train_index], Y[test_index]
        model.fit(XTrain, YTrain)
        pred = model.predict(XTest)
        acc += metrics.accuracy_score(YTest, pred)
        prec += metrics.precision_score(YTest, pred)
        recall += metrics.recall_score(YTest, pred)
        f1Score += metrics.f1_score(YTest, pred)

    print('Accuracy\t: ', acc / 5)
    print('Precision\t: ', prec / 5)
    print('Recall\t\t: ', recall / 5)
    print('F1-Score\t: ', f1Score / 5)
    print()

df = pd.read_csv('D:/CSE 4108/Lab 5/Dataset_170104014.csv')
np_arr = df.to_numpy()

X = np.reshape((np_arr[:, 0] - np.average(np_arr[:, 0])) / np.std(np_arr[:, 0]), (df.shape[0], 1))
#Y = np.reshape(np_arr[:, 2], (df.shape[0], 1))
Y = np_arr[:, 2]
#ones = np.ones((df.shape[0], 1))
#lr = 0.01

#X = np.append(ones, X, axis = 1)
#XTrain = X[: int(0.9 * df.shape[0])]
#YTrain = Y[: int(0.9 * df.shape[0])]

#XTest = X[int(0.9 * df.shape[0]) :]
#YTest = Y[int(0.9 * df.shape[0]) :]

crossValid('Logistic Regression', 5, LogisticRegression(), X, Y)
crossValid('MLP Classifier', 5, MLPClassifier(), X, Y)
crossValid('Naïve Bayes Classifier', 5, GaussianNB(), X, Y)
crossValid('Decision Tree Classifier', 5, DecisionTreeClassifier(), X, Y)
crossValid('Support Vector Classifier', 5, SVC(), X, Y)



