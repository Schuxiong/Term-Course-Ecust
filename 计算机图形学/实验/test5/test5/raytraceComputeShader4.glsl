#version 430

layout (local_size_x=1) in;
layout (binding=0, rgba8) uniform image2D output_texture;
float camera_pos = 5.0;

struct Ray
{	vec3 start;	// origin of the ray
	vec3 dir;	// normalized direction of the ray
};

float sphere_radius = 2.5;
vec3 sphere_position = vec3(1.0, 0.0, -3.0);
vec3 sphere_color = vec3(1.0, 0.0, 0.0); // red

vec3 box_mins = vec3(-2.0, -2.0, 0.0);
vec3 box_maxs = vec3(-0.5, 1.0, 2.0);
vec3 box_color = vec3(0.0, 1.0, 0.0); // green

vec3 square_mins = vec3(2.0, -0.5, 0.5);
vec3 square_maxs = vec3(4.0, 1.5, 1.5);
vec3 square_color = vec3(0.0, 0.93, 0.93); 

struct Collision
{	float t;	// value at which this collision occurs for a ray
	vec3 p;		// The world position of the collision
	vec3 n;		// the normal of the collision
	bool inside;	// Whether the ray started inside the object and collided while exiting
	int object_index;	// The index of the object this collision hit
};

//------------------------------------------------------------------------------
// Checks if Ray r intersects the Box defined by Object o.box
// This implementation is based on the following algorithm:
// http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf
//------------------------------------------------------------------------------
Collision intersect_box_object(Ray r)
{	// Calculate the box's world mins and maxs:
	vec3 t_min = (box_mins - r.start) / r.dir;
	vec3 t_max = (box_maxs - r.start) / r.dir;
	vec3 t_minDist = min(t_min, t_max);
	vec3 t_maxDist = max(t_min, t_max);
	float t_near = max(max(t_minDist.x, t_minDist.y), t_minDist.z);
	float t_far = min(min(t_maxDist.x, t_maxDist.y), t_maxDist.z);

	Collision c;
	c.t = t_near;
	c.inside = false;

	// If the ray is entering the box, t_near contains the farthest boundary of entry
	// If the ray is leaving the box, t_far contains the closest boundary of exit
	// The ray intersects the box if and only if t_near < t_far, and if t_far > 0.0
	
	// If the ray didn't intersect the box, return a negative t value
	if(t_near >= t_far || t_far <= 0.0)
	{	c.t = -1.0;
		return c;
	}

	float intersect_distance = t_near;
	vec3 plane_intersect_distances = t_minDist;

	// if t_near < 0, then the ray started inside the box and left the box
	if( t_near < 0.0)
	{	c.t = t_far;
		intersect_distance = t_far;
		plane_intersect_distances = t_maxDist;
		c.inside = true;
	}

	// Checking which boundary the intersection lies on
	int face_index = 0;

	if(intersect_distance == plane_intersect_distances.y) face_index = 1;
	else if(intersect_distance == plane_intersect_distances.z) face_index = 2;

	// Creating the collision normal
	c.n = vec3(0.0);
	c.n[face_index] = 1.0;

	// If we hit the box from the negative axis, invert the normal
	if(r.dir[face_index] > 0.0) c.n *= -1.0;

	// Calculate the world-position of the intersection:
	c.p = r.start + c.t * r.dir;

	return c;
}

//------------------------------------------------------------------------------
// Checks if Ray r intersects the Sphere defined by Object o.sphere
// This implementation is based on the following algorithm:
// http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf
//------------------------------------------------------------------------------
Collision intersect_sphere_object(Ray r)
{	float qa = dot(r.dir, r.dir);
	float qb = dot(2*r.dir, r.start-sphere_position);
	float qc = dot(r.start-sphere_position, r.start-sphere_position) - sphere_radius*sphere_radius;

	// Solving for qa * t^2 + qb * t + qc = 0
	float qd = qb * qb - 4 * qa * qc;

	Collision c;
	c.inside = false;

	if(qd < 0.0)	// no solution in this case
	{	c.t = -1.0;
		return c;
	}

	float t1 = (-qb + sqrt(qd)) / (2.0 * qa);
	float t2 = (-qb - sqrt(qd)) / (2.0 * qa);

	float t_near = min(t1, t2);
	float t_far = max(t1, t2);

	c.t = t_near;

	if(t_far < 0.0)		// sphere is behind the ray, no intersection
	{	c.t = -1.0;
		return c;
	}

	if(t_near < 0.0)	// the ray started inside the sphere
	{	c.t = t_far;
		c.inside = true;
	}

	c.p = r.start + c.t * r.dir;	// world position of the collision
	c.n = normalize(c.p - sphere_position);	// use the world position to compute the surface normal

	if(c.inside)	// if collision is leaving the sphere, flip the normal
	{	c.n *= -1.0;
	}
	return c;
}

