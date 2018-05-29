var http = require("http");
var https = require("https");

/**
 * getJSON:  REST get request returning JSON object(s)
 * @param options: http options object
 * @param callback: callback to pass the results JSON object(s) back
 */
exports.getJSON = function(options, onResult)
{
    console.log("rest::getJSON");

    var prot = options.port == 443 ? https : http;
    var req = prot.request(options, function(res)
    {
        var output = '';
        console.log(options.host + ':' + res.statusCode);
        res.setEncoding('utf8');

        res.on('data', function (chunk) {
            output += chunk;
        });

        res.on('end', function() {
            var obj = JSON.parse(output);
            onResult(res.statusCode, obj);
        });
    });

    req.on('error', function(err) {
        //res.send('error: ' + err.message);
    });

    req.end();
};

var options = {
    host: 'apilayer.net',
    port: 80,
    path: '/live?access_key=1e3575919fdca1e4b28f748cf71d1914&currencies=USD,AUD,CAD,PLN,MXN&format=1',
    method: 'GET',
    headers: {
        'Content-Type': 'application/json'
    }
};

exports.getJSON(options,
       function(statusCode, result)
       {
           // I could work with the result html/json here.  I could also just return it
           console.log("onResult: (" + statusCode + ")" + JSON.stringify(result));
           res.statusCode = statusCode;
           res.send(result);
       });
