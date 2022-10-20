package Leetcode.Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] answer = null;
            
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) answer = new int[] { i,j };
            }
        }
            
        return answer;
    }
}

public class Two_Sum {
    public static void main(String args[]) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(bufferedReader.readLine());
        int[] nums = new int[n];

        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        int target = Integer.parseInt(bufferedReader.readLine());

        int[] answer = (new Solution()).twoSum(nums, target);

        for (int i = 0; i < answer.length; i++) {
            bufferedWriter.write(String.valueOf(answer[i]) + " ");
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}