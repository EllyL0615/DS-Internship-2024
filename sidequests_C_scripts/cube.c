typedef struct{
    float x, y, z;
} Point;

typedef struct{
    float A, B, C, D;
} Plane;

Plane calc_plane(Point p1, Point p2, Point p3) {
    Plane plane;

    float v1x = p2.x - p1.x;
    float v1y = p2.y - p1.y;
    float v1z = p2.z - p1.z;

    float v2x = p3.x - p1.x;
    float v2y = p3.y - p1.y;
    float v2z = p3.z - p1.z;

    plane.A = v1y * v2z - v1z * v2y;
    plane.B = v1z * v2x - v1x * v2z;
    plane.C = v1x * v2y - v1y * v2x;
    plane.D = - (plane.A * p1.x + plane.B * p1.y + plane.C * p1.z);

    return plane;
}

float point_plane_dist(float x, float y, float z, Plane plane) {
    return plane.A * x + plane.B * y + plane.C * z + plane.D;
}

int in_cube(float x, float y, float z, Plane planes[6]) {
    for (int i = 0; i < 6; ++i) {
        if (point_plane_dist(x, y, z, planes[i]) > 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Point vertices[8] = {
        {0, 0, 0},
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 1, 1},
    };

    Point point = {0.5, 0.5, 0.5};

    Plane planes[6];
    planes[0] = calc_plane(vertices[0], vertices[1], vertices[2]);
    planes[1] = calc_plane(vertices[4], vertices[5], vertices[6]);
    planes[2] = calc_plane(vertices[0], vertices[1], vertices[4]);
    planes[3] = calc_plane(vertices[2], vertices[3], vertices[6]);
    planes[4] = calc_plane(vertices[0], vertices[2], vertices[4]);
    planes[5] = calc_plane(vertices[1], vertices[3], vertices[5]);

    if (in_cube(point.x, point.y, point.z, planes)) {
        printf("点在立方体内\n");
    } else {
        printf("点在立方体外\n");
    }

    return 0;
    
}