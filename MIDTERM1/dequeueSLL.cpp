node* Queue::dequeue() {
    if (head == NULL && tail == NULL)
    {
        /*head = newNode;
        tail = head;
        tail->next = NULL;*/
        //cout << "empty list" << endl;
    }
    else if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *tmp;
        tmp = head;
        head = head->next;
        delete tmp;

    }

    return head;
}
