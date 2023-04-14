operators = {
    0 : " + ",
    1 : " - ",
    2 : " // ",
    3 : " * "
}

doperators = {
    0 : " + ",
    1 : " - ",
    2 : " / ",
    3 : " * "
}

solutions = {}
for i in range(4):
    for x in range(4):
        for w in range(4):
            exp = f"4{operators[i]}4{operators[x]}4{operators[w]}4"
            editexp = f"4{doperators[i]}4{doperators[x]}4{doperators[w]}4"
            answer = eval(exp)
            solutions[answer] = editexp

iters = input()
for i in range(int(iters)):
    test = input()
    if int(test) in solutions:
        print(solutions[int(test)] + " = " + test)
    else:
        print("no solution")
