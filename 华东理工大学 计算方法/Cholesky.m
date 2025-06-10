function x = Cholesky( A,b )
disp("单楚雄21013025");
N = length(A);
L = zeros(N,N);
D = zeros(1,N);
for i = 1:N
    L(i,i) = 1;
end
D(1) = A(1,1);
for i = 2:N
    for j = 1:i-1
        if j == 1
            L(i,j) = A(i,j)/D(j);
        else
            sum1 = 0;
            for k = 1:j-1
                sum1 = sum1 + L(i,k)*D(k)*L(j,k);
            end
            L(i,j) = (A(i,j) - sum1)/D(j);
        end
    end
    sum2 = 0;
    for k = 1:i-1
        sum2 = sum2 + L(i,k)^2*D(k);
    end
    D(i) = A(i,i) - sum2;
end
 
y = zeros(1:N);
y(1) = b(1);
for i = 2:N
    sumi = 0;
    for k = 1:i-1
        sumi = sumi + L(i,k)*y(k);
    end
    y(i) = b(i) - sumi;
end
x = zeros(1,N);
x(N) = y(N)/D(N);
for i = N-1:-1:1
    sumi = 0;
    for k = i+1:N
        sumi = sumi + L(k,i)*x(k);
    end
    x(i) = y(i)/D(i) - sumi;
end
