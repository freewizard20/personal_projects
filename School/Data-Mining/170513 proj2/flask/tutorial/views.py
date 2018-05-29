from tutorial import app
from flask import render_template
from flask import request
import random
import json
import os
import operator

@app.route("/")
def index():

    #read json
    json_path = os.path.join(app.root_path,"data/articles.json")
    jsonfile = open(json_path)
    articles = json.load(jsonfile)
    jsonfile.close()

    i=0

    #premade url links for template
    urlarr = []
    for article in articles:
        urlarr.append("/content?i="+str(i))
        i=i+1
    

    # gets sort request as uri
    sort = request.values.get("sort")
    sorted_articles = []
    if sort == "titledown":
        sorted_articles = sorted(articles, key=operator.itemgetter("title"),reverse=True)
    elif sort == "titleup":
        sorted_articles = sorted(articles, key=operator.itemgetter("title"))
    elif sort == "timedown":
        sorted_articles = sorted(articles, key=operator.itemgetter("datetime"),reverse=True)
    elif sort == "timeup":
        sorted_articles = sorted(articles, key=operator.itemgetter("datetime"))
    else:
        sorted_articles = articles


    return render_template("index.html", articles = sorted_articles, urlarr=urlarr)

@app.route("/content")
def content():

    #read json
    json_path = os.path.join(app.root_path,"data/articles.json")
    jsonfile = open(json_path)
    articles = json.load(jsonfile)
    jsonfile.close()

    x = int(request.values.get("i"))
    article = articles[x]

    return render_template("content.html", article = article)

@app.route("/search")
def search():
    text = request.values.get("search")
    sam = text.lower().split()
    artarray = []
    index
    json_path = os.path.join(app.root_path,"data/articles.json")
    jsonfile = open(json_path)
    articles = json.load(jsonfile)
    jsonfile.close()

    #find matches
    for st in sam:
        for article in articles:
            pos = article['content'].lower().find(st)
            if pos != -1:
                artarray.append(article)
    
    
    
    
    
    return render_template("search.html", sam = sam, artarray=artarray)
