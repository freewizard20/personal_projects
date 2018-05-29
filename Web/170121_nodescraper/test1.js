var url = "http://jpub.tistory.com/";
var savepath = "test1.html";

var http = require('http');
var fs = require('fs');
var request = require('request');

var outfile = fs.createWriteStream(savepath);



var options = {
  url: 'https://api.github.com/repos/request/request',
  headers: {
    'User-Agent': 'request'
  }
};

function callback(error, response, body) {
  if (!error && response.statusCode == 200) {
    console.log(body);


    
  }
}

request(options, callback);
