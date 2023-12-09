import random
path = "C:\\Users\\maomao\\Desktop\\data\\"
def data_generator():
    # 1~10  1
    with open(path + f"1.in", "w") as f1:
        f1.write(f"3 2\n")
        f1.write(f"1 2 2\n")
        f1.write(f"1 2 1\n")
        f1.write(f"2 3 1\n")
    # 10~100  1
    for i in range(2, 3):
        with open(path + f"{i}.in", "w") as f1:
            n = random.randint(10, 100)
            m = random.randint(n,100000 if(n*(n-1)/2)>100000 else (n*(n-1)/2))
            f1.write(f"{n} {m}\n")
            for i in range(n):
                val1 = random.randint(1, 100)
                f1.write(f"{val1}\n")
            for l in range(m):
                val1 = random.randint(1, n)
                val2 = random.randint(1, n)
                while(val1 == val2):
                    val2 = random.randint(1, n)
                val3 = random.randint(1, 100)
                f1.write(f"{val1} {val2} {val3}\n")
    # 100~1000  4
    for i in range(3, 7):
        with open(path + f"{i}.in", "w") as f1:
            n = random.randint(100, 1000)
            m = random.randint(n,10000 if(n*(n-1)/2)>100000 else (n*(n-1)/2))
            f1.write(f"{n} {m}\n")
            for i in range(n):
                val1 = random.randint(1, 100)
                f1.write(f"{val1}\n")
            for l in range(m):
                val1 = random.randint(1, n)
                val2 = random.randint(1, n)
                while(val1 == val2):
                    val2 = random.randint(1, n)
                val3 = random.randint(1, 100)
                f1.write(f"{val1} {val2} {val3}\n")

    # 1000~3000  3
    for i in range(7, 10):
        with open(path + f"{i}.in", "w") as f1:
            n = random.randint(1000, 3000)
            m = random.randint(n,20000 if(n*(n-1)/2)>100000 else (n*(n-1)/2))
            f1.write(f"{n} {m}\n")
            for i in range(n):
                val1 = random.randint(1, 100)
                f1.write(f"{val1}\n")
            for l in range(m):
                val1 = random.randint(1, n)
                val2 = random.randint(1, n)
                while(val1 == val2):
                    val2 = random.randint(1, n)
                val3 = random.randint(1, 100)
                f1.write(f"{val1} {val2} {val3}\n")

    # 3000~5000  1
    for i in range(10, 11):
        with open(path + f"{i}.in", "w") as f1:
            n = random.randint(3000, 5000)
            m = random.randint(n,30000 if(n*(n-1)/2)>100000 else (n*(n-1)/2))
            f1.write(f"{n} {m}\n")
            for i in range(n):
                val1 = random.randint(1, 100)
                f1.write(f"{val1}\n")
            for l in range(m):
                val1 = random.randint(1, n)
                val2 = random.randint(1, n)
                while(val1 == val2):
                    val2 = random.randint(1, n)
                val3 = random.randint(1, 100)
                f1.write(f"{val1} {val2} {val3}\n")

if __name__ == "__main__":
    data_generator()