// // windows/cpp/printer.cpp
#include "printer.h"
#include <Windows.h>
#include <string>
#include <cstring>

extern "C" void printText(const char* text) {
    HANDLE printer;
    DOC_INFO_1A docInfo;
    DWORD bytesWritten;

    std::string pdfOutputPath = R"(C:\Users\vijay\DirectPrintPOC)";

    char printerName[] = "Microsoft Print to PDF";

    // Open a handle to the printer.
    LPSTR mutablePrinterName = new char[strlen(printerName) + 1];
    strcpy_s(mutablePrinterName, strlen(printerName) + 1, printerName);

    //OpenPrinterA("Microsoft Print to PDF", &printer, nullptr);

    OpenPrinterA(mutablePrinterName, &printer, nullptr);

    // Setup document information.
    char docName[] = "RAW_str_PDF_Document";
    LPSTR mutableDocName = new char[strlen(docName) + 1];
    strcpy_s(mutableDocName, strlen(docName) + 1, docName);
    docInfo.pDocName = mutableDocName;

    char dataType[] = "RAW";
    LPSTR mutableDataType = new char[strlen(dataType) + 1];
    strcpy_s(mutableDataType, strlen(dataType) + 1, dataType);
    docInfo.pOutputFile = const_cast<char*>(pdfOutputPath.c_str());;
    docInfo.pDatatype = mutableDataType;


    StartDocPrinter(printer, 1, (LPBYTE)&docInfo);
    StartPagePrinter(printer);

    // Write the text to the printer.
    WritePrinter(printer, (LPVOID)text, strlen(text), &bytesWritten);

    // End the page and document printing.
    EndPagePrinter(printer);
    EndDocPrinter(printer);

    // Close the printer handle.
    ClosePrinter(printer);
}

// #include "pch.h"
// #include <windows.h>

// extern "C" void printText(const char* text) {
// 	LPCWSTR printerName = L"Microsoft Print to PDF";

// 	DOCINFO di = { sizeof(DOCINFO), L"My Document", NULL };

// 	HDC printerDC = CreateDC(L"WINDSPOOL", printerName, NULL, NULL);

// 	StartDoc(printerDC, &di);
// 	StartPage(printerDC);

// 	TextOut(printerDC, 100, 100, L"Hello global ppls!", 13);

// 	EndPage(printerDC);
// 	EndDoc(printerDC);

// 	DeleteDC(printerDC);
// }
