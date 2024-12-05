import re

regex = r"mul\((\d{1,3}),(\d{1,3})\)"

regex = r"mul\((\d{1,3}),(\d{1,3})\)|(do\(\))|(don't\(\))"
with open("data") as f:
    data = f.read()

r = re.findall(regex, data)
res = 0
e = True
print(r)
for a,b,c,d in r:
    if c:
        e = True
        continue
    elif d:
        e = False
        continue
    if e:
        mul = int(a)*int(b)
        res += mul
        print(a, b, mul, res)
print(res)
