class Solution
{
    private:
        bool isDigit(char ch)
        {
            if(ch <= '9' && ch >= '0')return true;
            return false;
        }
    public:
        bool isNumber(const char *s)
        {
            if(s == NULL)return false;

            int len = strlen(s);
            int pos_op = -1, pos_f = -1, pos_dot = -1, pos_e = -1, i = 0;
            bool has_num = false, other_char = false;
            bool digit_before_e = false, digit_before_dot = false;
            while(i < len && (s[i] == ' ' || s[i] == '\t'))++i;
            --len;
            while(len >= i && (s[len] == ' ' || s[len] == '\t'))--len;
            ++len;
            if(i == len)return false;

            for(int j = i; j < len; j++)
            {
                char ch = s[j];
                if(ch <= '9' && ch >= '0')
                {
                    has_num = true;
                    if(pos_e == -1)digit_before_e = true;
                    if(pos_dot == -1)digit_before_dot = true;
                }
                else if(ch == '.')
                {
                    if(pos_dot != -1)return false;
                    pos_dot = j;
                }
                else if(ch == 'e')
                {
                    if(pos_e != -1)return false;
                    pos_e = j;
                }
                else if(ch == 'f')
                {
                    /*if(pos_f != -1 || j != len - 1 || (j == len - 1 && !has_num))return false;
                    pos_f = j;*/
					return false;
                }
                else if(ch == '-' || ch == '+')
                {
                    if(j == len - 1 || j != i && (pos_e == -1 || pos_e != -1 && pos_e != j - 1))return false;
                    pos_op = j;
                }
                else
                {
                    other_char = true;
                }
            }
            if(!has_num || other_char || pos_e != -1 && !digit_before_e)return false;
            if(pos_e != -1 && pos_f != -1)return false;
            if(s[i] == 'e' || s[len - 1] == 'e')return false;
            if(pos_e != -1 && pos_dot != -1 )
            {
                if(pos_dot > pos_e)return false;
                if(pos_e - pos_dot == 1 && pos_dot == i)return false;
            }
            return true;
        }
};