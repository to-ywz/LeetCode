#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SAMP_NUM 10

bool isIsomorphic(char *s, char *t)
{
    int len = strlen(s);
    unsigned char sHash[26] = {0}, tHash[26] = {0};

    if (!len)
        return true;

    for (int i = 0; i < len; i++)
    {
        if (!sHash[s[i] - 'a'])
        {
            sHash[s[i] - 'a'] = i + 1;
        }
        if (!tHash[t[i] - 'a'])
        {
            tHash[t[i] - 'a'] = i + 1;
        }
        if (tHash[t[i] - 'a'] != sHash[s[i] - 'a'])
            return false;
    }
    return true;
}

int main(void)
{
    char stra[100] = "";
    char strb[100] = "";

    scanf("%s", stra);
    getchar();
    scanf("%s", strb);

    printf("%s", isIsomorphic(stra, strb) == true ? "true" : "false");

    return 0;
}