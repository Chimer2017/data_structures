string commonRepeatingElement(Product arr[],int length) {
    int tempCount = 0;
    int actualCount = 0;
    string tempname;
    string actualname;

    for (int i = 0; i < length; i++)
    {
        if (arr[i].pname == arr[i+1].pname)
        {   tempname = arr[i].pname;
            while (arr[i].pname == arr[i+1].pname)
            {
                tempCount++;
                i++;


            }
            tempCount++;
        }
        if (tempCount > actualCount)
        {
            actualCount = tempCount;
            actualname = tempname;
        }
    }

    return actualname;
}
