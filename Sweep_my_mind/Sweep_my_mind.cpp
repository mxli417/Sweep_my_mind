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
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <type_traits>
#include <array>

// Console Color Codes
#define Magenta "\u001b[35m" /* Magenta */
#define Green "\u001b[32m" /* Green */
#define Cyan "\u001b[36m" /* Cyan */
#define Reset  "\033[0m" /* Reset to standard color*/
using namespace std;

// All helper functions declared here
int reset()
{
    cout << Cyan << "MAIN MENU" << endl;
    cout  << "========="  << endl;
    cout << endl;
    cout << "-> For Instructions on how to play, type: 'I'" << endl;
    cout << "-> To play immediately, type 'P'" << endl;
    cout << endl;
    cout << "Type your choice: " << Reset << endl;
    char choice;
    cin >> choice;
    if (tolower(choice) == 'i') 
    {
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

// hilfe dazu: https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
void placeBomb(int solution[9][9], int bombs) 
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 8);

    // define rowcount, colcount dynamically later on here

    for (int i = 1; i <= bombs; i++) 
    {
        // zweimal würfeln im bereich 0-8: position ziehen
        int first_draw = distribution(generator);
        int second_draw = distribution(generator);

        //Bombe platzieren
        if (solution[first_draw][second_draw] == 9)
        {
            i--; // pass or continue in c++
		}
        else
        {
            solution[first_draw][second_draw] = 9;
            // cout << "Placing bomb at: " << first_draw << " / " << second_draw << endl; 
            // randomisierte position funktioniert
            //iterating all fields next to bomb and incrementing their value
            for (int k = first_draw - 1; k <= first_draw + 1; k++)
            {
                for (int l = second_draw - 1; l <= second_draw + 1; l++)
                {
                    if ((k != first_draw || l != second_draw) &&
                        (k >= 0 && l >= 0) &&
                        (k <= 8 && l <= 8)) //If field is not the bomb and field is within the array....
                    {
                        if (solution[k][l] != 9)
                        {
                            solution[k][l]++; //increment field value
                        }
                    }
                }
            }
		}
    }
}

void printBoard(int solution[9][9]) 
{
    // erstmal leerzeilen schreiben 
    for (int i = 0; i < 20; i++) 
    {
        cout << " " << endl;
    }
    // alternativ: flushen https://mathbits.com/MathBits/CompSci/Introduction/clear.htm#:~:text=To%20clear%20the%20screen%20in,to%20%22flush%22%20the%20iostream.
    // dann: Grid Header
    cout << "     A   B   C   D   E   F   G   H   I" << endl;
    cout << "   =====================================" << endl;
    // later: cout << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗" << endl;
    // dann: Grid ausgeben: zeile / spalte 
    for (int i = 0; i < 9; i++) 
    {
        // zeilenstring initialisieren
        cout << i << "  | ";
        //string row; 
        // row = std::to_string(i) + "║";
        for (int j = 0; j < 9; j++) 
        {
            cout << to_string(solution[i][j]) + " | ";
        }
        cout << endl;
    }
    // dann: Grid Footer
    cout << "   =====================================" << endl;
    // later: cout << "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝" << endl;
}

// Main Program routine here - we program everything in functions -> procedural programming
int main()
{
    // Consolenausgabe auf Unicode characters
    // _setmode(_fileno(stdout), _O_U16TEXT);

    // Hier wird eine Reihe von Begrüßungsmessages ausgegeben
    cout << "\n" << endl;
    cout << Magenta << "Welcome to Mine Sweeper 0.1!" << endl;
    cout << Magenta << "============================" << Reset << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    // later here: "Excited to declare version 3.0 of MineSweeper as almost fully functional!"
    // also here: main body of the program 

    // first tip: https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/ -> mit Nullen initialisiert
    int solution_grid[9][9] = {};
    // jetzt mit Bomben "befüllen" 
    int bombs = 8;
    placeBomb(solution_grid, bombs);

    // Dev: Grid ausgeben
    printBoard(solution_grid);
    
    //* program body *//
    //* program body *//
    //* program body *//
    //* program body *//

    // then: 
    reset();
}


// def meine_funktion(a, b):
// soll addition sein 
//  return a + b
// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
