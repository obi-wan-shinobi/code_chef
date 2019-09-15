try:
    T = int(input())
except EOFError:
    pass
if(T>=1 and T<10**5):
    while(T>0):
        try:
           N = int(input())
        except EOFError:
            pass
        if(N>=1 and N<10**6):
            L = []
            i = 1
            L.append(i)
            N = N-1
            while(N>0):
                i = i+1
                X = L.pop(-1)
                L.append((i+X+i*X)%(10**9 + 7))
                N = N-1

            print(L[0])

        T = T-1
