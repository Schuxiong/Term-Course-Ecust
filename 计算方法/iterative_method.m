function root = iterative_method(f, g, x0, tol, max_iter)
    % f: 方程函数
    % g: 迭代公式函数
    % x0: 初始近似解
    % tol: 精度要求
    % max_iter: 最大迭代次数
    
    x = x0;
    iter = 0;
    
    while abs(f(x)) > tol && iter < max_iter
        x = g(x);
        iter = iter + 1;
    end
    
    if abs(f(x)) <= tol
        root = x;
        fprintf('迭代次数：%d\n', iter);
    else
        fprintf('未能达到指定精度要求。\n');
        root = NaN;
    end
end



