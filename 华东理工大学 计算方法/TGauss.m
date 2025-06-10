function G=TGauss(f,a,b)
x1=(a+b)/2-sqrt(3/5)*(b-a)/2;
x2=(a+b)/2-sqrt(3/5)*(b-a)/2;
G=(b-a)*(5*feval(f,x1)/9+8*feval(f,(a+b)/2)/9+5*feval(f,x2)/9)/2;
fprintf('result=%8.5f\n',G);
disp('单楚雄21013025');
