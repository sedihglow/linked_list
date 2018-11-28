

#include "linked_list.h"


int main(void)
{
    linked_list lll;
    char data[] = {"datain"};
    char d2[] = {"d2"};
    char d3[] = {"d3"};
    
    lll.insert(data);
    lll.insert(d2);
    lll.insert(d3);

    return 0;
}
