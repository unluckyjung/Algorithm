#if 00
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num <= 0) return false;
        int i = 1;
        while (num > 0)
        {
            num -= i;
            if (num == 0) return true;
            i += 2;
        }
        return false;
    }
};

#elif 01
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int s = 1, e = num;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int candidate = num / mid;

            if (candidate == mid)
            {
                return (num % mid) == 0;
            }
            if (candidate > mid) s = mid + 1;
            if (candidate < mid) e = mid - 1;
        }
        return false;
    }
};

#endif