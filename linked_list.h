/*
 *
 * written by: James Ross
 */


#include <iostream>
using namespace std;
#include <cstring>

class lll_node {
    public:
        lll_node();
        ~lll_node();
        int set_data(char *data);
        char* get_data();
    
        void set_next(lll_node *toset);
        lll_node* get_next();

    private:
        char *m_data;
        lll_node *m_next;
};


class linked_list {
    public:
        linked_list();
        ~linked_list();
        int insert(char *data);
        int remove(char *data);
        int remove_all();
        void display();

    private:
        lll_node *m_head; 
};
