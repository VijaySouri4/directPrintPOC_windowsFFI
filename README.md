# native_poc

This is a flutter project to print raw text to a USB connected printer via windows ffi. 

The current flut.dll is created with GDI functions. The flut_ANSI.dll uses the printer handles and doc handles. There is a problem with accessing the doc handles with raw type. 
