def solution(absolutes, signs):
    answer = 0
    
    for i, absolute in enumerate(absolutes):
        # signs가 True일 경우 양수이다.
        if signs[i]:
            answer = answer + absolute
        # signs가 False일 경우 음수이다.
        else:
            answer = answer - absolute
    
    return answer


if __name__ == '__main__':
    absolutes = list(map(int, input('absolutes : ').split()));
    signs = list(map(int, input('signs : ').split()));
    signs = list(map(bool, signs));
    
    print(solution(absolutes=absolutes, signs=signs))