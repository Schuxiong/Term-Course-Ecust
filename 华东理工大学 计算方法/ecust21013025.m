% 生成插值节点
x = linspace(-5, 5, 11);
y = 1 ./ (1 + x.^2);

% 绘制分段线性插值多项式
xx = linspace(-5, 5, 100);
yy = interp1(x, y, xx, 'linear');
plot(xx, yy, '-r', 'LineWidth', 1.5);
hold on;

% 绘制原函数
yy = 1 ./ (1 + xx.^2);
plot(xx, yy, '-k', 'LineWidth', 1.5);

% 绘制分段三次 Hermite 插值多项式
yy = interp1(x, y, xx, 'pchip');
plot(xx, yy, '-g', 'LineWidth', 1.5);

% 标签和图例
xlabel('x');
ylabel('f(x)');
title('分段线性插值和分段三次 Hermite 插值与原函数的比较（单楚雄21013025）');
legend('分段线性插值', '原函数', '分段三次 Hermite 插值', 'Location', 'northwest');