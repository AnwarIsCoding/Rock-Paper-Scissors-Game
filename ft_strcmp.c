int ft_strcmp(char *str1, char *str2)
{
    int i;
    i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] == str2[i])
            i++;
        else
            return str1[i] - str2[i];
    }
}