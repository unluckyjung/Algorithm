class Solution {

    public int maxProfit(int[] prices) {
        int minPrice = prices[0];
        int maxDiff = 0;

        for (int i = 1; i < prices.length; ++i) {
            minPrice = Math.min(minPrice, prices[i]);
            maxDiff = Math.max(maxDiff, prices[i] - minPrice);
        }

        return maxDiff;
    }
}
