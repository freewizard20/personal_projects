var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split(/[\n\s]+/);
var a = parseInt(input[0]);
var x = [];
for(i = 0 ; i < a;i++){
    x.push(parseInt(input[i+1]));
}
x.sort(function(a,b){return a-b;});
for(i = 0 ; i < x.length ; i++){
    console.log(x[i]);
}