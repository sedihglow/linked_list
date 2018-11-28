/*
 *
 * Written by: James Ross
 */

#include "linked_list.h"

#define FAILURE 0
#define SUCCESS 1


/* node functions */
lll_node::lll_node()
{
    m_data = NULL;
    m_next = NULL;
}

lll_node::~lll_node()
{
    delete m_data;
}

int lll_node::set_data(char *data)
{
    size_t len;

    len = strlen(data) + 1;
    m_data = new char[len];
    if (!data) {
        cerr << "Data failed to allocate" << endl;
        return FAILURE;
    }

    strncpy(m_data, data, len);
    return SUCCESS;
}

char* lll_node::get_data()
{
    return m_data;
}

void lll_node::set_next(lll_node *toset)
{
    m_next = toset;
}

lll_node* lll_node::get_next()
{
    return m_next;
}


/* linked list functions */

linked_list::linked_list():m_head(NULL){}

linked_list::~linked_list()
{
}


int linked_list::insert(char *data)
{
    if (!data)
        return FAILURE;

    if (!m_head) {
        m_head = new lll_node;
        m_head->set_data(data);
        return SUCCESS;
    }

    lll_node *temp = new lll_node;
    temp->set_data(data);
    temp->set_next(m_head);
    m_head = temp;

    return SUCCESS;
}
