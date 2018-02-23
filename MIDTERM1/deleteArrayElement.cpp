int ShiftArray(Product arr[],int size,int target) {
    //int newSize = size;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].price == target)
        {
            for (int x = i; x < size - 1; x++)
            {
                arr[x].pname = arr[x+1].pname;
                arr[x].price = arr[x+1].price;

            }
            size -= 1;

        }
    }

    return size;


}
