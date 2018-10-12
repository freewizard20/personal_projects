var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split(/[\n\s]+/);
var a = parseInt(input[0]);
var count = 1;
for(i = 0 ; i < a ; i++){
    var x = parseInt(input[count]);
    count++;
    var points = [];
    var avg = 0;
    for(j = 0 ; j < x ; j++){
        var curr = parseInt(input[count]);
        points.push(curr);
        count++;
        avg += curr;
    }
    // calculate average and count percentage
    avg /= x;
    var t = 0;
    for(j = 0 ; j < x ; j++){
        if(points[j]>avg){
            t++;
        }
    }
    console.log((t*100/x).toFixed(3)+'%');
}