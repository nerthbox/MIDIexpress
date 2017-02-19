'use strict'

var exec = require('child_process').exec;
var execFile = require('child_process').execFile;
var express = require("express");
var router = express.Router();
var path = require('path');


//GET /bb
router.get("/", function(req, res){
        res.sendFile(path.join(__dirname, 'testindex.html'));
});

//GET /bb/:root/:dur/maj
router.get("/:root/:dur/maj", function(req, res){
	var root = req.params.root;
	var dur = req.params.dur;
	execFile("./bin/maj",[root,dur]);
	console.log("root: " + req.params.root + " dur: " + req.params.dur);
	res.json({
		response: "Sent GET to /bb/:root/:dur/maj"
	});
});

//GET /bb/:root/:dur/min
router.get("/:root/:dur/min", function(req, res){
	var root = req.params.root;
	var dur = req.params.dur;
	execFile("./bin/min",[root,dur]);
	console.log("root: " + req.params.root + " dur: " + req.params.dur);
	res.json({
		response: "Sent GET to /bb/:root/:dur/min"
	});
});

//GET /bb/:root/:dur/aug
router.get("/:root/:dur/aug", function(req, res){
	var root = req.params.root;
	var dur = req.params.dur;
	execFile("./bin/aug",[root,dur]);
	console.log("root: " + req.params.root + " dur: " + req.params.dur);
	res.json({
		response: "Sent GET to /bb/:root/:dur/aug"
	});
});

//GET /bb/:root/:dur/dim
router.get("/:root/:dur/dim", function(req, res){
	var root = req.params.root;
	var dur = req.params.dur;
	execFile("./bin/dim",[root,dur]);
	console.log("root: " + req.params.root + " dur: " + req.params.dur);
	res.json({
		response: "Sent GET to /bb/:root/:dur/dim"
	});
});

module.exports = router;
