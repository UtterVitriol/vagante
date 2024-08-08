#include "menu.h"
#include "imgui_stdlib.h"
#include <string>
#include "hooks.h"
#include "Game.h"

extern Game g_Game;

static bool MyInputTextMultiline(const char *label, std::string *my_str, const ImVec2 &size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0)
{
	IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
	return ImGui::InputTextMultiline(label, my_str, size, flags, nullptr, (void *)my_str);
}


void my_menu()
{
	if (!g_Game.pCharacter)
	{
		return;
	}

	if (!ImGui::Begin("Tingle's Internal Trainer", (bool*)0, ImGuiWindowFlags_MenuBar))
	{
		ImGui::End();
		return;
	}
		

	ImGui::InputFloat("X Pos", &g_Game.pCharacter->xPos, 1, 100, "%.6f");
	ImGui::InputFloat("y Pos", &g_Game.pCharacter->yPos, 1, 100, "%.6f");
	ImGui::InputFloat("X Vel", &g_Game.pCharacter->xVel, 1, 100, "%.6f");
	ImGui::InputFloat("y Vel", &g_Game.pCharacter->yVel, 1, 100, "%.6f");
	ImGui::InputInt("Num Jumps", &g_Game.pCharacter->numExtraJumps);
	ImGui::InputInt("Jump Count", &g_Game.pCharacter->numJumps);

	ImGui::Separator();
	ImGui::InputFloat("Health", &g_Game.pCharacter->hp, 1, 100, "%.6f");
	ImGui::InputFloat("Max Health", &g_Game.pCharacter->maxHp, 1, 100, "%.6f");
	ImGui::Checkbox("Immortal", &g_Game.pCharacter->immortal);
	ImGui::Checkbox("NoClip", &g_Game.pCharacter->cheatNoClip);
	ImGui::InputFloat("NoClip Speed", &g_Game.pCharacter->debugNoclipSpeed, 1, 100, "%.6f");

	ImGui::Separator();
	ImGui::InputFloat("Melee Damage", &g_Game.pCharacter->meleeDamage, 1, 100, "%.6f");
	ImGui::InputFloat("Range Damage", &g_Game.pCharacter->rangeDamage, 1, 100, "%.6f");
	ImGui::InputFloat("Damage From Items", &g_Game.pCharacter->damageFromItems, 1, 100, "%.6f");
	ImGui::InputFloat("Evasion Percentage", &g_Game.pCharacter->evasionPercent, 1, 100, "%.6f");
	ImGui::InputFloat("Critical Percentage", &g_Game.pCharacter->criticalPercent, 1, 100, "%.6f");

	ImGui::Separator();
	ImGui::InputInt("Add Money", &g_Game.pCharacter->goldCount);
	ImGui::InputInt("Experience Level", &g_Game.pCharacter->experienceLevel);
	ImGui::InputInt("Stored exp lvls", &g_Game.pCharacter->storedExperienceLevels);

	ImGui::End();
}

