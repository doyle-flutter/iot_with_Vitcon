const mosca = require('mosca'),
    settings = {port:1883},
    server = new mosca.Server(settings);

server.on('ready', function(){
    console.log("ready");
});

server.on('clientConnected', function(d){
    console.log("conn");
    // console.log(d);
});

server.on('published', (p,c) => {
    console.log("Published");
});

server.on('subscribed', () => {
    console.log("subscribed");
});
