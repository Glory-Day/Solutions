import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 약수의_개수와_덧셈 {
    @FunctionalInterface
    public interface Input {
        public int[] getInputBuffer(String line);
    }

    // 약수의 개수가 홀수일 경우는 제곱수일 경우를 제외하고는 없다.
    // number가 제곱인지 아닌지 판별하는 함수이다.
    public static boolean isSquare(int number) {
        // number의 제곱근을 초과하는 경우는 존재하지 않는다.
        for (int i = 1; i * i <= number; i++) {
            if (i * i == number) {
                return true;
            }
        }
        return false;
    }

    public static int solution(int left, int right) {
        int answer = 0;

        // 만약 숫자가 제곱일 경우 약수의 개수는 홀수임으로, 음수로 변환한다.
        for (int i = left; i <= right; i++) {
            answer += (isSquare(i) ? -i : i);
        }

        return answer;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        Input func = (String line) -> {
            int[] inputs = new int[2];
            StringTokenizer stringTokenizer = new StringTokenizer(line);
            
            for (int i = 0; stringTokenizer.hasMoreTokens(); i++) {
                inputs[i] = Integer.parseInt(stringTokenizer.nextToken());
            }

            return inputs;
        };

        int[] inputs = func.getInputBuffer(bufferedReader.readLine());

        int left = inputs[0];
        int right = inputs[1];

        int answer = solution(left, right);
    
        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.flush();

        bufferedReader.close();
        bufferedWriter.close();
    }
}