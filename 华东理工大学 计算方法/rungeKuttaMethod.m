function [t, y] = rungeKuttaMethod(f, t0, y0, dt, numSteps)
    t = t0 + (0:numSteps) * dt;
    y = zeros(size(t));
    y(1) = y0;
    
    for i = 1:numSteps
        k1 = f(t(i), y(i));
        k2 = f(t(i) + 0.5*dt, y(i) + 0.5*dt*k1);
        k3 = f(t(i) + 0.5*dt, y(i) + 0.5*dt*k2);
        k4 = f(t(i) + dt, y(i) + dt*k3);
        y(i+1) = y(i) + (dt/6) * (k1 + 2*k2 + 2*k3 + k4);
    end
     disp("单楚雄21013025");
end
