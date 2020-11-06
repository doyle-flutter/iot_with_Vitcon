var mosca = require('mosca');
var settings = {port:1882};
var server = new mosca.Server(settings);
var express = require('express');
var app = express();
app.listen(3000);
var piCamera = require('pi-camera');
var myCam = new piCamera({
  mode:'photo',
  output: `${__dirname}/test.jpg`,
  width: 640,
  height: 640,
  nopreview: false
});

app.get('/', (req,res) => {
  res.sendFile(`${__dirname}/test.jpg`);
});

app.get('/a',(req,res) => {
  res.send('dd');
});

app.get('/cam',(req,res) => {
  myCam.snap()
   .then((result) => {res.redirect('/')})
    .catch((e) => res.redirect('/a'));
});

server.on('ready', function(){
    console.log("ready");
});

server.on('clientConnected', function(d){
    console.log("conn");
});

server.on('published', (p,c) => {
    console.log(`Published : ${p.topic}`);
});

server.on('subscribed', (d) => {
    console.log(`subscribed : ${d}`);
});

