def solution(s):
    # dictionary형 변수 생성
    digits = dict()
    # dictionary의 key값 배열 생성 및 초기화
    subjects = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

    for i, subject in enumerate(subjects):
        # 각 key값에 해당되는 정수를 문자열로 변환하여 digits에 저장한다.
        digits[subject] = str(i)
    
    for subject in subjects:
        if subject in s:
            # s에 key값에 해당하는 문자열이 존재하면 digits의 value값과 치환한다.
            s = s.replace(subject, digits[subject])
    
    return int(s)


if __name__ == "__main__":
    s = input('input : ')
    
    print(solution(s=s))