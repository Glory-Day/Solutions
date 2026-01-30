#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

struct ParseResult
{
    string word;
    int index = -1;
    int mask = 0;
    bool valid = false;
};

string solution(string sentence)
{
    string answer;

    vector<int> positions[26];
    int size = (int)sentence.size();
    for (int i = 0; i < size; i++)
    {
        if (islower(sentence[i]))
        {
            positions[sentence[i] - 'a'].push_back(i);
        }
        else if (isupper(sentence[i]) == false)
        {
            return "invalid";
        }
    }

    unordered_set<unsigned long long> used;
    function<ParseResult(int, int)> try_parse[2];

    try_parse[0] = [&](int index, int mask)
    {
        ParseResult result;

        if (index + 1 >= size)
        {
            return result;
        }

        if (isupper(sentence[index]) == false || islower(sentence[index + 1]) == false)
        {
            return result;
        }

        int j = sentence[index + 1] - 'a';
        if ((mask & (1 << j)) != 0)
        {
            return result;
        }

        if (positions[j].empty() || positions[j][0] != index + 1)
        {
            return result;
        }

        int count = (int)positions[j].size();
        if (positions[j].back() != index + 2 * count - 1)
        {
            return result;
        }

        int e = index + 2 * count;
        if (e >= size || isupper(sentence[e]) == false)
        {
            return result;
        }

        for (int i = 0; i < count; i++)
        {
            int l = index + 1 + 2 * i;
            int r = index + 2 + 2 * i;

            if (l >= size || sentence[l] != sentence[index + 1])
            {
                return result;
            }

            if (r >= size || isupper(sentence[r]) == false)
            {
                return result;
            }
        }

        for (int i = index + 1; i <= e; i++)
        {
            if (islower(sentence[i]) && sentence[i] != sentence[index + 1])
            {
                return result;
            }
        }

        string word;
        for (int i = index; i <= e; i += 2)
        {
            word.push_back(sentence[i]);
        }

        result.word = word;
        result.index = e + 1;
        result.mask = mask | (1 << j);
        result.valid = true;

        return result;
    };

    try_parse[1] = [&](int index, int mask)
    {
        ParseResult result;

        if (index >= size || islower(sentence[index]) == false)
        {
            return result;
        }

        int j = sentence[index] - 'a';
        if ((mask & (1 << j)) != 0)
        {
            return result;
        }

        if ((int)positions[j].size() != 2 || positions[j][0] != index)
        {
            return result;
        }

        if (positions[j][1] == index + 1)
        {
            return result;
        }

        int a = index + 1;
        int b = positions[j][1] - 1;
        if (a > b)
        {
            return result;
        }

        if (isupper(sentence[a]) == false)
        {
            return result;
        }

        bool checked = false;
        for (int i = a; i <= b; i++)
        {
            if (islower(sentence[i]))
            {
                checked = true;

                break;
            }
        }

        if (checked == false)
        {
            for (int i = a; i <= b; i++)
            {
                if (isupper(sentence[i]) == false)
                {
                    return result;
                }
            }

            result.word = sentence.substr(a, b - a + 1);
            result.index = positions[j][1] + 1;
            result.mask = mask | (1 << j);
            result.valid = true;

            return result;
        }

        if (a + 1 > b || islower(sentence[a + 1]) == false)
        {
            return result;
        }

        if (sentence[a + 1] == sentence[index])
        {
            return result;
        }

        int k = sentence[a + 1] - 'a';
        if ((mask & (1 << k)) != 0)
        {
            return result;
        }

        for (int i = a; i <= b; i++)
        {
            if (islower(sentence[i]) && sentence[i] != sentence[a + 1])
            {
                return result;
            }
        }

        if (positions[k].empty() || positions[k][0] != a + 1)
        {
            return result;
        }

        int count = (int)positions[k].size();
        if (positions[k].back() != b - 1)
        {
            return result;
        }

        if (a + 2 * count != b)
        {
            return result;
        }

        for (int i = 0; i < count; i++)
        {
            int l = a + 1 + 2 * i;
            int r = a + 2 + 2 * i;

            if (sentence[l] != sentence[a + 1])
            {
                return result;
            }

            if (isupper(sentence[r]) == false)
            {
                return result;
            }
        }

        string word;
        for (int i = a; i <= b; i += 2)
        {
            word.push_back(sentence[i]);
        }

        result.valid = true;
        result.index = positions[j][1] + 1;
        result.mask = mask | (1 << j) | (1 << k);
        result.word = word;

        return result;
    };

    vector<string> words;

    function<bool(int, int)> dfs = [&](int index, int mask)
    {
        if (index == size)
        {
            for (int i = 0; i < (int)words.size(); i++)
            {
                if (i != 0)
                {
                    answer.push_back(' ');
                }

                answer += words[i];
            }

            return true;
        }

        unsigned long long key = ((unsigned long long)index << 26) | (unsigned long long)mask;

        if (used.find(key) != used.end())
        {
            return false;
        }

        vector<ParseResult> results;
        if (islower(sentence[index]))
        {
            ParseResult result = try_parse[1](index, mask);
            if (result.valid)
            {
                results.push_back(result);
            }
        }
        else
        {
            if (isupper(sentence[index]) == false)
            {
                used.insert(key);

                return false;
            }

            if (index == size - 1)
            {
                ParseResult result;
                result.word = string(1, sentence[index]);
                result.index = size;
                result.mask = mask;
                result.valid = true;
                
                results.push_back(result);
            }
            else if (isupper(sentence[index + 1]))
            {
                int j = index;
                while (j < size && isupper(sentence[j]))
                {
                    j++;
                }

                for (int i = 1; index + i <= j; i++)
                {
                    ParseResult result;
                    result.word = sentence.substr(index, i);
                    result.index = index + i;
                    result.mask = mask;
                    result.valid = true;

                    results.push_back(result);
                }
            }
            else if (islower(sentence[index + 1]))
            {
                ParseResult cache = try_parse[0](index, mask);
                if (cache.valid)
                {
                    results.push_back(cache);
                }

                ParseResult result;
                result.word = string(1, sentence[index]);
                result.index = index + 1;
                result.mask = mask;
                result.valid = true;

                results.push_back(result);
            }
            else
            {
                used.insert(key);

                return false;
            }
        }

        for (auto &result : results)
        {
            words.push_back(result.word);

            if (dfs(result.index, result.mask))
            {
                return true;
            }

            words.pop_back();
        }

        used.insert(key);

        return false;
    };

    if (dfs(0, 0) == false)
    {
        return "invalid";
    }

    return answer;
}

int main()
{
    string sentence;
    cin >> sentence;

    string answer = solution(sentence);

    cout << answer << '\n';

    return 0;
}