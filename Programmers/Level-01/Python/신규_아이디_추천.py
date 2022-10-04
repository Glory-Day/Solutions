import re


# new_id의 모든 대문자를 소문자로 변경한다.
def upper_to_lower(new_id: str) -> str:
    return new_id.lower()


# new_id에서 알파벳 소문자, 숫자, '-', '_', '.'를 제외한 모든 문자를 제거한다.
def remove_characters(new_id: str) -> str:
    def check(character: str) -> bool:
        return character.isalpha() or character.isdigit() or character == '-' or character == '_' or character == '.'

    # new_id의 문자를 순회하면서 check()에 넣어 True를 반환하면 ''로 문자를 치환한다.
    return ''.join([character for character in new_id if check(character=character) is True])


# new_id에서 '.'가 2번 이상 연속된 부분을 하나의 '.'로 치환한다.
def unique(new_id: str) -> str:
    return re.sub('(([.])\\2+)', '.', new_id)


# new_id에서 '.'가 처음이나 끝에 위치한다면 제거한다.
def remove_dot(new_id: str) -> str:
    return new_id.strip('.')


# new_id가 빈 문자열이라면, new_id에 "a"를 대입한다.
def is_empty(new_id: str) -> str:
    return 'a' if new_id == '' else new_id


# new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거한다.
# 만약 제거 후 '.'가 new_id의 끝에 위치한다면 끝에 위치한 '.' 문자를 제거한다.
def substring(new_id: str) -> str:
    return remove_dot(new_id=new_id[:15]) if len(new_id) >= 16 else new_id


# new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙힌다.
def add_string(new_id: str) -> str:
    length = len(new_id)
    if length <= 2:
        count = 3 - length
        return new_id + (new_id[length - 1] * count)
    else:
        return new_id


def solution(new_id):
    answer = upper_to_lower(new_id=new_id)
    answer = remove_characters(new_id=answer)
    answer = unique(new_id=answer)
    answer = remove_dot(new_id=answer)
    answer = is_empty(new_id=answer)
    answer = substring(new_id=answer)
    answer = add_string(new_id=answer)
    
    return answer


if __name__ == "__main__":
    new_id = input('input : ')
    
    print(solution(new_id=new_id))
