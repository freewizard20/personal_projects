var express = require('express');
var app = express();

app.get('/', function (req, res) {

  console.log(req.headers);
  res.send(test1.html);
});

app.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});
