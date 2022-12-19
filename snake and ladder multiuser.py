import random as r
sl = {17: 6, 26: 3, 43: 21, 55: 33, 59: 8, 75: 10, 97: 1, 19: 39,
      16: 28, 30: 50, 41: 61, 52: 72, 63: 83, 74: 94, 66: 96}
d = [1, 2, 3, 4, 5, 6]


def print_chart(l, sc):
    x = 100
    print(
        "\t\t \033[1m ---------------------------------------------------------------------------------------")
    for i in range(1, 11):
        print("\t\t | ", end="\t")
        for j in range(1, 11):
            if x in sl:
                if sl[x] > x:
                    print("\033[33m#\033[39m", end="\t")
                else:
                    print("\033[31m🐍\033[39m", end="\t")
            else:
                if sc.count(x) == 1:
                    print("\033[31m"+l[sc.index(x)][1]+"\033[39m", end="\t")
                elif sc.count(x) > 1:
                    print("≚", end="\t")
                else:
                    print(x, end="\t")
            x -= 1
        print(" |")
    print(
        "\t\t  ---------------------------------------------------------------------------------------\033[22m")


def play(name, m):
    print("\t\033[1m \033[35m its "+name+"'s turn\033[39m \033[1m")
    n = int(input(
        "\t\033[1m \033[35m No of times to shuffle the dice : \033[39m \033[1m"))
    for i in range(n):
        r.shuffle(d)
    k = r.choice(d)
    print("\t \033[1m \033[33m"+name+" number is : \033[22m\033[39m", k)
    if m+k > 100:
        print("\t\t\t\t\t\033[1m  \033[36m"+name+" need "+str(100 - m) +
              " steps to win not ", k, " steps \033[1m\033[39m")
        return m
    else:
        m += k
        if m == 100:
            return 100
        elif m in sl:
            if sl[m] > m:
                print("\t\t\t\t\t\t\033[1m\033[32m  "+name+" climber from " +
                      str(m)+" -> "+str(sl[m])+"\033[22m\033[39m")
                m = sl[m]
            else:
                print("\t\t\t\t\t  \033[31m\033[1m"+name +
                      " was biten by a snake and reached to "+str(sl[m])+" \033[22m\033[39m")
                m = sl[m]
        if k == 6:
            return play(name, m)
        return m


print("\t\t\t\t\t \033[1m    let's play Snake and Ladder game ")
n = int(input("\tEnter number of players : "))
s = "QWERTYUIOASDFGHJKLZXCVBNM"
l = []
sc = []
for i in range(0, n):
    name = input("\tEnter name of player "+str(i+1) + " : ")
    l.append([name, s[i]])
    sc.append(0)
for i in range(0, n):
    print("\t"+l[i][0]+" player symbol is - "+l[i][1])
winners = []
while len(winners) != n-1:
    i = 0
    while i < len(sc):
        sc[i] = play(l[i][0], sc[i])
        print_chart(l, sc)
        if sc[i] == 100:
            print("\t\t\t\t\t\t\033[1m\033[32m  " +
                  l[i][0]+" reached the destination\033[1m\033[39m")
            winners.append(l[i][0])
            l.pop(i)
            sc.pop(i)
        i += 1
    for i in range(0, len(sc)):
        print("\t\t\t\t\t\t\033[1m\033[33m-- " +
              l[i][0]+"( "+l[i][1]+" )"+" is at : "+str(sc[i])+" --")
for i in range(0, len(winners)):
    print("\t\t\t\t\t"+str(i+1)+" place : "+winners[i])
    print("\t\t\t\t\t"+str(len(winners)+1) +
          " place : "+l[0][0]+"\033[22m\033[39m")
