/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** gl_cube
*/

#include "main.h"

GL_cube::GL_cube(float size, float scale, int point[3], colors_t colors[6]) {
    this->size = size;
    this->scale = scale;
    for (int i = 0; i < size; i++) {
        init_point[i] = point[i];
        current_point[i] = point[i];
    }
    Set_vertices(size);
    Set_visible_faces();
    for (int i = 0; i < 6; i++) {
        if (colors[i] == COLORS_END) {
            for (int j = i; j < 6; j++)
                colors[i] = COLOR_BLACK;
        }
        for (int j = 0; j < 3; j++)
            faces_colors[i][j] = colors_codes[colors[i]][j];
    }
}

GL_cube::~GL_cube() {}

void GL_cube::Set_vertices(float size) {
    float half_size = size / 2;
    for (int i = 0; i < 8; i++) {
        vertices[i] = Vector3f(
            vertex[i].x * half_size,
            vertex[i].y * half_size,
            vertex[i].z * half_size
        );
    }
}

void GL_cube::Set_visible_faces() {
    // Face Top (y == size - 1)
    visible_faces[FACE_TOP] = current_point[1] == size - 1 ? true : false;
    // Face Bottom (y == 0)
    visible_faces[FACE_BOTTOM] = current_point[1] == 0 ? true : false;

    // Face Front (z == size - 1)
    visible_faces[FACE_FRONT] = current_point[2] == size - 1 ? true : false;
    // Face Back (z == 0)
    visible_faces[FACE_BACK] = current_point[2] == 0 ? true : false;

    // Face Left (x == 0)
    visible_faces[FACE_LEFT] = current_point[0] == size - 1 ? true : false;
    // Face Right (x == cube_size - 1)
    visible_faces[FACE_RIGHT] = current_point[0] == 0 ? true : false;
}

bool GL_cube::Is_affected(action_t action) const {
    return current_point[action.axis] == action.layer;
}

void GL_cube::Rotate(float angle, action_t action) const {
    glRotatef(
        angle * action.dir,
        action.axis == 0 ? 1 : 0,
        action.axis == 1 ? 1 : 0,
        action.axis == 2 ? 1 : 0
    );
}

float *GL_cube::Transform_mat() const {
    Matrix4f s(rotation);
    s.a11 *= scale, s.a12 *= scale, s.a13 *= scale;
    s.a21 *= scale, s.a22 *= scale, s.a23 *= scale;
    s.a31 *= scale, s.a32 *= scale, s.a33 *= scale;
    float pos = (size - 1) / 2;

    s.a41 = (current_point[0] - pos) * 3.1 * scale;
    s.a42 = (current_point[1] - pos) * 3.1 * scale;
    s.a43 = (current_point[2] - pos) * 3.1 * scale;
    return s.Get_list();
}

void GL_cube::Update(action_t action) {
    if (!Is_affected(action))
        return;

    int i = (action.axis + 1) % size;
    int j = (action.axis + 2) % size;

    std::array _rotation = rotation.Get_matrixed_list();
    for (int k = 0; k < size; k++) {
        float tmp = _rotation[k][i];
        _rotation[k][i] = -_rotation[k][j] * action.dir;
        _rotation[k][j] = tmp * action.dir;
    }
    rotation = Matrix4f(_rotation);

    int tmp = current_point[i];
    current_point[i] = action.dir < 0 ? current_point[j] : size - 1 - current_point[j];
    current_point[j] = action.dir > 0 ? tmp : size - 1 - tmp;
}

void GL_cube::Draw_points() {
    glBegin(GL_POINTS);
    for (size_t i = 0; i < faces.size(); i++) {
        if (!visible_faces[i])
            continue;
        for (size_t j = 0; j < faces[i].size(); j++) {
            glColor3fv(colors_codes[COLOR_BLACK]);
            glVertex3fv(vertices[faces[i][j]].Get_list());
        }
    }
    glEnd();
}

void GL_cube::Draw_lines() {
    glBegin(GL_LINES);
    for (size_t i = 0; i < faces.size(); i++) {
        if (!visible_faces[i])
            continue;
        glColor3fv(colors_codes[COLOR_BLACK]);
        for (size_t j = 0; j < faces[i].size(); j++) {
            glVertex3fv(vertices[faces[i][j]].Get_list());
            glVertex3fv(vertices[faces[i][(j + 1) % faces[i].size()]].Get_list());
        }
    }
    glEnd();

    Draw_points();
}

void GL_cube::Draw_cube() {
    glBegin(GL_QUADS);
    for (size_t i = 0; i < faces.size(); i++) {
        if (!visible_faces[i])
            continue;
        glColor3fv(faces_colors[i]);
        for (size_t j = 0; j < faces[i].size(); j++) {
            glVertex3fv(vertices[faces[i][j]].Get_list());
        }
    }
    glEnd();
}

void GL_cube::Draw(bool rotating, float angle, action_t action) {
    glPushMatrix();

    if (rotating && Is_affected(action))
        Rotate(angle, action);

    glMultMatrixf(Transform_mat());

    Draw_cube();
    Draw_lines();

    glPopMatrix();
}
