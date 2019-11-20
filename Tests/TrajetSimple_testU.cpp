#include "../Code/TrajetSimple.h"

int main ()
{
    TrajetSimple * ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    ts1->Afficher();
    delete(ts1);
}