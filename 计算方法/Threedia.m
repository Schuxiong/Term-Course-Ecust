function x = Threedia( a,b,c,f )
disp("单楚雄21013025");
N = length(f);
x = zeros(1,N);y = zeros(1,N);
d = zeros(1,N);u = zeros(1,N);
% 预处理
d(1) = b(1);
for i = 1:N-1
    u(i) = c(i)/d(i);
    d(i+1) = b(i+1) - a(i+1)*u(i);
end
% 追
y(1) = f(1)/d(1);
for i = 2:N
    y(i) = (f(i)-a(i)*y(i-1))/d(i);
end
% 赶
x(N) = y(N);
for i = N-1:-1:1
    x(i) = y(i) - u(i)*x(i+1);
end
