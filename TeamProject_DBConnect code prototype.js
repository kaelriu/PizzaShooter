// Requirements
var express = require('express');
var app = express();
var qs = require('querystring');
const oracledb = require('oracledb');

// Settings
oracledb.autoCommit = false;
app.listen(3000, function() { console.log('app listening on port 3000!'); });
var DB_Account = { user : "C##TEAMPRO", password : "team123456", connectString : "kaelriu.iptime.org:1521/XE" };


// Connection test
oracledb.getConnection( DB_Account, function(err, connection) {
    if (err) { console.error(err.message); return; }
    else { console.log(DB_Account); connection.close(); }
});

//// Post Requests
// Login request
app.post('/login', function(request, response) {
    var body = '';
    request.on('data', function(data) { if ((body += data).length > 1e6) request.connection.destroy(); });
    request.on('end', function()
    {
        var post = qs.parse(body);
        console.log("Login / ID = %s, PW = %s", post.ID, post.PW);
        login(post.ID, post.PW, response);
    });
});

// Create request
app.post('/create', function(request, response) {
    var body = '';
    request.on('data', function(data) { if ((body += data).length > 1e6) request.connection.destroy(); });
    request.on('end', function(){
        var post = qs.parse(body);
        console.log("Create / ID = %s, PW = %s", post.ID, post.PW);
        create(post.ID, post.PW, response);
    });
});

//// Functions using DB
// Login function
function login(ID, PW, response) {
    oracledb.getConnection( DB_Account, function(err, connection){
        if (err) { console.error(err.message); return; }
        connection.execute('SELECT * FROM player WHERE player_id =:a', [ID], { maxRows:1 }, function(err, result){
            var jsonObj = {};
            if (err) { console.error(err.message); connection.close(); jsonObj.result = "Error"; return; }
            else {
                console.log(result.rows); console.log([ID, PW]); connection.close();
                if (result.rows.length <= 0) jsonObj.result = "ID Failed"; else if (result.rows[0][1] != PW) jsonObj.result = "PW Failed"; else jsonObj.result = "Succeed";
            }
            response.end(JSON.stringify(jsonObj));
        });
    });
}

// Create account function
function create(ID, PW, response) {
    oracledb.getConnection( DB_Account, function(err, connection){
        if (err) { console.error(err.message); return; }
        connection.execute('INSERT INTO player (player_id, player_pswd) VALUES (:a, :b)', [ID, PW], function(err, result){
            var jsonObj = {};
            if (err) { console.error(err.message); connection.close(); jsonObj.result = "Error"; return; }
            else {
                console.log(result); console.log([ID, PW]); connection.close();
                jsonObj.result = "Succeed";
            }
            response.end(JSON.stringify(jsonObj));
        });
        connection.commit();
    });
}