#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED

#include <iostream>

class Arc
{
protected:
	int id;
	int id_orig;
	int id_dest;
	int cout;
public:
	//Arc();
	void set_id(int); int get_id();
	void set_orig(int); int get_orig();
	void set_dest(int); int get_dest();
	void set_cout(int); int get_cout();
	void afficher();
	//~Arc();
};

#endif // ARC_H_INCLUDED
