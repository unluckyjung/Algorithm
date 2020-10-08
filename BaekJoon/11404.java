package com.ps.baekjoon;

import java.io.*;
import java.util.StringTokenizer;

public class Boj11404 {
    public static int n;
    public static int [][] moveCost = new int[102][102];
    public static final int INF = 100000 * 100 + 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        costInitSet();
        int m = Integer.parseInt(br.readLine());
        while(--m >= 0){
            int s, e, cost;
            StringTokenizer st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());

            moveCost[s][e] = Math.min(moveCost[s][e], cost);
        }
        floydSolution();

        StringBuilder sb = new StringBuilder();
        for(int i = 1 ; i <= n; ++i){
            for(int ii = 1 ; ii <= n; ++ii){
                if(moveCost[i][ii] == INF) sb.append(0);
                else sb.append(moveCost[i][ii]);    //자동으로 문자열으로 바뀐다. bw는 자동으로 바뀌지 않는다.
                sb.append(" ");
            }
            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
        bw.close();
    }

    private static void floydSolution() {
        for(int v = 1; v <= n; ++v){
            for(int s = 1; s <= n ; ++s){
                for(int e = 1; e <= n; ++e){
                    moveCost[s][e] = Math.min(moveCost[s][e], moveCost[s][v] + moveCost[v][e]);
                }
            }
        }

    }

    public static void costInitSet(){
        for(int i = 1; i <= n; ++i){
            for(int ii = 1; ii <= n; ++ii){
                if(i == ii) continue;
                moveCost[i][ii] = INF;
            }
        }
    }
}
