import os

def canbe(card:str):
    if '3' in card or '4' in card or '7' in card:
        return ''
    else:
        new_card = ""
        card = str(card)
        for i in range(len(card)-1, -1, -1):
            if card[i] == '6':
                new_card+='9'
            elif card[i] == '9':
                new_card+='6'
            else:
                new_card+=card[i]

        return new_card
    
_, desired = str(input()).split(' ')
desired = int(desired)
cards = input().split(' ')
new_cards = []

for card in cards:
    new_card = canbe(card)
    if new_card != card and new_card!='':
        new_cards.append(new_card)
cards += new_cards

import copy

lookup = []
for n in cards:
    x = canbe(n)
    if not str(desired-int(n)) in cards:
        continue
    if str(desired-int(n)) != n and str(desired-int(n)) != x:
        print("YES")
        raise SystemExit
    if str(desired-int(n)) == x and cards.count(x) > 1:
        print("YES")
        raise SystemExit
    if str(desired-int(n)) == n and cards.count(n) > 1:
        print("YES")
        raise SystemExit
print("NO")
