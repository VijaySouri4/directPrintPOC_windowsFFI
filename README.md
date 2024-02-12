# native_poc

This is a flutter project to print raw text to a USB connected printer via windows ffi. 

The current flut.dll is created with GDI functions. The flut_ANSI.dll uses the printer handles and doc handles. There is a problem with accessing the doc handles with raw type. 

# Changes required to run locally

1. Update paths in lines 111 and 114 of windows\CMakeLists.txt to project_dir/windows/cpp and project_dir/windows/cpp/printer.cpp
2. Update file save path in line 12 of Printer.cpp to run the previous code. 
