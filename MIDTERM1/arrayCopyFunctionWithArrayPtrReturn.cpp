int *CopyArray(int array[], int length, int value) {
    int valueCount = 0;
    int *newArray;

    for (int i = 0; i < length; i++)
    {
        if (array[i] == value)
            valueCount++;


    }
    int copySize = length - valueCount;
    int z = 0;
     newArray = new int[copySize];
    for (int i = 0; i < length;i++)
    {
        if (array[i] != value)
        {
            newArray[z] = array[i];
            z++;
        }

    }

    return newArray;
}
