#include "linked_list.h"


int main(void)
{
    linked_list lll;

    char data[] = {"datain"};
    char d2[] = {"d2"};
    char d3[] = {"d3"};

    lll.insert(d2);
    lll.insert(data);
    lll.insert(d3);

    //lll.remove(d2);
    //lll.remove(d3);
    lll.display();
   
    return 0;
}
