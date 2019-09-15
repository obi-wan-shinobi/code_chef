try:
    T = int(input())
except EOFError:
    pass

if(T>=1 and T<=1000):
    while(T>0):
        try:
            line = input()
        except EOFError:
            pass

        N,Z = line.split(" ")
        N = int(N)
        Z = int(Z)
        if(N>=1 and Z<=10**6):
            A = []
            try:
                i = input()
            except EOFError:
                pass
            i = i.split(" ")
            while(N>0):
                n = i.pop(0)
                n = int(n)
                A.append(n)
                N = N-1

            while(Z!=0):
                for i in range(0,len(A)-1):
                    if(A[i] == 0 and A[i+1] == 1):
                        A[i],A[i+1] = A[i+1],A[i]
                Z = Z-1

            print(A)
        T=T-1
