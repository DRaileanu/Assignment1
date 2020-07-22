#include "Sphere.h"

Sphere::Sphere() {
	createIcosahedron();


	setupBufferData();
}

Sphere::~Sphere() {

}

std::vector<float> Sphere::computeIcosahedronVertices() {

    float radius = 3;

    const float PI = 3.1415926f;
    const float H_ANGLE = PI / 180 * 72;    // 72 degree = 360 / 5
    const float V_ANGLE = atanf(1.0f / 2);  // elevation = 26.565 degree

    std::vector<float> vertices(12 * 3);    // 12 vertices
    int i1, i2;                             // indices
    float z, xy;                            // coords
    float hAngle1 = -PI / 2 - H_ANGLE / 2;  // start from -126 deg at 2nd row
    float hAngle2 = -PI / 2;                // start from -90 deg at 3rd row

    // the first top vertex (0, 0, r)
    vertices[0] = 0;
    vertices[1] = 0;
    vertices[2] = radius;

    // 10 vertices at 2nd and 3rd rows
    for (int i = 1; i <= 5; ++i)
    {
        i1 = i * 3;         // for 2nd row
        i2 = (i + 5) * 3;   // for 3rd row

        z = radius * sinf(V_ANGLE);             // elevaton
        xy = radius * cosf(V_ANGLE);

        vertices[i1] = xy * cosf(hAngle1);      // x
        vertices[i2] = xy * cosf(hAngle2);
        vertices[i1 + 1] = xy * sinf(hAngle1);  // y
        vertices[i2 + 1] = xy * sinf(hAngle2);
        vertices[i1 + 2] = z;                   // z
        vertices[i2 + 2] = -z;

        // next horizontal angles
        hAngle1 += H_ANGLE;
        hAngle2 += H_ANGLE;
    }

    // the last bottom vertex (0, 0, -r)
    i1 = 11 * 3;
    vertices[i1] = 0;
    vertices[i1 + 1] = 0;
    vertices[i1 + 2] = -radius;

    return vertices;
}

void Sphere::createIcosahedron() {
    //const float S_STEP = 1 / 11.0f;         // horizontal texture step
//const float T_STEP = 1 / 3.0f;          // vertical texture step
    const float S_STEP = 186 / 2048.0f;     // horizontal texture step
    const float T_STEP = 322 / 1024.0f;     // vertical texture step

    // compute 12 vertices of icosahedron
    std::vector<float> tmpVertices = computeIcosahedronVertices();


    float* v0, * v1, * v2, * v3, * v4, * v11;                // vertex positions
    float n[3];                                         // face normal
    float t0[2], t1[2], t2[2], t3[2], t4[2], t11[2];    // texCoords
    unsigned int index = 0;

    // compute and add 20 tiangles
    v0 = &tmpVertices[0];       // 1st vertex
    v11 = &tmpVertices[11 * 3]; // 12th vertex
    for (int i = 1; i <= 5; ++i)
    {
        // 4 vertices in the 2nd row
        v1 = &tmpVertices[i * 3];
        if (i < 5)
            v2 = &tmpVertices[(i + 1) * 3];
        else
            v2 = &tmpVertices[3];

        v3 = &tmpVertices[(i + 5) * 3];
        if ((i + 5) < 10)
            v4 = &tmpVertices[(i + 6) * 3];
        else
            v4 = &tmpVertices[6 * 3];

        // texture coords
        t0[0] = (2 * i - 1) * S_STEP;   t0[1] = 0;
        t1[0] = (2 * i - 2) * S_STEP;   t1[1] = T_STEP;
        t2[0] = (2 * i - 0) * S_STEP;   t2[1] = T_STEP;
        t3[0] = (2 * i - 1) * S_STEP;   t3[1] = T_STEP * 2;
        t4[0] = (2 * i + 1) * S_STEP;   t4[1] = T_STEP * 2;
        t11[0] = 2 * i * S_STEP;         t11[1] = T_STEP * 3;

        // add a triangle in 1st row
        //Icosahedron::computeFaceNormal(v0, v1, v2, n);
        addVertices(v0, v1, v2);
        //addNormals(n, n, n);
        //addTexCoords(t0, t1, t2);
        addIndices(index, index + 1, index + 2);

        // add 2 triangles in 2nd row
        //Icosahedron::computeFaceNormal(v1, v3, v2, n);
        addVertices(v1, v3, v2);
        //addNormals(n, n, n);
       // addTexCoords(t1, t3, t2);
        addIndices(index + 3, index + 4, index + 5);

        //Icosahedron::computeFaceNormal(v2, v3, v4, n);
        addVertices(v2, v3, v4);
        //addNormals(n, n, n);
        //addTexCoords(t2, t3, t4);
        addIndices(index + 6, index + 7, index + 8);

        // add a triangle in 3rd row
        //Icosahedron::computeFaceNormal(v3, v11, v4, n);
        addVertices(v3, v11, v4);
        //addNormals(n, n, n);
        //addTexCoords(t3, t11, t4);
        addIndices(index + 9, index + 10, index + 11);

        // add 6 edge lines per iteration
        //addLineIndices(index);

        // next index
        index += 12;
    }
    // generate interleaved vertex array as well
    //buildInterleavedVertices();
}


void Sphere::addVertices(float* v1, float* v2, float* v3) {
    vertices.push_back(glm::vec3(v1[0], v1[1], v1[2]));
    vertices.push_back(glm::vec3(v2[0], v2[1], v2[2]));
    vertices.push_back(glm::vec3(v3[0], v3[1], v3[2]));
}


void Sphere::addIndices(unsigned int i1, unsigned int i2, unsigned int i3)
{
    indices.push_back(i1);
    indices.push_back(i2);
    indices.push_back(i3);
}



