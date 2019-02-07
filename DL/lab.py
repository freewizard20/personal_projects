import numpy as np

lab = np.array([1,2,3,4])
lab2 = np.array([1,2,4,5])
lab3 = np.equal(lab,lab2)

count = 0
for i in lab3:
    if i == True:
        count = count+1
    print(i)

print(count)

