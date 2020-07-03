// Sweep_my_mind.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
// Das Programm soll das bekannte Spiel "Mine Sweeper" sein, dass hier als Konsolenapplikation umgesetzt werden soll.
// Eine gute Einführung in die Logik des Programms und eine Umsetzung mit Python liefert: 
// https://repl.it/talk/learn/How-to-program-MineSweeper-in-Python-fully-explained-in-depth-tutorial/9397
// Dieselbe Programmlogik soll hier in Form einer C++ Console App umgesetzt werden (mit / ohne Erweiterungen).
// Dies ist eine Coding-Challenge, die unter Freunden gelöst wird.

#include <iostream>
#include <fstream>
#include <string>
#include <random>
// Console Color Codes
#define Magenta "\u001b[35m" /* Magenta */
#define Green "\u001b[32m" /* Green */
#define Cyan "\u001b[36m" /* Cyan */
#define Reset  "\033[0m" /* Reset to standard color*/
using namespace std;

// All helper functions declared here
int reset()
{
    cout << Cyan << "MAIN MENU" << Reset << endl;
    cout << Cyan << "=========" << Reset << endl;
    cout << "\n" << endl;
    cout << Cyan << "-> For Instructions on how to play, type: 'I'" << Reset << endl;
    cout << Cyan << "-> To play immediately, type 'P'" << Reset << endl;
    cout << "\n" << endl;
    cout << Cyan << "Type your choice: " << Reset << endl;
    char choice;
    cin >> choice;
    if (tolower(choice) == 'i') {
        // cout << Cyan << "Now, we print the instructions!" << endl;
        // Read instructions from Text File and display them, line by line
        // Got this from: https://www.tutorialspoint.com/read-file-line-by-line-using-cplusplus#:~:text=file%20object%20%7D%20newfile.-,open(%22tpoint.,data%20of%20the%20string%20%7D%20newfile.
        fstream instfile;
        instfile.open("instructions.txt", ios::in);
        if (instfile.is_open()) {   //checking whether the file is open
            string tp;
            while (getline(instfile, tp)) { //read data from file object and put it into string.
                cout << tp << "\n"; //print the data of the string
            }
            instfile.close(); //close the file object.
        }
        else {
            cout << "There was a problem with the text_file!" << endl;
        }
    } else if (tolower(choice) != 'P') {
        // call the function itself again (recursion)
        reset();
    }
    // return a value with the function (mandatory)
    return 1;
}

// Main Program routine here - we program everything in functions -> procedural programming
int main()
{
    // Hier wird eine Reihe von Begrüßungsmessages ausgegeben
    cout << "\n" << endl;
    cout << Magenta << "Welcome to Mine Sweeper 0.1!" << Reset << endl;
    cout << Magenta << "============================" << Reset << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    // later here: "Excited to declare version 3.0 of MineSweeper as almost fully functional!"
    // also here: main body of the program 
    //* program body *//
    //* program body *//
    //* program body *//
    //* program body *//
    // then: 
    reset();
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
