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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct PopRec {
		char* postCode;
		int pop;
	};

	void sort();
	bool load(const char file[]);
	bool load(PopRec& popRec);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_