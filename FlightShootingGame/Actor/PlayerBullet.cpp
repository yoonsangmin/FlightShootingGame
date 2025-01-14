﻿#include "PlayerBullet.h"
#include <cmath>

PlayerBullet::PlayerBullet(const Vector2& position)
    : DrawableActor("!")
{
    // 탄약 위치 설정.
    this->position = position;
    yPosition = (float)position.y;
}

void PlayerBullet::Update(float deltaTime)
{
    Super::Update(deltaTime);
    
    // 위치 갱신.
    // 프레임 단위 이동.
    //--position.y;

    yPosition -= speed * deltaTime;
    //position.y = (int)(yPosition + 0.5f);
    //position.y = (int)roundf(yPosition);
    position.y = (int)yPosition;

    // y좌표가 화면을 벗어나면 액터 삭제.
    //if (position.y < 0)
    if (yPosition < 0.0f)
    {
        Destroy();
        return;
    }
}
