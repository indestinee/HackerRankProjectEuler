t = int(input())
import math
while t > 0:
    t -= 1
    n = int(input())
    x = math.factorial(n)
    ans = 0
    while x > 0:
        ans += x % 10
        x //= 10
    print(ans)
