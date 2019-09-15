def proxy():
    try:
        T = int(input())
    except EOFError:
        pass
        if(T<=0 or T>200):
            return

    while(T>0):
        try:
            D = int(input())
        except EOFError:
            pass

            S = input()
            if(S.len()>D):
                return

            tokens = S.split()

            T = T - 1

proxy()
