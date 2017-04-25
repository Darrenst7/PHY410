from root_finding import *
from math import *

def f ( x ) :
#    return exp(x) * log(x) - x * x
    return tanh(x)

#print(" Algorithms for root of exp(x)*log(x) - x*x")
print(" Algorithms for roots of tan(x)")
print(" ------------------------------------------------")

print(" 1. Secant Method")
x0 = float ( input(" Enter initial guess x_0 : ") )
x1 = float ( input(" Enter ending guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_secant(f, x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" 2. Bisection search")
#x0 = float ( input(" Enter bracketing guess x_0 : ") )
#x1 = float ( input(" Enter bracketing guess x_1 : ") )
#acc = float ( input(" Enter accuracy : ") )
answer = root_bisection(f, x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"



