var request = require('request');
var fs = require('fs');
var cheerio = require('cheerio');
var savepath = "test2.html";

var options = {
  url: 'http://localhost:3000',
  headers: {
  "connection":"keep-alive",
  "cache-control":"max-age=0",
  "upgrade-insecure-requests":"1",
  "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36",
  "accept":"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
  //"accept-encoding":"gzip, deflate, sdch",
  "accept-language":"ko-KR,ko;q=0.8,en-US;q=0.6,en;q=0.4",
  }
};


function callback(error, response, body) {

    $ = cheerio.load(body);
    console.log($.html());

}


request(options, callback);
