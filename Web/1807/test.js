function tuple(f,u,v){
    var ru = f(u);
    var rv = f(v);
    return [ru,rv];
}

function add(x){
    return x+3;
}

function sub(x){
    return x-3;
}


var sam = 13;
var sam2 = 15;

var ret1 = tuple(add,sam,sam2);
var ret2 = tuple(sub,sam,sam2);

console.log(ret1[0] + " " + ret1[1]);
console.log(ret2[0] + " " + ret2[1]);