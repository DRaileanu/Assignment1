#include "Sphere.h"

Sphere::Sphere(float r, int s) {
    radius = r;
    subdivision = s;
    buildVerticesFlat();
    
    //dangerous and dumb, but I know what I'm doing
    glm::vec3* vecs = reinterpret_cast<glm::vec3*>(icosahedronVertices.data());
    auto nVecs = icosahedronVertices.size() / 3;
    vertices.assign(vecs, vecs + nVecs);
    //otherwise have to push them one by one like this like this:
    //for (int i = 0; i < icosahedronVertices.size()/3; ++i) {
    //    vertices.push_back(glm::vec3(icosahedronVertices[3*i], icosahedronVertices[3 * i + 1], icosahedronVertices[3 * i +2]));
    //}

	setupBufferData();
}

Sphere::~Sphere() {

}


///////////////////////////////////////////////////////////////////////////////
// compute 12 vertices of icosahedron using spherical coordinates
// The north pole is at (0, 0, r) and the south pole is at (0,0,-r).
// 5 vertices are placed by rotating 72 deg at elevation 26.57 deg (=atan(1/2))
// 5 vertices are placed by rotating 72 deg at elevation -26.57 deg
///////////////////////////////////////////////////////////////////////////////
std::vector<float> Sphere::computeIcosahedronVertices() {


    const float PI = acos(-1);
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
        vertices[i1 + 1] = xy * sinf(hAngle1);  // x
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

void Sphere::addVertices(const float v1[3], const float v2[3], const float v3[3]) {
    icosahedronVertices.push_back(v1[0]);  // x
    icosahedronVertices.push_back(v1[1]);  // y
    icosahedronVertices.push_back(v1[2]);  // z
    icosahedronVertices.push_back(v2[0]);
    icosahedronVertices.push_back(v2[1]);
    icosahedronVertices.push_back(v2[2]);
    icosahedronVertices.push_back(v3[0]);
    icosahedronVertices.push_back(v3[1]);
    icosahedronVertices.push_back(v3[2]);
}


void Sphere::addIndices(unsigned int i1, unsigned int i2, unsigned int i3)
{
    indices.push_back(i1);
    indices.push_back(i2);
    indices.push_back(i3);
}


///////////////////////////////////////////////////////////////////////////////
// generate vertices with flat shading
// each triangle is independent (no shared vertices)
///////////////////////////////////////////////////////////////////////////////
void Sphere::buildVerticesFlat()
{
    //const float S_STEP = 1 / 11.0f;         // horizontal texture step
    //const float T_STEP = 1 / 3.0f;          // vertical texture step
    const float S_STEP = 186 / 2048.0f;     // horizontal texture step
    const float T_STEP = 322 / 1024.0f;     // vertical texture step

    // compute 12 vertices of icosahedron
    std::vector<float> tmpVertices = computeIcosahedronVertices();

    // clear memory of prev arrays
    std::vector<float>().swap(icosahedronVertices);
    //std::vector<float>().swap(normals);
    //std::vector<float>().swap(texCoords);
    std::vector<unsigned int>().swap(indices);

    const float* v0, * v1, * v2, * v3, * v4, * v11;     // vertex positions
    //float n[3];                                         // face normal
    //float t0[2], t1[2], t2[2], t3[2], t4[2], t11[2];    // texCoords
    unsigned int index = 0;

    // compute and add 20 tiangles of icosahedron first
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
        //t0[0] = (2 * i - 1) * S_STEP;   t0[1] = 0;
        //t1[0] = (2 * i - 2) * S_STEP;   t1[1] = T_STEP;
        //t2[0] = (2 * i - 0) * S_STEP;   t2[1] = T_STEP;
        //t3[0] = (2 * i - 1) * S_STEP;   t3[1] = T_STEP * 2;
        //t4[0] = (2 * i + 1) * S_STEP;   t4[1] = T_STEP * 2;
        //t11[0] = 2 * i * S_STEP;         t11[1] = T_STEP * 3;

        // add a triangle in 1st row
        //Icosphere::computeFaceNormal(v0, v1, v2, n);
        addVertices(v0, v1, v2);
        //addNormals(n, n, n);
        //addTexCoords(t0, t1, t2);
        addIndices(index, index + 1, index + 2);

        // add 2 triangles in 2nd row
        //Icosphere::computeFaceNormal(v1, v3, v2, n);
        addVertices(v1, v3, v2);
        //addNormals(n, n, n);
        //addTexCoords(t1, t3, t2);
        addIndices(index + 3, index + 4, index + 5);

        //Icosphere::computeFaceNormal(v2, v3, v4, n);
        addVertices(v2, v3, v4);
        //addNormals(n, n, n);
        //addTexCoords(t2, t3, t4);
        addIndices(index + 6, index + 7, index + 8);

        // add a triangle in 3rd row
        //Icosphere::computeFaceNormal(v3, v11, v4, n);
        addVertices(v3, v11, v4);
        //addNormals(n, n, n);
        //addTexCoords(t3, t11, t4);
        addIndices(index + 9, index + 10, index + 11);

        // next index
        index += 12;
    }

    // subdivide icosahedron
    subdivideVerticesFlat();

}

