import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 로또의_최고_순위와_최저_순위 {
    @FunctionalInterface
    public interface Rank {
        public int getRank(int count);
    }

    @FunctionalInterface
    public interface Input {
        public int[] getInputBuffer(String line);
    }

    public static int[] solution(int[] lottos, int[] win_nums) {
        // 정답 번호의 개수.
        int win_nums_count = win_nums.length;
        // lottos에서 0의 개수.
        int zero_count = 0;
        // lottos의 번호와 win_nums의 번호가 일치하는 횟수.
        int win_count = 0;

        // lottos에서 0의 개수를 세어 zero_count에 저장한다.
        for (var lotto: lottos) {
            zero_count += ((lotto == 0) ? 1 : 0);
        }

        Arrays.sort(win_nums);

        // lottos의 번호와 win_nums의 번호가 일치하는만큼 win_count에 1씩 증가시킨다.
        for (int i = 0; i < lottos.length; i++) {
            win_count += ((Arrays.binarySearch(win_nums, lottos[i]) >= 0) ? 1 : 0);
        }

        // win_nums의 개수에 win_count를 뺀다.
        // lottos의 번호와 win_nums의 번호가 일치하는 번호는 0에 들어갈 수 없기 때문이다.
        win_nums_count -= win_count;

        // 최소로 win_nums와 일치하는 횟수.
        int min_win_count = win_count;
        // 최대로 win_nums와 일치하는 횟수.
        // zero_count가 win_nums_count보다 작거나 같으면, 모든 zero_count에 win_nums의 번호를 넣을 수 있다.
        // zero_count가 win_nums_count보다 크면, 모든 win_nums의 번호들이 들어가고 나머지 번호들이 0에 들어간다.
        int max_win_count = ((zero_count <= win_nums_count) ? zero_count : win_nums_count) + win_count;

        // rank를 반환하는 lambda식
        Rank func = (int count) -> (7 - count) < 6 ? 7 - count : 6;

        // answer를 저장하고 반환한다.
        int[] answer = { func.getRank(max_win_count),func.getRank(min_win_count) };
        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        Input func = (String line) -> {
            int[] inputs = new int[6];
            StringTokenizer stringTokenizer = new StringTokenizer(line);
            
            for (int i = 0; stringTokenizer.hasMoreTokens(); i++) {
                inputs[i] = Integer.parseInt(stringTokenizer.nextToken());
            }

            return inputs;
        };

        int[] lottos = func.getInputBuffer(bufferedReader.readLine());
        int[] win_nums = func.getInputBuffer(bufferedReader.readLine());

        int[] answer = solution(lottos, win_nums);

        for (int i = 0; i < answer.length; i++) {
            bufferedWriter.write(answer[i] + " ");
            bufferedWriter.flush();
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}