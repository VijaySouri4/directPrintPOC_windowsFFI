#include <iostream>
#include <fstream>

extern "C" void escPrintText(const std::string& command, const std::string& printerPath){
    std::ofstream printer(printerPath, std::ios::out | std::ios::binary);
    if (printer.is_open()) {
            printer.write(command.c_str(), command.size());
            printer.close();
        } else {
            std::cerr << "Failed to open printer at " << printerPath << std::endl;
        }
}

// extern ESCPOS_Printer {
// public:
//     ESCPOS_Printer(const std::string& printerPath) : printerPath_(printerPath) {}

//     void initializePrinter() {
//         sendCommand("\x1B\x40");
//     }
//     void printText(const std::string& text) {
//         sendCommand(text + "\n");
//     }
//     void cutPaper() {
//         sendCommand("\x1D\x56\x41\x03"); // Full cut
//     }

// private:
//     std::string printerPath_;|

//     void sendCommand(const std::string& command) {
//         std::ofstream printer(printerPath_, std::ios::out | std::ios::binary);
//         if (printer.is_open()) {
//             printer.write(command.c_str(), command.size());
//             printer.close();
//         } else {
//             std::cerr << "Failed to open printer at " << printerPath_ << std::endl;
//         }
//     }
// };

// int main() {
//     ESCPOS_Printer printer("SWD\\PRINTENUM\\{03BB0FD3-610D-40FA-B8E4-155274A65691}"); // Microsoft Print to PDF Device Instance Parth:  printer path
//     printer.initializePrinter();
//     printer.printText("Hello, POS World!");
//     printer.cutPaper();
//     return 0;
// }
