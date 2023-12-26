#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <chrono>
#include <random>

bool isMouseOverButton(const SDL_Rect& buttonRect, int mouseX, int mouseY) {
    return mouseX >= buttonRect.x && mouseX <= buttonRect.x + buttonRect.w &&
        mouseY >= buttonRect.y && mouseY <= buttonRect.y + buttonRect.h;
}



bool isLionSelected = true;
bool isOwlSelected = false;
bool isDeerSelected = false;

// ������ ��� �������� ��������� ��������
std::vector<std::pair<int, int>> animals;




void drawText(SDL_Renderer* renderer, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int width, height;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}


int main(int argc, char* args[]) {

    SDL_Texture* foodTexture = nullptr;




    // ������������� SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL �� ������� ����������������! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // ������������� SDL_ttf
    if (TTF_Init() < 0) {
        printf("SDL_ttf �� ������� ����������������! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    // �������� ������
    TTF_Font* font = TTF_OpenFont("arial.ttf", 16);
    if (font == nullptr) {
        printf("�� ������� ��������� �����! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    // ������������� SDL_image
    if (IMG_Init(IMG_INIT_PNG) < 0) {
        printf("SDL_image �� ������� ����������������! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }


    // �������� ����
    SDL_Window* window = SDL_CreateWindow("��� SDL ����", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("���� �� ����� ���� �������! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }



    // �������� ������������� ���������
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    
    
    // ��������� ���������
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // ������� 
    SDL_Rect background = { 0, 0, 800, 800 }; 
    SDL_RenderFillRect(renderer, &background);

    // ���� (����� ������� ����)
    SDL_SetRenderDrawColor(renderer, 0, 191, 255, 255); // ������� 
    SDL_Rect pond = { 0, 0, 100, 200 };

    SDL_RenderFillRect(renderer, &pond);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // ������� 
    SDL_Rect addAnimalButtonRect = { 50, 625, 150, 50 }; 
    SDL_RenderFillRect(renderer, &addAnimalButtonRect);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // �����
    SDL_Rect removeAnimalButtonRect = { 210, 625, 150, 50 }; 
    SDL_RenderFillRect(renderer, &removeAnimalButtonRect);
    


    // �������� ����������� �����
    foodTexture = IMG_LoadTexture(renderer, "food.png");
    if (!foodTexture) {
        printf("�� ������� ��������� ����������� �����! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture* sleepTexture = IMG_LoadTexture(renderer, "sleep_spot.png"); 
    if (!sleepTexture) {
        printf("�� ������� ��������� ����������� ����� ��� ���! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    //  ����� ��� ��������� (������ ������ ����)
    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); // ����
    SDL_Rect feedingArea = { 500, 600, 400, 200 };
    SDL_RenderFillRect(renderer, &feedingArea);




    // ��������� ���������� ��������
    

    int initialLionX = 200;
    int initialLionY = 150;

    

    // ������� ���������� ��������
    


    int lionX = initialLionX;
    int lionY = initialLionY;

   

    // ����������� ���������� ��� ��������� �����
    std::vector<std::pair<int, int>> foodTargets;
    std::vector<std::pair<int, int>> sleepTargets;
    std::vector<std::pair<int, int>> exitTargets;

   
    

    // ���� ��������
    while (true) {
        SDL_RenderClear(renderer);

        // ��������� ����, �����,  �����
        SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // ������� ���
        SDL_RenderFillRect(renderer, &background);

        SDL_SetRenderDrawColor(renderer, 0, 191, 255, 255); // ������� 
        SDL_RenderFillRect(renderer, &pond);



        // ��������� ����������� �����
        SDL_Rect foodRect = { 525, 625, 200, 100 }; // ������ � ��������� 
        SDL_RenderCopy(renderer, foodTexture, nullptr, &foodRect);

        // ��������� ���� ��� ���
        SDL_Rect sleepRect = { 600, 300, 150, 100 }; 
        SDL_RenderCopy(renderer, sleepTexture, nullptr, &sleepRect);

        // ��������� ������
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // ������� 
        SDL_RenderFillRect(renderer, &addAnimalButtonRect);
        drawText(renderer, "Add Animal", 60, 645, font, { 0, 0, 0, 255 });

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // ����� 
        SDL_RenderFillRect(renderer, &removeAnimalButtonRect);
        drawText(renderer, "Remove Animal", 220, 645, font, { 0, 0, 0, 255 });


        
        // ���������� ������ ���������
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT && isMouseOverButton(addAnimalButtonRect, event.button.x, event.button.y)) {
                    
                    int currentLionX = lionX;
                    int currentLionY = lionY;

                    animals.push_back({ currentLionX, currentLionY });

                    

                    // �������� ����� ����� ��� ������������ ���������
                    foodTargets.push_back({ 500, 600 });  
                    sleepTargets.push_back({ 600, 300 }); 
                    exitTargets.push_back({ 700, 0 });  
                }
                else if (event.button.button == SDL_BUTTON_LEFT && isMouseOverButton(removeAnimalButtonRect, event.button.x, event.button.y)) {
                    // �������� ���������� ������������ ��������� � ��� �����
                    if (!animals.empty()) {
                        animals.pop_back();
                        foodTargets.pop_back();
                        sleepTargets.pop_back();
                        exitTargets.pop_back();
                    }
                }
                break;
            default:
                break;
            }
        }

        // ��������� �������� �� �������
        for (const auto& animal : animals) {
            int animalX = animal.first;
            int animalY = animal.second;

          
            
            SDL_SetRenderDrawColor(renderer, 255,255, 0, 255);
            SDL_Rect animalRect = { animalX, animalY, 50, 20 };
            SDL_RenderFillRect(renderer, &animalRect);

            // ����� ��� ������� ���������
            drawText(renderer, "Animal", animalX, animalY - 20, font, { 0, 0, 0, 255 });
        }

        //  ���������� �����
        for (std::size_t i = 0; i < animals.size(); ++i) {
            if (foodTargets.size() <= i) {
                // �������� ����� ����� ��� ������� ������������ ���������
                foodTargets.push_back({ 500, 600 });  
                sleepTargets.push_back({ 600, 300 }); 
                exitTargets.push_back({ 700, 0 });  
            }

            int targetX = foodTargets[i].first;
            int targetY = foodTargets[i].second;

            int animalX = animals[i].first;
            int animalY = animals[i].second;
            


            

            // ������� ������ ����������� � ����������� ����
            if (animalX < targetX) {
                animalX += 5; // ����������� ������
            }
            else if (animalX > targetX) {
                animalX -= 5; // ����������� �����
            }

            if (animalY < targetY) {
                animalY += 5; // ����������� ����
            }
            else if (animalY > targetY) {
                animalY -= 5; // ����������� �����
            }



            // ���������� ��������� ���������
            animals[i].first = animalX;
            animals[i].second = animalY;

            // �������� ���������� ���� � ������� � ���������
            if (std::abs(animalX - targetX) < 5 && std::abs(animalY - targetY) < 5) {
                
                
                foodTargets[i] = sleepTargets[i];  // ������ ��������� ��� ��������� ����
            }
            
            if (std::abs(600 - animalX) < 5 && std::abs(300 - animalY) < 5) {
                
                foodTargets[i] = exitTargets[i];  
                
            }
            
            
            if (std::abs(700 - animalX) < 5 && std::abs(0 - animalY) < 5) {
                // �������� ��������� ����� ���������� ��������� ���� (������ � ������)
                animals.erase(animals.begin() + i);
                foodTargets.erase(foodTargets.begin() + i);
                sleepTargets.erase(sleepTargets.begin() + i);
                
                --i;
            }
        
        }

       

        // ���������� ������
        SDL_RenderPresent(renderer);

        // ��� �������� 
        SDL_Delay(30);

    }


    // ����� ��������� ���� 
    SDL_Delay(2000);

    TTF_CloseFont(font);



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
    
}
