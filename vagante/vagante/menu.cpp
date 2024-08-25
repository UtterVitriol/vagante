#include "menu.h"
#include "imgui.h"
#include "Game.h"

extern Game g_Game;

void
my_menu ()
{
    const float MAX_SCALE = 3.0F;
    const float MIN_SCALE = 0.3F;

    ImGuiIO                &io = ImGui::GetIO();
    static ImGuiWindowFlags flags
        = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);

    if (!g_Game.pCharacter)
    {
        return;
    }

    if (!ImGui::Begin("Tingle's Internal Trainer", (bool *)0, flags))
    {
        ImGui::End();
        return;
    }

    if (ImGui::CollapsingHeader("Settings"))
    {
        ImGui::DragFloat("global scale",
                         &io.FontGlobalScale,
                         0.005f,
                         MIN_SCALE,
                         MAX_SCALE,
                         "%.2f",
                         ImGuiSliderFlags_AlwaysClamp); // Scale everything
    }

    ImGui::Separator();
    ImGui::InputScalar("Player", ImGuiDataType_U32, &g_Game.pCharacter, NULL, NULL, "%08X");

    ImGui::Separator();
    ImGui::InputFloat("X Pos", &g_Game.pCharacter->xPos, 1, 100, "%.1f");
    ImGui::InputFloat("y Pos", &g_Game.pCharacter->yPos, 1, 100, "%.1f");
    ImGui::InputFloat("X Vel", &g_Game.pCharacter->xVel, 1, 100, "%.1f");
    ImGui::InputFloat("y Vel", &g_Game.pCharacter->yVel, 1, 100, "%.1f");
    ImGui::InputInt("Num Jumps", &g_Game.pCharacter->numExtraJumps);
    ImGui::InputInt("Jump Count", &g_Game.pCharacter->numJumps);

    ImGui::Separator();
    ImGui::InputFloat("Health", &g_Game.pCharacter->hp, 1, 100, "%.1f");
    ImGui::InputFloat("Max Health", &g_Game.pCharacter->maxHp, 1, 100, "%.1f");
    ImGui::Checkbox("Immortal", &g_Game.pCharacter->immortal);
    ImGui::Checkbox("NoClip", &g_Game.pCharacter->cheatNoClip);
    ImGui::InputFloat("NoClip Speed", &g_Game.pCharacter->debugNoclipSpeed, 1, 100, "%.1f");

    ImGui::Separator();
    ImGui::InputFloat("Melee Damage", &g_Game.pCharacter->meleeDamage, 1, 100, "%.1f");
    ImGui::InputFloat("Range Damage", &g_Game.pCharacter->rangeDamage, 1, 100, "%.1f");
    ImGui::InputFloat("Damage From Items", &g_Game.pCharacter->damageFromItems, 1, 100, "%.1f");
    ImGui::InputFloat("Evasion Percentage", &g_Game.pCharacter->evasionPercent, 1, 100, "%.1f");
    ImGui::InputFloat("Critical Percentage", &g_Game.pCharacter->criticalPercent, 1, 100, "%.1f");

    ImGui::Separator();
    ImGui::InputInt("Add Money", &g_Game.pCharacter->goldCount);
    ImGui::InputInt("Experience Level", &g_Game.pCharacter->experienceLevel);
    ImGui::InputInt("Stored exp lvls", &g_Game.pCharacter->storedExperienceLevels);

    ImGui::End();
}
