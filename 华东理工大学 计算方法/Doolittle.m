function x =Doolittle( A,b )
disp("单楚雄21013025");
n = length(b);
L1 = eye(n);
U = zeros(n,n);
x = zeros(n,1);
y = zeros(n,1);
for i = 1:n
    U(1,i) = A(1,i);
    if i==1
        L1(i,1) = 1;
    else
        L1(i,1) = A(i,1)/U(1,1);
    end
end
for i = 2:n
    for j = i:n
        sum = 0;
        for k = 1:i-1
            sum = sum + L1(i,k)*U(k,j);
        end
        U(i,j) = A(i,j) - sum;
        if j ~= n
            sum = 0;
            for k = 1:i-1
                sum = sum + L1(j+1,k)*U(k,i);
            end
            L1(j+1,i) = (A(j+1,i) - sum)/U(i,i);
        end
    end
end
y(1) = b(1);
for k = 2:n
    sum = 0;
    for j = 1:k-1
        sum = sum + L1(k,j)*y(j);
    end
    y(k) = b(k) - sum;
end
x(n) = y(n)/U(n,n);
for k = n-1:-1:1
    sum = 0;
    for j = k+1:n
        sum = sum + U(k,j)*x(j);
    end
    x(k) = (y(k)-sum)/U(k,k);
end
