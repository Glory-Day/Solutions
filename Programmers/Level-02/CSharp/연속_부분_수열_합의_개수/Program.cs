using System;
using System.Collections.Generic;
using System.Linq;

namespace 연속_부분_합의_개수
{
    public class Solution {
        public int solution(int[] elements) {
            int answer = 0;
            HashSet<int> sums = new HashSet<int>();
            
            var length = elements.Length;
            for (var i = 0; i < length; i++) {
                var sum = 0;
                for (var j = i; j < i + length; j++) {
                    var index = j % length;
                    sum += elements[index];
                    sums.Add(sum);
                }
            }
            
            answer = sums.Count;
            
            return answer;
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            var elements = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();

            var answer = new Solution().solution(elements);

            Console.WriteLine(answer);
        }
    }
}