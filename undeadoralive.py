from sys import stdin

message = stdin.readline()

start = 0
smiley = False
frown = False

while start + 1 < len(message):
    if message[start:start+2] == ':)':
        smiley = True
    if message[start:start+2] == ':(':
        frown = True
    start += 1

if frown and smiley:
    print("double agent")
elif frown:
    print("undead")
elif smiley:
    print("alive")
else:
    print("machine")