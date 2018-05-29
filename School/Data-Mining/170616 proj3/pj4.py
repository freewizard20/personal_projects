import json
import math
import random
import operator
from pprint import pprint

with open('project3.json') as data_file:    
    data = json.load(data_file)

#pprint(data["documents"][0]["text"]) #data는 json 전체를 dictionary 형태로 저장하고 있음
#print(len(data["documents"]))
#-----여기까지 동일-----

 #값 하나하나 접근하기
        
#print(baggg)
print("bag set")

baglist = []
for sam in data["documents"]:
    tmp = {}
    
    for key in sam["tf"]:
        tmp[key] = sam["tf"][key]*math.log(400/sam["df"][key])

    baglist.append(tmp)
    
print("baglist set")



kmeans = 30
centroid = []

for i in range(kmeans):
    centroid.append(baglist[random.randrange(1,400)])
   

for i in range(10):
    print(str(i)+" : iteration")
    j=0
    cluster=[]
    for i in range(kmeans):
        cluster.append([])
    
    # make a centroid cluster
    for sam in baglist:
        tmp = []
        for clu in centroid:
            tot = 0
            
            for key in clu:
                try:
                    tot = tot + (clu[key]-sam[key])**2
                except:
                    pass
            tmp.append(math.sqrt(tot))
        a = tmp.index(min(tmp))
        cluster[a].append(j)
        j=j+1

    print("cluster statistics")
    for i in range(len(cluster)):
        print("cluster"+str(i)+" : " + str(len(cluster[i])))
        bag33 = {}
        for j in range(len(cluster[i])):
            for key in baglist[cluster[i][j]]:
                try:
                    bag33[key] = bag33[key]+baglist[cluster[i][j]][key]
                except:
                    bag33[key] = 0
        bag33_sort = sorted(bag33.items(), key=operator.itemgetter(1),reverse=True)
        print(bag33_sort[0])
    
    for i in range(len(cluster)):
        #len(cluster[i])
        tmp = {}
        for nums in cluster[i]:
            
            for key in baglist[nums]:
                try:
                    tmp[key] = tmp[key] + baglist[nums][key]/len(cluster[i])
                except:
                    tmp[key]=0
        
        centroid[i] = tmp
    print("centroid updated")
        



"""
centroid =[]
cluster = []

for i in range(kmeans):
    centroid.append(baglist[random.randrange(1,400)])
    cluster.append([])

print(len(centroid))
for i in range(10):
    # make a centroid cluster
    print("firr")
    for sam in baglist:
        tmp = []
        for clu in centroid:
            tot = 0
            
            for key in clu:
                tot = tot + (clu[key]-sam[key])**2
            tmp.append(math.sqrt(tot))
        a = tmp.index(min(tmp))
        print(a)
        cluster[a].append(sam)
    print("midd")
    # update centroid coordinate
    centroid = []
    for sam in cluster:
        total = {}
        for sam2 in data["documents"]:
            for key in sam2["tf"]:
                total[key]= 0
        for sam2 in sam:
            for key in sam2:
                bag[key] = bag[key] + sam2[key]/len(sam)
        centroid.append(total)
    

print("centroid updated")
    
    """
    
    
    
