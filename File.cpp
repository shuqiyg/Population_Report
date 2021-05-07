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
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* postCode) {
       return fscanf(fptr, "%3s,", postCode) == 1 ? true : false;
   }

   bool read(int& pop) {
       return fscanf(fptr, "%d", &pop) == 1 ? true : false;
   }
}