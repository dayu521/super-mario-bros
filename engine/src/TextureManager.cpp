
#include <ResourceManager.h>
#include "TextureManager.h"
#include "Constants.h"
#include "glad/glad.h"

TextureManager::TextureManager() {

    ResourceManager::LoadShader("shaders/sprite.vsh", "shaders/sprite.fsh", nullptr, "shader");
    //configure shader
    glm::mat4 projection = glm::ortho(0.0f,
                                      static_cast<float>(256),
                                      static_cast<float>(224), 0.0f, -4.f, 4.f);

    auto shader = ResourceManager::GetShader("shader")
            .Use()
            .SetInteger("image", 0)
            .SetMatrix4("projection", projection);
    spriteRenderer = new SpriteRenderer(shader);
    ResourceManager::LoadTexture("assets/tileset.png", true, "tileset");

    //SDL_FreeSurface(tempSurface);

    // small mario
    atlasRects.insert_or_assign(MARIO_STAND, new SDL_Rect{0, 254, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MARIO_RUN_1, new SDL_Rect{17, 254, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MARIO_RUN_2, new SDL_Rect{34, 254, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MARIO_RUN_3, new SDL_Rect{51, 254, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MARIO_JUMP, new SDL_Rect{85, 254, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MARIO_DRIFT, new SDL_Rect{68, 254, TILE_SIZE, TILE_SIZE});

    //big mario
    atlasRects.insert_or_assign(MARIO_GROWING, new SDL_Rect{136, 271, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_STAND, new SDL_Rect{0, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_RUN_1, new SDL_Rect{17, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_RUN_2, new SDL_Rect{34, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_RUN_3, new SDL_Rect{51, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_JUMP, new SDL_Rect{85, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_DRIFT, new SDL_Rect{68, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(SUPER_MARIO_DUCK, new SDL_Rect{102, 221, TILE_SIZE, TILE_SIZE * 2});

    //tiles
    atlasRects.insert_or_assign(FLOOR, new SDL_Rect{0, 0, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(QUESTION_BLOCK_1, new SDL_Rect{0, 204, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(QUESTION_BLOCK_2, new SDL_Rect{17, 204, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(QUESTION_BLOCK_3, new SDL_Rect{34, 204, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(QUESTION_BLOCK_OFF, new SDL_Rect{51, 204, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MUSHROOM, new SDL_Rect{119, 204, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(TUBE_TOP_LEFT, new SDL_Rect{0, 34, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(TUBE_TOP_RIGHT, new SDL_Rect{17, 34, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(TUBE_LEFT, new SDL_Rect{0, 51, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(TUBE_RIGHT, new SDL_Rect{17, 51, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CLOUD, new SDL_Rect{204, 51, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(GOOMBA, new SDL_Rect{119, 187, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(GOOMBA_CRUSHED, new SDL_Rect{102, 187, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(BLOCK, new SDL_Rect{34, 34, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BRICK, new SDL_Rect{85, 0, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BUSH_LEFT, new SDL_Rect{34, 0, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BUSH_CENTER, new SDL_Rect{51, 0, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BUSH_RIGHT, new SDL_Rect{68, 0, TILE_SIZE, TILE_SIZE});

    //Background clouds
    atlasRects.insert_or_assign(BACKGROUND_CLOUD_TOP_LEFT, new SDL_Rect{0, 119, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_CLOUD_TOP_CENTER, new SDL_Rect{17, 119, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_CLOUD_TOP_RIGHT, new SDL_Rect{34, 119, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_CLOUD_BOTTOM_LEFT, new SDL_Rect{0, 136, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_CLOUD_BOTTOM_CENTER, new SDL_Rect{17, 136, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_CLOUD_BOTTOM_RIGHT, new SDL_Rect{34, 136, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(BRICK_DEBRIS_1, new SDL_Rect{136, 153, 8, 8});
    atlasRects.insert_or_assign(BRICK_DEBRIS_2, new SDL_Rect{144, 153, 8, 8});
    atlasRects.insert_or_assign(BRICK_DEBRIS_3, new SDL_Rect{136, 161, 8, 8});
    atlasRects.insert_or_assign(BRICK_DEBRIS_4, new SDL_Rect{144, 161, 8, 8});

    atlasRects.insert_or_assign(BACKGROUND_MOUNTAIN_1, new SDL_Rect{0, 17, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_MOUNTAIN_2, new SDL_Rect{17, 17, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_MOUNTAIN_3, new SDL_Rect{34, 17, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_MOUNTAIN_4, new SDL_Rect{17, 0, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(BACKGROUND_MOUNTAIN_5, new SDL_Rect{51, 17, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(COIN_1, new SDL_Rect{153, 153, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(COIN_2, new SDL_Rect{170, 153, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(COIN_3, new SDL_Rect{187, 153, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(COIN_4, new SDL_Rect{204, 153, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(TURTLE_1, new SDL_Rect{119, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(TURTLE_2, new SDL_Rect{136, 221, TILE_SIZE, TILE_SIZE * 2});
    atlasRects.insert_or_assign(TURTLE_SHELL_1, new SDL_Rect{153, 237, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(TURTLE_SHELL_2, new SDL_Rect{170, 237, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(MARIO_DEAD, new SDL_Rect{102, 254, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(FLAG_TOP, new SDL_Rect{51, 34, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(FLAG_RIGHT, new SDL_Rect{51, 51, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(FLAG_LEFT, new SDL_Rect{34, 51, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(FLAG_POLE, new SDL_Rect{187, 119, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_1, new SDL_Rect{0, 68, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_2, new SDL_Rect{17, 68, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_3, new SDL_Rect{34, 68, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_4, new SDL_Rect{0, 85, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_5, new SDL_Rect{17, 85, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_6, new SDL_Rect{34, 85, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_DOOR, new SDL_Rect{17, 102, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(CASTLE_8, new SDL_Rect{34, 102, TILE_SIZE, TILE_SIZE});

    atlasRects.insert_or_assign(COIN_SMALL_1, new SDL_Rect{119, 254, 5, 8});
    atlasRects.insert_or_assign(COIN_SMALL_2, new SDL_Rect{129, 254, 5, 8});
    atlasRects.insert_or_assign(COIN_SMALL_3, new SDL_Rect{124, 262, 5, 8});

    atlasRects.insert_or_assign(ONE_UP, new SDL_Rect{136, 204, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(ONE_UP_LABEL, new SDL_Rect{184, 271, 16, 7});
    atlasRects.insert_or_assign(ONEHUNDRED, new SDL_Rect{153, 287, 11, 8});
    atlasRects.insert_or_assign(TWOHUNDRED, new SDL_Rect{153, 279, 12, 8});
    atlasRects.insert_or_assign(THOUSAND, new SDL_Rect{153, 287, 15, 8});
    atlasRects.insert_or_assign(MARIO_FLAG_1, new SDL_Rect{170, 170, TILE_SIZE, TILE_SIZE});
    atlasRects.insert_or_assign(MARIO_FLAG_2, new SDL_Rect{187, 170, TILE_SIZE, TILE_SIZE});
}

void TextureManager::renderTexture(TextureId textureId, SDL_Rect& dstRect, float index, bool flipH, bool flipV) {
    auto textureRect = atlasRects.find(textureId);
    if (textureRect != atlasRects.end()) {
        if (dstRect.w == 0) dstRect.w = textureRect->second->w;
        if (dstRect.h == 0) dstRect.h = textureRect->second->h;

        spriteRenderer->DrawSprite(ResourceManager::GetTexture("tileset"),
                                   glm::vec3(dstRect.x, dstRect.y, index),
                                   glm::vec2(dstRect.w, dstRect.h),
                                   glm::vec2(textureRect->second->x, textureRect->second->y),
                                   0.0f,
                                   glm::vec3(1.0, 1.0, 1.0),
                                   flipH,
                                   flipV
        );
    }
}

TextureManager::~TextureManager() {
    std::unordered_map<TextureId, SDL_Rect*>::iterator it;
    for (it = atlasRects.begin(); it != atlasRects.end(); ++it) delete it->second;
    delete spriteRenderer;
}
