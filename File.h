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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* postCode);
   bool read(int& pop);
}
#endif // !SDDS_FILE_H_
