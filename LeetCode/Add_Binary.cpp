
class Solution
{
    public:
        string addBinary(string a, string b)
        {
            int lena = a.length(), lenb = b.length();
            string aa = reverse(a, lena);
            string bb = reverse(b, lenb);

            int carry = 0, i = 0;

            string result;

            while (carry || i < lena || i < lenb)
            {
                int xa = i < lena ? aa[i] - '0' : 0;
                int xb = i < lenb ? bb[i] - '0' : 0;
                int sum = xa + xb + carry;

                carry = sum / 2;

                result.push_back('0' + (sum % 2));

                ++i;
            }

            return reverse(result, result.length());
        }

        string reverse(string s, int len)
        {

            for (int i = 0; i < len / 2; i++)
            {
                char ch = s[i];
                s[i] = s[len - i - 1];
                s[len - i - 1] = ch;
            }

            return s;
        }
};
