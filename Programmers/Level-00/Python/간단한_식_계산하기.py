def solution(binomial):
    answer = 0
    
    caches = binomial.split()
    if caches[1] == "+":
        answer = int(caches[0]) + int(caches[2])
    elif caches[1] == "*":
        answer = int(caches[0]) * int(caches[2])
    else:
        answer = int(caches[0]) - int(caches[2])
    
    return answer

if __name__ == "__main__":
    binomial = input()

    answer = solution(binomial=binomial)

    print(answer)