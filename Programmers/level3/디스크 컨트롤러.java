import java.util.PriorityQueue;

class Solution {
    int readyTime;
    int curTime;
    PriorityQueue<Job> jobPq = new PriorityQueue<>();
    PriorityQueue<Ready> readyPq = new PriorityQueue<>();

    public int solution(int[][] jobs) {
        int jobCount = jobs.length;
        for (int[] job : jobs) {
            jobPq.add(new Job(job[0], job[1]));
        }

        while (!(jobPq.isEmpty() && readyPq.isEmpty())) {
            work();
            jobQMoveToReadyQ();
        }

        return readyTime / jobCount;
    }

    private void work() {
        if (readyPq.isEmpty()) {
            Job selectJob = jobPq.remove();
            curTime = selectJob.callTime + selectJob.needTime;
            readyTime += curTime - selectJob.callTime;
        } else {
            Ready selectJob = readyPq.remove();
            curTime += selectJob.needTime;
            readyTime += curTime - selectJob.callTime;
        }
    }

    private void jobQMoveToReadyQ() {
        while (!jobPq.isEmpty() && jobPq.element().callTime <= curTime) {
            readyPq.add(new Ready(jobPq.element().needTime, jobPq.element().callTime));
            jobPq.remove();
        }
    }
}

class Job implements Comparable<Job> {
    int callTime;
    int needTime;

    public Job(final int callTime, final int needTime) {
        this.callTime = callTime;
        this.needTime = needTime;
    }

    @Override
    public int compareTo(final Job o) {
        if (this.callTime == o.callTime) return Integer.compare(this.needTime, o.needTime);
        return Integer.compare(this.callTime, o.callTime);
    }
}

class Ready implements Comparable<Ready> {
    int needTime;
    int callTime;

    public Ready(final int needTime, final int callTime) {
        this.needTime = needTime;
        this.callTime = callTime;
    }

    @Override
    public int compareTo(final Ready o) {
        if (this.needTime == o.needTime) return Integer.compare(this.callTime, o.callTime);
        return Integer.compare(this.needTime, o.needTime);
    }
}
