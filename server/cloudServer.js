// Raspberry Pi 예정

var mqtt = require('mqtt');
var client  = mqtt.connect('mqtt://localhost:1883');
var server = require('http').createServer();
var io = require('socket.io')(server);
server.listen(3303);

var sendFlutter = "sflutter";

io.on('connection', client => {
    console.log('CONNECT Socket Await ... ');
});

client.on('connect', function () {
    client.subscribe('presence');
    client.subscribe('presence/A0');
});
 
client.on('message', function (topic, message) {
    console.log(`TOPIC : ${topic} / MSG : ${message}`);
    io.emit(sendFlutter, message.toString());
});


 
