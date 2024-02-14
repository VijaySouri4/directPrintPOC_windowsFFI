#include "escpospp/escpospp.h"

int main() {
    escpospp::Printer printer("/dev/usb/lp0"); // Replace with your printer's device path

    printer.initialize();
    printer.setFont(escpospp::Font::A);
    printer.setTextAlign(escpospp::Align::Center);
    printer.println("Hello, POS World!");

    // Cutting the paper
    printer.cut();

    return 0;
}
