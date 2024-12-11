/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** gl_cube
*/

#pragma once
#ifndef GL_CUBE_HPP_
#define GL_CUBE_HPP_

typedef enum colors_s {
    COLOR_WHITE,
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_ORANGE,
    COLOR_BLACK,
    COLORS_END,
} colors_t;

typedef enum faces_s {
    FACE_BACK,
    FACE_RIGHT,
    FACE_FRONT,
    FACE_LEFT,
    FACE_TOP,
    FACE_BOTTOM,
    FACE_SIZE,
} faces_t;

UNUSED static float colors_codes[COLORS_END][3] = {
    {1,  1,  1},     // white
    {1,  1,  0},     // yellow
    {1,  0,  0},     // red
    {0,  0,  1},     // blue
    {0,  1,  0},     // green
    {1, 0.5, 0},     // orange
    {0,  0,  0},     // black
};

class GL_cube {
    std::vector<std::vector<int>> faces = {
        {0, 1, 2, 3},       // back     side
        {3, 2, 7, 6},       // right    side
        {6, 7, 5, 4},       // front    side
        {4, 5, 1, 0},       // left     side
        {1, 5, 7, 2},       // top      side
        {4, 0, 3, 6}        // bottom   side
    };

    std::vector<Vector3f> vertex = {
        Vector3f(  1, -1, -1),      //? point 1 coordinates
        Vector3f(  1,  1, -1),      //? point 5 coordinates
        Vector3f( -1,  1, -1),      //? point 4 coordinates
        Vector3f( -1, -1, -1),      //? point 0 coordinates
        Vector3f(  1, -1,  1),      //? point 2 coordinates
        Vector3f(  1,  1,  1),      //? point 6 coordinates
        Vector3f( -1, -1,  1),      //? point 3 coordinates
        Vector3f( -1,  1,  1),      //? point 7 coordinates
    };

    std::array<bool, 6> visible_faces = {true, true, true, true, true, true};

    Vector3f position;
    std::vector<Vector3f> vertices = std::vector<Vector3f>(8);
    float faces_colors[6][3];

    int init_point[3];
    int current_point[3];

    int size = 1;
    float scale = 1;
    Matrix4f rotation;

    void Draw_cube();
    void Draw_lines();
    void Draw_points();

    public:
        GL_cube(float size, float scale, int point[3], colors_t colors[6]);
        ~GL_cube();
        void Set_vertices(float size);
        void Set_visible_faces();

        bool Is_affected(action_t action) const;
        void Rotate(float angle, action_t action) const;

        float *Transform_mat() const;

        void Update(action_t action);
        void Events(sf::Event *event);

        void Draw(bool rotating, float angle, action_t action);
};

#endif /* !GL_CUBE_HPP_ */
