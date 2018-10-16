#include "Arc.h"

using namespace std;

void Arc::set_id(int i)
{
	id = i;
}
int Arc::get_id()
{
	return id;
}
void Arc::set_orig(int o)
{
	id_orig = o;
}
int Arc::get_orig()
{
	return id_orig;
}
void Arc::set_dest(int d)
{
    id_dest=d;
}
int Arc::get_dest()
{
    return id_dest;
}
void Arc::set_cout(int c)
{
    cout = c;
}
int Arc::get_cout()
{
    return cout;
}
void Arc::afficher()
{
	std::cout << "id=" << id << ":" << id_orig << "->" << id_dest << "cout=" << cout <<endl;
}
