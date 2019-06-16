var express = require('express');
var app = express();
var expressWs = require('express-ws')(app);
var mysql=require('mysql');

var conn=mysql.createConnection({
  host:'127.0.0.1',
  user: 'root',
  password: 'rahul',
  database: 'collision'
});

conn.connect(function(err){
  console.log("Connected");
  if (err){
    console.log(err);
  }

});


var ip=[];
var dist1=1000,dist2=1000;


app.ws('/:carId', function(ws, req) {
  // console.log(req.params.carId);
  // console.log(ws);
  ws.on('message', function(msg) {
    //if(msg.distance < threshold)

    console.log('Recieved request from '+req.ip.substr(7));
    //console.log(req.ip.substr(7));
    if(req.params.carId==1)
    {
      dist1=msg;
      ip[0]=ws;//req.ip.substr(7);

    }
        
    if(req.params.carId==2)
    {
      dist2=msg;
      ip[1]=ws;//req.ip.substr(7);
    }
    console.log("DISt1 "+dist1+" Dist2 "+dist2);


    const out=Math.abs((dist1-dist2));
  //  console.log("OUT=",out)

    if(req.params.carId==1)
    {
        if (0<=dist1 && dist1<20)
        {
            ip[0].send('2');
        }
        if(dist1>=20 && dist1<50)
        {
            ip[0].send('1');
        }
        if(dist1>=50)
        {
            ip[0].send("Green Zone");
        }
    }

    if(req.params.carId==2)
    {
        if (0<=dist2 && dist2<20)
        {
            ip[1].send('2');
        }
        if(dist2>=20 && dist2<50)
        {
            ip[1].send('1');
        }
        if(dist2>=50)
        {
            ip[1].send("Green Zone");
        }
    }
    
  });

  ws.on('error', function(error) {
    console.log(ws.id + ':' + error)
});
 // console.log('socket', req.testing);
});
 
app.listen(3000);