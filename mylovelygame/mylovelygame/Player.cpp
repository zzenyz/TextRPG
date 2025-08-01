#include "Player.h"


bool Player::Save(std::ofstream& ofs) const {
    if (!ofs) return false;

    // 문자열 저장: null 문자('\0') 포함해서 저장
    ofs.write(name.c_str(), name.size() + 1);
    ofs.write(jobName.c_str(), jobName.size() + 1);

    // 정수형 멤버 저장
    ofs.write(reinterpret_cast<const char*>(&hp), sizeof(hp));
    ofs.write(reinterpret_cast<const char*>(&maxHp), sizeof(maxHp));
    ofs.write(reinterpret_cast<const char*>(&atk), sizeof(atk));
    ofs.write(reinterpret_cast<const char*>(&def), sizeof(def));
    ofs.write(reinterpret_cast<const char*>(&level), sizeof(level));
    ofs.write(reinterpret_cast<const char*>(&karma), sizeof(karma));

    return !ofs.fail();
}

bool Player::Load(std::ifstream& ifs) {
    if (!ifs) return false;

    // null 문자('\0')까지 읽으며 문자열 복원
    std::getline(ifs, name, '\0');
    std::getline(ifs, jobName, '\0');

    // 정수형 멤버 복원
    ifs.read(reinterpret_cast<char*>(&hp), sizeof(hp));
    ifs.read(reinterpret_cast<char*>(&maxHp), sizeof(maxHp));
    ifs.read(reinterpret_cast<char*>(&atk), sizeof(atk));
    ifs.read(reinterpret_cast<char*>(&def), sizeof(def));
    ifs.read(reinterpret_cast<char*>(&level), sizeof(level));
    ifs.read(reinterpret_cast<char*>(&karma), sizeof(karma));

    return !ifs.fail();
}

void Player::ShowMemoryStorage() const 
{
    std::cout << "\n=== [기억 저장소] ===\n";

    std::cout << "\n[단서]\n";
    if (clues.empty()) 
    {
        std::cout << "아직 발견한 단서가 없습니다.\n";
    }
    else
    {
        for (size_t i = 0; i < clues.size(); ++i) {
            std::cout << i + 1 << ". " << clues[i] << "\n";
        }
    }

    std::cout << "\n[유품]\n";
    if (keepsakes.empty()) 
    {
        std::cout << "아직 발견한 유품이 없습니다.\n";
    }
    else 
    {
        for (size_t i = 0; i < keepsakes.size(); ++i) 
        {
            std::cout << i + 1 << ". " << keepsakes[i] << "\n";
        }
    }

    std::cout << "\n====================\n";
    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();
}

void Player::InitSkills() {
    skillSet.clear(); // 기존 스킬 비우고

    if (Job == 1) {
        skillSet.push_back({ "부적 투척", "기본 데미지" });
        skillSet.push_back({ "강신의 춤", "중간 데미지 + 3턴 동안 지속 데미지" });
        // 필요 시 더 추가 가능
    }
    else if (Job == 2) {
        skillSet.push_back({ "지맥 붕괴", "기본 데미지" });
        skillSet.push_back({ "풍수 봉인", "강한 데미지 + 1턴 동안 귀신 봉인" });
    }
    else if (Job == 3) {
        skillSet.push_back({ "성수 투척", "기본 데미지" });
        skillSet.push_back({ "은총의 일격", "중간 데미지 + 피해량 50% 회복" });
    }
}
