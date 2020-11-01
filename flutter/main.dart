// https://pub.dev/packages/socket_io_client

import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';
import 'package:socket_io_client/socket_io_client.dart' as IO;

void main(){
  WidgetsFlutterBinding.ensureInitialized();
  GestureBinding.instance.resamplingEnabled = true;
  return runApp(MaterialApp(home: MainPage(),));
}

class MainPage extends StatefulWidget {
  @override
  _MainPageState createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  String mqData;

  @override
  void initState() {
    IO.Socket socket = IO.io(
        'ws://localhost',
        <String, dynamic>{
          'transports': ['websocket'],
        }
    )
    ..connect();
    socket.on('sflutter', (data){
      print(DateTime.now().second);
      setState(() {
        this.mqData = data;
      });
    });
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("MQTT * SOCKET"),
      ),
      body: Container(
        width: MediaQuery.of(context).size.width,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text("Flutter + Node.js(Broker) + Node.js(Socket)"),
            Text(': ${this.mqData ?? 'Loading...'}'),
          ],
        ),
      ),
    );
  }
}
