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

typedef ESCInitializePrinterC = ffi.Void Function();
typedef ESCInitializePrinterDart = void Function();

typedef ESCPrintTextC = ffi.Void Function(ffi.Pointer<Utf8>);
typedef ESCPrintTextDart = void Function(ffi.Pointer<Utf8>);

typedef ESCCutPaperC = ffi.Void Function();
typedef ESCCutPaperDart = void Function();

class ESCPOSPrinter {
  late ffi.DynamicLibrary _lib;
  late ESCInitializePrinterDart initializePrinter;
  late ESCPrintTextDart escprintText;
  late ESCCutPaperDart cutPaper;

  ESCPOSPrinter() {
    _lib = ffi.DynamicLibrary.open('escprinter.dll');

    initializePrinter = _lib.lookupFunction<ESCInitializePrinterC, ESCInitializePrinterDart>('initializePrinter');
    escprintText = _lib.lookupFunction<ESCPrintTextC, ESCPrintTextDart>('printText');
    cutPaper = _lib.lookupFunction<ESCCutPaperC, ESCCutPaperDart>('cutPaper');
    //     .lookup<ffi.NativeFunction<ESCInitializePrinterC>>('initialize_printer')
    //     .asFunction<ESCInitializePrinterDart>();

    // _printText = _lib
    //     .lookup<ffi.NativeFunction<PrintTextC>>('print_text')
    //     .asFunction<PrintTextDart>();

    // _cutPaper = _lib
    //     .lookup<ffi.NativeFunction<ESCCutPaperC>>('cut_paper')
    //     .asFunction<ESCCutPaperDart>();
  }

  // void initializePrinter() => _initializePrinter();
  // void escprintText(String text) {
  //   final textPtr = text.toNativeUtf8();
  //   _printText(textPtr);
  //   calloc.free(textPtr);
  // }
  // void cutPaper() => _cutPaper();
}