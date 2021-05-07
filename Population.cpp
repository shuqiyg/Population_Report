/* W02 DIY
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 01-27-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    int noOfRec;
    PopRec* popRecs;
    int totalPop = 0;

    void sort() {
        int i, j;
        PopRec temp;
        for (i = noOfRec - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (popRecs[j].pop > popRecs[j + 1].pop) {
                    temp = popRecs[j];
                    popRecs[j] = popRecs[j + 1];
                    popRecs[j+1] = temp;
                }
            }
        }
    }

    bool load(PopRec& popRec) {
        bool ok = false;
        popRec.postCode = new char[4];
        if (read(popRec.postCode) && read(popRec.pop)) {
            ok = true;
        }
        return ok;
    }

	bool load(const char file[]) {
        bool ok = false;
        int i;
        
        if (openFile(file)) {
            int read = 0;
            noOfRec = noOfRecords();
            popRecs = new PopRec[noOfRec];
            for (i = 0; i < noOfRec; i++) {
                if (load(popRecs[i])) {
                    read++;
                    totalPop += popRecs[i].pop;
                }
            }
            if (noOfRec == read) {
                ok = true;
            }
            else {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
        }
        else {
            cout << "Could not open data file: " << file << endl;
        }
        closeFile();
        return ok;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfRec; i++) {
            cout << i + 1 << "- " << popRecs[i].postCode << ":  " << popRecs[i].pop << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPop << endl;
    }

    void deallocateMemory() {
        for (int i = 0; i < noOfRec; i++) {
            delete[] popRecs[i].postCode;
            popRecs[i].postCode = nullptr;
        }
        delete[] popRecs;
        popRecs = nullptr;
    }
}