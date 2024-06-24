function x = Solver(a, b, c, d)
    % 追赶法求解带有三对角矩阵结构的线性方程组

    n = length(d);  % 方程组的维度

    % 追赶法的分解步骤
    c_prime = zeros(n, 1);
    d_prime = zeros(n, 1);
    x = zeros(n, 1);

    c_prime(1) = c(1) / b(1);
    d_prime(1) = d(1) / b(1);
    for i = 2:n-1
        m = 1 / (b(i) - a(i-1) * c_prime(i-1));
        c_prime(i) = c(i) * m;
        d_prime(i) = (d(i) - a(i-1) * d_prime(i-1)) * m;
    end

    % 回代步骤
    x(n) = (d(n) - a(n-1) * d_prime(n-1)) / (b(n) - a(n-1) * c_prime(n-1));
    for i = n-1:-1:1
        x(i) = d_prime(i) - c_prime(i) * x(i+1);
    end
end
