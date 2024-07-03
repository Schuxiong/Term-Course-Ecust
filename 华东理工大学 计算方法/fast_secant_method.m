function root = fast_secant_method(f, x0, x1, tol, max_iter)
    % f: 方程函数
    % x0, x1: 初始近似解
    % tol: 精度要求
    % max_iter: 最大迭代次数
    
    iter = 0;
    
    while abs(f(x1)) > tol && iter < max_iter
        f0 = f(x0);
        f1 = f(x1);
        x_next = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        x1 = x_next;
        iter = iter + 1;
    end
    
    if abs(f(x1)) <= tol
        root = x1;
        fprintf('迭代次数：%d\n', iter);
    else
        fprintf('未能达到指定精度要求。\n');
        root = NaN;
    end
end


