import json
import math
import random
import operator
from pprint import pprint

with open('project3.json') as data_file:    
    data = json.load(data_file)

search2 = 1

vector={}
for key in data["documents"][search2]["tf"]:
    vector[key] = data["documents"][search2]["tf"][key] * math.log(400/data["documents"][search2]["df"][key])

vector_sort = sorted(vector.items(), key=operator.itemgetter(1), reverse=True)
print(vector_sort)

