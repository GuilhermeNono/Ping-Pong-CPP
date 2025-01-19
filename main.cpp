#include <iostream>
#include "raylib.h"

int playerScore = 0;
int cpuScore = 0;

class Ball {
public:
    float x, y;
    int speedX, speedY;
    int radius;

    void Draw() {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update() {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speedY *= -1;
        }

        if (x + radius >= GetScreenWidth()) {
            cpuScore++;
            ResetBall();
        }

        if (x - radius <= 0) {
            playerScore++;
            ResetBall();
        }
    }

    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {1, -1};
        speedX *= speed_choices[GetRandomValue(0, 1)];
        speedY *= speed_choices[GetRandomValue(0, 1)];
    }
};

class Player {
protected:
    void LimitMovement() {
        if (y <= 0) {
            y = 0;
        }

        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;

    void Draw() {
        // DrawRectangle(10, (screenHeight / 2) - 120 / 2, 20, 120, WHITE);
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update() {
        if (IsKeyDown(KEY_UP)) {
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y += speed;
        }

        LimitMovement();
    }

    void Win() {

    }
};

class CpuPlayer : public Player {
public:
    void Update(int ballY) {
        if (y + height / 2 > ballY) {
            y -= speed;
        }

        if (y + height / 2 <= ballY) {
            y += speed;
        }

        LimitMovement();
    }
};

Ball ball;
Player player;
CpuPlayer cpuPlayer;

int main() {
    std::cout << "Starting the game" << std::endl;

    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Ping-Pong");
    SetTargetFPS(60);

    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.radius = 20;
    ball.speedX = 7;
    ball.speedY = 7;

    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 6;

    cpuPlayer.width = 25;
    cpuPlayer.height = 120;
    cpuPlayer.x = 10;
    cpuPlayer.y = screenHeight / 2 - cpuPlayer.height / 2;
    cpuPlayer.speed = 6;

    while (WindowShouldClose() == false) {
        BeginDrawing();

        if (playerScore == 5) {
            player.Win();
        }

        ball.Update();
        player.Update();
        cpuPlayer.Update(ball.y);

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
                                    Rectangle{player.x, player.y, player.width, player.height})) {
            ball.speedX *= -1;
        }

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{
                                        cpuPlayer.x, cpuPlayer.y, cpuPlayer.width, cpuPlayer.height
                                    })) {
            ball.speedX *= -1;
        }

        ClearBackground(BLACK);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        ball.Draw();
        cpuPlayer.Draw();
        player.Draw();

        DrawText(TextFormat("%i", cpuScore), screenWidth / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", playerScore), 3 * screenWidth / 4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
