import 'package:flutter/material.dart';
import 'package:ffi/ffi.dart';
import 'printer_bindings.dart';

void main() {
  PrinterBindings.loadLibrary();
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('USB Printer Example'),
        ),
        body: Center(
          child: ElevatedButton(
            onPressed: () {
              final text = 'Hello, printer!'.toNativeUtf8();
              //PrinterBindings.printText(text);
              // ESCPOSPrinter.initializePrinter();
              calloc.free(text);
              print('pressed!');
            },
            child: const Text('Print Text'),
          ),
        ),
      ),
    );
  }
}
