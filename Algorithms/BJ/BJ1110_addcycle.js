var fs = require('fs');
var input = fs.readFileSync('./testcase.txt').toString().split(/[\n\s]+/);
var a = input[0];

var count = 0;

var b=a;

do{
    // calculate tmp
    var tmp=0;
    if(parseInt(b)<10){
         tmp = parseInt(b);
    }else{
        tmp = parseInt(b.charAt(0))+parseInt(b.charAt(1));
    }
    b = String((parseInt(b)%10)*10+(tmp%10));

    count++;
}while(a!=b);

console.log(count);