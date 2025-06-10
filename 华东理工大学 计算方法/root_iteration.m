function root = root_iteration(f, g, x0, tol, max_iter)
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
End
