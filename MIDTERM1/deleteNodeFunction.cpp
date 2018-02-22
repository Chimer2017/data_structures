node * DeleteNode(node *head, int value) {

        node *tmp, *current;
        tmp = head;
        current = head;

        while (current != NULL)
        {
            if (current->value == value)
            {
                tmp = current;
                if (tmp == head)
                {
                    head = tmp->next;
                }
                if (tmp->next != NULL)
                {
                    tmp->next->prev = tmp->prev;
                }
                if (tmp->prev != NULL)
                {
                    tmp->prev->next = tmp->next;
                }

                delete tmp;
            }
            current = current->next;


        }

        return head;


}
