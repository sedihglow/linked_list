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
        
        bool compare_data(char *data);
        int set_data(char *data);

        lll_node*& get_next();
        void display();

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
        void remove_all(lll_node *current);
        void display();

    private:
        int remove(char *data, lll_node *&head);
        int insert(char *data, lll_node *&head);
        void display(lll_node *current);
        lll_node *m_head; 
};
