deff('y=f(x)','y=x^4')
a=input("Enter Lower Limit: ")
b=input("Enter Upper Limit: ")
n=input("Enter number of sum intervals: ")
h=(b-a)/n
add1=0
add2=0
add3=0
for i=0:n
    x=a+i*h
    y=f(x)
    disp([x y])
    if (i==0)|(i==n) then
        add1=add1+y
        else if (modulo(i,2)==0) then
        add2=add2+y
    else
        add3=add3+y
    end
end
end
I=(h/3)*(add1+2*add2+4*add3)
disp(I,"Integration by Simpsons (1/3)rd Rule is:")
//
//Enter Lower Limit: -3
//
//Enter Upper Limit: 3
//
//Enter number of sum intervals: 6
//
//
//  -3.   81.
//
//  -2.   16.
//
//  -1.   1.
//
//   0.   0.
//
//   1.   1.
//
//   2.   16.
//
//   3.   81.
//
// Integration by Simpsons (1/3)rd Rule is:
//
//   98.
