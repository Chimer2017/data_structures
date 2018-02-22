void findMax() {
    int maxValue = 0;
    Node *current;
    current = head;
    while (current != NULL)
    {
        if ( current->key > maxValue)
        {
            maxValue = current->key;
        }
        current = current->next;
    }
    cout << maxValue << endl;





}
