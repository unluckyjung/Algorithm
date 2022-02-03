class Result {

    /*
     * Complete the 'repeatedString' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. LONG_INTEGER n
     */

    public static long repeatedString(String s, long n) {
        long answer = 0;

        int[] aCount = new int[102];
        if (s.charAt(0) == 'a') aCount[0] = 1;

        for (int i = 1; i < s.length(); ++i) {
            aCount[i] = aCount[i - 1];
            if (s.charAt(i) == 'a') aCount[i]++;
        }

        answer += aCount[s.length() - 1] * (n / s.length());

        int leftLen = (int) (n % s.length());
        if (leftLen != 0) {
            answer += aCount[leftLen - 1];
        }

        return answer;
    }
}