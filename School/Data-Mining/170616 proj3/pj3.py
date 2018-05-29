import json
from pprint import pprint

with open('project3.json') as data_file:    
    data = json.load(data_file)

pprint(data["documents"][0]["text"]) #data는 json 전체를 dictionary 형태로 저장하고 있음
print(len(data["documents"]))
#-----여기까지 동일-----

 #값 하나하나 접근하기
baggg = {}

for sam in data["documents"]:
    for key in sam["tf"]:
        baggg[key] = 0

print(baggg)

    
