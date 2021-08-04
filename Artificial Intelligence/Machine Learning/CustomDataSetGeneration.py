# -*- coding: utf-8 -*-
"""
Created on Fri Mar 26 12:54:32 2021

@author: Dragneel
"""
#%% The Equation

# y = (2*ln(x) + 0.14*x + .25 * x * x) / 1000000

#%%
import numpy as np
import random
import pandas as pd
import matplotlib.pyplot as plt

df = pd.DataFrame(columns = ['Feature', 'Result', 'Class'])

while df.shape[0] < 10000:
    randNum = random.randint(1, 1000000)
    
    if df.isin([randNum]).any()['Feature'] :
        print(randNum, ' is present in dataframe')
        continue
    else:
        df.loc[df.shape[0]] = [randNum, (2 * np.log(randNum) + 0.14 * randNum + .25 * randNum * randNum) / 1000000, 1 if ((2 * np.log(randNum) + 0.14 * randNum + .25 * randNum * randNum) / 1000000 > 100000 and (2 * np.log(randNum) + 0.14 * randNum + .25 * randNum * randNum) / 1000000 < 500000) else 0]
        #df.loc[df.shape[0]] = [randNum, (0.14 * randNum) / 1000, 1 if (2 * np.log(randNum) + 0.14 * randNum + .25 * randNum * randNum) / 1000000 > 1000 else 0]

print(df)
df.to_csv('D:/CSE 4108/Lab 5/Dataset_170104014.csv', index = False)

# plotting a line graph
print("Line graph: ")
plt.plot(df["Feature"], df["Result"])
plt.show()
  
# plotting a scatter plot
print("Scatter Plot:  ")
plt.scatter(df["Feature"], df["Result"])
plt.show()

