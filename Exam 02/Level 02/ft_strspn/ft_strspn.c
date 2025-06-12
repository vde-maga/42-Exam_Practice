size_t  ft_strspn(const char *s, const char *accept)
{
    size_t  size;
    const char *ptr;

    size = 0;
    while (s[size])
    {
        ptr = accept;
        while (*ptr)
        {
            if (s[size] == *ptr)
                break;
            ptr++;
        }
        if (!*ptr)
            return (size);
        size++;
    }
    return (size);
}

/*

Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

*/