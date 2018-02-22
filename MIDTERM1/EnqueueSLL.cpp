void Queue::enqueue(node *newNode) {
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = head;
        tail->next = NULL;
    }
    else
    {
        node *tmp;
        tmp = tail;
        tail = newNode;
        tmp->next = tail;
        tail->next = NULL;
    }










}
