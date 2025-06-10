% 定义矩阵A、列向量B和列向量C
A = [4, -1, 0, 1, 0, 0;
     -1, 4, -1, 0, -1, 0;
     0, -1, 4, -1, 0, -1;
     0, 0, -1, 4, 1, 0;
     0, -1, 0, 1, 4, -1;
     -1, 0, -1, 0, -1, 4];
B = [x1; 
    x2; 
    x3; 
    x4;
    x5; 
    x6];
C = [0;
    5;
    -2; 
    5; 
    -2;
    6];

% 初始化变量
x = zeros(size(B));
x_prev = x;
n = length(x);
epsilon = 1e-5;
iteration = 0;

% Jacobi迭代
while true
    x = zeros(size(B));
    for i = 1:n
        x(i) = (C(i) - A(i, 1:i-1) * x_prev(1:i-1) - A(i, i+1:n) * x_prev(i+1:n)) / A(i, i);
    end
    
    iteration = iteration + 1;
    
    % 判断迭代是否收敛
    if norm(x - x_prev) < epsilon
        break;
    end
    
    x_prev = x;
end

fprintf('Jacobi迭代结果：\n');
disp(x);
fprintf('迭代次数：%d\n', iteration);

% 初始化变量
x = zeros(size(B));
x_prev = x;
iteration = 0;
