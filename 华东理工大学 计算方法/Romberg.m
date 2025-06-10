function[quad,R]=Romberg(f,a,b,eps)
h=b-a;
R(1,1)=h*(feval(f,a)+feval(f,b))/2;
M=1;J=0;err=1;
while err>eps
    J=J+1;
    h=h/2;
    S=0;
    for p=1:M
        x=a+h*(2*p-1);
        S=S+feval(f,x);
    end
    R(J+1,1)=R(J,1)/2+h*S;
    M=2*M;
    for k=1:J
        R(J+1,k+1)=R(J+1,k)+(R(J+1,k)-R(J,k))/(4^k-1);
    end
    err=abs(R(J+1,J)-R(J+1,J+1));
end
quad=R(J+1,J+1);
fprintf('result=%8.5f\n',R);
disp('单楚雄21013025');