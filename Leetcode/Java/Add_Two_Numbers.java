package Leetcode.Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode answer = null;

        if (l1 == null || l2 == null) {
            return (l1 == null) ? l2 : l1;
        }
        else {
            int sum = l1.val + l2.val;
            if (l1.next == null) {
                if(sum >= 10) {
                    l1.next = new ListNode(1, null);
                    sum -= 10;
                }
            }
            else if (l2.next == null) {
                if (sum >= 10) {
                    l2.next = new ListNode(1, null);
                    sum -= 10;
                }
            }
            else {
                if (sum >= 10) {
                    l1.next.val += 1;
                    sum -= 10;
                }
            }

            ListNode next = addTwoNumbers(l1.next, l2.next);
            answer = new ListNode(sum, next);
        }
        
        return answer;
    }
}

public class Add_Two_Numbers {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(bufferedReader.readLine());
        int[] inputs = new int[n];

        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 0; i < n; i++) {
            inputs[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        ListNode l1 = new ListNode(inputs[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            l1 = new ListNode(inputs[i], l1);
        }

        n = Integer.parseInt(bufferedReader.readLine());
        inputs = new int[n];

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i = 0; i < n; i++) {
            inputs[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        ListNode l2 = new ListNode(inputs[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            l2 = new ListNode(inputs[i], l2);
        }

        ListNode answer = (new Solution()).addTwoNumbers(l1, l2);

        while (answer.next != null) {
            bufferedWriter.write(String.valueOf(answer.val) + " ");
            answer = answer.next;
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}
