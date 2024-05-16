using System;

public class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        double sum = 0;
        foreach(int n in arr)
            sum += n;
        return sum / arr.Length;
    }
}