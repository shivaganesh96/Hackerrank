// Leetcode - 829.Consecutive Numbers Sum


class Solution {
    public int consecutiveNumbersSum(int N) {
        int sum = 0;
        int lowest = 1;
        int current = 2;
        int answer = 1;
        sum = lowest;
        while (lowest + current <= N ){
            if (sum + current < N){
               // System.out.println ("sum="+ sum + "current="+ current + "lowest=" + lowest);
                sum = sum + current;
                current++;
            }
            else if (sum + current > N){
               // System.out.println ("sum="+ sum + "current="+ current + "lowest=" + lowest);
                sum = sum - lowest;
                lowest++;
            }
            else if (sum + current == N){
             //  System.out.println ("sum="+ sum + "current="+ current + "lowest=" + lowest + "BINGO");
                answer++;
                sum = sum + current;
                current++;
            }
            
        }
        return answer;
    }
}
