/*
 * ============================================================================
 * Project Name: Corner Grocer Item-Tracking Program
 * File Name:    main.cpp
 * Author:       Jeffrey Alexander
 * Date:         August 12, 2026
 * Course:       CS-210: Programming Languages
 * Institution:  Southern New Hampshire University
 * Description:  An object-oriented C++ program that tracks and analyzes 
 *               grocery purchase frequencies using a map container. It
 *               automatically generates a data backup file and provides
 *               an interactive menu for item search, sorted listings,
 *               and histogram graphics with built-in input validation.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits> // Required for input validation clearing

using namespace std;

// Class to handle all grocery tracking data and actions
class ItemTracker {
private:
    // Private data structure to protect the map from external modification
    map<string, int> frequencyMap;

    // Private method to read the raw input text file
    void loadInputFile() {
        // Automatically create a sample input file if it doesn't exist
        ofstream setupFile("CS210_Project_Three_Input_File.txt");
        if (setupFile.is_open()) {
            setupFile << "Potatoes\nPumpkins\nPotatoes\nOnions\nPumpkins\nPotatoes\nOnions\nPumpkins\nPumpkins\n";
            setupFile.close();
        }

        ifstream inputFile("CS210_Project_Three_Input_File.txt");
        if (!inputFile.is_open()) {
            cout << "Error opening input file!" << endl;
            return;
        }

        string item;
        while (inputFile >> item) {
            frequencyMap[item]++;
        }
        inputFile.close();
    }

    // Private method to write the data backup file automatically at launch
    void createBackupFile() {
        ofstream outputFile("frequency.dat");
        if (outputFile.is_open()) {
            for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
                outputFile << it->first << " " << it->second << endl;
            }
            outputFile.close();
        }
    }

public:
    // Constructor: Automatically initializes and prepares data instantly upon program startup
    ItemTracker() {
        loadInputFile();
        createBackupFile();
    }

    // Public Method for Menu Option 1: Search item frequency
    void searchItemCount() {
        string searchItem;
        cout << "Enter the item name to look up: ";
        cin >> searchItem;
        
        if (frequencyMap.count(searchItem)) {
            cout << searchItem << " " << frequencyMap[searchItem] << endl;
        } else {
            cout << searchItem << " 0" << endl;
        }
    }

    // Public Method for Menu Option 2: Print total frequencies list
    void printAllFrequencies() {
        cout << "\n--- Item Frequencies ---" << endl;
        for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }

    // Public Method for Menu Option 3: Print histogram graph representation
    void printHistogramGraph() {
        cout << "\n--- Item Histogram ---" << endl;
        for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
            cout << it->first << " ";
            for (int i = 0; i < it->second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    // Instantiate our object-oriented tracker class
    ItemTracker tracker;
    int userChoice = 0;

    // Loop system to control interactive user terminal interface
    while (userChoice != 4) {
        cout << "\n=== Corner Grocer Item Tracker ===" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Print total frequencies list" << endl;
        cout << "3. Print histogram graph" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        // --- INPUT VALIDATION CHALLENGE ---
        // If the user inputs a non-integer or letter, handle it safely
        if (!(cin >> userChoice)) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear(); // Clear the error state flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input characters
            continue; // Restart the loop
        }

        if (userChoice == 1) {
            tracker.searchItemCount();
        } else if (userChoice == 2) {
            tracker.printAllFrequencies();
        } else if (userChoice == 3) {
            tracker.printHistogramGraph();
        } else if (userChoice == 4) {
            cout << "Exiting program. Thank you!" << endl;
        } else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }

    return 0;
}
