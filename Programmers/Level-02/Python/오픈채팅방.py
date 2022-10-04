def solution(record):
    answer = []
    
    # 아이디를 key로 닉네임을 value로 저장하는 사전형 변수를 선언한다.
    d = {}
    
    # 사전형 변수를 초기화한다. 
    for i in record:
        # 문자열을 ' ' 단위로 나눈다.
        l = i.split()
        
        # "Leave"가 앞에 붙은 문자열은 아이디와 닉네임을 가지지 않음으로 제외한다.
        if l[0] != "Leave": 
            # 아이디를 key로 닉네임을 value로 저장한다.
            d[l[1]] = l[2]
    
    
    for i in record:
        # 문자열을 ' ' 단위로 나눈다.
        l = i.split()
        
        # "Change"가 앞에 붙은 문자열은 기록에 남기지 않는다.
        if l[0] != "Change":
            if l[0] == "Enter":
                answer.append(d[l[1]] + "님이 들어왔습니다.")
            else:
                answer.append(d[l[1]] + "님이 나갔습니다.")
    
    return answer

if __name__ == "__main__":
    record = []
    
    n = int(input("Input Count : "))
    for i in range(0, n):
        record.append(input())
    
    answer = solution(record=record)
    
    for i in answer:
        print(i, end='\n')
    