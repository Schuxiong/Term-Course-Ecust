% 四阶亚当姆斯方法（Adam-Moulton方法）
function [t, y] = adam_moulton(f, tspan, y0, h)
    t0 = tspan(1);
    tf = tspan(2);
    t = t0:h:tf;
    y = zeros(size(t));
    y(1) = y0;
    %21013014 谭鑫迪
    for i = 2:length(t)
        y_prev = y(i-1);
        t_curr = t(i);
        
        % 使用亚当姆斯预估器方法进行预估
        y_pred = y_prev + (h/24) * (9*f(t_curr-h, y(i-1)) + 19*f(t_curr, y_pred) - 5*f(t_curr+ h, y_pred) + f(t_curr+2*h, y_pred));
        
        % 使用隐式欧拉法进行修正
        y(i) = y_prev + (h/24) * (f(t_curr-h, y(i-1)) - 5*f(t_curr, y_pred) + 19*f(t_curr+h, y(i)) + 9*f(t_curr+2*h, y_pred));
    end
end
