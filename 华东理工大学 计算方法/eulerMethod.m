function [t, y] = eulerMethod(f, t0, y0, dt, numSteps)
    t = t0 + (0:numSteps) * dt;
    y = zeros(size(t));
    y(1) = y0;
    
    for i = 1:numSteps
        y(i+1) = y(i) + dt * f(t(i), y(i));
    end
   disp("单楚雄21013025");
end
