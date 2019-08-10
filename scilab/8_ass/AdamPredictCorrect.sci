deff('g=f(x,y)','g=y-x^2');
x0=input("Enter the initial value of x: ");
y0=input("Enter the initial value of y: ");
h=input("Enter the value of h: ");
xn=input("Enter the value of xn: ");
xn1=xn-h;
n=(xn-x0)/h;
x(1)=x0;
y(1)=y0;
for i=1:n-1
    k1=h*f(x(i),y(i));
    k2=h*f(x(i)+h/2,y(i)+k1/2);
    k3=h*f(x(i)+h/2,y(i)+k2/2);
    k4=h*f(x(i)+h,y(i)+k3);
    x(i+1)=x(i)+h;
    y(i+1)=y(i)+(k1+2*k2+2*k3+k4)/6;
end
yp=y(n)+((h/24)*(55*f(x(n),y(n))-59*f(x(n-1),y(n-1))+37*f(x(n-2),y(n-2))-9*f(x(n-3),y(n-3))));
disp(yp,"Value of predictor method:");
yc=y(n)+(h/24)*(9*f(xn,yp)+19*f(x(n),y(n))-5*f(x(n-1),y(n-1))+f(x(n-2),y(n-2)));
disp(yc,"Value of corrector method:");
         
         
         
