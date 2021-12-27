class Solution {

    Pair[] board = {
        new Pair(3, 1),
        new Pair(0, 0),
        new Pair(0, 1),
        new Pair(0, 2),
        new Pair(1, 0),
        new Pair(1, 1),
        new Pair(1, 2),
        new Pair(2, 0),
        new Pair(2, 1),
        new Pair(2, 2),
        new Pair(3, 0),
        new Pair(3, 2)
    };

    StringBuilder sb = new StringBuilder();
    int leftHand = 10;
    int rightHand = 11;

    public String solution(int[] numbers, String hand) {
        for (int num : numbers) {
            if (num == 1 || num == 4 || num == 7) {
                leftTouch(num);
            } else if (num == 3 || num == 6 || num == 9) {
                rightTouch(num);
            } else {
                middleTouch(hand, num);
            }
        }
        return sb.toString();
    }

    private void middleTouch(final String hand, final int num) {
        int leftDist = getDist(leftHand, num);
        int rightDist = getDist(rightHand, num);

        if (leftDist < rightDist) {
            leftTouch(num);
        } else if (leftDist > rightDist) {
            rightTouch(num);
        } else {
            if ("right".equals(hand)) {
                rightTouch(num);
            } else {
                leftTouch(num);
            }
        }
    }

    private void leftTouch(final int num) {
        leftHand = num;
        sb.append("L");
    }

    private void rightTouch(final int num) {
        rightHand = num;
        sb.append("R");
    }

    private int getDist(final int hand, final int num) {
        int xDiff = Math.abs(board[hand].x - board[num].x);
        int yDiff = Math.abs(board[hand].y - board[num].y);
        return xDiff + yDiff;
    }

    public static void main(String[] args) {
        int[][] test = {
            {0, 0},
            {1, 0}
        };

        int[] t = test[0];
    }
}

class Pair {

    int x;
    int y;

    public Pair(final int x, final int y) {
        this.x = x;
        this.y = y;
    }
}