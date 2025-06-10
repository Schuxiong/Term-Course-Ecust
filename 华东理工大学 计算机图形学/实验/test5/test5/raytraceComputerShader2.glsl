#version 430 core
layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

layout (binding = 0, rgba8) writeonly uniform image2D outputImage;

void main() {
    ivec2 storePos = ivec2(gl_GlobalInvocationID.xy);

    // Ray generation for the first sphere
    vec3 sphere1Center = vec3(0.0, 0.0, -3.0);
    float sphere1Radius = 1.0;
    vec3 ray1Direction = normalize(vec3(storePos - RAYTRACE_RENDER_WIDTH / 2, -RAYTRACE_RENDER_HEIGHT / 2, -1.0));
    
    // Ray generation for the second sphere
    vec3 sphere2Center = vec3(1.5, 0.0, -3.0);
    float sphere2Radius = 0.5;
    vec3 ray2Direction = normalize(vec3(storePos - RAYTRACE_RENDER_WIDTH / 2, -RAYTRACE_RENDER_HEIGHT / 2, -1.0));

    // Check intersection with the first sphere
    float t1;
    bool hit1 = intersectRaySphere(vec3(0.0), ray1Direction, sphere1Center, sphere1Radius, t1);

    // Check intersection with the second sphere
    float t2;
    bool hit2 = intersectRaySphere(vec3(0.0), ray2Direction, sphere2Center, sphere2Radius, t2);

    // Color the pixel based on the intersection
    vec3 color = vec3(0.0);
    if (hit1) {
        color = vec3(1.0, 0.0, 0.0); // Red for the first sphere
    }
    else if (hit2) {
        color = vec3(0.0, 0.0, 1.0); // Blue for the second sphere
    }

    // Output the color to the image
    imageStore(outputImage, storePos, vec4(color, 1.0));
}
