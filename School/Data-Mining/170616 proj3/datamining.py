import json
import math
import random
import operator
from pprint import pprint

with open('project3.json') as data_file:    
    data = json.load(data_file)


# check tf-idf rank for a document

def tfmax(vec):
    
    vector_sort = sorted(vec.items(), key=operator.itemgetter(1), reverse=True)

    print("content : ",end="")
    for i in range(15):
        print(str(vector_sort[i][0]),end=" ")
    print()


# tf-idf vector list set

vectorlist = []
for sam in data["documents"]:
    tmp = {}
    
    for key in sam["tf"]:
        if sam["df"][key] <100:
            tmp[key] = sam["tf"][key]*math.log(400/sam["df"][key])

    vectorlist.append(tmp)


# prepare for centroids

kmeans = 12
repetitions = 30


centroid = []
for i in range(kmeans):
    centroid.append(vectorlist[random.randrange(1,400)])

# iterate for centroids and recluster

    # cluster vectors
for i in range(repetitions):
    print("---------------------------------------------------")
    print(str(i)+" : iteration")
    cluster = []
    clusterstrength=[]
    for i in range(kmeans):
        cluster.append([])
        clusterstrength.append(0)
    j = 0
    for sam in vectorlist:
        tmp = []
        for clu in centroid:
            tot = 0
            for key in clu:
                flag = 0
                try:
                    tot = tot + (clu[key]-sam[key])**2
                    flag = 1
                except:
                    pass
                try:
                    if flag==0:
                        tot = tot + (clu[key])**2
                        flag = 1
                except:
                    pass
                try:
                    if flag==0:
                        tot = tot + (sam[key])**2
                        flag = 1
                except:
                    pass

            tmp.append(math.sqrt(tot))
        a = tmp.index(min(tmp))
        clusterstrength[a] = clusterstrength[a]+min(tmp)/100
        cluster[a].append(j)
        j=j+1

    print("cluster statistics")


    # recalculate centroid vectors

    for i in range(len(cluster)):
        tmp = {}
        for nums in cluster[i]:
            for key in vectorlist[nums]:
                if key.isalpha():
                    try:
                        tmp[key] = tmp[key] + vectorlist[nums][key]/len(cluster[i])
                    except:
                        tmp[key] = vectorlist[nums][key]/len(cluster[i])
            centroid[i] = tmp

    for i in range(len(cluster)):
        if len(cluster[i])!=0:
            print("cluster"+str(i)+" : " + str(len(cluster[i])))
            print("clusterstrength(lower is denser) : " + str(clusterstrength[i]))
            tfmax(centroid[i])
            print("---")
        else:
            print("cluster"+str(i)+" dead")
            print("---")
    print("centroid updated")

