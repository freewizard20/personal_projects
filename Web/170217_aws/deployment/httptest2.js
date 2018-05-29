var url ="http://apilayer.net/api/live?access_key=1e3575919fdca1e4b28f748cf71d1914&currencies=USD,AUD,CAD,PLN,MXN&format=1";
var savepath = "test.html";

var http = require('http');
var fs = require('fs');

var outfile = fs.createWriteStream(savepath);

http.get(url, function(res){
  console.log(res);
  /*res.pipe(outfile);
  res.on('end',function(){
      outfile.close();
      console.log("ok");*/

});
