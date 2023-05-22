#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    int q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

   
    SDL_SetRenderDrawColor(gRenderer.get(), 0, 0, 0, 255);
    SDL_Rect prost_zewn = {q_x-102, q_y-10, 204, 20};
    SDL_RenderFillRect(gRenderer.get(), &prost_zewn);

    SDL_SetRenderDrawColor(gRenderer.get(), 140, 140, 140, 255);
    SDL_Rect prost_wewn = {q_x-100, q_y-8, 200, 16};
    SDL_RenderFillRect(gRenderer.get(), &prost_wewn);

    SDL_SetRenderDrawColor(gRenderer.get(), 0, 0, 0, 255);
    SDL_Rect prost_lewe = {q_x-65, q_y-30, 3, 20};
    SDL_RenderFillRect(gRenderer.get(), &prost_lewe);
    SDL_Rect prost_praw = {q_x+65, q_y-30, 3, 20};
    SDL_RenderFillRect(gRenderer.get(), &prost_praw);

    filledEllipseRGBA(gRenderer.get(), q_x-84, q_y-30, 20, 5, 0, 128, 192, 255);
    filledEllipseRGBA(gRenderer.get(), q_x+86, q_y-30, 20, 5, 0, 128, 192, 255);
    filledEllipseRGBA(gRenderer.get(), q_x-44, q_y-30, 20, 5, 0, 128, 192, 255);
    filledEllipseRGBA(gRenderer.get(), q_x+46, q_y-30, 20, 5, 0, 128, 192, 255);

    //filledCircleColor(gRenderer.get(), q_x, q_y, 30, 0xFF0000FF);
}