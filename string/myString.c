/*
* @brief : 实现 strlen / strcmp / strcpy / strcat / strchr / strstr
* @time : 2024/4/4
* @author : 熊锦
*/

#include <stdio.h>
// the length of C style string, except \0
size_t my_strlen(const char* pStr)
{
    size_t cnt = 0;
    while (*pStr != '\0')
    {
        ++cnt;
        ++pStr;
    }
    return cnt;
}

// compare 2 C style string alphabetically
int my_strcmp(const char* pStr1, const char* pStr2)
{
    while (*pStr1 && *pStr2)
    {
        if (*pStr1 > *pStr2)
        {
            return 1;
        }
        else if (*pStr1 < *pStr2)
        {
            return -1;
        }
        ++pStr1;
        ++pStr2;
    }

    if (*pStr1)
    {
        return 1;
    }

    if (*pStr2)
    {
        return -1;
    }
    return 0;
}

// copy src to dest
char* my_strcpy(char* dest, const char* src)
{   
    while (*src != '\0')
    {
        *dest = *src;
        ++src;
        ++dest;
    }
    *dest = '\0';
    return dest;
}

// append src to dest
char* my_strcat(char* dest, const char* src)
{
    while (*dest != '\0')
        ++dest;
    while (*src != '\0')
    {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
    return dest;
}

// find first match character
char* my_strchr(const char* str, int character)
{
    while (*str != '\0')
    {
        if (*str == character)
        {
            return (char*)str;
        }
        ++str;
    }
    return NULL;
}

// find first match substr, return the first position of substr in str
// 用了滑动窗口的思想，实际是暴力匹配，因为 C 没有散列容器。
// 用KMP算法更好
char* my_strstr(const char* str, const char* substr)
{
    if (! *substr)
        return NULL;
    if (! *str)
        return NULL;

    int left = 0, right = 0;
    const int str_len = my_strlen(str);// [0, str_len)
    const int substr_len = my_strlen(substr); 

    while (right < str_len)
    {
        ++right;

        while (right - left == substr_len)
        {
            // compare
            for (int pos = left; pos < right; ++pos)
            {
                if (str[pos] != substr[pos - left]) break;// compare each char
                // all char matched, return window left
                if (pos == right - 1) return (char*) str + left; 
            }
            // this time match failed
            ++left;
        }
    }
    // all times match failed
    return NULL;
}



// int main()
// {
//     // size_t len = my_strlen("hello");
//     // printf("len = %d" , len);

//     // int ans = my_strcmp("hello", "helloz");
//     // printf("ans = %d" , ans);

//     // char str[10];
//     // my_strcpy(str, "hello");
//     // for(int i = 0; i < 10; ++i)
//     // {
//     //     printf("%c", str[i]);
//     // }

//     // char dest[20] = "hello";
//     // char src[] = ", vvvv";
//     // my_strcat(dest, src);
//     // for(int i = 0; i < 20; ++i)
//     // {
//     //     printf("%c", dest[i]);
//     // }

//     // char dest[20] = "hello , my word";
//     // char* pos = my_strchr(dest, 'o');
//     // printf("%s", pos);

//     char str[64] = "hello, word! this is my word.";
//     char substr[5] = "wo";
//     char* ans = my_strstr(str, substr);
//     printf("ans = %s\n", ans);
//     ans[0] = 'z';
//     printf("ans = %s\n", ans);
//     return 0;
// }