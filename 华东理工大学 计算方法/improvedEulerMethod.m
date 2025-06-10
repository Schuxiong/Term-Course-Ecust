function [t, y] = improvedEulerMethod(f, t0, y0, dt, numSteps)
    t = t0 + (0:numSteps) * dt;
    y = zeros(size(t));
    y(1) = y0;
    
    for i = 1:numSteps
        k1 = f(t(i), y(i));
        k2 = f(t(i) + dt, y(i) + dt * k1);
        y(i+1) = y(i) + 0.5 * dt * (k1 + k2);
    end
     disp("单楚雄21013025");
end
