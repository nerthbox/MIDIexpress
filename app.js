'use strict'

var express = require("express");
var app = express();
var routes = require("./routes");

var jsonParser = require("body-parser").json;
var logger = require("morgan");

app.use('/public', express.static(__dirname + '/public'));

app.use(logger("dev"));
app.use(jsonParser());

app.use("/bb", routes);

var port = process.env.PORT || 3000;

app.listen(port, function(){
		console.log("Express server listening on port", port);
});


