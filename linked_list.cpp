/*
 *
 * Written by: James Ross
 */

#include "linked_list.h"

#define FAILURE -1
#define SUCCESS 0


/* node functions */

lll_node::lll_node():m_data(NULL), m_next(NULL){}

lll_node::~lll_node()
{
    if (m_data)
        delete [] m_data;

    m_next = NULL;
}

lll_node*& lll_node::get_next()
{
    return m_next;
}

void lll_node::display()
{
    cout << m_data << endl;
}

int lll_node::set_data(char *data)
{
    size_t len;

    if (!data)
        return FAILURE;
    
    len = strlen(data) + 1;
    m_data = new char[len];
    if (!m_data) {
        cerr << "failed to alloc data" << endl;
        return FAILURE;
    }

    strcpy(m_data, data);

    return SUCCESS;

}

bool lll_node::compare_data(char *data)
{
    if (strcmp(m_data, data) == 0)
        return true;

    return false;
}


/* linked list functions */

linked_list::linked_list():m_head(NULL){}

linked_list::~linked_list()
{
    remove_all(m_head);
}


void linked_list::remove_all(lll_node *current)
{
    if (!current)
        return;

    remove_all(current->get_next());

    delete current;
}

int linked_list::insert(char *data)
{
    if (!data)
        return FAILURE;

    return insert(data, m_head);
}

int linked_list::insert(char *data, lll_node *&head)
{
    if (!head) {
        head = new lll_node;
        if (!head) {
            cerr << "failed to alloc" << endl;
            return FAILURE;
        }

        if (head->set_data(data) == FAILURE)
            return FAILURE;

        return SUCCESS;
    }

    return insert(data, head->get_next());
}

int linked_list::remove(char *data)
{
    if (!data)
        return FAILURE;

    return remove(data, m_head);
}

int linked_list::remove(char *data, lll_node *&head)
{   
    lll_node *tmp;
    if (!head)
        return FAILURE;
    
    if (head->compare_data(data)) {
        tmp = head->get_next();
        delete head;
        head = tmp;
        return SUCCESS;
    }

    return remove(data, head->get_next());
}

void linked_list::display()
{
    display(m_head);
}

void linked_list::display(lll_node *current)
{
    if (!current)
        return;
    current->display(); 
    display(current->get_next());
}
