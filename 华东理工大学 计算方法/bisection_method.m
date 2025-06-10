function root = bisection_method(f, a, b, tol, max_iter)
    fa = f(a);
    fb = f(b);
    if sign(fa) == sign(fb)
        fprintf('区间两端函数值同号，无法使用弦截法。\n');
        root = NaN;
        return;
    end
    
    x = (a + b) / 2;
    iter = 0;
    while abs(f(x)) > tol && iter < max_iter
        fx = f(x);
        if sign(fx) == sign(fa)
            a = x;
            fa = fx;
        else
            b = x;
            fb = fx;
        end
        x = (a + b) / 2;
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
