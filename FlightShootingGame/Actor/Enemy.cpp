﻿#include "Enemy.h"
#include "Engine/Engine.h"
#include <cmath>

Enemy::Enemy(const char* image, int yPosition)
    : DrawableActor(image)
{
    // 램덤으로 이동할 방향 선택.
    int random = Random(1, 10);
    if (random % 2 == 0)
    {
        // 짝수인 경우에는 왼쪽으로 이동하도록 설정.
        direction = Direction::Left;

        // x좌표를 화면 끝으로 설정.
        xPosition = (float)(Engine::Get().ScreenSize().x - width);
    }
    else
    {
        // 홀수인 경우에는 오른쪽으로 이동하도록 설정.
        direction = Direction::Right;

        // x좌표를 0으로 설정.
        xPosition = 0.0f;
    }

    // 시작 위치 설정.
    this->position = Vector2((int)xPosition, yPosition);
}

void Enemy::Update(float deltaTime)
{
    Super::Update(deltaTime);

    // 좌우 이동.
    float factor = direction == Direction::Left ? -1.0f : 1.0f;
    xPosition += speed * factor * deltaTime;
    position.x = (int)xPosition;

    // 화면 밖 벗어나면 삭제.
    if (xPosition < 0 || position.x > Engine::Get().ScreenSize().x - width)
    {
        Destroy();
    }
}