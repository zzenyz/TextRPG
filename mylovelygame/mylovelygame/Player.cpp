#include "Player.h"


bool Player::Save(std::ofstream& ofs) const {
    if (!ofs) return false;

    // ���ڿ� ����: null ����('\0') �����ؼ� ����
    ofs.write(name.c_str(), name.size() + 1);
    ofs.write(jobName.c_str(), jobName.size() + 1);

    // ������ ��� ����
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

    // null ����('\0')���� ������ ���ڿ� ����
    std::getline(ifs, name, '\0');
    std::getline(ifs, jobName, '\0');

    // ������ ��� ����
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
    std::cout << "\n=== [��� �����] ===\n";

    std::cout << "\n[�ܼ�]\n";
    if (clues.empty()) 
    {
        std::cout << "���� �߰��� �ܼ��� �����ϴ�.\n";
    }
    else
    {
        for (size_t i = 0; i < clues.size(); ++i) {
            std::cout << i + 1 << ". " << clues[i] << "\n";
        }
    }

    std::cout << "\n[��ǰ]\n";
    if (keepsakes.empty()) 
    {
        std::cout << "���� �߰��� ��ǰ�� �����ϴ�.\n";
    }
    else 
    {
        for (size_t i = 0; i < keepsakes.size(); ++i) 
        {
            std::cout << i + 1 << ". " << keepsakes[i] << "\n";
        }
    }

    std::cout << "\n====================\n";
    TypeWriter("\n--- [����Ϸ��� Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();
}

void Player::InitSkills() {
    skillSet.clear(); // ���� ��ų ����

    if (Job == 1) {
        skillSet.push_back({ "���� ��ô", "�⺻ ������" });
        skillSet.push_back({ "������ ��", "�߰� ������ + 3�� ���� ���� ������" });
        // �ʿ� �� �� �߰� ����
    }
    else if (Job == 2) {
        skillSet.push_back({ "���� �ر�", "�⺻ ������" });
        skillSet.push_back({ "ǳ�� ����", "���� ������ + 1�� ���� �ͽ� ����" });
    }
    else if (Job == 3) {
        skillSet.push_back({ "���� ��ô", "�⺻ ������" });
        skillSet.push_back({ "������ �ϰ�", "�߰� ������ + ���ط� 50% ȸ��" });
    }
}