///////////////////////////////////////////////////////////////////////////////
// divide a trinage into 4 sub triangles and repeat N times
// If subdivision=0, do nothing.
///////////////////////////////////////////////////////////////////////////////
void Sphere::subdivideVerticesFlat()
{
    std::vector<float> tmpVertices;
    std::vector<float> tmpTexCoords;
    std::vector<unsigned int> tmpIndices;
    int indexCount;
    const float* v1, * v2, * v3;          // ptr to original vertices of a triangle
    //const float* t1, * t2, * t3;          // ptr to original texcoords of a triangle
    float newV1[3], newV2[3], newV3[3]; // new vertex positions
    //float newT1[2], newT2[2], newT3[2]; // new texture coords
    //float normal[3];                    // new face normal
    unsigned int index = 0;             // new index value
    int i, j;

    // iteration
    for (i = 1; i <= subdivision; ++i)
    {
        // copy prev arrays
        tmpVertices = icosahedronVertices;
        //tmpTexCoords = texCoords;
        tmpIndices = indices;

        // clear prev arrays
        icosahedronVertices.clear();
        //normals.clear();
        //texCoords.clear();
        indices.clear();

        index = 0;
        indexCount = (int)tmpIndices.size();
        for (j = 0; j < indexCount; j += 3)
        {
            // get 3 vertice and texcoords of a triangle
            v1 = &tmpVertices[tmpIndices[j] * 3];
            v2 = &tmpVertices[tmpIndices[j + 1] * 3];
            v3 = &tmpVertices[tmpIndices[j + 2] * 3];
            //t1 = &tmpTexCoords[tmpIndices[j] * 2];
            //t2 = &tmpTexCoords[tmpIndices[j + 1] * 2];
            //t3 = &tmpTexCoords[tmpIndices[j + 2] * 2];

            // get 3 new vertices by spliting half on each edge
            computeHalfVertex(v1, v2, radius, newV1);
            computeHalfVertex(v2, v3, radius, newV2);
            computeHalfVertex(v1, v3, radius, newV3);
            //computeHalfTexCoord(t1, t2, newT1);
            //computeHalfTexCoord(t2, t3, newT2);
            //computeHalfTexCoord(t1, t3, newT3);

            // add 4 new triangles
            addVertices(v1, newV1, newV3);
            //addTexCoords(t1, newT1, newT3);
            //computeFaceNormal(v1, newV1, newV3, normal);
            //addNormals(normal, normal, normal);
            addIndices(index, index + 1, index + 2);

            addVertices(newV1, v2, newV2);
            //addTexCoords(newT1, t2, newT2);
            //computeFaceNormal(newV1, v2, newV2, normal);
            //addNormals(normal, normal, normal);
            addIndices(index + 3, index + 4, index + 5);

            addVertices(newV1, newV2, newV3);
            //addTexCoords(newT1, newT2, newT3);
            //computeFaceNormal(newV1, newV2, newV3, normal);
            //addNormals(normal, normal, normal);
            addIndices(index + 6, index + 7, index + 8);

            addVertices(newV3, newV2, v3);
            //addTexCoords(newT3, newT2, t3);
            //computeFaceNormal(newV3, newV2, v3, normal);
            //addNormals(normal, normal, normal);
            addIndices(index + 9, index + 10, index + 11);
       

            // next index
            index += 12;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// find middle point of 2 vertices
// NOTE: new vertex must be resized, so the length is equal to the given length
///////////////////////////////////////////////////////////////////////////////
void Sphere::computeHalfVertex(const float v1[3], const float v2[3], float length, float newV[3])
{
    newV[0] = v1[0] + v2[0];
    newV[1] = v1[1] + v2[1];
    newV[2] = v1[2] + v2[2];
    float scale = computeScaleForLength(newV, length);
    newV[0] *= scale;
    newV[1] *= scale;
    newV[2] *= scale;
}

///////////////////////////////////////////////////////////////////////////////
// get the scale factor for vector to resize to the given length of vector
///////////////////////////////////////////////////////////////////////////////
float Sphere::computeScaleForLength(const float v[3], float length)
{
    // and normalize the vector then re-scale to new radius
    return length / sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}



