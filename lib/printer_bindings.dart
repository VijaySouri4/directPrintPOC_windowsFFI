import 'dart:ffi' as ffi;
//import 'dart:io' show Platform;
import 'package:ffi/ffi.dart';

// Define a typedef for the printText function signature.
typedef PrintTextC = ffi.Void Function(ffi.Pointer<Utf8> text);
typedef PrintTextDart = void Function(ffi.Pointer<Utf8> text);

class PrinterBindings {
  static late ffi.DynamicLibrary _library;
  static late PrintTextDart printText;

  static void loadLibrary() {
    _library = ffi.DynamicLibrary.open('flut_ANSI_new.dll');
    print('Dude I am in now, so at least the dll was loaded');

    printText = _library
        .lookupFunction<PrintTextC, PrintTextDart>('printText');
  }
}
