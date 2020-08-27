/*
//反转字符串【https://leetcode-cn.com/problems/reverse-string/】
void reverseString(vector<char>& s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);

    }
}
 /*
 //仅仅反转字母【https://leetcode-cn.com/problems/reverse-only-letters/】
string reverseOnlyLetters(string S)
{
    int start = 0;
    int end = S.size() - 1;
    while (start < end)
    {
        //查找左边第一个字母
        while (start < end)
        {
            if ((S[start] >= 'a' && S[start] <= 'z')
                || (S[start] >= 'A' && S[start] <= 'Z'))
                break;
            start++;
        }
        //查找右边第一个字母
        while (start < end)
        {
            if ((S[end] >= 'a' && S[end] <= 'z')
                || (S[end] >= 'A' && S[end] <= 'Z'))
                break;
            end--;
        }
        if (start < end)
        {
            char tmp = S[start];
            S[start] = S[end];
            S[end] = tmp;
            start++;
            end--;
        }
    }
    return S;
}*/