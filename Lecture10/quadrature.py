from trapezoid import *
from simpson import *
from math import *



n1 = 1
n2 = 0

while n1 % 2 != 0 :
    n1 = int(raw_input( "Enter number of intervals desired for trapezoidal rule (must be even)" ))

#a = 0
#b = 2 * atan(1.0)
a = 0
b = 1.0
ans1 = trapezoid(exp, a, b, n1)
print 'Trapezoidal rule = ' + str(ans1)
print 'Difference using the Trapezoidal method = ' + str(abs(ans1 - (exp(1)-1)))

ans2 = simpson(exp, a, b, n1)
print 'Simpsons rule = ' + str(ans2)
print 'Difference using the Simpsons method = ' + str(abs(ans2 - (exp(1)-1)))