Collision intersect_square_object(Ray r)
{
    vec3 t_min = (square_mins - r.start) / r.dir;
    vec3 t_max = (square_maxs - r.start) / r.dir;
    vec3 t_minDist = min(t_min, t_max);
    vec3 t_maxDist = max(t_min, t_max);
    float t_near = max(max(t_minDist.x, t_minDist.y), t_minDist.z);
    float t_far = min(min(t_maxDist.x, t_maxDist.y), t_maxDist.z);
    Collision c;
    c.t = t_near;
    c.inside = false;
    if (t_near >= t_far || t_far <= 0.0)
    {
        c.t = -1.0;
        return c;
    }
    float intersect_distance = t_near;
    vec3 plane_intersect_distances = t_minDist;
    if (t_near < 0.0)
    {
        c.t = t_far;
        intersect_distance = t_far;
        plane_intersect_distances = t_maxDist;
        c.inside = true;
    }
    int face_index = 0;
    if (intersect_distance == plane_intersect_distances.y)
        face_index = 1;
    else if (intersect_distance == plane_intersect_distances.z)
        face_index = 2;
    c.n = vec3(0.0);
    c.n[face_index] = 1.0;
    if (r.dir[face_index] > 0.0)
        c.n *= -1.0;
    c.p = r.start + c.t * r.dir;
    return c;
}
//------------------------------------------------------------------------------
// Returns the closest collision of a ray
// object_index == -1 if no collision
// object_index == 1 if collision with sphere
// object_index == 2 if collision with box
//------------------------------------------------------------------------------
Collision get_closest_collision(Ray r)
{
    Collision closest_collision, cSph, cBox, cSquare;
    closest_collision.object_index = -1;
    cSph = intersect_sphere_object(r);
    cBox = intersect_box_object(r);
    cSquare = intersect_square_object(r); // 添加对正方形的检测
    if ((cSph.t > 0) && ((cSph.t < cBox.t) || (cBox.t < 0)) && ((cSph.t < cSquare.t) || (cSquare.t < 0)))
    {
        closest_collision = cSph;
        closest_collision.object_index = 1;
    }
    if ((cBox.t > 0) && ((cBox.t < cSph.t) || (cSph.t < 0)) && ((cBox.t < cSquare.t) || (cSquare.t < 0)))
    {
        closest_collision = cBox;
        closest_collision.object_index = 2;
    }
    if ((cSquare.t > 0) && ((cSquare.t < cSph.t) || (cSph.t < 0)) && ((cSquare.t < cBox.t) || (cBox.t < 0)))
    {
        closest_collision = cSquare;
        closest_collision.object_index = 3;
    }
    return closest_collision;
}
//------------------------------------------------------------------------------
// This function casts a ray into the scene and returns the final color for a pixel
//------------------------------------------------------------------------------
vec3 raytrace(Ray r)
{	Collision c = get_closest_collision(r);
	if (c.object_index == -1) return vec3(0.0);	// no collision
	if (c.object_index == 1) return sphere_color;
	if (c.object_index == 2) return box_color;
	if (c.object_index == 3) return square_color;
}

void main()
{	int width = int(gl_NumWorkGroups.x);
	int height = int(gl_NumWorkGroups.y);
	ivec2 pixel = ivec2(gl_GlobalInvocationID.xy);

	// convert this pixels screen space location to world space
	float x_pixel = 2.0 * pixel.x/width - 1.0;
	float y_pixel = 2.0 * pixel.y/height - 1.0;
	
	// Get this pixels world-space ray
	Ray world_ray;
	world_ray.start = vec3(0.0, 0.0, camera_pos);
	vec4 world_ray_end = vec4(x_pixel, y_pixel, camera_pos-1.0, 1.0);
	world_ray.dir = normalize(world_ray_end.xyz - world_ray.start);

	// Cast the ray out into the world and intersect the ray with objects
	vec3 color = raytrace(world_ray);
	imageStore(output_texture, pixel, vec4(color,1.0));
}