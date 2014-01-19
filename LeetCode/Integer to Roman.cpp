class Solution
{
    private:
        string getX(int num)
        {
            switch(num)
            {
                case 0:
                    return "";
                case 1:
                    return "I";
                case 2:
                    return "II";
                case 3:
                    return "III";
                case 4:
                    return "IV";
                case 5:
                    return "V";
                case 6:
                    return "VI";
                case 7:
                    return "VII";
                case 8:
                    return "VIII";
                case 9:
                    return "IX";
                case 10:
                    return "X";
                case 50:
                    return "L";
                case 100:
                    return "C";
                case 500:
                    return "D";
                case 1000:
                    return "M";
            }
            if(num >= 1000)
            {
                string xx = "";
                int n = num / 1000;
                for(int i = 0; i < n; i++)xx += "M";
                return xx + getX(num % 1000);
            }
            if(num >= 900)
            {
                return "CM" + getX(num % 100);
            }
            if(num >= 500)
            {
                string xx = "D";
                for(int i = 0, n = (num - 500) / 100; i < n; i++)xx += "C";
                return  xx + getX(num % 100);
            }
            if(num >= 400)
            {
                return "CD" + getX(num % 100);
            }
            if(num >= 100)
            {
                string xx = "";
                for(int i = 0, n = num / 100; i < n; i++)xx += "C";
                return xx + getX(num % 100);
            }
            if(num >= 90)
            {
                return "XC" + getX(num % 10);
            }
            if(num >= 50)
            {
                string xx = "L";
                for(int i = 0, n = (num - 50) / 10; i < n; i++)xx += "X";
                return xx + getX(num % 10);
            }
            if(num >= 40)
            {
                return "XL" + getX(num % 10);
            }
            if(num >= 10)
            {
                string xx = "";
                for(int i = 0, n = num / 10; i < n; i++)xx += "X";
                return xx + getX(num % 10);
            }
            return "";
        }
    public:
        string intToRoman(int num)
        {
            return getX(num);
        }
};
